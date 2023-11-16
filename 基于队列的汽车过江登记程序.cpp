
#include"管理程序.h"

int main()
{
	SignSolution Sg;
	while (1)
	{
		Sg.showmenu();
		std::cout << "请输入您的选择" << std::endl;
		int choice = 0;
		std::cin >> choice;
		switch (choice)
		{
		case 1://登记排队
			Sg.Sign();
			break;
		case 2://叫号登船
			Sg.Call();
			break;
		case 3://查看已载汽车信息
			std::cout << "船上车辆信息如下" << std::endl;
			Sg.ShowInformation();
			break;
		case 4://查看等待汽车信息
			Sg.ShowInWaiting();
			break;
		case 5://退出系统
			Sg.Exit();
			break;
		}
	}
	

	system("pause");
	return 0;
}