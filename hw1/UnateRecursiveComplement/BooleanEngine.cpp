#include "BooleanEngine.h"
using namespace std;

/**Cube Class**/
void 
Cube::setSlot(int* val,size_t num)
{
    _numVar = num;
    //assert(varNum == num+1);//first is dummy
    for(size_t i=0;i<num;++i){ 
        if(val[i] > 0)
            _slots[val[i]] = POSITIVE;
        else
            _slots[abs(val[i])] = NEGATIVE;
    }
}
CubeListType
CubeList::checkType()const
{
    if(this->_pcns.size() == 0) //empty
        return CONST0;
    else if (this->_pcns.size() == 1)
        return TRIVIAL;
    else
    {
        for (size_t i = 0;i<_pcns.size();++i) {
            if(_pcns[i].isTautology())
                return CONST1;
        }
        return NORMAL;
    }
}


/**CubeList Class**/

CubeList
CubeList::cubeComp(CubeList f)
{
    if(f.checkType() == NORMAL)
    {
        //choose the most binate variable
    }
    else if(f.checkType() == CONST0)
        return CubeList(_totalVarNum,1);
    else if(f.checkType() == CONST1)
        return CubeList(_totalVarNum,0);
    else
        return f.simpleComp();
}
CubeList
CubeList::cubeAnd(bool inv,size_t splitVar,CubeList f)
{
    for (size_t i = 0;i<f._pcns.size();++i) {
        if(inv){
            f._pcns[splitVar] = NEGATIVE;}
        else{
            f._pcns[splitVar] = POSITIVE;}
        ++f._varNum;
    }
    return f;
}
CubeList
CubeList::cubeOr(CubeList f1,CubeList f2)
{
    f1.insert(f1.end(),f2.begin(),f2.end());
    return f1;
}
CubeList
CubeList::posCofactor(size_t splitVar,CubeList f)
{
    vector<size_t> removeIds;

    for (size_t i = 0;i<_pcns.size();++i) {

        if(f._pcns[i]._slots[splitVar] == NEGATIVE){
            removeIds.push_back(i);}
        else if(f._pcns[i]._slots[splitVar] == POSITIVE){
            f._pcns[i]._slots[splitVar] = DONTCARE;
            --f._pcns[i]._varNum;
        }
        else;
    }
    
    if(!removeIds.empty())
    {
        bool eraseFirst = false;

        for (size_t i = 0;i<removeIds.size();++i) {
            if(removeIds[i] == 0){
                eraseFirst = true;}
            else{
                f.erase(f.begin()+removeIds[i]);}
        }//begin fixed

        if(eraseFirst)
            f.erase(f.begin());
    }
    return f;
}
CubeList
CubeList::negCofactor(size_t splitVar,CubeList f)
{
    vector<size_t> removeIds;

    for (size_t i = 0;i<_pcns.size();++i) {

        if(f._pcns[i]._slots[splitVar] == POSITIVE){
            removeIds.push_back(i);}
        else if(f._pcns[i]._slots[splitVar] == NEGATIVE){
            f._pcns[i]._slots[splitVar] = DONTCARE;
            --f._pcns[i]._varNum;
        }
        else;
    }
    
    if(!removeIds.empty())
    {
        bool eraseFirst = false;

        for (size_t i = 0;i<removeIds.size();++i) {
            if(removeIds[i] == 0){
                eraseFirst = true;}
            else{
                f.erase(f.begin()+removeIds[i]);}
        }//begin fixed

        if(eraseFirst)
            f.erase(f.begin());
    }
    return f;
}
