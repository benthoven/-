#include"�������.h"

//���캯��
Array_Quenu::Array_Quenu()
{
	//��ʼ������
	/*for (int i = 0; i < MAX - 1; i++)
	{
		Array[i] = 0;
	}*/
	Quenu_size = 0;
}
//���
void Array_Quenu::InsertQuenu(Truck& data)
{
	if (data.Type == "\0"&&data.TId=="\0" or Quenu_size == MAX)
	{
		std::cout << "����ʧ�ܣ����������Ƿ�Ϊ��" <<std:: endl;
		return;
	}
	Array[Quenu_size] .TId= data.TId;
	Array[Quenu_size].Type = data.Type;
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
	
	for (int i = 0; i < Quenu_size-1 ; i++)
	{
		Array[i] = Array[i + 1];
		Array[i + 1].TId = " ";
		Array[i + 1].Type = " ";
	}
	Quenu_size--;
}
//��ȡͷԪ��
Truck* Array_Quenu::GetFirst()
{
	if (Quenu_size == 0)
	{
		std::cout << "ͷԪ��Ϊ��" <<std:: endl;
		return NULL;

	}
	return &Array[0];
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
		std::cout << Array[i].TId << std::endl;
	}
}
//��������
Array_Quenu::~Array_Quenu()
{
	//�߼�ɾ��
	Quenu_size = 0;
}