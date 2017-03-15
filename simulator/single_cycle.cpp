#include"single_cycle.h"
#include<iostream>
#include<fstream>
#include<vector>

int main()
{
    std::cout << "hello archi......" << std::endl;

    std::ifstream iimage("iimage.bin", std::ios::binary);
    char* imem;
    unsigned int pc=0;
    unsigned int ins_num=0;
    
    if(iimage.is_open()){
        iimage.seekg(0, std::ios::end);
        auto size=iimage.tellg();
        imem=new char [size];
        iimage.seekg(0, std::ios::beg);
        iimage.read(imem, size);
        iimage.close();
        
        std::cout << "size:" << size << "\n";

        for(int i=0;i<4;++i){
            pc<<=8;
            pc+=(unsigned int)(imem[i]);
        }
        std::cout << "pc:" << pc << "\n";
        
        for(int i=4;i<8;++i){
            ins_num<<=8;
            ins_num+=(unsigned int)(imem[i]);
        }
        std::cout << "Instruction num:" << ins_num << "\n";        
        /*
        while(num--){
            auto opcode=(unsigned int)((unsigned char)(imem[pos])>>2);
            
            std::cout << std::hex << opcode << " ";
            pos+=4;
        }*/
    }else std::cout << "Cannot open iimage.bin\n";
    
    unsigned int pos=8;
    //std::string imems(imem);
    
    for(unsigned int i=0;i<ins_num;++i){
        //std::string ins_src(imems, pos, 4);
        std::string ins_src;
        for(int j=0;j<4;++j) ins_src.push_back(imem[pos]+j);
        Instruction ins_cur=decode_iimage(ins_src);
        ins_cur.print();
        
        pos+=4;
    }
    return 0;
}
