
#include"�������.h"

int main()
{
	SignSolution Sg;
	while (1)
	{
		Sg.showmenu();
		std::cout << "����������ѡ��" << std::endl;
		int choice = 0;
		std::cin >> choice;
		switch (choice)
		{
		case 1://�Ǽ��Ŷ�
			Sg.Sign();
			break;
		case 2://�кŵǴ�
			Sg.Call();
			break;
		case 3://�鿴����������Ϣ
			std::cout << "���ϳ�����Ϣ����" << std::endl;
			Sg.ShowInformation();
			break;
		case 4://�鿴�ȴ�������Ϣ
			Sg.ShowInWaiting();
			break;
		case 5://�˳�ϵͳ
			Sg.Exit();
			break;
		}
	}
	

	system("pause");
	return 0;
}