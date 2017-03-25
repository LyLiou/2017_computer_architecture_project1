#include"single_cycle.h"

void Instruction::read_reg(uint& rs, uint& rt, std::vector<uint> regs)
{
    if(this->type=='R' || this->type=='I'){
        rs=regs[this->rs.num];
        rt=regs[this->rt.num];
        return;
    }else return;
}

void Instruction::alu(uint rs, uint rt, uint& output, uint& HI, uint& LO, uint& pc, uint& data_addr)
{
    uint next_pc=pc+4;
    int imm=int(this->C); imm<<=16; imm>>=16;
    switch(this->name){
        case "add":  output=rs+rt; break;
        case "addu": output=rs+rt; break;//todo: check out what happen
        case "sub":  output=rs-rt; break;
        case "and_": output=rs&rt; break;
        case "or_":  output=rs|rt; break;
        case "xor_": output=rs^rt; break;
        case "nor":  output=~(rs|rt); break;
        case "nand": output=~(rs&rt); break;
        case "slt":  output=(rs<rt) ? 1 : 0; break;
        case "sll":  output=rt<<this->C; break;
        case "srl":  output=rt>>this->C; break;
        case "sra":  output=int(rt)>>this->C break;
        case "jr":   next_pc=rs; break;
        case "mult":
            uint64_t ans=uint64_t(int64_t(int(rs))*int64_t(int(rt)));
            HI=uint(ans>>32);
            LO=uint(ans);
            break;
        case "multu":
            uint64_t ans=uint64_t(rs)*uint64_t(rt);
            HI=uint(ans>>32);
            LO=uint(ans);
            break;
        case "mfhi": output=HI; break;//should set flag for HILO error
        case "mflo": output=LO; break;
        case "addi": output=rs+imm; break;
        case "addiu":output=rs+imm; break; //todo: check out what happen
        case "lw":   data_addr=rs+imm; break;
        case "lh":   data_addr=rs+imm; break;
        case "lhu":  data_addr=rs+imm; break;
        case "lb":   data_addr=rs+imm; break;
        case "lbu":  data_addr=rs+imm; break;
        case "sw":   data_addr=rs+imm; output=rt; break;
        case "sh":   data_addr=rs+imm; output=rt&0x0000ffff; break;
        case "sb":   data_addr=rs+imm; output=rt&0x000000ff; break;
        case "lui":  output=this->C<<16; break;
        case "andi": output=rs&this->C; break;
        case "ori":  output=rs|this->C; break;
        case "nori": output=~(rs|this->C); break;
        case "slti": output=rs<imm ? 1 : 0; break;
        case "beq":  next_pc=(rs==rt) ? pc+4+4*imm : pc+4; break;
        case "bne":  next_pc=(rs!=rt) ? pc+4+4*imm : pc+4; break;
        case "bgtz": next_pc=(rs>0) ? pc+4+4*imm : pc+4; break;
        case "j":    next_pc=((pc+4)&0xf0000000)+(this->C<<2); break;
        case "jal":  next_pc=((pc+4)&0xf0000000)+(this->C<<2); output=pc+4; break;
        case "halt": break;
        default: break;
    }
    pc=next_pc;
}
/*
switch(this->name){
        case "add":   break;
        case "addu":  break;
        case "sub":   break;
        case "and_":  break;
        case "or_":   break;
        case "xor_":  break;
        case "nor":   break;
        case "nand":  break;
        case "slt":   break;
        case "sll":   break;
        case "srl":   break;
        case "sra":   break;
        case "jr":    break;
        case "mult":  break;
        case "multu": break;
        case "mfhi":  break;
        case "mflo":  break;
        case "addi":  break;
        case "addiu": break;
        case "lw":    break;
        case "lh":    break;
        case "lhu":   break;
        case "lb":    break;
        case "lbu":   break;
        case "sw":    break;
        case "sh":    break;
        case "sb":    break;
        case "lui":   break;
        case "andi":  break;
        case "ori":   break;
        case "nori":  break;
        case "slti":  break;
        case "beq":   break;
        case "bne":   break;
        case "bgtz":  break;
        case "j":     break;
        case "jal":   break;
        case "halt":  break;
        default: break;
    }
*/
