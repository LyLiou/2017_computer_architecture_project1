#include"single_cycle.h"

void Instruction::read_reg(uint& rs, uint& rt, std::vector<uint> regs)
{
    if(this->type=='R' || this->type=='I'){
        rs=regs[this->rs.num];
        rt=regs[this->rt.num];
        return;
    }else return;
}

void Instruction::alu(uint rs, uint rt, bool& w_enable, uint& output, uint& HI, uint& LO, uint& pc, uint& data_addr)
{
    uint next_pc=pc+4;
    int imm=int(this->C); imm<<=16; imm>>=16;
    if(this->name=="add"){
        output=rs+rt;
        w_enable=true;
    }else if(this->name=="addu"){
        output=rs+rt;//todo: check out what happen
        w_enable=true;
    }else if(this->name=="sub"){
        output=rs-rt;
        w_enable=true;
    }else if(this->name=="and_"){
        output=rs&rt;
        w_enable=true;
    }else if(this->name=="or_"){
        output=rs|rt;
        w_enable=true;
    }else if(this->name=="xor_"){
        output=rs^rt;
        w_enable=true;
    }else if(this->name=="nor"){
        output=~(rs|rt);
        w_enable=true;
    }else if(this->name=="nand"){
        output=~(rs&rt);
        w_enable=true;
    }else if(this->name=="slt"){
        output=(rs<rt) ? 1 : 0;
        w_enable=true;
    }else if(this->name=="sll"){
        output=rt<<this->C;
        w_enable=true;
    }else if(this->name=="srl"){
        output=rt>>this->C;
        w_enable=true;
    }else if(this->name=="sra"){
        output=int(rt)>>this->C;
        w_enable=true;
    }else if(this->name=="jr"){
        next_pc=rs;
        w_enable=false;
    }else if(this->name=="mult"){
        uint64_t ans=uint64_t(int64_t(int(rs))*int64_t(int(rt)));
        HI=uint(ans>>32);
        LO=uint(ans);
        w_enable=false;
    }else if(this->name=="multu"){
        uint64_t ans=uint64_t(rs)*uint64_t(rt);
        HI=uint(ans>>32);
        LO=uint(ans);
        w_enable=false;
    }else if(this->name=="mfhi"){
        output=HI;//should set flag for HILO error
        w_enable=true;
    }else if(this->name=="mflo") {
        output=LO;
        w_enable=true;
    }else if(this->name=="addi") {
        output=rs+imm;
        w_enable=true;
    }else if(this->name=="addiu"){
        output=rs+imm; //todo: check out what happen
        w_enable=true;
    }else if(this->name=="lw")   {
        data_addr=rs+imm;
        w_enable=true;
    }else if(this->name=="lh")   {
        data_addr=rs+imm;
        w_enable=true;
    }else if(this->name=="lhu")  {
        data_addr=rs+imm;
        w_enable=true;
    }else if(this->name=="lb")   {
        data_addr=rs+imm;
        w_enable=true;
    }else if(this->name=="lbu")  {
        data_addr=rs+imm;
        w_enable=true;
    }else if(this->name=="sw")   {
        data_addr=rs+imm;
        output=rt;
        w_enable=false;
    }else if(this->name=="sh")   {
        data_addr=rs+imm;
        output=rt&0x0000ffff;
        w_enable=false;
    }else if(this->name=="sb")   {
        data_addr=rs+imm;
        output=rt&0x000000ff;
        w_enable=false;
    }else if(this->name=="lui")  {
        output=this->C<<16;
        w_enable=true;
    }else if(this->name=="andi") {
        output=rs&this->C;
        w_enable=true;
    }else if(this->name=="ori")  {
        output=rs|this->C;
        w_enable=true;
    }else if(this->name=="nori") {
        output=~(rs|this->C);
        w_enable=true;
    }else if(this->name=="slti") {
        output=int(rs)<imm ? 1 : 0;
        w_enable=true;
    }else if(this->name=="beq")  {
        next_pc=(rs==rt) ? pc+4+4*imm : pc+4;
        w_enable=false;
    }else if(this->name=="bne")  {
        next_pc=(rs!=rt) ? pc+4+4*imm : pc+4;
        w_enable=false;
    }else if(this->name=="bgtz") {
        next_pc=(rs>0) ? pc+4+4*imm : pc+4;
        w_enable=false;
    }else if(this->name=="j")    {
        next_pc=((pc+4)&0xf0000000)+(this->C<<2);
        w_enable=false;
    }else if(this->name=="jal")  {
        next_pc=((pc+4)&0xf0000000)+(this->C<<2); output=pc+4;
        w_enable=false;
    }
    //else if(this->name=="halt") 
    pc=next_pc;
}

void Instruction::data_rw(uint data_addr, uint& to_write, std::vector<unsigned char>& dimage)
{//todo: detect alignment
    if(this->name=="lw"){
        to_write=0;
        for(uint i=data_addr;i<data_addr+4;++i){
            to_write<<=8;
            to_write+=uint(dimage[i]);
        }
    }else if(this->name=="lh"){
        to_write=0;
        for(uint i=data_addr;i<data_addr+2;++i){
            to_write<<=8;
            to_write+=uint(dimage[i]);
        }
        int temp=to_write;
        to_write=uint((temp<<16)>>16);
    }else if(this->name=="lhu"){
        to_write=0;
        for(uint i=data_addr;i<data_addr+2;++i){
            to_write<<=8;
            to_write+=uint(dimage[i]);
        }
    }else if(this->name=="lb"){
        to_write=uint(dimage[data_addr]);
        int temp=to_write;
        to_write=uint((temp<<24)>>24);
    }else if(this->name=="lbu"){
        to_write=uint(dimage[data_addr]);
    }else if(this->name=="sw"){
        dimage[data_addr]=(unsigned char)(to_write>>24);
        dimage[data_addr+1]=(unsigned char)((to_write<<8)>>24);
        dimage[data_addr+2]=(unsigned char)((to_write<<16)>>24);
        dimage[data_addr+3]=(unsigned char)((to_write<<24)>>24);
    }else if(this->name=="sh"){
        dimage[data_addr]=(unsigned char)((to_write<<16)>>24);
        dimage[data_addr+1]=(unsigned char)((to_write<<24)>>24);
    }else if(this->name=="sb"){
        dimage[data_addr]=(unsigned char)((to_write<<24)>>24);
    }
}

void Instruction::write_reg(bool w_enable, uint to_write, uint HI, uint LO, std::vector<uint>& regs)
{
    uint reg_num;
    if(this->name=="mult" || this->name=="multu"){
        if(regs[32]!=HI){
            std::cout << "HI " << std::hex << HI << std::dec << "\n";
        }
        if(regs[33]!=LO){
            std::cout << "LO " << std::hex << LO << std::dec << "\n";
        }
        regs[32]=HI;
        regs[33]=LO;
        return;
    }else if(!w_enable){
        return;
    }else{
        if(this->type=='R') reg_num=this->rd.num;
        else if(this->type=='I') reg_num=this->rt.num;
        if(reg_num==0){
            return;//error
        }else if(regs[reg_num]!=to_write){
            std::cout << reg_num << " " << std::hex << to_write << std::dec << "\n"; 
        }
        regs[reg_num]=to_write;
        return;
    }    
}