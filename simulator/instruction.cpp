#include"single_cycle.h"
#include<iostream>
#include<vector>
#include<string>

unsigned char get_bits(unsigned char c, int a, int b) //get part of bits in a byte;
{
    if(a<b || a>7 || b>7 || a<0 || b<0) return c; //76543210, a is left bound, b is right
    else{
        c<<=(7-a);
        c>>=(7-a+b);
        return c;
    }
}

Instruction decode_iimage(std::string &ins_src)
{
    unsigned int opc=(unsigned int)((unsigned char)(ins_src[0])>>2);
    /*switch(ins.opc){
        
    }*/
    OPcode name=add;
    Instruction ins(name, opc, 0, 0, 0, 0, 0, 0);
    return ins;
}