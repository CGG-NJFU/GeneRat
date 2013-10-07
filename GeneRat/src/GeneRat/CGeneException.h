/*
 * CGeneException.h
 *
 *  Created on: 2012-12-10
 *      Author: yiqingxu
 */

#ifndef CLASS_GENEEXCEPTION_H_
#define CLASS_GENEEXCEPTION_H_

namespace generat {

typedef enum  {
	EXCEPTION_NORMAL = 1,
	EXCEPTION_VITAL = 2
} ExceptionClass;

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
		CGeneException(const char* info, int exceptionClass=EXCEPTION_NORMAL);
		/**
		 * 析构异常
		 */
		virtual ~CGeneException();
		/**
		 * 获取异常信息
		 * @return 异常信息
		 */
		const char* getInfo();
		/**
		 * 获取异常等级
		 * @return 异常等级
		 */
		int getExceptionClass();
//		const char* getExceptionClassName();
	private:
		/**
		 * 异常信息
		 */
		const char* sInfo;
		/**
		 * 异常等级
		 */
		int iExceptionClass;
	};
} /* namespace generat */
#endif /* GENEEXCEPTION_H_ */
