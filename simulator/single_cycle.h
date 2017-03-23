#pragma once
#include<vector>
#include<string>
#include<iomanip>
#include<iostream>
#include<cstdint>
#include<cstdio>

#define int int32_t
#define uint uint32_t
#define uchar unsigned char

class Instruction;
Instruction decode_iimage(std::string &);
void read_file(std::vector<uint>&, uint&, uint&);

/*enum OPcode{
    add,
    addu,
    sub,
    and_,
    or_,
    xor_,
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
    mflo,
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
    bgtz,
    j,
    jal,
    halt,
    illegal
};*/
class Instruction{
    public:
        Instruction(): name(""), type('X'), opc(0), rs(0), rt(0), rd(0), C(0), funct(0){}
        Instruction(std::string name, char type, uint opc, uint rs, uint rt, uint rd, uint C, uint funct): name(name), type(type), opc(opc), rs(rs), rt(rt), rd(rd), C(C), funct(funct){}
        /*Instruction(Instruction&& ins)
        {
            opc=ins.opc;
            rt=ins.rt;
            rd=ins.rd;
            shamt=ins.shamt;
            funct=ins.funct;
        }*/
        void inst_decoder(uint&);
        void set_pc(uint&);
        void print()
        {
            std::cout << 
            std::hex << 
            std::uppercase <<
            this->name << "\t" << this->opc << "\t" << this->type << "\t" << this->rs << "\t" << this->rt << "\t" << this->rd << "\t" << this->C << "\t" << this->funct << 
            std::dec << std::endl;
            //std::cout << this->name;
            //printf("%5X%2c\n", this->opc, this->type);
        }
    private:
        //OPcode name;
        std::string name;
        char type;
        uint opc;
        uint rs;
        uint rt;
        uint rd;
        uint C;
        uint funct;
};