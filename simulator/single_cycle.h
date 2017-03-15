#pragma once
#include<vector>
#include<string>
#include<iomanip>
#include<iostream>
class Instruction;
Instruction decode_iimage(std::string &);

enum OPcode{
    add,
    addu,
    sub,
    _and,
    _or,
    _xor,
    nor,
    nand,
    slt,
    sll,
    srl,
    sra,
    jr,
    mult,
    multu,
    mfhi,
    addi,
    addiu,
    lw,
    lh,
    lhu,
    lb,
    lbu,
    sw,
    sh,
    sb,
    lui,
    andi,
    ori,
    nori,
    slti,
    beq,
    bne,
    j,
    halt,
    illegal
};
class Instruction{
    public:
        Instruction(): name(illegal), opc(0), rs(0), rt(0), rd(0), shamt(0), funct(0), addr(0){}
        Instruction(OPcode name, unsigned int opc, unsigned int rs, unsigned int rt, unsigned int rd, unsigned int shamt, unsigned int funct, unsigned int addr): name(name), opc(opc), rs(rs), rt(rt), rd(rd), shamt(shamt), funct(funct), addr(addr){}
        /*Instruction(Instruction&& ins)
        {
            opc=ins.opc;
            rt=ins.rt;
            rd=ins.rd;
            shamt=ins.shamt;
            funct=ins.funct;
        }*/
        void print()
        {
            std::cout << 
            std::hex << 
            std::setw(2) << 
            std::setfill('0') << 
            this->opc << " " << this->rs << " " << this->rt << " " << this->rd << " " << this->shamt << " " << this->funct << 
            std::dec << 
            std::endl;
        }
    private:
        OPcode name;
        unsigned int opc;
        unsigned int rs;
        unsigned int rt;
        unsigned int rd;
        unsigned int shamt;
        unsigned int funct;
        unsigned int addr;
};