#pragma once
#include<vector>
#include<string>
#include<iomanip>
#include<iostream>
#include<cstdint>

#define int int32_t
#define uint uint32_t
#define uchar unsigned char

class Instruction;
Instruction decode_iimage(std::string &);
void read_file(std::vector<uint>&, uint&, uint&);

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
        Instruction(OPcode name, uint opc, uint rs, uint rt, uint rd, uint shamt, uint funct, uint addr): name(name), opc(opc), rs(rs), rt(rt), rd(rd), shamt(shamt), funct(funct), addr(addr){}
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
        uint opc;
        uint rs;
        uint rt;
        uint rd;
        uint shamt;
        uint funct;
        uint addr;
};