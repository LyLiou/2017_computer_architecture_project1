#include"single_cycle.h"
#include<string>

void Instruction::set_pc(uint& pc)
{
    switch(this->type){
        case 'R':
            if(this->name=="jr"){
                pc+=4;
                //todo
            }else pc+=4;
            break;
        case 'I':
            uint to_jump=pc+4;
            if(this->name=="beq"){
                to_jump=pc+4;
                //todo
            }else if(this->name=="bne"){
                to_jump=pc+4;
                //todo
            }else if(this->name=="bgtz"){
                to_jump=pc+4;
                //todo
            }
            pc=to_jump;
            break;
        case 'J':
            if(this->name=="j"){
                //todo
            }else if(this->name=="jal"){
                //todo
            }
            break;
        case 'S':
            break;
        default:
            break;
    }
}