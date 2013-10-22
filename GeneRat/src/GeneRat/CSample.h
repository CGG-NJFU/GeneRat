/*
 * CSample.h
 *
 *  Created on: 2012-12-10
 *      Author: yiqingxu
 */

#ifndef CLASS_SAMPLE_H_
#define CLASS_SAMPLE_H_

#include <vector>
#include <string>
#include "CGeneMap.h"
using namespace std;

namespace generat {

	/**
	 * 样本类，样本包括基因型数据和表现型数据，和一个基因名称的链接
	 */
	template <typename geneType, typename expType>
	class CSample{
		private:
			/**
			 * 样本名称
			 */
			string sName;
			/**
			 * 该样本的基因图谱
			 */
			CGeneMap& oGeneMap;
			/**
			 * 基因型数据
			 */
			vector<geneType> vtGeneValue;
			/**
			 * 表现型数据
			 */
			vector<expType> vtExpressValue;

			const vector<string>& vsExpressNames;

			/**
			 * 验证样本的基因数量与图谱是否一致
			 * @return 若一致返回TRUE，否则为FALSE
			 */
			const bool verifySize() const;
		public:
			CSample(const string name, CGeneMap& geneMap_, vector<string>& nameList_);
			CSample(const CSample& copy);
			~CSample();

			/**
			 * 设置样本名称
			 * @param sName_ 样本名称
			 */
			void setName(const string& name_);
			/**
			 * 获取样本名称
			 * @return 样本名称
			 */
			const string& getName() const;

			/**
			 * 获取样本中的基因数量，该数量应与图谱的规定一致
			 * @return 基因数量
			 */
			const size_t size() const;

			/**
			 * 设置样本的所有基因型
			 * @param vtGeneValue_ 基因型数据向量
			 */
			void setGeneValue(const vector<geneType>& vtGeneValue_);
			/**
			 * 获取样本的所有基因型
			 * @return 基因型数据向量
			 */
			const vector<geneType>& getGeneValues() const;
			/**
			 * 获取样本的某一基因型
			 * @param index 基因序号
			 * @return 表现型数据
			 */
			const geneType& getGeneValueAt(const size_t index) const;

			/**
			 * 设置样本的所有表现型
			 * @param vtExpressValue_ 表现型数据向量
			 */
			void setExpressValue(const vector<expType>& vtExpressValue_);
			/**
			 * 获取样本的所有表现型
			 * @return 表现型数据向量
			 */
			const vector<expType>& getExpressValues() const;
			/**
			 * 获取样本某一基因的表现型
			 * @param index 基因序号
			 * @return 表现型数据
			 */
			const expType& getExpressValueAt(const size_t index) const;

			CSample& operator = (const CSample& oSample);

			const string toString() const;
	};

} /* namespace generat */
#endif /* SAMPLE_H_ */
