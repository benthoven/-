#pragma once
#include<iostream>
#include"�������.h"
#include"truck.h"

class SignSolution
{
public:
	SignSolution();
	~SignSolution();
	//�˵���
	void showmenu();
	//�Ǽ��Ŷ�
	void Sign();
	//�кŵǴ�
	void Call();
	//�鿴����������Ϣ
	void ShowInformation();
	//�鿴������δ�ϴ���������
	void ShowInWaiting();
	//�˳�
	void Exit();

	Array_Quenu Qper;//�ͳ�
	Array_Quenu Qfresh;//�ʻ���
	Array_Quenu Qtruck;//��ͨ����

	//ͳ�Ƹ����͵Ǵ�����
	 int Qper_num;
	 int Qfresh_num;
	 int Qtruck_num;

	//�ѵǴ�����
	Truck Signed[10];
	int Size;//��¼����
};