/*
 * CSampleSet.cpp
 *
 *  Created on: 2012-12-10
 *      Author: yiqingxu
 */

#include "CSampleSet.h"

namespace generat {

	template <typename geneType, typename expType>
	CSampleSet<geneType, expType>::CSampleSet(const string& name_, CGeneMap& geneMap_)
		:oGeneMap(geneMap_) {
		this->sName = name_;
		this->iSampleGeneNumber = geneMap_.size();
	}

	template <typename geneType, typename expType>
	CSampleSet<geneType, expType>::~CSampleSet() {
	}

	template <typename geneType, typename expType>
	const string& CSampleSet<geneType, expType>::getName() const {
		return sName;
	}

	template <typename geneType, typename expType>
	const size_t CSampleSet<geneType, expType>::size() const {
		return voSamples.size();
	}

	template <typename geneType, typename expType>
	const bool CSampleSet<geneType, expType>::verifyGeneSize() const {
		if ( voSamples.size() != 0 && voSamples[0].size() != iSampleGeneNumber ) {
			throw new CGeneException("Sample[0] size error");
			return false;
		}
		if ( oGeneMap.size() != iSampleGeneNumber ) {
			throw new CGeneException("Gene Name size error");
			return false;
		}
		return true;
	}

	template <typename geneType, typename expType>
	void CSampleSet<geneType, expType>::setName(const string& name_) {
		sName = name_;
	}

	template <typename geneType, typename expType>
	const size_t CSampleSet<geneType, expType>::getSampleGeneNumber() const {
		if ( verifyGeneSize() ) return this->iSampleGeneNumber;
		else return -1;
	}

	template <typename geneType, typename expType>
	const vector<CSample<geneType, expType> >& CSampleSet<geneType, expType>::getSamples() const {
		return voSamples;
	}

	template <typename geneType, typename expType>
	const CSample<geneType, expType>& CSampleSet<geneType, expType>::getSampleAt(int index) const {
		return voSamples.at(index);
	}

	template <typename geneType, typename expType>
	CSample<geneType, expType> CSampleSet<geneType, expType>::operator [](size_t index) const {
		return voSamples[index];
	}

	template <typename geneType, typename expType>
	const CGeneMap& CSampleSet<geneType, expType>::getGeneMap() const {
		return this->oGeneMap;
	}

	template <typename geneType, typename expType>
	const string CSampleSet<geneType, expType>::toString() const {
		string re = "SampleSet(";
		re += uToString(this->sName) + "): ";
		re += uToString(this->size()) + " sample(s) with ";
		re += uToString(this->getSampleGeneNumber()) + " gene(s) each";
		return re;
	}
} /* namespace generat */
