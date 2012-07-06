#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
/*===============================================================
 *                    CircularQueue.h                                 
 *                    ���ζ�����ģ�涨��
 ===============================================================*/
#include "Type.h"
#include "DataContainer.h"

template <typename DataClass,unsigned int Max>
class CircularQueue
{
public:
	void Init();						// ��ʼ��
	Result GetItem(DataClass *Item);	// ��ȡ
	Result SetItem(DataClass *Item);	// д��
private:
	DataClass data[Max];				// ����

	unsigned int head;					// ͷָ��
	unsigned int tail;					// βָ��
};

/************************************************************************/
/*                      ��ʼ������										*/
/*                         Init                                         */
/************************************************************************/
template <typename DataClass,unsigned int Max>
void CircularQueue<DataClass,Max>::Init()
{
	head = 0;
	tail = 0;
}
/************************************************************************/
/*					       ��ȡ��											*/
/*                        GetItem                                       */
/************************************************************************/
template <typename DataClass,unsigned int Max>
Result CircularQueue<DataClass,Max>::GetItem(DataClass *Item)
{
	// ���ռ��Ƿ�Ϊ��
	if (head == tail) return E_MAX;
	// ���ͷָ���1�������ޣ����ͷָ����Ϊ0
	head = (head + 1) % Max;
	DataClass *base = &CircularQueue<DataClass,Max>::data[0];
	*Item = *(base + head);			// ��ȡ

	return S_OK;
}
/************************************************************************/
/*					       д����											*/
/*                        SetItem                                       */
/************************************************************************/
template <typename DataClass,unsigned int Max>
Result CircularQueue<DataClass,Max>::SetItem(DataClass *Item)
{
	// ���ռ��Ƿ�����
	if ((tail+1)%Max == head) return E_MAX;
	// ���βָ���1�������ޣ����βָ����Ϊ0�����ʵ�ֱ��ҵĸ����ܶడ��
	tail = (tail + 1) % Max;		//(++tail == Max) ? 0 : tail;
	DataClass *base = &CircularQueue<DataClass,Max>::data[0];
	*(base + tail) = *Item;			// д��

	return S_OK;
}

#endif
