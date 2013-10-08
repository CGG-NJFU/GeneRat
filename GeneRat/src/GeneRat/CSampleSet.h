/*
 * CSampleSet.h
 *
 *  Created on: 2012-12-10
 *      Author: yiqingxu
 */

#ifndef CLASS_SAMPLESET_H_
#define CLASS_SAMPLESET_H_

#include "CSample.h"
#include "CGeneMap.h"
#include "CGeneException.h"
#include "../utils/GRUtils.h"
#include <vector>
#include <string>

namespace generat {
	/**
	 * 样本集类，样本集是包含多个样本的集合，所有样本共享同一个基因命名池。
	 */
	template <typename geneType, typename expType>
	class CSampleSet {
		private:
			/**
			 * 该样本集的名称
			 */
			string sName;
			/**
			 * 样本集中样本的基因数量
			 */
			size_t iSampleGeneNumber;
			/**
			 * 样本集中样本的对象向量
			 */
			vector<CSample<geneType, expType> > voSamples;
			/**
			 * 样本集中各样本的基因图谱
			 */
			CGeneMap& oGeneMap;

			/**
			 * 验证样本集中样本的基因数量
			 * @return 若一致返回TRUE，否则为FALSE
			 */
			const bool verifyGeneSize() const;
		public:
			/**
			 * 利用给定的基因图谱构造具名的样本集
			 * @param name_ 样本集名称
			 * @param geneMap_ 样本的基因图谱
			 */
			CSampleSet(const string& name_, CGeneMap& geneMap_);
			/**
			 * 析构样本集
			 */
			~CSampleSet();

			/**
			 * 获取样本集的名称
			 * @return 样本集的名称
			 */
			const string& getName() const;
			/**
			 * 设置样本集的名称
			 * @param name_ 样本集的名称
			 */
			void setName(const string& name_);
			/**
			 * 获取样本集中样本的数量
			 * @return 样本的数量
			 */
			const size_t size() const;
			/**
			 * 获取样本集中样本的基因数量
			 * @return 样本的基因数量，-1表示出错
			 */
			const size_t getSampleGeneNumber() const;
			/**
			 * 获取所有样本
			 * @return 样本向量
			 */
			const vector<CSample<geneType, expType> >& getSamples() const;
			/**
			 * 获取给定序号的样本
			 * @param index 样本序号
			 * @return 给定序号的样本
			 */
			const CSample<geneType, expType>& getSampleAt(const int index) const;
			/**
			 * 获取给定下标的样本
			 * @param index 样本下标
			 * @return 给定下标的样本
			 */
			CSample<geneType, expType> operator [](const size_t index) const;
			/**
			 * 获取所有基因的名称
			 * @return 所有基因的名称
			 */
			const CGeneMap& getGeneMap() const;
			/**
			 * 获取样本集的字符串描述
			 * @return 字符串描述
			 */
			const string toString() const;

			const size_t initFromMatrix(const vector<vector<geneType> >& data, const vector<string>& nameList_);
			//TODO todolist
	};

} /* namespace generat */
#endif /* SAMPLESET_H_ */
