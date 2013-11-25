/*
 * CQTLLocator.cpp
 *
 *  Created on: 2013-11-19
 *      Author: yiqingxu
 */

#include "CQTLLocator.h"

namespace generat {

	template <typename geneType, typename expType>
	CQTLLocator<geneType, expType>::CQTLLocator(CSampleSet<geneType, expType>& oSampleSet_)
		:CLocator<geneType, expType>(oSampleSet_) {
	}

	template <typename geneType, typename expType>
	CQTLLocator<geneType, expType>::~CQTLLocator() {
	}

	template <typename geneType, typename expType>
	bool CQTLLocator<geneType, expType>::locate() {
		return true;
	}

	template <typename geneType, typename expType>
	LOD CQTLLocator<geneType, expType>::getLOD() {
		return 0;
	}

} /* namespace generat */
