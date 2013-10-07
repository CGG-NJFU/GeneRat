/*
 * CGeneMap.h
 *
 *  Created on: 2013-9-29
 *      Author: yiqingxu
 */

#ifndef CLASS_GENEMAP_H_
#define CLASS_GENEMAP_H_

#include <vector>
#include <string>
#include <iostream>

#include "CGeneException.h"
#include "../utils/GRUtils.h"

using namespace std;

namespace generat {

class CGeneMap {
	private:
		/**
		 * 基因图谱的名称
		 */
		string sMapName;
		/**
		 * 基因图谱中对应基因的染色体编号
		 */
		vector<int> viGeneChromosome;
		/**
		 * 基因谱图中对应基因的位置，单位：厘摩
		 */
		vector<double> vdGenePositions;
		/**
		 * 基因图谱中对应基因的名称
		 */
		vector<string> vsGeneNames;

		/**
		 * 验证基因图谱的位点数
		 * @return 位点数是否一致
		 */
		const bool verifySize() const;
	public:
		CGeneMap(string sMapName_);
		~CGeneMap();
		/**
		 * 获取基因图谱的位点个数
		 * @return 位点个数，返回-1表示图谱数据不一致
		 */
		const size_t size() const;
		/**
		 * 添加染色体信息
		 * @param iChromosomeIndex_ 染色体编号
		 * @param vdGeneInterval_ 基因位点间隔数据，单位：厘摩
		 * @param vsGeneNames_ 基因位点名称数据
		 * @return 该染色体中基因位点数量
		 */
		const size_t addChromosome(int iChromosomeIndex_, vector<double> vdGeneInterval_, vector<string> vsGeneNames_);
		/**
		 * 获取基因图谱的字符串描述
		 * @return 字符串描述
		 */
		const string toString() const;
		/**
		 * 删除特定编号的染色体
		 * @param iChromosomeIndex_ 染色体编号
		 * @return 删除的位点个数
		 */
		const size_t removeChromosome(int iChromosomeIndex_);

		//TODO todolist
};

} /* namespace generat */
#endif /* CGENEMAP_H_ */
