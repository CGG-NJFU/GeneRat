/*
 * SampleSetTester.cpp
 *
 *  Created on: 2013-10-6
 *      Author: yiqingxu
 */

#include "testers.h"
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

		logger <<Priority::INFO <<gm->toString();

		logger <<Priority::INFO <<gm->removeChromosome(0) <<" removed";
		logger <<Priority::INFO <<gm->toString();

		CSampleSet<char, double>* ss = new CSampleSet<char, double>("TestSampleSet", *gm);
		logger <<Priority::INFO <<ss->toString();
	} catch (CGeneException* ge) {
		logger <<Priority::WARN <<"["<<ge->getExceptionClass() <<"]" <<ge->getInfo();
	}
}

void GeneMapReader(string fileName) {
	try {
		///创建空基因图谱
		CGeneMap* gm = new CGeneMap("TestGeneMap");
		logger <<Priority::INFO <<gm->toString();

		///从文件导入基因图谱信息
		vector<double>* vd = new vector<double>();
		int realsize = readFile2Vector(fileName, *vd);

		vector<string>* vs = new vector<string>();
		for (int i=0; i<realsize+1;i++) {
			vs->push_back("Ch1-Lo"+uToString(i+1));
		}
		gm->addChromosome(1, *vd, *vs);

		logger <<Priority::INFO <<gm->toString();

		///创建父本信息
		CSample<string, double>* f = new CSample<string, double>("P-F", *gm);
		vector<string>* vsf = new vector<string>(realsize+1, "ab");
		f->setGeneValue(*vsf);
		logger <<Priority::INFO <<f->toString();

		///创建母本信息
		CSample<string, double>* m = new CSample<string, double>("P-M", *gm);
		vector<string>* vsm = new vector<string>(realsize+1, "ab");
		m->setGeneValue(*vsm);
		logger <<Priority::INFO <<m->toString();

		///读取子代信息
		vector<vector<string> > data;
		data = vector<vector<string> >(realsize+1, vector<string>(189, "  "));
		string newData = "data/geneChildFull.txt";
		readFile2Matrix(newData, data);

		///初始化样本集
		CSampleSet<string, double>* ss = new CSampleSet<string, double>("TestSampleSet", *gm);
		vector<string>* nameList = new vector<string>();
		for (int i=0; i<189; i++) {
			nameList->push_back("Sample"+uToString(i+1));
		}
		ss->initFromMatrix(data, *nameList);
		logger <<Priority::INFO <<ss->toString();

		delete ss;
		delete gm;

		logger <<Priority::DEBUG <<"Data init done";
	} catch (CGeneException* ge) {
		logger <<Priority::WARN <<"["<<ge->getExceptionClass() <<"]" <<ge->getInfo();
	}
}
