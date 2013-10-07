//============================================================================
// Name        : GeneRat.cpp
// Author      : Yiqing Xu
// Version     :
// Copyright   : Ethan @2013
// Description : Gene Rat in C++, Ansi-style
//============================================================================

#include <iostream>
#include "GeneRat.h"

#include "testers/testers.h"

typedef int (*MainFunc)();
int runMain(MainFunc, bool=true);

int gr_main() {
	//EmptySampleSetTester(8, 0.01);
	GeneMapReader("data/traitInterval.txt");
	return 0;
}

int main() {
	return runMain(gr_main);
}

/**
 * 运行简单参数的主函数
 * @param func 简单参数的主函数，无参数，返回整型
 * @param ifUseLog 是否使用日志
 * @return 返回主函数的返回值
 */
int runMain(MainFunc func, bool ifUseLog) {
	if ( !ifUseLog ) return func();

	int re=0;
	bool ifLogOK = initLoggers();

	if ( ifLogOK ) {
		re = func();
	} else {
		cerr <<"LOG SYSTEM MALFUNCTION DETECTED" <<endl;
		cerr <<"Make sure log4cpp is deployed as a dependency." <<endl;
	}

	haltLoggers();
	return re;
}


