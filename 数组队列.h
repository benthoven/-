#pragma once
#include<iostream>
#define MAX 1000


class Array_Quenu
{
public:
	//���캯��
	Array_Quenu();
	//���
	void InsertQuenu(void * data);
	//����
	void DeleteQuenu();
	//�ж��Ƿ�Ϊ��
	bool IsEmpty();
	//���ض�ͷԪ��
	void* GetFirst();
	//��������
	~Array_Quenu();
	//����
	void Recurision();

	void* Array[MAX];
	int Quenu_size;


};