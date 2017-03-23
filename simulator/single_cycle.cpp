#include"single_cycle.h"
#include<iostream>
#include<vector>
#include<iomanip>

uint amt_inst, pc, pc_init,  num_inst;
uint raw_inst;
std::vector<uint> iimage;
Instruction cur_inst;

int main()
{
    std::cout << "hello archi......" << std::endl;

    read_file(iimage, pc_init, amt_inst);
    
    //pc=pc_init(iimage[0]);
    std::cout << std::hex << "PC: " << pc_init << "\n";
    //amt_inst=get_amt_inst(iimage[0]);
    std::cout << "# of inst: " << amt_inst << " " << iimage.size() << "\n";
    
    pc=pc_init;
    num_inst=0;
    for(uint i=0;i<amt_inst;++i){
        raw_inst=iimage[i];
        Instruction temp;
        cur_inst=temp;
        cur_inst.inst_decoder(raw_inst);
        
        cur_inst.print();
        
        cur_inst.set_pc(pc);
    }
    
    return 0;
}
