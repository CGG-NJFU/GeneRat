/*
 * SampleSetTester.cpp
 *
 *  Created on: 2013-10-6
 *      Author: yiqingxu
 */

#include "Testers.h"
#include "math.h"

void EmptySampleSetTester(int iSize_, double dInterval_) {
	try {
		CGeneMap* gm = new CGeneMap("TestGeneMap");
		for (int j=0; j<3; j++) {
			vector<double>* vd = new vector<double>(iSize_-1, dInterval_);
			vector<string>* vs = new vector<string>();
			for (int i=0; i<iSize_;i++) {
				vs->push_back("a"+uToString(i+1));
			}
			gm->addChromosome(j, *vd, *vs);
		}

		logger <<Priority::DEBUG <<gm->toString();

		logger <<Priority::DEBUG <<gm->removeChromosome(0) <<" removed";
		logger <<Priority::DEBUG <<gm->toString();

		CSampleSet<char, double>* ss = new CSampleSet<char, double>("TestSampleSet", *gm);
		logger <<Priority::DEBUG <<ss->toString();
	} catch (CGeneException* ge) {
		logger <<Priority::WARN <<"["<<ge->getExceptionClass() <<"]" <<ge->getInfo();
	}
}

void GeneMapReader(string fileName) {
	try {
		CGeneMap* gm = new CGeneMap("TestGeneMap");
		logger <<Priority::DEBUG <<gm->toString();

		vector<double>* vd = new vector<double>();
		int realsize = readFile2Vector(fileName, *vd);

		vector<string>* vs = new vector<string>();
		for (int i=0; i<realsize+1;i++) {
			vs->push_back("Ch1-Lo"+uToString(i+1));
		}
		gm->addChromosome(1, *vd, *vs);

		logger <<Priority::DEBUG <<gm->toString();
	} catch (CGeneException* ge) {
		logger <<Priority::WARN <<"["<<ge->getExceptionClass() <<"]" <<ge->getInfo();
	}
}
