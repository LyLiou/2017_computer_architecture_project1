#include"single_cycle.h"
#include<iostream>
#include<vector>
#include<iomanip>
#include<bitset>

uint amt_inst, pc, pc_init,  num_inst;
uint raw_inst;
std::vector<uint> iimage;
Instruction cur_inst;

int main()
{
    std::cout << "hello archi......" << std::endl;

    read_file(iimage, pc_init, amt_inst);//read iimage.bin, get initial pc, #inst
    
    //pc=pc_init(iimage[0]);
    std::cout << std::hex << "PC: " << pc_init << "\n" << std::dec;
    //amt_inst=get_amt_inst(iimage[0]);
    std::cout << "# of inst: " << amt_inst << " " << iimage.size() << "\n";
    
    pc=pc_init;
    num_inst=0;
    for(uint i=0;i<amt_inst;++i){// todo: should take next inst by pc
        raw_inst=iimage[i];
        //std::bitset<32> x(raw_inst);
        //std::cout << x << "\n";
        Instruction temp;
        cur_inst=temp;
        cur_inst.inst_decoder(raw_inst);//get information of a inst
        
        cur_inst.print();
        
        cur_inst.set_pc(pc);//decide next inst
    }
    
    return 0;
}
