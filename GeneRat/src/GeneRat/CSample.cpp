/*
 * CSample.cpp
 *
 *  Created on: 2012-12-10
 *      Author: yiqingxu
 */

#include "CSample.h"

namespace generat {

	template <typename geneType, typename expType>
	CSample<geneType, expType>::CSample(string name_, CGeneMap& geneMap_)
		:oGeneMap(geneMap_) {
		this->sName = name_;
		this->vtGeneValue = *(new vector<geneType>(geneMap_.size()));
	}

	template <typename geneType, typename expType>
	CSample<geneType, expType>::CSample(const CSample& copy)
		:oGeneMap(copy.oGeneMap){
		this->sName = copy.sName;
		this->vtGeneValue = *(new vector<geneType>(copy.size()));
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
		if ( verifySize() ) {
			return this->vtGeneValue.size();
		}
		return -1;
	}

	template <typename geneType, typename expType>
	const bool CSample<geneType, expType>::verifySize() const {
		if ( this->oGeneMap.size() != this->vtGeneValue.size() ) {
			throw new CGeneException("Sample size error");
			return false;
		}
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

	template <typename geneType, typename expType>
	const string CSample<geneType, expType>::toString() const {
		string re = "Sample ";
		re += sName + " = ";
		re += uToString(this->size()) + " gene(s) + ";
		re += uToString(this->vtExpressValue.size()) + " express data :";
		for (size_t i=0; i<this->size(); i++) {
			re += "\n" + this->oGeneMap.getGeneNameAt(i) + " : " +this->vtGeneValue[i];
		}
		return re;
	}

	template <typename geneType, typename expType>
	CSample<geneType, expType>& CSample<geneType, expType>::operator = (const CSample<geneType, expType>& copy) {
		if (this==&copy) return *this;
		this->sName = copy.sName;
		this->oGeneMap = copy.oGeneMap;
		this->setGeneValue(copy.vtGeneValue);
		return *this;
	}
} /* namespace generat */

