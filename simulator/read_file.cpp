#include"single_cycle.h"
#include<fstream>

char* read_file(){
    std::ifstream ifile("iimage.bin", std::ios::binary|std::ios::ate|std::ios::in);
    
    char* iimage;
    
    if(ifile.is_open()){
        auto size=ifile.tellg();
        iimage=new char[size];
        ifile.seekg(0, std::ios::beg);
        ifile.read(iimage, size);
        ifile.close();
        
        std::cout << "size:" << size << "\n";
/*
        for(int i=0;i<4;++i){
            pc<<=8;
            pc+=(unsigned int)(iimage[i]);
        }*/
        //std::cout << "pc:" << pc << "\n";
        /*
        for(int i=4;i<8;++i){
            num_inst<<=8;
            num_inst+=(unsigned int)(iimage[i]);
        }*/
        //std::cout << "Instruction num:" << num_inst << "\n";        
        /*
        while(num--){
            auto opcode=(unsigned int)((unsigned char)(imem[pos])>>2);
            
            std::cout << std::hex << opcode << " ";
            pos+=4;
        }*/
    }else std::cout << "Cannot open iimage.bin\n";
    return iimage;
}