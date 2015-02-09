#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<cmath>

using namespace std;

enum VarForm
{
    POSITIVE =  0,
    NEGATIVE =  1,
    DONTCARE =  2,

    TOT_FORM
};

class Cube
{
    friend ostream& operator<<(ostream& f,const Cube & cube)
    {
        f << cube._numBinateVar<< " ";
        for (size_t i = 1;i<cube._slots.size();++i) {
            if(cube._slots[i] == POSITIVE)
                f << i << " ";
            else if(cube._slots[i] == NEGATIVE)
                f << '-' << i << " ";
            else;
        }
        return f;
    }
public:
    Cube(size_t varNum)
    {
        _slots.resize(varNum+1,DONTCARE);//first is dummy
    }
    void setSlot(int* val,size_t num)
    {
        _numBinateVar = num;
        //assert(varNum == num+1);//first is dummy
        for(size_t i=0;i<num;++i)
        {
            if(val[i] > 0)
                _slots[val[i]] = POSITIVE;
            else
                _slots[abs(val[i])] = NEGATIVE;
        }
        cout << endl;
        
    }

    vector<VarForm> _slots;
private:
    size_t _numBinateVar;
};
class CubeList
{
    friend ostream& operator<<(ostream& f,const CubeList& cubeList)
    {
        f << cubeList._varNum << endl;
        f << cubeList._pcns.size() << endl;
        for (size_t i = 0;i<cubeList._pcns.size();++i) {
            f << cubeList._pcns[i] << endl;
        }
        return f;
    }
public:
    CubeList(size_t varNum,size_t cubeNum)
    {
        _pcns.resize(cubeNum,Cube(varNum));
        _varNum = varNum;
    }
    CubeList(){}
    CubeList cubeComp(CubeList f);
    CubeList cubeAnd(bool inv,size_t splitVar,CubeList f);
    CubeList cubeOr(bool inv,CubeList f1,CubeList f2);
    CubeList posCofactor(size_t splitVar,CubeList f);
    CubeList negCofactor(size_t splitVar,CubeList f);

    vector<Cube> _pcns;
private:
    size_t _varNum;
};


int main(int argc,const char** argv)
{
    CubeList* cubeMgr = new CubeList();

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
            cout << cubeList;
        }
    }
    else{
        cerr << "Usage: ./urpComp pcnFile" << endl;
        exit(-1);   
    }
    
    
    return 0;
}
