#ifndef H_DATA
#define H_DATA
/*===============================================================
 *                  DataContainer.h
 *                 ������������ģ���� ����
 ===============================================================*/

template <typename DataClass,unsigned int Max>

class DataContainer
{
public:
	void Init();				// ��ʼ��
protected:
	DataClass data[Max];		// ����
};

#endif
