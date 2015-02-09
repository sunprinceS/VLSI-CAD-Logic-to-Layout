#include<iostream>
#include<fstream>
#include<cstdlib>
#include "BooleanEngine.h"
using namespace std;
CubeList* boolEngMgr = new CubeList();

int main(int argc,const char** argv)
{

    ifstream pcnFile;
    
    //Read Part
    if(argc !=1){
        pcnFile.open(argv[1],ios::in);
        if(pcnFile.is_open())
        {
            size_t varNum,cubeNum;
            pcnFile >> varNum >> cubeNum;

            CubeList cubeList(varNum,cubeNum);

            int* cubeContent = new int (varNum);
            size_t slotNum;
            for(size_t i=0;i< cubeNum ;++i)
            {
                pcnFile>> slotNum;
                for (size_t j = 0;j<slotNum;++j) {
                    pcnFile >> cubeContent[j];
                }
                cubeList._pcns[i].setSlot(cubeContent,slotNum);
            }
            //ReadEnd

            //CubeList resultList = cubeMgr->cubeComp(cubeList);
            //cout << cubeList;
        }
    }
    else{
        cerr << "Usage: ./urpComp pcnFile" << endl;
        exit(-1);   
    }
    return 0;
}
