#include"single_cycle.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<bitset>
#include<sstream>

uint amt_inst, cur_pc, init_pc, cycle;//amount of inst, pc now, pc first, cycle now
uint sp_init;
uint raw_inst;//inst in bin
uint rs_value, rt_value, rd_value;
uint to_write, HI, LO, data_addr;
bool w_enable;
bool e1, e2, e3, e4, e5;//5 error
bool HI_w, LO_w;
std::vector<uint> iimage; //all inst in bin
std::vector<unsigned char> dimage; //all data in bin
std::vector<uint> reg_arr; //all 32 reg
Instruction cur_inst;//inst in class

std::stringstream snap, err;

int main()
{
    std::cout << "hello archi......" << std::endl;

    read_file(dimage, sp_init, iimage, init_pc, amt_inst);//read .bin, get initial pc, #inst
    
    std::cout << std::hex << "PC: " << init_pc << "\n" << std::dec;
    std::cout << "#inst: " << amt_inst << " " << iimage.size() << "\n";
    
    snap.clear();
    snap.str(std::string());
    err.clear();
    err.str(std::string());
    
    for(int i=0;i<REG_AMT;++i) reg_arr.push_back(0);//init regs
    reg_arr[29]=sp_init;
    cur_pc=init_pc;
    cycle=0;
    HI_w=true;
    LO_w=true;
    
    snap << "cycle " << cycle << "\n";
    for(int i=0;i<32;++i){
        snap << "$" << std::setw(2) << std::setfill('0') << i << ": 0x" << std::hex << std::uppercase << std::setw(8) << reg_arr[i] << std::dec << "\n";
    }
    snap << "$HI: 0x" << std::setw(8) << std::setfill('0') << 0 << "\n";
    snap << "$LO: 0x" << std::setw(8) << std::setfill('0') << 0 << "\n";
    snap << "PC: 0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0') << cur_pc << std::dec << "\n\n\n";
    
    std::ofstream snp_rpt, err_rpt;
    snp_rpt.open("snapshot.rpt");
    err_rpt.open("error_dump.rpt");
    
    while(1){
        raw_inst=iimage[cur_pc/4];
        e1=false;
        e2=false;
        e3=false;
        e4=false;
        e5=false;
        //std::bitset<32> x(raw_inst);
        //std::cout << x << "\n";
        Instruction temp;
        cur_inst=temp;
        cur_inst.inst_decoder(raw_inst);//get information of a inst
        cur_inst.print();
        
        if(cur_inst.halt()) break;
        ++cycle;
        std::cout << "cycle: " << cycle << "\n";
        snap << "cycle " << cycle << "\n";
        
        cur_inst.read_reg(rs_value, rt_value, reg_arr);
        cur_inst.alu(rs_value, rt_value, w_enable, to_write, HI, LO, cur_pc, data_addr, e2, e3, HI_w, LO_w);
        cur_inst.data_rw(data_addr, to_write, dimage, e4, e5);
        cur_inst.write_reg(w_enable, e1, to_write, HI, LO, reg_arr, snap, err);
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
