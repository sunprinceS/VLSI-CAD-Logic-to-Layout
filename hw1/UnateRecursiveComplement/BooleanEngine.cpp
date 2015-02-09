#include "BooleanEngine.h"
using namespace std;

/**Cube Class**/
void 
Cube::setSlot(int* val,size_t num)
{
    _numBinateVar = num;
    //assert(varNum == num+1);//first is dummy
    for(size_t i=0;i<num;++i){ 
        if(val[i] > 0)
            _slots[val[i]] = POSITIVE;
        else
            _slots[abs(val[i])] = NEGATIVE;
    }
}


/**CubeList Class**/

CubeList
CubeList::cubeComp(CubeList f)
{}
CubeList
CubeList::cubeAnd(bool inv,size_t splitVar,CubeList f)
{}
CubeList
CubeList::cubeOr(bool inv,CubeList f1,CubeList f2)
{}
CubeList
CubeList::posCofactor(size_t splitVar,CubeList f)
{}
CubeList
CubeList::negCofactor(size_t splitVar,CubeList f)
{}
