/***************************************************************************
                          JetEtRoI.h  -  description
                             -------------------
    begin                : Thursday 2 Feb 2006
    copyright            : (C) 2006 by Alan Watson
    email                : Alan.Watson@cern.ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef JetEtRoI_H
#define JetEtRoI_H

// Gaudi kernel stuff.
#include "GaudiKernel/DataObject.h"
#include "CLIDSvc/CLASS_DEF.h"

namespace LVL1 {

/**
This class defines the ROI
which is generated by the Jet ET sum Trigger.

*@author Alan Watson
*/
  class JetEtRoI : public DataObject {
  public:

  // constructor
  JetEtRoI(unsigned int word, unsigned int jetEt) :
    m_roiWord(word), m_Et(jetEt)
    {
      m_hits = word&0xF;
    };

  // destructor
  ~JetEtRoI(){};
  /** return roi word*/
  unsigned int roiWord() const {return m_roiWord;}
  /** return result of Et estimation*/
  unsigned int jetEt() const {return m_Et;}
  /** return hit vector */
  unsigned int hits() const {return m_hits;}
private:
  unsigned int m_roiWord;
  unsigned int m_Et;
  unsigned int m_hits;

};

}//end of LVL1 namespace defn

#include "TrigT1CaloEvent/JetEtRoI_ClassDEF.h"
#endif
