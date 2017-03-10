class Instruction{
    public:
        Instruction(): opcode(0), rs(0), rt(0), rd(0), shamt(0), funct(0);
        instruct(Instruction, int, int);
        Instruction(int opcode, int rs, int rt, int rd, int shamt, int funct): opcode(opcode), rs(rs), rt(rt), rd(rd), shamt(shamt), funct(funct);

    private:
        int opcode;
        int rs;
        int rt;
        int rd;
        int shamt;
        int funct;
};

