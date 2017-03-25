#include"single_cycle.h"
#include<iostream>
#include<vector>
#include<iomanip>
#include<bitset>

uint amt_inst, cur_pc, init_pc, cycle;//amount of inst, pc now, pc first, cycle now
uint raw_inst;//inst in bin
uint rs_value, rt_value, rd_value, alu_output, HI, LO, data_addr;
std::vector<uint> iimage; //all inst in bin
std::vector<uint> dimage; //all data in bin
std::vector<uint> reg_arr; //all 32 reg
Instruction cur_inst;//inst in class

//int memr, memw, regw, jump;
//determine whether or not to read/write d-memory, to write reg, to jump
//-1 -> no need

int main()
{
    std::cout << "hello archi......" << std::endl;

    read_file(iimage, init_pc, amt_inst);//read iimage.bin, get initial pc, #inst
    
    std::cout << std::hex << "PC: " << init_pc << "\n" << std::dec;
    std::cout << "# of inst: " << amt_inst << " " << iimage.size() << "\n";
    
    for(int i=0;i<REG_AMT;++i) reg_arr.push_back(0);//init regs
    cur_pc=init_pc;
    cycle=0;
    
    
    for(uint i=0;i<amt_inst;++i){// todo: should take next inst by pc
        raw_inst=iimage[i];
        //std::bitset<32> x(raw_inst);
        //std::cout << x << "\n";
        Instruction temp;
        cur_inst=temp;
        cur_inst.inst_decoder(raw_inst);//get information of a inst
        cur_inst.print();
        
        cur_inst.read_reg(rs_value, rt_value, reg_arr);
        
        cur_inst.alu(rs_value, rt_value, alu_output, HI, LO, pc, data_addr);
        cur_inst.
        
        //cur_inst.set_pc(cur_pc);//decide next inst
    }
    
    return 0;
}
