#include"�������.h"

//���캯��
Array_Quenu::Array_Quenu()
{
	//��ʼ������
	for (int i = 0; i < MAX - 1; i++)
	{
		Array[i] = 0;
	}
	Quenu_size = 0;
}
//���
void Array_Quenu::InsertQuenu(void* data)
{
	if (data == NULL or Quenu_size == MAX)
	{
		std::cout << "����ʧ�ܣ����������Ƿ�Ϊ��" <<std:: endl;
		return;
	}
	Array[Quenu_size] = data;
	Quenu_size++;
}
//����
void Array_Quenu::DeleteQuenu()
{
	if (Quenu_size == 0)
	{
		std::cout << "ɾ��ʧ�ܣ�����Ϊ��" << std::endl;
		return;
	}
	for (int i = 0; i < Quenu_size ; i++)
	{
		Array[i] = Array[i + 1];
	}
	Quenu_size--;
}
//��ȡͷԪ��
void* Array_Quenu::GetFirst()
{
	return Array[0];
}
//�ж��Ƿ�Ϊ��
bool Array_Quenu::IsEmpty()
{
	return Quenu_size ?false : true;
}
//����
void Array_Quenu::Recurision()
{
	for (int i = 0; i < Quenu_size; i++)
	{
		std::cout << Array[i] << std::endl;
	}
}
//��������
Array_Quenu::~Array_Quenu()
{
	//�߼�ɾ��
	Quenu_size = 0;
}