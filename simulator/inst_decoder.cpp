#include"single_cycle.h"

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
        case 0x08: this->name="addiu"; type='I';break;
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
            this->rs=(raw_inst<<6)>>27;
            this->rt=(raw_inst<<11)>>27;
            this->rd=(raw_inst<<16)>>27;
            this->C=(raw_inst<<21)>>27;
            break;
        case 'I':
            this->rs=(raw_inst<<6)>>27;
            this->rt=(raw_inst<<11)>>27;
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