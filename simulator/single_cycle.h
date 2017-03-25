#pragma once
#include<vector>
#include<string>
#include<iomanip>
#include<iostream>
#include<cstdint>
#include<cstdio>

#define int int32_t
#define uint uint32_t
#define REG_AMT 32

class Instruction;
class Reg;
Instruction decode_iimage(std::string &);
void read_file(std::vector<unsigned char>&, uint&, std::vector<uint>&, uint&, uint&);

class Reg{
    friend class Instruction;
    public:
        Reg(): name(""), num(0){}
        Reg(std::string name, uint num): name(name), num(num){}
    private:
        std::string name;
        uint num;
};

class Instruction{
    public:
        Instruction(): name(""), type('X'), opc(0), C(0), funct(0){
            Reg reg;
            rs=reg;
            rt=reg;
            rd=reg;
        }
        Instruction(std::string name, char type, uint opc, Reg rs, Reg rt, Reg rd, uint C, uint funct): name(name), type(type), opc(opc), rs(rs), rt(rt), rd(rd), C(C), funct(funct){}
        void inst_decoder(uint&);
        void read_reg(uint&, uint&, std::vector<uint>);
        void alu(uint, uint, bool&, uint&, uint&, uint&, uint&, uint&);
        void data_rw(uint, uint&, std::vector<unsigned char>&);
        void write_reg(bool, uint, std::vector<uint>&);
        void set_pc(uint&);
        void print()
        {
            std::cout << 
            std::hex << 
            std::uppercase <<
            this->name << "\t" << this->opc << "\t" << this->type << "\t" << this->rs.name << "\t" << this->rt.name << "\t" << this->rd.name << "\t" << this->C << "\t" << this->funct << 
            std::dec << std::endl;
            //std::cout << this->name;
            //printf("%5X%2c\n", this->opc, this->type);
        }
    private:
        //OPcode name;
        std::string name;
        char type;
        uint opc;
        Reg rs;
        Reg rt;
        Reg rd;
        uint C;
        uint funct;
};
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