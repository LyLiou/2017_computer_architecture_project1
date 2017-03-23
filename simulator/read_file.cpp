#include"single_cycle.h"
#include<fstream>
#include<vector>

void read_file(std::vector<uint>& iimage, uint& pc, uint& amt_inst){
    std::ifstream ifile("iimage.bin", std::ios::binary|std::ios::ate|std::ios::in);
    
    char* iimage_char;
    
    if(ifile.is_open()){
        auto size=ifile.tellg();
        iimage_char=new char[size];
        ifile.seekg(0, std::ios::beg);
        ifile.read(iimage_char, size);
        ifile.close();
        
        std::cout << "size:" << size << "\n";
        
        pc=0;
        for(int i=0;i<4;++i){
            pc<<=8;
            pc+=iimage_char[i];
        }
        amt_inst=0;
        for(int i=4;i<8;++i){
            amt_inst<<=8;
            amt_inst+=iimage_char[i];
        }
        uint temp;
        iimage.clear();
        for(int i=8;i<size;i+=4){
            temp=0;
            for(int j=i;j<i+4;++j){
                temp<<=8;
                temp+=iimage_char[j];
            }
            iimage.push_back(temp);
        }
    }else std::cout << "Cannot open iimage.bin\n";
    return;
}