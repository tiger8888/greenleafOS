#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
/*===============================================================
 *                    CircularQueue.h                                 
 *                    环形队列类模版定义
 ===============================================================*/
#include "Type.h"
#include "DataContainer.h"

template <typename DataClass,unsigned int Max>
class CircularQueue
{
public:
	void Init();						// 初始化
	Result GetItem(DataClass *Item);	// 读取
	Result SetItem(DataClass *Item);	// 写入
private:
	DataClass data[Max];				// 数据

	unsigned int head;					// 头指针
	unsigned int tail;					// 尾指针
};

/************************************************************************/
/*                      初始化函数										*/
/*                         Init                                         */
/************************************************************************/
template <typename DataClass,unsigned int Max>
void CircularQueue<DataClass,Max>::Init()
{
	head = 0;
	tail = 0;
}
/************************************************************************/
/*					       读取项											*/
/*                        GetItem                                       */
/************************************************************************/
template <typename DataClass,unsigned int Max>
Result CircularQueue<DataClass,Max>::GetItem(DataClass *Item)
{
	// 检测空间是否为空
	if (head == tail) return E_MAX;
	// 如果头指针加1等于上限，则把头指针置为0
	head = (head + 1) % Max;
	DataClass *base = &CircularQueue<DataClass,Max>::data[0];
	*Item = *(base + head);			// 读取

	return S_OK;
}
/************************************************************************/
/*					       写入项											*/
/*                        SetItem                                       */
/************************************************************************/
template <typename DataClass,unsigned int Max>
Result CircularQueue<DataClass,Max>::SetItem(DataClass *Item)
{
	// 检测空间是否已满
	if ((tail+1)%Max == head) return E_MAX;
	// 如果尾指针加1等于上限，则把尾指针置为0，这个实现比我的高明很多啊。
	tail = (tail + 1) % Max;		//(++tail == Max) ? 0 : tail;
	DataClass *base = &CircularQueue<DataClass,Max>::data[0];
	*(base + tail) = *Item;			// 写入

	return S_OK;
}

#endif
