#ifndef H_DATA
#define H_DATA
/*===============================================================
 *                  DataContainer.h
 *                 数据容器抽象模版类 定义
 ===============================================================*/

template <typename DataClass,unsigned int Max>

class DataContainer
{
public:
	void Init();				// 初始化
protected:
	DataClass data[Max];		// 数据
};

#endif
