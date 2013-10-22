/*
 * DebugMarco.h
 *
 *  Created on: 2013-10-22
 *      Author: yiqingxu
 */

#ifndef DEBUGMACRO_H_
#define DEBUGMACRO_H_

#define DEBUG_INFO_LEVEL INFO
#define DEBUG_POINT_HERE() logger \
	<<Priority::DEBUG_INFO_LEVEL <<__FILE__<< ":"<<__LINE__ \
	<<"->"<< __FUNCTION__ <<"()";

#endif /* DEBUGMARCO_H_ */
