#include"single_cycle.h"
#include<iostream>
#include<vector>

uint amt_inst, pc, num_inst;
uint raw_inst;
std::vector<uint> iimage;
Instruction cur_inst;

int main()
{
    std::cout << "hello archi......" << std::endl;

    read_file(iimage, pc, amt_inst);
    
    //pc=pc_init(iimage[0]);
    std::cout << "PC: " << pc << "\n";
    //amt_inst=get_amt_inst(iimage[0]);
    std::cout << "# of inst: " << amt_inst << " " << iimage.size() << "\n";
    
    num_inst=0;
    for(uint i=0;i<amt_inst;++i){
        raw_inst=iimage[i];
        Instruction temp;
        cur_inst=temp;
        cur_inst.inst_decoder(raw_inst);
        cur_inst.print();
        
        
    }
    
    return 0;
}
