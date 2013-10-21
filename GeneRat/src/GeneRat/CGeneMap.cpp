/*
 * CGeneMap.cpp
 *
 *  Created on: 2013-9-29
 *      Author: yiqingxu
 */

#include "CGeneMap.h"

namespace generat {

	CGeneMap::CGeneMap(string sMapName_) {
		this->sMapName = sMapName_;
		logger <<Priority::DEBUG <<"GeneMap(" <<this->sMapName <<") is constructed.";
	}

	CGeneMap::~CGeneMap() {
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

	const size_t CGeneMap::addChromosome(int iChromosomeIndex_, vector<double> vdGeneInterval_, vector<string> vsGeneNames_) {
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

	const size_t CGeneMap::removeChromosome(int iChromosomeIndex_) {
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

	const string CGeneMap::getGeneNameAt(size_t index) const {
		return this->vsGeneNames[index];
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
