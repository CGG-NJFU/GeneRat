/*
 * CLocator.cpp
 *
 *  Created on: 2013-11-19
 *      Author: yiqingxu
 */

#include "CLocator.h"

namespace generat {
	template <typename geneType, typename expType>
	CLocator<geneType, expType>::CLocator(CSampleSet<geneType, expType>& oSampleSet_)
		:oSampleSet(oSampleSet_) {
	}

	template <typename geneType, typename expType>
	CLocator<geneType, expType>::~CLocator() {
		// TODO Auto-generated destructor stub
	}

} /* namespace generat */
