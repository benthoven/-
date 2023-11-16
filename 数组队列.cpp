#include"数组队列.h"

//构造函数
Array_Quenu::Array_Quenu()
{
	//初始化数组
	for (int i = 0; i < MAX - 1; i++)
	{
		Array[i] = 0;
	}
	Quenu_size = 0;
}
//入队
void Array_Quenu::InsertQuenu(void* data)
{
	if (data == NULL or Quenu_size == MAX)
	{
		std::cout << "输入失败，请检查输入是否为空" <<std:: endl;
		return;
	}
	Array[Quenu_size] = data;
	Quenu_size++;
}
//出队
void Array_Quenu::DeleteQuenu()
{
	if (Quenu_size == 0)
	{
		std::cout << "删除失败，队列为空" << std::endl;
		return;
	}
	for (int i = 0; i < Quenu_size ; i++)
	{
		Array[i] = Array[i + 1];
	}
	Quenu_size--;
}
//获取头元素
void* Array_Quenu::GetFirst()
{
	return Array[0];
}
//判断是否为空
bool Array_Quenu::IsEmpty()
{
	return Quenu_size ?false : true;
}
//遍历
void Array_Quenu::Recurision()
{
	for (int i = 0; i < Quenu_size; i++)
	{
		std::cout << Array[i] << std::endl;
	}
}
//析构函数
Array_Quenu::~Array_Quenu()
{
	//逻辑删除
	Quenu_size = 0;
}