/*
 * CLocator.h
 *
 *  Created on: 2013-11-19
 *      Author: yiqingxu
 */

#ifndef CLASS_LOCATOR_H_
#define CLASS_LOCATOR_H_

#include "CSampleSet.h"

typedef double LOD;

namespace generat {

	template <typename geneType, typename expType>
	class CLocator {

	public:
		const CSampleSet<geneType, expType>& oSampleSet;

		CLocator(CSampleSet<geneType, expType>& oSampleSet_);
		virtual ~CLocator();

		virtual bool locate()=0;
		virtual LOD getLOD()=0;
	};
} /* namespace generat */
#endif /* CLOCATOR_H_ */
