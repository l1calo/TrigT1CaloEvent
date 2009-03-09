/***************************************************************************
                          Jetroi.h  -  description
                             -------------------
    begin                : Mon Jan 22 2001
    copyright            : (C) 2001 by moyse
    email                : moyse@heppch.ph.qmw.ac.uk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef JetROI_H
#define JetROI_H

// Gaudi kernel stuff.
#include "GaudiKernel/SmartRef.h"
#include "GaudiKernel/SmartRefVector.h"

//LVL1 Calo trigger includes
#include "TrigT1Interfaces/TrigT1CaloDefs.h"
 
namespace LVL1 {

/**
This class defines the Jet ROIs which are generated by the LVL1 Calo Trigger.
These are not the persistent objects - you should use Jet_ROI (from RoIB)
for analysis, and JEMRoI for bytestream decoding and monitoring.

*@author moyse
*/

  class JetROI {
  public: 

    // constructor
    JetROI(double phi, double eta, int energy, unsigned long int roiWord,
    unsigned int m_cluster4, unsigned int m_cluster6, unsigned int m_cluster8,
    bool saturated);

    // destructor
    ~JetROI();

    /** returns the 32bit ROI word.
	*\todo implement hardware coords in ROI word
	*/    
    unsigned int roiWord() const;

    /** returns TRUE if ROI constructed from a 
	Jet Element that was saturated - in other
	words this ROI is signalling that it does not
	know it's correct energy. 
	*\todo implement*/
  bool saturated() const;

  /** returns phi coord of ROI */
  double phi() const;

  /** returns eta coord of ROI */
  double eta() const;

  /** returns the energy*/
  int energy() const;

  /** returns TRUE if threshold number <em>threshold_number</em> has been passed 
  by this ROI. 1st threshold is thresh 1 */
  bool thresholdPassed(int threshold_number) const;

  /** returns TRUE if threshold number <em>threshold_number</em> has been passed
  by this ROI. 1st threshold is thresh 1 */
  bool fwdThresholdPassed(int threshold_number) const;
    
  /** returns true if the RoI is a forward jet*/
  bool isForward() const;

  /** returns type of thresholds number <em>threshold_number</em>*/
  TrigT1CaloDefs::JetWindowSize thresholdType(int threshold_number) const;
  /** returns the most energetic cluster from window size 4 */
  unsigned int clusterEnergy4() const { return m_cluster4;} 
  /** returns the most energetic cluster from window size 6 */
  unsigned int clusterEnergy6() const { return m_cluster6;} 
  /** returns the most energetic cluster from window size 8 */
  unsigned int clusterEnergy8() const { return m_cluster8;} 

  private: // Private attributes

    /** phi coord of ROI */
    double m_phi;

    /** eta coord of ROI */
    double m_eta;
		
    /**Energy of ROI core, */
    int m_energy;

    /**Energy of most energetic cluster*/
    int m_cluster4;

    /**Energy of most energetic cluster*/
    int m_cluster6;

    /**Energy of most energetic cluster*/
    int m_cluster8;

    /** this is the actual format of the data sent from
	the LVL1 hardware. See  ATL-DAQ-99-015 for
	further explanation. */
    unsigned long int m_roiWord;
    
    /** saturation flag */
    bool m_isSaturated;
		
    /** Contains the algo type of thresh sets. This should really be in a database.*/
    std::vector<unsigned int> m_algorithmType;

};
}//end of LVL1 namespace defn

#endif
