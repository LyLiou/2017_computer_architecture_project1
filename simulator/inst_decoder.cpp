#include"single_cycle.h"
#include<string>

Reg map_reg(uint r)
{
    std::string s;
    switch(r){
        case 0: s="$zero"; break;
        case 1: s="$at"; break;
        case 2: s="$v0"; break;
        case 3: s="$v1"; break;
        case 4: s="$a0"; break;
        case 5: s="$a1"; break;
        case 6: s="$a2"; break;
        case 7: s="$a3"; break;
        case 8: s="$t0"; break;
        case 9: s="$t1"; break;
        case 10: s="$t2"; break;
        case 11: s="$t3"; break;
        case 12: s="$t4"; break;
        case 13: s="$t5"; break;
        case 14: s="$t6"; break;
        case 15: s="$t7"; break;
        case 16: s="$s0"; break;
        case 17: s="$s1"; break;
        case 18: s="$s2"; break;
        case 19: s="$s3"; break;
        case 20: s="$s4"; break;
        case 21: s="$s5"; break;
        case 22: s="$s6"; break;
        case 23: s="$s7"; break;
        case 24: s="$t8"; break;
        case 25: s="$t9"; break;
        case 26: s="$k0"; break;
        case 27: s="$k1"; break;
        case 28: s="$gp"; break;
        case 29: s="$sp"; break;
        case 30: s="$fp"; break;
        case 31: s="$ra"; break;
        default: s=""; break;
    }
    Reg reg(s, r);
    return reg;
}

void Instruction::inst_decoder(uint& raw_inst)
{
    this->opc=raw_inst>>26;
    switch(this->opc){
        case 0x00: 
            this->type='R';
            this->funct=(raw_inst<<26)>>26;
            switch(this->funct){
                case 0x20: this->name="add";   break;
                case 0x21: this->name="addu";  break;
                case 0x22: this->name="sub";   break;
                case 0x24: this->name="and_";  break;
                case 0x25: this->name="or_";   break;
                case 0x26: this->name="xor_";  break;
                case 0x27: this->name="nor";   break;
                case 0x28: this->name="nand";  break;
                case 0x2a: this->name="slt";   break;
                case 0x00: this->name="sll";   break;
                case 0x02: this->name="srl";   break;
                case 0x03: this->name="sra";   break;
                case 0x08: this->name="jr";    break;
                case 0x18: this->name="mult";  break;
                case 0x19: this->name="multu"; break;
                case 0x10: this->name="mfhi";  break;
                case 0x12: this->name="mflo";  break;
                default: this->name="illegal"; break;
            }
            break;
        case 0x08: this->name="addi"; type='I';break;
        case 0x09: this->name="addiu"; type='I';break;
        case 0x23: this->name="lw";    type='I';break;
        case 0x21: this->name="lh";    type='I';break;
        case 0x25: this->name="lhu";   type='I';break;
        case 0x20: this->name="lb";    type='I';break;
        case 0x24: this->name="lbu";   type='I';break;
        case 0x2b: this->name="sw";    type='I';break;
        case 0x29: this->name="sh";    type='I';break;
        case 0x28: this->name="sb";    type='I';break;
        case 0x0f: this->name="lui";   type='I';break;
        case 0x0c: this->name="andi";  type='I';break;
        case 0x0d: this->name="ori";   type='I';break;
        case 0x0e: this->name="nori";  type='I';break;
        case 0x0a: this->name="slti";  type='I';break;
        case 0x04: this->name="beq";   type='I';break;
        case 0x05: this->name="bne";   type='I';break;
        case 0x07: this->name="bgtz";  type='I';break;
        case 0x02: this->name="j";     type='J';break;
        case 0x03: this->name="jal";   type='J';break;
        case 0x3f: this->name="halt";  type='S';break;
        default: this->name="illegal"; type='X'; break;
    }
    
    switch(this->type){
        case 'R':
            this->rs=map_reg((raw_inst<<6)>>27);
            this->rt=map_reg((raw_inst<<11)>>27);
            this->rd=map_reg((raw_inst<<16)>>27);
            this->C=(raw_inst<<21)>>27;
            break;
        case 'I':
            this->rs=map_reg((raw_inst<<6)>>27);
            this->rt=map_reg((raw_inst<<11)>>27);
            this->C=(raw_inst<<16)>>16;
            break;
        case 'J':
            this->C=(raw_inst<<6)>>6;
            break;
        case 'S':
            break;
        default: break;
    }
    
    return;
}