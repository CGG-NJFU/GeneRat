/*
 * CSample.cpp
 *
 *  Created on: 2012-12-10
 *      Author: yiqingxu
 */

#include "CSample.h"

namespace generat {

	template <typename geneType, typename expType>
	CSample<geneType, expType>::CSample() {
		vsGeneNames = NULL;
	}

	template <typename geneType, typename expType>
	CSample<geneType, expType>::~CSample() {
	}

	template <typename geneType, typename expType>
	const string& CSample<geneType, expType>::getName() const {
		return sName;
	}


	template <typename geneType, typename expType>
	const size_t CSample<geneType, expType>::size() const {
		//TODO verify and return
		return 0;
	}

	template <typename geneType, typename expType>
	const bool CSample<geneType, expType>::verifySize() const {
		//TODO verify and return
		return true;
	}

	template <typename geneType, typename expType>
	void CSample<geneType, expType>::setName(const string& sName_) {
		sName = sName_;
	}

	template <typename geneType, typename expType>
	void CSample<geneType, expType>::setExpressValue(const vector<expType>& vtExpressValue_) {
		this->vtExpressValue = vtExpressValue_;
	}

	template <typename geneType, typename expType>
	const vector<expType>& CSample<geneType, expType>::getExpressValues() const {
		return vtExpressValue;
	}

	template <typename geneType, typename expType>
	const expType& CSample<geneType, expType>::getExpressValueAt(int index) const {
		return vtExpressValue.at(index);
	}

	template <typename geneType, typename expType>
	void CSample<geneType, expType>::setGeneValue(const vector<geneType>& vtGeneValue_) {
		this->vtGeneValue = vtGeneValue_;
	}


	template <typename geneType, typename expType>
	const vector<geneType>& CSample<geneType, expType>::getGeneValues() const {
		return vtGeneValue;
	}


	template <typename geneType, typename expType>
	const geneType& CSample<geneType, expType>::getGeneValueAt(int index) const {
		return vtGeneValue.at(index);
	}

} /* namespace generat */

