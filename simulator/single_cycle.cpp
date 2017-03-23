#include"single_cycle.h"
#include<iostream>
#include<vector>

uint num_inst, pc;
std::vector<uint> iimage;
int main()
{
    std::cout << "hello archi......" << std::endl;

    read_file(iimage, pc, num_inst);
    
    //pc=pc_init(iimage[0]);
    std::cout << "PC: " << pc << "\n";
    
    //num_inst=get_num_inst(iimage[0]);
    std::cout << "# of inst: " << num_inst << " " << iimage.size() << "\n";
    
    return 0;
}
