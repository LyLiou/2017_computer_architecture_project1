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
    
    /*uint pos=8;    
    for(uint i=0;i<num_inst;++i){
        //std::string ins_src(imems, pos, 4);
        std::string ins_src;
        for(int j=0;j<4;++j) ins_src.push_back(iimage[pos]+j);
        Instruction ins_cur=decode_iimage(ins_src);
        std::cout << i << " ";
        ins_cur.print();
        pos+=4;
    }*/
    return 0;
}
