#include"single_cycle.h"
#include<iostream>
#include<vector>
#include<iomanip>
#include<bitset>

uint amt_inst, cur_pc, init_pc, cycle;//amount of inst, pc now, pc first, cycle now
uint sp_init;
uint raw_inst;//inst in bin
uint rs_value, rt_value, rd_value;
uint to_write, HI, LO, data_addr;
bool w_enable;
std::vector<uint> iimage; //all inst in bin
std::vector<unsigned char> dimage; //all data in bin
std::vector<uint> reg_arr; //all 32 reg
Instruction cur_inst;//inst in class

//int memr, memw, regw, jump;
//determine whether or not to read/write d-memory, to write reg, to jump
//-1 -> no need

int main()
{
    std::cout << "hello archi......" << std::endl;

    read_file(dimage, sp_init, iimage, init_pc, amt_inst);//read .bin, get initial pc, #inst
    
    std::cout << std::hex << "PC: " << init_pc << "\n" << std::dec;
    std::cout << "#inst: " << amt_inst << " " << iimage.size() << "\n";
    
    for(int i=0;i<REG_AMT;++i) reg_arr.push_back(0);//init regs
    cur_pc=init_pc;
    cycle=0;
    
    for(uint i=0;i<amt_inst;++i){// todo: should take next inst by pc
        raw_inst=iimage[(cur_pc-init_pc)/4];
        //std::bitset<32> x(raw_inst);
        //std::cout << x << "\n";
        Instruction temp;
        cur_inst=temp;
        cur_inst.inst_decoder(raw_inst);//get information of a inst
        //cur_inst.print();
        
        if(cur_inst.halt()) break;
        ++cycle;
        std::cout << "cycle: " << cycle << "\n";
        
        cur_inst.read_reg(rs_value, rt_value, reg_arr);
        cur_inst.alu(rs_value, rt_value, w_enable, to_write, HI, LO, cur_pc, data_addr);
        cur_inst.data_rw(data_addr, to_write, dimage);
        cur_inst.write_reg(w_enable, to_write, HI, LO, reg_arr);
        std::cout << "PC: " << std::hex << cur_pc << std::dec << "\n\n";
    }
    return 0;
}
