#include"Manager.h"

Manager::Manager()
{}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��ѧ������ʦ����
	this->initVectorST();

	//��ʼ����������
	this->initVectorC();
}

//��д����---�˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա�� " << this->m_Name << " ��½�� " << endl;
	cout << "\t\t ------------------------------------ \n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           1.����˺�               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           2.�鿴�˺�               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           3.�鿴����               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           4.���ԤԼ               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           0.ע����½               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------ \n";
	cout << "��ѡ����Ĳ�����" << endl;
}

//��ʼ������---ȥ�ص�һ����
void Manager::initVectorST()
{
	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}

	cout << "��ǰ��ʦ����" << vTea.size() << endl;
	ifs.close();
}

//ȥ��
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_empId)
			{
				return true;
			}
		}
	}
	return false;
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string filename;
	string tid;
	string errorTip;

	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)//ѧ��
	{
		filename = STUDENT_FILE;
		tid = "������ѧ��";
		errorTip = "ѧ���ظ�������������";
	}
	else//��ʦ
	{
		filename = TEACHER_FILE;
		tid = "������ְ����";
		errorTip = "ְ�����ظ�������������";
	}

	ofs.open(filename, ios::out | ios::app);

	int id = 0;
	string name;
	string pwd;

	//idȥ��
	cout << tid << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)//���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "����������" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;

	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->initVectorST();
}


void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������ " << s.m_Name << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_empId << " ������ " << t.m_Name << endl;
}
//��ʾ�˺�
void Manager::showPerson()
{
	cout << "������鿴����" << endl;
	cout << "1.�鿴ѧ��" << endl;
	cout << "2.�鿴��ʦ" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}

	else
	{
		cout << "��ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//��ʼ������--��������
void Manager::initVectorC()
{
	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "��������: " << vCom.size() << endl;
}

void printComputerRoom(ComputerRoom& com)
{
	cout << "������ţ�" << com.m_ComId << "  ����������" << com.m_MaxNum << endl;
}
//��ʾ������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ����" << endl;

	for_each(vCom.begin(), vCom.end(), printComputerRoom);

	system("pause");
	system("cls");
}

//����ļ�
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

Manager::~Manager()
{}

