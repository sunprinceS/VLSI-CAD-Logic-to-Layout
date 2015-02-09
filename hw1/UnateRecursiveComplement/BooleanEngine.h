#ifndef BOOL_ENG_H
#define BOOL_ENG_H
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Cube;
class CubeList;

extern CubeList* boolEngMgr;

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
    Cube(size_t varNum) {
        _slots.resize(varNum+1,DONTCARE);//first is dummy
    }
    void setSlot(int* val,size_t num);
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
    CubeList(size_t varNum,size_t cubeNum) {
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
#endif //BOOL_ENG_H
