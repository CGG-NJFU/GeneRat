/*
 * IMQTLLogger.h
 *
 *  Created on: 2013-5-16
 *      Author: yiqingxu
 */

#ifndef CLASS_LOGGER_H_
#define CLASS_LOGGER_H_

// using log4cpp
#include <log4cpp/Category.hh>
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Layout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PropertyConfigurator.hh>

using namespace std;
using namespace log4cpp;

extern Category& logger;
bool initLoggers();
void haltLoggers();

#endif /* C_LOGGER_H_ */
