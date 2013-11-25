/*
 * CQTLLocator.h
 *
 *  Created on: 2013-11-19
 *      Author: yiqingxu
 */

#ifndef CLASS_QTL_LOCATOR_H_
#define CLASS_QTL_LOCATOR_H_

#include "CLocator.cpp"

namespace generat {

	template <typename geneType, typename expType>
	class CQTLLocator: public CLocator<geneType, expType> {
	public:
		CQTLLocator(CSampleSet<geneType, expType>& oSampleSet_);
		virtual ~CQTLLocator();

		bool locate();
		LOD getLOD();
	};

} /* namespace generat */
#endif /* CQTLLOCATOR_H_ */
