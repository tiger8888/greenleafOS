#ifndef BMPDATA_H
#define BMPDATA_H

#include "Type.h"
#include "Atomic.h"

template <typename DataClass,unsigned int Max>
class BmpData
{
public:
	Result Add(int &ID,DataClass Item);
	void Delete(int ID);
	Result Set(int ID,DataClass Item);
	Result Get(int ID,DataClass &Item);

	Result Get(int ID,DataClass *Item);
protected:
	Atomic bmp[sizeof(DataClass)/32];	// 位图
	DataClass data[Max];				// 数据
};
/*************************************************************/
/*******************实现部分***********************************/
/************************************************************/
template <typename DataClass,unsigned int Max>
Result BmpData<DataClass,Max>::Add(int &ID,DataClass Item)
{
	for(int i=0;i<Max/32;i++)
	{
		Atomic data = bmp[i];
		if (!(data.value)) continue;
		for(int j=0;j<32;j++)
		{
			if(data.TestBit(j))
			{
				ID = (i*32)+j;
				goto add;
			}
		}
	}
	return E_MAX;
add:
	Set(ID,Item);

	return S_OK;
}

template <typename DataClass,unsigned int Max>
void BmpData<DataClass,Max>::Delete(int ID)
{
	bmp[ID/32].ClearBit(ID%32);
	return;
}

template <typename DataClass,unsigned int Max>
Result BmpData<DataClass,Max>::Get(int ID,DataClass &Item)
{
	if(bmp[ID/32].TestBit(ID%32))
		Item = this->data[ID];
	else return E_NOITEM;
	return S_OK;
}

template <typename DataClass,unsigned int Max>
Result BmpData<DataClass,Max>::Set(int ID,DataClass Item)
{
	if(bmp[ID/32].TestBit(ID%32))
		this->data[ID] = Item;
	else return E_NOITEM;
	return S_OK;
}

template <typename DataClass,unsigned int Max>
Result BmpData<DataClass,Max>::Get(int ID,DataClass *Item)
{
	if(bmp[ID/32].TestBit(ID%32))
		Item = &(this->data[ID]);
	else return E_NOITEM;
	return S_OK;
}
#endif
