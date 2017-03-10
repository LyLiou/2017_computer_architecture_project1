#define add 0x20
#define addu 0x
#define sub 0x
#define and 0x
#define or 0x
#define xor 0x
#define nor 0x
#define nand 0x
#define slt 0x
#define sll 0x
#define srl 0x
#define sra 0x
#define jr 0x
#define mult 0x
#define multu 0x
#define mfhi 0x
#define mflo 0x

#define addi 0x
#define addiu 0x
#define lw 0x
#define lh 0x
#define lhu 0x
#define lb 0x
#define lbu 0x
#define sw 0x
#define sh 0x
#define sb 0x
#define lui 0x
#define andi 0x
#define ori 0x
#define nori 0x
#define slti 0x
#define beq 0x
#define bne 0x
#define bgtz 0x

#define j 0x
#define jal 0x

#define halt 0x


class Instruction{
    public:
        Instruction(): opcode(0), rs(0), rt(0), rd(0), shamt(0), funct(0);
        instruct(Instruction, int, int);
        Instruction(int opcode, int rs, int rt, int rd, int shamt, int funct): opcode(opcode), rs(rs), rt(rt), rd(rd), shamt(shamt), funct(funct);

    private:
        unsigned int opcode;
        unsigned int rs;
        unsigned int rt;
        unsigned int rd;
        unsigned int shamt;
        unsigned int funct;
        unsigned int addr;
};

