#pragma once
#include<iostream>
#define MAX 1000


class Array_Quenu
{
public:
	//构造函数
	Array_Quenu();
	//入队
	void InsertQuenu(void * data);
	//出队
	void DeleteQuenu();
	//判断是否为空
	bool IsEmpty();
	//返回队头元素
	void* GetFirst();
	//析构函数
	~Array_Quenu();
	//遍历
	void Recurision();

	void* Array[MAX];
	int Quenu_size;


};