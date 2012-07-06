#ifndef BINSEM_H_
#define BINSEM_H_
/*===============================================================
 *                   BinarySemaphore.h
 *                   内核同步锁机制相关 定义
 ===============================================================*/

#include "Lock.h"

class BinarySemaphore
{
public:
	void Init();
	void Wait();
	void Signal();
protected:
	volatile int value;
};

#endif
