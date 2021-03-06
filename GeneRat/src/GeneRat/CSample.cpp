/*
 * CSample.cpp
 *
 *  Created on: 2012-12-10
 *      Author: yiqingxu
 */

#include "CSample.h"

namespace generat {

	template <typename geneType, typename expType>
	CSample<geneType, expType>::CSample(const string name_, CGeneMap& geneMap_, vector<string>& nameList_)
		:oGeneMap(geneMap_), vsExpressNames(nameList_) {
		this->sName = name_;
		this->vtGeneValue = *(new vector<geneType>(geneMap_.size()));
		logger <<Priority::DEBUG <<"Sample(" <<this->sName <<") is constructed.";
	}

	template <typename geneType, typename expType>
	CSample<geneType, expType>::CSample(const CSample& copy)
		:oGeneMap(copy.oGeneMap), vsExpressNames(copy.vsExpressNames){
		this->sName = copy.sName;
		this->vtGeneValue = *(new vector<geneType>(copy.size()));
		logger <<Priority::DEBUG <<"Sample(" <<this->sName <<") is copied.";
	}

	template <typename geneType, typename expType>
	CSample<geneType, expType>::~CSample() {
		logger <<Priority::DEBUG <<"Sample(" <<this->sName <<") is destructed.";
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
	const expType& CSample<geneType, expType>::getExpressValueAt(const size_t index) const {
		if ( index > vtExpressValue.size() ) throw new CGeneException("Index out of express data size");
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
	const geneType& CSample<geneType, expType>::getGeneValueAt(const size_t index) const {
		if ( index > vtGeneValue.size() ) throw new CGeneException("Index out of gene data size");
		return vtGeneValue.at(index);
	}

	template <typename geneType, typename expType>
	const string CSample<geneType, expType>::toString() const {
		string re = "Sample ";
		re += sName + " = ";
		re += uToString(this->size()) + " gene(s) + ";
		re += uToString(this->vtExpressValue.size()) + " express data :";
		for (size_t i=0; i<this->size(); i++) {
			re += "\n" + this->oGeneMap.getGeneNameAt(i) + " : " +uToString(this->vtGeneValue[i]);
		}
		for (size_t i=0; i<this->vtExpressValue.size(); i++) {
			re += "\nexp" + uToString(i+1) + "("+ this->vsExpressNames[i] +"): "+uToString(this->vtExpressValue[i]);
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

