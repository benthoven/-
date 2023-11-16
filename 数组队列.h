#pragma once
#include<iostream>
#define MAX 1000
#include"truck.h"


class Array_Quenu
{
public:
	//构造函数
	Array_Quenu();
	//入队
	void InsertQuenu(Truck& data);
	//出队
	void DeleteQuenu();
	//判断是否为空
	bool IsEmpty();
	//返回队头元素
	Truck* GetFirst();
	//析构函数
	~Array_Quenu();
	//遍历
	void Recurision();

	Truck Array[MAX];
	int Quenu_size;


};