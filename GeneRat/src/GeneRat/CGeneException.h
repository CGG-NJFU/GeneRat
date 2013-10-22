/*
 * CGeneException.h
 *
 *  Created on: 2012-12-10
 *      Author: yiqingxu
 */

#ifndef CLASS_GENEEXCEPTION_H_
#define CLASS_GENEEXCEPTION_H_

#include <string>

using namespace std;

namespace generat {

typedef enum  {
	EXCEPTION_NONE = 0,
	EXCEPTION_NORMAL = 1,
	EXCEPTION_VITAL = 2
} ExceptionClass;

const string EXCEPTION_CLASS_NAME[] = {
		"NONE",
		"NORMAL",
		"VITAL"
};

/**
 * GR异常类
 */
class CGeneException {
	public:
		/**
		 * 根据给定信息构造异常
		 * @param info 异常信息
		 * @param exceptionClass 异常等级
		 */
		CGeneException(const string info, int iExceptionClass=EXCEPTION_NORMAL);
		/**
		 * 析构异常
		 */
		virtual ~CGeneException();
		/**
		 * 获取异常信息
		 * @return 异常信息
		 */
		const string getInfo();
		/**
		 * 获取异常等级
		 * @return 异常等级
		 */
		int getExceptionClass();
		/**
		 * 获取异常等级的名称
		 * @return 异常等级名称
		 */
		const string getExceptionClassName();
	private:
		/**
		 * 异常信息
		 */
		string sInfo;
		/**
		 * 异常等级
		 */
		int iExceptionClass;
	};
} /* namespace generat */
#endif /* GENEEXCEPTION_H_ */
