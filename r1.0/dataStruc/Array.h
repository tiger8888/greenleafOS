#ifndef ARRAY_H_
#define ARRAY_H_

#include "Type.h"

template<typename DataClass,unsigned int Max>
class Array
{
public:
	inline Result Add(int &ID,DataClass Item);
	inline Result Get(int ID,DataClass *Item);
	inline Result Get(int ID,DataClass &Item);
	inline Result Set(int ID,DataClass Item);

protected:
	Atomic count;
	DataClass data[Max];	// Êý¾Ý
};

template<typename DataClass,unsigned int Max>
inline Result Array<DataClass,Max>::Add(int &ID,DataClass Item)
{
	ID = count;
	if (count++ == Max) return E_MAX;
	data[ID] = Item;
	return S_OK;
}

template<typename DataClass,unsigned int Max>
inline Result Array<DataClass,Max>::Get(int ID,DataClass *Item)
{
	if(ID >= count) return E_MAX;
	Item = &data[ID];
	return S_OK;
}

template<typename DataClass,unsigned int Max>
inline Result Array<DataClass,Max>::Get(int ID,DataClass &Item)
{
	if(ID >= count) return E_MAX;
	Item = data[ID];
	return S_OK;
}

template<typename DataClass,unsigned int Max>
inline Result Array<DataClass,Max>::Set(int ID,DataClass Item)
{
	if(ID >= count) return E_MAX;
	data[ID] = Item;
	return S_OK;
}


#endif /* ARRAY_H_ */
