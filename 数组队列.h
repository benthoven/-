#pragma once
#include<iostream>
#define MAX 1000
#include"truck.h"


class Array_Quenu
{
public:
	//���캯��
	Array_Quenu();
	//���
	void InsertQuenu(Truck& data);
	//����
	void DeleteQuenu();
	//�ж��Ƿ�Ϊ��
	bool IsEmpty();
	//���ض�ͷԪ��
	Truck* GetFirst();
	//��������
	~Array_Quenu();
	//����
	void Recurision();

	Truck Array[MAX];
	int Quenu_size;


};