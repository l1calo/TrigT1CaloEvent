#ifndef CPMHits_ClassDEF_H
#define CPMHits_ClassDEF_H
//Put here the CLASS_DEF macros for the STL containers you put in StoreGate

#ifndef CPMHits_H
#include "TrigT1CaloEvent/CPMHits.h"
#endif

#include "CLIDSvc/CLASS_DEF.h"
#include "DataModel/DataVector.h"

CLASS_DEF( LVL1::CPMHits , 242253504 , 1 )
CLASS_DEF( DataVector<LVL1::CPMHits> , 110337239 , 1 )
     //the third field is the version which is currently ignored
#endif
