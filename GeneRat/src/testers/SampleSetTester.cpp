/*
 * SampleSetTester.cpp
 *
 *  Created on: 2013-10-6
 *      Author: yiqingxu
 */

#include "testers.h"
#include "math.h"

void emptySampleSetTester(int iSize_, double dInterval_) {
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

		delete ss;
		delete gm;
	} catch (CGeneException* ge) {
		logger <<Priority::WARN <<"["<<ge->getExceptionClassName() <<"]" <<ge->getInfo();
	}
}

void geneMapReader() {
	try {

		///创建空基因图谱
		CGeneMap* gm = new CGeneMap("TestGeneMap");

		///从文件导入基因图谱信息
		vector<double>* vd = new vector<double>();
		int geneNumber = readFile2Vector("data/traitInterval.txt", *vd) + 1;

		gm->initFromIntervalData(*vd, 1);
		logger <<Priority::INFO <<gm->toString();

		int sampleSize = 189;
		///读取子代基因型信息，并初始化样本集
		CSampleSet<string, double>* ss = new CSampleSet<string, double>("TestSampleSet", *gm);

		vector<vector<string> > geneData = vector<vector<string> >(geneNumber, vector<string>(sampleSize, "  "));
		readFile2Matrix("data/geneChildFull.txt", geneData);

		vector<string>* geneNameList = new vector<string>();
		for (int i=0; i<sampleSize; i++) {
			geneNameList->push_back("Sample"+uToString(i+1));
		}
		ss->initGeneDataFromMatrix(geneData, *geneNameList);

		///读取子代表现型信息，并初始化样本集
		vector<vector<double> > expData = vector<vector<double> >(1, vector<double>(sampleSize, 0));
		readFile2Matrix("data/expressData.txt", expData);

		vector<string>* expNameList = new vector<string>(1, "expData");
		ss->initExpDataFromMatrix(expData, *expNameList);
		logger <<Priority::INFO <<ss->toString();

		///随机抽查数据是否正确
		srand (time(NULL));
		logger <<Priority::INFO <<(*ss)[rand()%sampleSize].toString();

		///创建父本信息
		CSample<string, double>* f = new CSample<string, double>("P-F", *gm, *expNameList );
		vector<string>* vsf = new vector<string>();
		readFile2Vector("data/geneParentF.txt", *vsf);
		f->setGeneValue(*vsf);
		logger <<Priority::INFO <<f->toString();

		///创建母本信息
		CSample<string, double>* m = new CSample<string, double>("P-M", *gm, *expNameList );
		vector<string>* vsm = new vector<string>();
		readFile2Vector("data/geneParentM.txt", *vsm);
		m->setGeneValue(*vsm);
		logger <<Priority::INFO <<m->toString();

		///析构退出
		delete ss;
		delete gm;

		logger <<Priority::DEBUG <<"Data init done";
	} catch (CGeneException* ge) {
		logger <<Priority::WARN <<"["<<ge->getExceptionClass() <<"]" <<ge->getInfo();
	}
}

void basicTest() {
	try {
		throw new CGeneException("CGeneException Test Here", EXCEPTION_VITAL);
	} catch (CGeneException* ge) {
		DEBUG_POINT_HERE();
		logger <<Priority::WARN <<"["<<ge->getExceptionClassName() <<"]" <<ge->getInfo();
	}
}

void testMore() {
	int iSize_ = 5;
	double dInterval_ =0.1;

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

	CQTLLocator<char, double>* ql = new CQTLLocator<char, double>(*ss);
	logger <<Priority::INFO <<"here" <<ql->locate();
}

void QTLTestRun() {
	try {
//		testMore();
//		return;

		///创建空基因图谱
		CGeneMap* gm = new CGeneMap("TestGeneMap");

		///从文件导入基因图谱信息
		vector<double>* vd = new vector<double>();
		int geneNumber = readFile2Vector("data/traitInterval.txt", *vd) + 1;

		gm->initFromIntervalData(*vd, 1);
		logger <<Priority::INFO <<gm->toString();

		int sampleSize = 189;
		///读取子代基因型信息，并初始化样本集
		CSampleSet<string, double>* ss = new CSampleSet<string, double>("TestSampleSet", *gm);

		vector<vector<string> > geneData = vector<vector<string> >(geneNumber, vector<string>(sampleSize, "  "));
		readFile2Matrix("data/geneChildFull.txt", geneData);

		vector<string>* geneNameList = new vector<string>();
		for (int i=0; i<sampleSize; i++) {
			geneNameList->push_back("Sample"+uToString(i+1));
		}
		ss->initGeneDataFromMatrix(geneData, *geneNameList);

		///读取子代表现型信息，并初始化样本集
		vector<vector<double> > expData = vector<vector<double> >(1, vector<double>(sampleSize, 0));
		readFile2Matrix("data/expressData.txt", expData);

		vector<string>* expNameList = new vector<string>(1, "expData");
		ss->initExpDataFromMatrix(expData, *expNameList);
		logger <<Priority::INFO <<ss->toString();

		///随机抽查数据是否正确
		srand (time(NULL));
		logger <<Priority::INFO <<(*ss)[rand()%sampleSize].toString();

		///创建父本信息
		CSample<string, double>* f = new CSample<string, double>("P-F", *gm, *expNameList );
		vector<string>* vsf = new vector<string>();
		readFile2Vector("data/geneParentF.txt", *vsf);
		f->setGeneValue(*vsf);
		logger <<Priority::INFO <<f->toString();

		///创建母本信息
		CSample<string, double>* m = new CSample<string, double>("P-M", *gm, *expNameList );
		vector<string>* vsm = new vector<string>();
		readFile2Vector("data/geneParentM.txt", *vsm);
		m->setGeneValue(*vsm);
		logger <<Priority::INFO <<m->toString();

		CQTLLocator<string, double>* ql = new CQTLLocator<string, double>(*ss);
		logger <<Priority::INFO <<"here" <<ql->locate();
		logger <<Priority::INFO <<"here" <<ql->getLOD();

		///析构退出
		delete ss;
		delete gm;

		logger <<Priority::DEBUG <<"Data init done";
	} catch (CGeneException* ge) {
		logger <<Priority::WARN <<"["<<ge->getExceptionClass() <<"]" <<ge->getInfo();
	}
}
