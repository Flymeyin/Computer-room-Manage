#include"Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	this->initVectorC();

}

//��д����---�˵�
void Student::operMenu()
{
	cout << "��ӭѧ���� " << this->m_Name << " ��½�� " << endl;
	cout << "\t\t ------------------------------------ \n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           1.����ԤԼ               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           2.�鿴�ҵ�ԤԼ           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           3.�鿴����ԤԼ           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           4.ȡ��ԤԼ               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           0.ע����½               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------ \n";
	cout << "��ѡ����Ĳ�����" << endl;
}

//��ʼ��������Ϣ
void Student::initVectorC()
{
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

//����ԤԼ
void Student::applyOrder()
{
	int data = 0;//����
	int interval = 0;//ʱ���
	int room = 0;//������

	cout << "��������ʱ����һ������" << endl;
	cout << "����������ԤԼʱ��" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}

	cout << "����������ԤԼʱ���" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}

	cout << "�������������" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << " �Ż�������Ϊ��" << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	cout << "ԤԼ�У������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out);

	ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;;
	ofs.close();

	system("pause");
	system("cls");
}

//�鿴ԤԼ
void Student::showOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//��stringתΪC����int
		//string ���� .c_str()תΪconst char*
		//����atoi��const char*��תΪint
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))//�ҵ��Լ�ԤԼ
		{
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"] << " ";
			cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "�����ţ�" << of.m_orderData[i]["roomId"] << " ";

			string status = "״̬ ";
			//1����� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ȡ��ԤԼ";
			}
			cout << status << " " << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"] << " ";
		cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"] << " ";
		cout << "������" << of.m_orderData[i]["stuName"] << " ";
		cout << "�����ţ�" << of.m_orderData[i]["roomId"] << " ";

		string status = "״̬ ";
		//1����� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ȡ��ԤԼ";
		}
		cout << status << " " << endl;
	}
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��˻���ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);

				cout << index++ << " ";

				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"] << " ";
				cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
				cout << "�����ţ�" << of.m_orderData[i]["roomId"] << " ";
				string status = "״̬ ";
				//1����� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ����¼��0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updataOrder();
				cout << "�Ѿ�ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "�����������������" << endl;
	}
	system("pause");
	system("cls");
}

Student::~Student()
{

}

