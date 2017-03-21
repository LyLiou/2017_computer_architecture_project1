#include"single_cycle.h"
#include<iostream>
#include<vector>


unsigned int num_inst, pc;
char* iimage;
int main()
{
    std::cout << "hello archi......" << std::endl;

    iimage=read_file();
    pc=pc_init(iimage);
    std::cout << "PC: " << pc << "\n";
    num_inst=get_num_inst(iimage);
    std::cout << "# of inst: " << num_inst << "\n";
    
    unsigned int pos=8;
    //std::string imems(imem);
    
    for(unsigned int i=0;i<num_inst;++i){
        //std::string ins_src(imems, pos, 4);
        std::string ins_src;
        for(int j=0;j<4;++j) ins_src.push_back(iimage[pos]+j);
        Instruction ins_cur=decode_iimage(ins_src);
        std::cout << i << " ";
        ins_cur.print();
        
        pos+=4;
    }
    return 0;
}
