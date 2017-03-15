#pragma once
#include<vector>
class Instruction;
void decode_iimage(unsigned int&);

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
        Instruction(): opc(illegal), rs(0), rt(0), rd(0), shamt(0), funct(0){}
        Instruction(OPcode opcode, unsigned int rs, unsigned int rt, unsigned int rd, unsigned int shamt, unsigned int funct): opc(opcode), rs(rs), rt(rt), rd(rd), shamt(shamt), funct(funct){}

    private:
        OPcode opc;
        unsigned int rs;
        unsigned int rt;
        unsigned int rd;
        unsigned int shamt;
        unsigned int funct;
        unsigned int addr;
};