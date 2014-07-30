
 //***************************************************************************
 //                           CPMCMXData.h  -  description
 //                              -------------------
 //     begin                : 04 04 2014
 //     copyright            : (C) 2013 by Alan Watson
 //     email                : Alan.Watson@cern.ch
 //  ***************************************************************************/
  
 //***************************************************************************
 //  *                                                                         *
 //  *   This program is free software; you can redistribute it and/or modify  *
  // *   it under the terms of the GNU General Public License as published by  *
//   *   the Free Software Foundation; either version 2 of the License, or     *
 //  *   (at your option) any later version.                                   *
 //  *                                                                         *
 //  ***************************************************************************/
  
  #ifndef CPMCMXDATA_H
  #define CPMCMXDATA_H
  
  #include "CLIDSvc/CLASS_DEF.h"
  #include "TrigT1CaloEvent/CPMTobRoI.h"

  namespace LVL1 {
  
/** The CPMCMXData object contains the data transferred from the CPM to one of
    the CMXes (EM or Tau) in the crate.
    This is a transient class, describing backplane data */

    class CPMCMXData  {
    public:

    /** Constructors */
    CPMCMXData();
    CPMCMXData(int crate, int module, int type, 
               const std::vector<unsigned int>& tobWords);
    CPMCMXData(int crate, int module, int type, 
               const DataVector<CPMTobRoI>* tobs);

    /** Destructor */
    virtual ~CPMCMXData();

    /** Data accessors */
    int crate() const;
    int module() const;
    int type() const;
    unsigned int presenceMap() const;
    std::vector<unsigned int> DataWords() const;
    std::vector<unsigned int> TOBPresenceBits() const;
    std::vector<unsigned int> TOBWords() const;
    std::vector<unsigned int> TopoTOBs() const;
      
  /** Internal data */
    private:
    int m_crate;
    int m_module;
    int m_type;
    std::vector <unsigned int> m_DataWords;
    
    };
  } // end of namespace

#ifndef CPMCMXData_ClassDEF_H
#include "TrigT1CaloEvent/CPMCMXData_ClassDEF.h"
#endif

#endif
