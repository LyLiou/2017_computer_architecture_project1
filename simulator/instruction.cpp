#include"single_cycle.h"
#include<iostream>
#include<fstream>
#include<vector>

unsigned char get_bits(unsigned char c, int a, int b) //get part of bits in a byte;
{
    if(a<b || a>7 || b>7 || a<0 || b<0) return c; //76543210, a is left bound, b is right
    else{
        c<<=(7-a);
        c>>=(7-a+b);
        return c;
    }
}

void decode_iimage(unsigned int &pc)
{
    std::ifstream iimage("iimage.bin", std::ios::binary);
    char* imem;
    if(iimage.is_open()){
        iimage.seekg(0, std::ios::end);
        auto size=iimage.tellg();
        imem=new char [size];
        iimage.seekg(0, std::ios::beg);
        iimage.read(imem, size);
        iimage.close();
        
        std::cout << "size:" << size << "\n";
        
        pc=0;
        for(int i=0;i<4;++i){
            pc<<=8;
            pc+=(unsigned int)(imem[i]);
        }
        std::cout << "pc:" << pc << "\n";
        
        unsigned int num=0;
        for(int i=4;i<8;++i){
            num<<=8;
            num+=(unsigned int)(imem[i]);
        }
        int pos=8;
        
        std::cout << "num:" << num << "\n";
        
        while(num--){
            auto opcode=(unsigned int)((unsigned char)(imem[pos])>>2);
            
            std::cout << std::hex << opcode << " ";
            pos+=4;
        }
    }else std::cout << "Cannot open iimage.bin\n";
}