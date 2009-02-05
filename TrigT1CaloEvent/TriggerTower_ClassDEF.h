#ifndef TriggerTower_ClassDEF_H
#define TriggerTower_ClassDEF_H
//Put here the CLASS_DEF macros for the STL containers you put in StoreGate

#include "TrigT1CaloEvent/TriggerTower.h"

#include "CLIDSvc/CLASS_DEF.h"
#include "DataModel/DataVector.h"


CLASS_DEF(LVL1::TriggerTower,   6206, 1)
CLASS_DEF(DataVector<LVL1::TriggerTower>,   6207, 1)

     //the third field is the version which is currently ignored
#endif
