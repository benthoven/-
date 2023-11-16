#include"管理程序.h"


SignSolution::SignSolution()
{//初始化汇总容器
	/*for (int i = 0; i < 6; i++)
	{
		Signed[i]->TId = " ";
		Signed[i]->Type = " ";
	}*/
	Size = 0;

	Qper_num=0;
	Qfresh_num=0;
	Qtruck_num=0;
}
SignSolution::~SignSolution()
{
	//逻辑清空
	Size = 0;
	std::cout << "清空完成" << std::endl;
}
//菜单、
void SignSolution::showmenu()
{
	std::cout << "***********欢迎使用汽车登船管理系统***********" << std::endl;
	std::cout << "***********请选择功能***********" << std::endl;
	std::cout << "***********1.登记排队***********" << std::endl;
	std::cout << "***********2.叫号登船***********" << std::endl;
	std::cout << "***********3.查看已上船汽车信息***********" << std::endl;
	std::cout << "***********4.查看等待中汽车信息***********" << std::endl;
	std::cout << "***********5.退出系统***********" << std::endl;
}
//登记排队
void SignSolution::Sign()
{
	Truck car;
	std::cout << "请输入您的车牌号" << std::endl;
	std::cin >> car.TId;
	std::cout << "请选择您的车型" << std::endl;
	std::cout << "1.客车" << std::endl;
	std::cout << "2.鲜货车" << std::endl;
	std::cout << "3.普通货车" << std::endl;
	int type = 0;
	std::cin >> type;
	if (type == 1)
	{
		car.Type = "客车";
		Qper.InsertQuenu(&car);
	}
	else if (type == 2)
	{
		car.Type = "鲜货车";
		Qfresh.InsertQuenu(&car);
	}
	else if (type == 3)
	{
		car.Type = "普通货车";
		Qtruck.InsertQuenu(&car);
	}
	std::cout << "您的信息登记成功，请耐心等待叫号" << std::endl;
	system("pause");
	system("cls");

}
//叫号登船
void SignSolution::Call()
{
	static int Acculumate = Qfresh_num + Qper_num + Qtruck_num;//计算总数
	while (!Qper.IsEmpty() or !Qfresh.IsEmpty() or !Qtruck.IsEmpty())//三个容器都不空
	{
		while (!Qper.IsEmpty() && Qper_num < 3 or !Qper.IsEmpty() && Qfresh.IsEmpty() && Qfresh_num + Qper_num < 5 or !Qper.IsEmpty() && Qfresh.IsEmpty() && Qtruck.IsEmpty() && Acculumate < 6)//考虑加入客车的情况
		{
			//获取客车第一个元素 保存到登船数组
			Truck* tr1=(Truck*)Qper.GetFirst();
			Qper.DeleteQuenu();//出队
			Signed[Size] = tr1;
			Size++;//SIZE可替换为Acculuate
			ShowInformation();
			Acculumate++;
			Qper_num++;
		}
		if (Acculumate == 6)
		{
			//显示登船车辆信息
			std::cout << "登船车辆信息如下：" << std::endl;
			ShowInformation();
			std::cout << "请尽快登船" << std::endl;
			system("pause");
			std::cout << "发船成功" << std::endl;
			system("pause");
			system("cls");
			return;//退出
		}
		//考虑鲜货车的情况
		while (!Qfresh.IsEmpty() && Qper_num + Qfresh_num < 5 or Qper.IsEmpty() && !Qfresh.IsEmpty() && Qtruck.IsEmpty() && Acculumate < 6)
		{
			Truck* tr2 = (Truck*)Qfresh.GetFirst();
			Qfresh.DeleteQuenu();//出队
			Signed[Size] = tr2;
			Size++;//SIZE可替换为Acculuate
			ShowInformation();
			Acculumate++;
			Qfresh_num++;
		}
		if (Acculumate == 6)
		{
			//显示登船车辆信息
			std::cout << "登船车辆信息如下：" << std::endl;
			ShowInformation();
			std::cout << "请尽快登船" << std::endl;
			system("pause");
			std::cout << "发船成功" << std::endl;
			system("pause");
			system("cls");
			return;
		}
		//考虑普通货车的情况
		while (!Qtruck.IsEmpty() && Qtruck_num < 1 or Qper.IsEmpty() && Qfresh.IsEmpty() && !Qtruck.IsEmpty() && Acculumate < 6)
		{

			Truck* tr3 = (Truck*)Qtruck.GetFirst();
			Qtruck.DeleteQuenu();//出队
			Signed[Size] = tr3;
			Size++;//SIZE可替换为Acculuate
			ShowInformation();
			Acculumate++;
			Qtruck_num++;
		}
		if (Acculumate == 6)
		{
			//显示登船车辆信息
			std::cout << "登船车辆信息如下：" << std::endl;
			ShowInformation();
			std::cout << "请尽快登船" << std::endl;
			system("pause");
			std::cout << "发船成功" << std::endl;
			system("pause");
			system("cls");
			return;
		}
	}
	if (Acculumate < 6)
	{
		std::cout << "此时轮渡上有" << Acculumate << "辆车,继续等待中***" << std::endl;
		system("pause");
		system("cls");
	}
}
//查看已载汽车信息
void SignSolution::ShowInformation()
{
	if (Size == 0)
	{
		std::cout << "当前船上并无车辆" << std::endl;
		return;
	}
	//遍历已登船容器
	for (int i = 0; i < Size; i++)
	{
		std::cout<< "车牌号为：" << Signed[i]->TId  << "车型为: " << Signed[i]->Type << std::endl;
	}
	
}
//查看岸上尚未上船汽车数量
void SignSolution::ShowInWaiting()
{
	std::cout << "未上船客车数量为" << Qper.Quenu_size << std::endl;
	std::cout << "未上船鲜货车数量为" << Qfresh.Quenu_size << std::endl;
	std::cout << "未上船普通货车数量为" << Qtruck.Quenu_size << std::endl;

	system("pause");
	system("cls");
}
//退出
void SignSolution::Exit()
{
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	system("cls");
	return;
}