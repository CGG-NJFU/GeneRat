/*
 * CGeneException.cpp
 *
 *  Created on: 2012-12-10
 *      Author: yiqingxu
 */


#include <iostream>
#include "CGeneException.h"
#include "../utils/GRUtils.h"
using namespace std;

namespace generat {

	CGeneException::CGeneException(const string info, int exceptionClass) {
		this->sInfo = info;
		this->iExceptionClass = exceptionClass;
	}

	CGeneException::~CGeneException() {
	}

	const string CGeneException::getInfo() {
		return this->sInfo;
	}

	int CGeneException::getExceptionClass() {
		return this->iExceptionClass;
	}

	const string CGeneException::getExceptionClassName() {
		return EXCEPTION_CLASS_NAME[this->getExceptionClass()];
	}
} /* namespace generat */
