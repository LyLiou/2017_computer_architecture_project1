#include"single_cycle.h"
#define PC_LOC 0
#define PC_LEN 4
#define NUMBER_LOC 4
#define NUMBER_LEN 4

unsigned int pc_init(char* iimage){
    unsigned int pc;
    for(int i=PC_LOC;i<PC_LOC+PC_LEN;++i){
        pc<<=8;
        pc+=(unsigned int)(iimage[i]);
    }
    return pc;
}

unsigned int get_num_inst(char* iimage){
    unsigned int num_inst;
    for(int i=NUMBER_LOC;i<NUMBER_LOC+NUMBER_LEN;++i){
        num_inst<<=8;
        num_inst+=(unsigned int)(iimage[i]);
    }
    return num_inst;
}