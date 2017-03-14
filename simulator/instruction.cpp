#include"single_cycle.h"
#include<iostream>
#include<fstream>

char get_bits(char c, int a, int b) //get part of bits in a byte;
{
    if(a<b || a>7 || b>7 || a<0 || b<0) return c; //76543210, a is left bound, b is right
    else{
        c << (7-a);
        c >> (7-a+b);
        return c;
    }
}

void decode_iimage(unsigned int &pc, vector<Instruction> &ins_vec)
{
    ifstream iimage("iimage.bin", ios::in|ios::binary|ios::ate);
    char* imem;
    if(iimage.is_open()){
        auto size=iimage.tellg();
        imem=new char [size];
        iimage.seekg(0, ios::beg);
        iimage.read(imem, size);
        iimage.close();
        
        pc=0;
        for(int i=0;i<8;++i){
            pc+=imem[i];
            pc<<4;
        }
        unsigned int num=0;
        for(int i=0;i<8;++i){
            num+=imem[i];
            num<<4;
        }
        int pos=16;

        while(num--){
            unsigned int opcode=(((unsigned int)(imem[pos])) << 2) + (unsigned int)(get_bits(imem[pos+1], 7, 6));
            if(opcode==)
            pos+=4;
        }
    }else cout << "Cannot open iimage.bin\n";
}