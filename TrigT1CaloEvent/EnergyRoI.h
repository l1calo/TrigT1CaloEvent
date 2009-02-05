/***************************************************************************
                          EnergyRoI.h  -  description
                             -------------------
    begin                : Friday May 05 2002
    copyright            : (C) 2002 by moyse
    email                : e.moyse@qmul.ac.uk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef EnergyRoI_H
#define EnergyRoI_H

// Gaudi kernel stuff.
#include "GaudiKernel/DataObject.h"

namespace LVL1 {

/**This class defines the Energy ROI which is generated by the Energy Trigger.
This is not the final persistent class - use EnergySum_ROI (from RoIB) for
analysis, and CMMRoI for bytestream decoding and monitoring.

*@author moyse
*/
  class EnergyRoI : public DataObject {
  public:

  // constructor
  EnergyRoI(unsigned int word0, unsigned int word1, unsigned int word2) :
    m_roiWord0(word0),m_roiWord1(word1), m_roiWord2(word2) {};

  // destructor
  ~EnergyRoI(){};
  /** return roi word 0*/
  unsigned int roiWord0() const {return m_roiWord0;}
  /** return roi word 1*/
  unsigned int roiWord1() const {return m_roiWord1;}
  /** return roi word 2*/
  unsigned int roiWord2() const {return m_roiWord2;}
private:
  unsigned int m_roiWord0;
  unsigned int m_roiWord1;
  unsigned int m_roiWord2;

};

}//end of LVL1 namespace defn

#include "TrigT1CaloEvent/EnergyRoI_ClassDEF.h"

#endif
