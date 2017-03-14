enum OPcode{
    add,
    addu,
    sub,
    and,
    or,
    xor,
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
    halt
}
class Instruction{
    public:
        Instruction(): opc(0), rs(0), rt(0), rd(0), shamt(0), funct(0);
        instruct(Instruction, int, int);
        Instruction(int opc, int rs, int rt, int rd, int shamt, int funct): opc(opc), rs(rs), rt(rt), rd(rd), shamt(shamt), funct(funct);

    private:
        OPcode opc;
        unsigned int rs;
        unsigned int rt;
        unsigned int rd;
        unsigned int shamt;
        unsigned int funct;
        unsigned int addr;
};

