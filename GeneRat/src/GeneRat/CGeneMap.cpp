/*
 * CGeneMap.cpp
 *
 *  Created on: 2013-9-29
 *      Author: yiqingxu
 */

#include "CGeneMap.h"

namespace generat {

	CGeneMap::CGeneMap(const string sMapName_) {
		this->sMapName = sMapName_;
		logger <<Priority::DEBUG <<"GeneMap(" <<this->sMapName <<") is constructed.";
	}

	CGeneMap::~CGeneMap() {
		this->vdGenePositions.clear();
		this->viGeneChromosome.clear();
		this->vsGeneNames.clear();
		logger <<Priority::DEBUG <<"GeneMap(" <<this->sMapName <<") is destructed.";
	}

	const size_t CGeneMap::size() const {
		if ( verifySize() ) return this->vsGeneNames.size();
		else return -1;
	}

	const bool CGeneMap::verifySize() const {
		if ( this->vdGenePositions.size() == this->vsGeneNames.size() &&
			this->viGeneChromosome.size() == this->vsGeneNames.size() ) {
			return true;
		} else {
			throw new CGeneException("GeneMap size error");
			return false;
		}
	}

	const size_t CGeneMap::addChromosome(const int iChromosomeIndex_, vector<double> vdGeneInterval_, vector<string> vsGeneNames_) {
		if ( vsGeneNames_.size() - vdGeneInterval_.size() != 1 ) {
			throw new CGeneException("Chromosome Info error, check interval and name data");
		}
		size_t oldSize = size();

		double currentPosition=0.0;
		for (size_t i=0; i<=vdGeneInterval_.size(); i++) {
			this->viGeneChromosome.push_back(iChromosomeIndex_);
			this->vdGenePositions.push_back(currentPosition);
			currentPosition += vdGeneInterval_[i];
			this->vsGeneNames.push_back(vsGeneNames_[i]);
		}
		return size()-oldSize;
	}

	const size_t CGeneMap::removeChromosome(const int iChromosomeIndex_) {
		size_t oldSize = size();
		for (size_t i=0; i<size(); ) {
			if (this->viGeneChromosome[i] == iChromosomeIndex_ ) {
				this->viGeneChromosome.erase(this->viGeneChromosome.begin()+i);
				this->vdGenePositions.erase(this->vdGenePositions.begin()+i);
				this->vsGeneNames.erase(this->vsGeneNames.begin()+i);
			} else {
				i++;
			}
		}

		return oldSize - size();
	}

	const string CGeneMap::getGeneNameAt(const size_t index) const {
		return this->vsGeneNames[index];
	}

	const int CGeneMap::initFromIntervalData(const vector<double> vdIntervalData_, const int iChromosomeIndex_) {
		int realsize = vdIntervalData_.size()+1;

		vector<string>* vs = new vector<string>();
		for (int i=0; i<realsize;i++) {
			vs->push_back( "Ch"+uToString(iChromosomeIndex_)+"-Lo"+uToString(i+1));
		}
		this->addChromosome(iChromosomeIndex_, vdIntervalData_, *vs);
		return realsize;
	}

	const string CGeneMap::toString() const{
		size_t s = size();
		string re = "GeneMap Data: "+uToString(s)+" locus";
		for (size_t i=0; i<s; i++ ){
			re += "\n("+uToString(this->viGeneChromosome[i])+":"
					+this->vsGeneNames[i]+")\t"
					+uToString(this->vdGenePositions[i]);
		}
		return re;
	}

} /* namespace generat */
