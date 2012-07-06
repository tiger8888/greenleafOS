#ifndef BINSEM_H_
#define BINSEM_H_
/*===============================================================
 *                   BinarySemaphore.h
 *                   �ں�ͬ����������� ����
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
