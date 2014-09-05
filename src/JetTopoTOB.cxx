
#include "TrigT1CaloEvent/JetTopoTOB.h"
#include <cmath>

namespace LVL1 {

// Static constants

const int JetTopoTOB::s_jemBit;
const int JetTopoTOB::s_frameBit;
const int JetTopoTOB::s_lcBit;
const int JetTopoTOB::s_etSmallBit;
const int JetTopoTOB::s_etLargeBit;

const int JetTopoTOB::s_jemMask;
const int JetTopoTOB::s_frameMask;
const int JetTopoTOB::s_lcMask;
const int JetTopoTOB::s_etSmallMask;
const int JetTopoTOB::s_etLargeMask;

JetTopoTOB::JetTopoTOB() : m_crate(0), m_tobWord(0)
{
}

JetTopoTOB::JetTopoTOB(int crate, uint32_t tobWord) : m_crate(crate), m_tobWord(tobWord)
{
}

JetTopoTOB::JetTopoTOB(int crate, int jem, int frame, int localCoord, int etSmall, int etLarge) : m_crate(crate)
{
  m_tobWord  =  0;
  m_tobWord |= (jem        & s_jemMask)        << s_jemBit;
  m_tobWord |= (frame      & s_frameMask)      << s_frameBit;
  m_tobWord |= (localCoord & s_lcMask)         << s_lcBit;
  m_tobWord |= (etSmall    & s_etSmallMask)    << s_etSmallBit;
  m_tobWord |= (etLarge    & s_etLargeMask)    << s_etLargeBit;
}

JetTopoTOB::~JetTopoTOB()
{
}

/** Extract eta index from TOB data
    The index is an integer eta coordinate in multiples of 0.1 (TT eta granularity) */

int JetTopoTOB::ieta() const
{
  int jemFrame = frame();
  int loc = localCoord();
  int moduleEta  =  (jemFrame >> 2)*s_frameEtaWidth + (loc&1);
  
  // Jet eta coordinates are irregular in forward regions as JE sizes vary
  int ieta = 0;
  if (jem() == 0 || jem() == 8) {
    switch (moduleEta) {
      case 0:
        ieta = -s_jemFJEta;
        break;
      case 1:
        ieta = -s_jemEC1Eta;
        break;
      case 2:
        ieta = -s_jemEC2Eta;
        break;
      case 3:
        ieta = -s_jemEC3Eta;
        break;
    }
  }
  else if (jem() == 7 || jem() == 15) {
    switch (moduleEta) {
      case 0:
        ieta = s_jemEC2Eta;
        break;
      case 1:
        ieta = s_jemEC1Eta;
        break;
      case 2:
        ieta = s_jemFJEta;
        break;
      case 3:
        ieta = s_jemFJEta;
        break;    
    }
  }
  else {
    ieta = moduleEta + (jem()%s_nJemPerQuadrant)*s_jemEtaWidth  - s_jemEtaOffset;
    ieta *= s_jetElementWidth;
  }
  
  return ieta;
}

// Extract eta coordinate from TOB data

float JetTopoTOB::eta() const
{
  return ieta()*0.1;
}

/** Extract phi index from TOB data.
    The index has the range -30 -> +32 in steps of 2*/

int JetTopoTOB::iphi() const
{
  int jemFrame = frame();
  int loc = localCoord();
  int modulePhi = (loc >> 1) + (jemFrame&0x3)*s_framePhiWidth;
  int iphi = modulePhi + m_crate*s_jemPhiWidth  + s_jemPhiOffset;
  if (jem() > s_nJemPerQuadrant) iphi -= 2*s_jemPhiWidth;
  return iphi*s_jetElementWidth;
}

// Extract phi coordinate from TOB data

float JetTopoTOB::phi() const
{
  return iphi()*M_PI/16;
}


} // end namespace
