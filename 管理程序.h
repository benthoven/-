#pragma once
#include<iostream>
#include"数组队列.h"
#include"truck.h"

class SignSolution
{
public:
	SignSolution();
	~SignSolution();
	//菜单、
	void showmenu();
	//登记排队
	void Sign();
	//叫号登船
	void Call();
	//查看已载汽车信息
	void ShowInformation();
	//查看岸上尚未上船汽车数量
	void ShowInWaiting();
	//退出
	void Exit();

	Array_Quenu Qper;//客车
	Array_Quenu Qfresh;//鲜货车
	Array_Quenu Qtruck;//普通货车

	//统计各车型登船数量
	 int Qper_num;
	 int Qfresh_num;
	 int Qtruck_num;

	//已登船容器
	Truck Signed[10];
	int Size;//记录容量
};