#include"�������.h"


SignSolution::SignSolution()
{//��ʼ����������
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
	//�߼����
	Size = 0;
	std::cout << "������" << std::endl;
}
//�˵���
void SignSolution::showmenu()
{
	std::cout << "***********��ӭʹ�������Ǵ�����ϵͳ***********" << std::endl;
	std::cout << "***********��ѡ����***********" << std::endl;
	std::cout << "***********1.�Ǽ��Ŷ�***********" << std::endl;
	std::cout << "***********2.�кŵǴ�***********" << std::endl;
	std::cout << "***********3.�鿴���ϴ�������Ϣ***********" << std::endl;
	std::cout << "***********4.�鿴�ȴ���������Ϣ***********" << std::endl;
	std::cout << "***********5.�˳�ϵͳ***********" << std::endl;
}
//�Ǽ��Ŷ�
void SignSolution::Sign()
{
	Truck car;
	std::cout << "���������ĳ��ƺ�" << std::endl;
	std::cin >> car.TId;
	std::cout << "��ѡ�����ĳ���" << std::endl;
	std::cout << "1.�ͳ�" << std::endl;
	std::cout << "2.�ʻ���" << std::endl;
	std::cout << "3.��ͨ����" << std::endl;
	int type = 0;
	std::cin >> type;
	if (type == 1)
	{
		car.Type = "�ͳ�";
		Qper.InsertQuenu(&car);
	}
	else if (type == 2)
	{
		car.Type = "�ʻ���";
		Qfresh.InsertQuenu(&car);
	}
	else if (type == 3)
	{
		car.Type = "��ͨ����";
		Qtruck.InsertQuenu(&car);
	}
	std::cout << "������Ϣ�Ǽǳɹ��������ĵȴ��к�" << std::endl;
	system("pause");
	system("cls");

}
//�кŵǴ�
void SignSolution::Call()
{
	static int Acculumate = Qfresh_num + Qper_num + Qtruck_num;//��������
	while (!Qper.IsEmpty() or !Qfresh.IsEmpty() or !Qtruck.IsEmpty())//��������������
	{
		while (!Qper.IsEmpty() && Qper_num < 3 or !Qper.IsEmpty() && Qfresh.IsEmpty() && Qfresh_num + Qper_num < 5 or !Qper.IsEmpty() && Qfresh.IsEmpty() && Qtruck.IsEmpty() && Acculumate < 6)//���Ǽ���ͳ������
		{
			//��ȡ�ͳ���һ��Ԫ�� ���浽�Ǵ�����
			Truck* tr1=(Truck*)Qper.GetFirst();
			Qper.DeleteQuenu();//����
			Signed[Size] = tr1;
			Size++;//SIZE���滻ΪAcculuate
			ShowInformation();
			Acculumate++;
			Qper_num++;
		}
		if (Acculumate == 6)
		{
			//��ʾ�Ǵ�������Ϣ
			std::cout << "�Ǵ�������Ϣ���£�" << std::endl;
			ShowInformation();
			std::cout << "�뾡��Ǵ�" << std::endl;
			system("pause");
			std::cout << "�����ɹ�" << std::endl;
			system("pause");
			system("cls");
			return;//�˳�
		}
		//�����ʻ��������
		while (!Qfresh.IsEmpty() && Qper_num + Qfresh_num < 5 or Qper.IsEmpty() && !Qfresh.IsEmpty() && Qtruck.IsEmpty() && Acculumate < 6)
		{
			Truck* tr2 = (Truck*)Qfresh.GetFirst();
			Qfresh.DeleteQuenu();//����
			Signed[Size] = tr2;
			Size++;//SIZE���滻ΪAcculuate
			ShowInformation();
			Acculumate++;
			Qfresh_num++;
		}
		if (Acculumate == 6)
		{
			//��ʾ�Ǵ�������Ϣ
			std::cout << "�Ǵ�������Ϣ���£�" << std::endl;
			ShowInformation();
			std::cout << "�뾡��Ǵ�" << std::endl;
			system("pause");
			std::cout << "�����ɹ�" << std::endl;
			system("pause");
			system("cls");
			return;
		}
		//������ͨ���������
		while (!Qtruck.IsEmpty() && Qtruck_num < 1 or Qper.IsEmpty() && Qfresh.IsEmpty() && !Qtruck.IsEmpty() && Acculumate < 6)
		{

			Truck* tr3 = (Truck*)Qtruck.GetFirst();
			Qtruck.DeleteQuenu();//����
			Signed[Size] = tr3;
			Size++;//SIZE���滻ΪAcculuate
			ShowInformation();
			Acculumate++;
			Qtruck_num++;
		}
		if (Acculumate == 6)
		{
			//��ʾ�Ǵ�������Ϣ
			std::cout << "�Ǵ�������Ϣ���£�" << std::endl;
			ShowInformation();
			std::cout << "�뾡��Ǵ�" << std::endl;
			system("pause");
			std::cout << "�����ɹ�" << std::endl;
			system("pause");
			system("cls");
			return;
		}
	}
	if (Acculumate < 6)
	{
		std::cout << "��ʱ�ֶ�����" << Acculumate << "����,�����ȴ���***" << std::endl;
		system("pause");
		system("cls");
	}
}
//�鿴����������Ϣ
void SignSolution::ShowInformation()
{
	if (Size == 0)
	{
		std::cout << "��ǰ���ϲ��޳���" << std::endl;
		return;
	}
	//�����ѵǴ�����
	for (int i = 0; i < Size; i++)
	{
		std::cout<< "���ƺ�Ϊ��" << Signed[i]->TId  << "����Ϊ: " << Signed[i]->Type << std::endl;
	}
	
}
//�鿴������δ�ϴ���������
void SignSolution::ShowInWaiting()
{
	std::cout << "δ�ϴ��ͳ�����Ϊ" << Qper.Quenu_size << std::endl;
	std::cout << "δ�ϴ��ʻ�������Ϊ" << Qfresh.Quenu_size << std::endl;
	std::cout << "δ�ϴ���ͨ��������Ϊ" << Qtruck.Quenu_size << std::endl;

	system("pause");
	system("cls");
}
//�˳�
void SignSolution::Exit()
{
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	system("cls");
	return;
}