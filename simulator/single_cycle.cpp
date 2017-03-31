#include"single_cycle.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<bitset>
#include<sstream>

uint amt_inst;//amount of inst
uint cur_pc, init_pc, cycle;//current pc, initial pc, current cycle
uint init_sp;//initial sp
uint raw_inst;//inst in binary
uint rs_value, rt_value;//value in register, read by address in inst
uint to_write;//value to write, in d_memory or registers or nowhere
uint HI, LO;//HI LO value, change if mult
uint data_addr;//d_memory address to write in
bool w_enable;//whether or not register can be written(write_enable)
bool e1, e2, e3, e4, e5;//5 error flags
bool HI_w_enable, LO_w_enable;//before/after mfhi/mflo
std::vector<uint> iimage; //all inst in binary
std::vector<unsigned char> dimage; //all data in binary
std::vector<uint> reg_arr; //all 32 register
Instruction cur_inst;//current inst decoded

std::stringstream snap;

int main()
{
    //read .bin, get initial pc, #inst
    read_file(dimage, init_sp, iimage, init_pc, amt_inst);
    
    //std::cout << std::hex << "PC: " << init_pc << "\n" << std::dec;
    //std::cout << "#inst: " << amt_inst << " " << iimage.size() << "\n";
    
    //initialize
    snap.clear();
    snap.str(std::string());
    for(int i=0;i<REG_AMT;++i) reg_arr.push_back(0);//init regs
    reg_arr[29]=init_sp;//set sp
    cur_pc=init_pc;
    cycle=0;
    HI_w_enable=true;
    LO_w_enable=true;
    
    //print cycle 0
    snap << "cycle " << cycle << "\n";
    for(int i=0;i<32;++i){
        snap << "$" << std::setw(2) << std::setfill('0') << i << ": 0x" << std::hex << std::uppercase << std::setw(8) << reg_arr[i] << std::dec << "\n";
    }
    snap << "$HI: 0x" << std::setw(8) << std::setfill('0') << 0 << "\n";
    snap << "$LO: 0x" << std::setw(8) << std::setfill('0') << 0 << "\n";
    snap << "PC: 0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0') << cur_pc << std::dec << "\n\n\n";
    
    //open file
    std::ofstream snp_rpt, err_rpt;
    snp_rpt.open("snapshot.rpt");
    err_rpt.open("error_dump.rpt");
    
    while(1){
        //initialize error flag
        e1=false;
        e2=false;
        e3=false;
        e4=false;
        e5=false;
        
        ++cycle;
        
        //std::bitset<32> x(raw_inst);
        //std::cout << x << "\n";
        
        raw_inst=iimage[cur_pc/4];//load from iimage by pc
        Instruction temp;
        cur_inst=temp;
        cur_inst.inst_decoder(raw_inst);//decode it
        //cur_inst.print();
        
        if(cur_inst.halt()) break;
        
        //std::cout << "cycle: " << cycle << "\n";
        snap << "cycle " << cycle << "\n";
        
        //read reg value from address in inst
        cur_inst.read_reg(reg_arr, rs_value, rt_value);
        
        cur_inst.alu(rs_value, rt_value, to_write, HI, LO, cur_pc, data_addr, w_enable, e2, e3, HI_w_enable, LO_w_enable);
        
        cur_inst.data_rw(data_addr, to_write, dimage, e4, e5);
        
        cur_inst.write_reg(w_enable, to_write, HI, LO, reg_arr, snap, e1);
        
        //std::cout << "PC: 0x" << std::hex << cur_pc << std::dec << "\n\n";
        snap << "PC: 0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0') << cur_pc << std::dec << "\n\n\n";
        
        if(e1 && raw_inst!=0) err_rpt << "In cycle " << cycle << ": Write $0 Error\n";
        if(e2) err_rpt << "In cycle " << cycle << ": Number Overflow\n";
        if(e3) err_rpt << "In cycle " << cycle << ": Overwrite HI-LO registers\n";
        if(e4) err_rpt << "In cycle " << cycle << ": Address Overflow\n";
        if(e5) err_rpt << "In cycle " << cycle << ": Misalignment Error\n";
        if(e4||e5) break;
        
        snp_rpt << snap.str();
        snap.clear();
        snap.str(std::string());
    }
    snp_rpt.close();
    err_rpt.close();
    return 0;
}
