/*
 * logger.cpp
 *
 *  Created on: 2013-5-16
 *      Author: yiqingxu
 */

#include "CLogger.h"

Category& logger = log4cpp::Category::getInstance("rootCategory");

/**
 * 初始化日志系统
 * @return 返回是否初始化成功
 */
bool initLoggers() {
	try {
		PropertyConfigurator::configure("config/log4cpp.properties");
	} catch (ConfigureFailure& f) {
		cerr << "log4cpp configuration failed:" <<endl
				<< f.what() <<endl;
		return false;
	}

	logger << Priority::DEBUG <<"log4cpp is ready";
	return true;
}

/**
 * 关闭日志系统
 */
void haltLoggers() {
	logger <<Priority::DEBUG <<"log4cpp is shutting down";
	Category::shutdown();
}
