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
		this->vsExpressNames = *(new vector<string>());
		logger <<Priority::DEBUG <<"SampleSet(" <<this->sName <<") is constructed.";
	}

	template <typename geneType, typename expType>
	CSampleSet<geneType, expType>::~CSampleSet() {
		logger <<Priority::DEBUG <<"SampleSet(" <<this->sName <<") is deleting.";
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
	const CSample<geneType, expType>& CSampleSet<geneType, expType>::getSampleAt(const size_t index) const {
		if ( index > voSamples.size() ) throw new CGeneException("Index out of SampleSet size");
		return voSamples.at(index);
	}

	template <typename geneType, typename expType>
	const CSample<geneType, expType>& CSampleSet<geneType, expType>::operator [](const size_t index) const {
		if ( index > voSamples.size() ) throw new CGeneException("Index out of SampleSet size");
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
		re += uToString(this->getSampleGeneNumber()) + " gene data and ";
		re += uToString(this->vsExpressNames.size()) + " express data each";
		return re;
	}

	template <typename geneType, typename expType>
	const vector<string>& CSampleSet<geneType, expType>::getExpressNames() const {
		return this->vsExpressNames;
	}

	template <typename geneType, typename expType>
	void CSampleSet<geneType, expType>::setExpressNames(const vector<string>& vsExpressNames_) {
		this->vsExpressNames = vsExpressNames_;
	}

	template <typename geneType, typename expType>
	const size_t CSampleSet<geneType, expType>::initGeneDataFromMatrix(const vector<vector<geneType> >& data_, const vector<string>& nameList_){
		if ( this->getSampleGeneNumber() != data_.size() ) {
			throw new CGeneException("Sample Data size error in line");
			return -1;
		}
		if ( data_[0].size() != nameList_.size() ) {
			throw new CGeneException("Name List Data size error");
			return -1;
		}

		CSample<string, double>* emptySample = new CSample<geneType, expType>("", this->oGeneMap, this->vsExpressNames);
		this->voSamples = *new vector<CSample<geneType,expType> >(nameList_.size(), *emptySample);

		size_t i=0;
		for (; i<nameList_.size(); i++) {
			this->voSamples[i].setName(nameList_[i]);

			vector<geneType>* vg = new vector<geneType>();
			for (size_t j=0; j<this->getSampleGeneNumber(); j++) {
				vg->push_back(data_[j][i]);
			}
			this->voSamples[i].setGeneValue(*vg);
		}
		return i;
	}

	template <typename geneType, typename expType>
	const size_t CSampleSet<geneType, expType>::initExpDataFromMatrix(const vector<vector<expType> >& data_, const vector<string>& nameList_) {
		if ( nameList_.size() != data_.size() ) {
			throw new CGeneException("Name List Data size error");
			return -1;
		}
		if ( data_[0].size() != this->size() ) {
			throw new CGeneException("Exp Data size error in line");
			return -1;
		}

		this->setExpressNames(nameList_);
		//this->vsExpressNames = *new vector<string>( nameList_.size() );

		size_t i=0;
		for (; i<this->size(); i++) {
			vector<expType>* ve = new vector<expType>();
			for (size_t j=0; j<nameList_.size(); j++) {
				ve->push_back(data_[j][i]);
			}
			this->voSamples[i].setExpressValue(*ve);
		}
		return i;
	}
} /* namespace generat */
