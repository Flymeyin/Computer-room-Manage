#include"Manager.h"

Manager::Manager()
{}

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化学生和老师容器
	this->initVectorST();

	//初始化机房容器
	this->initVectorC();
}

//重写父类---菜单
void Manager::operMenu()
{
	cout << "欢迎管理员： " << this->m_Name << " 登陆！ " << endl;
	cout << "\t\t ------------------------------------ \n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           1.添加账号               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           2.查看账号               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           3.查看机房               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           4.清空预约               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           0.注销登陆               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------ \n";
	cout << "请选择你的操作：" << endl;
}

//初始化容器---去重的一部分
void Manager::initVectorST()
{
	vStu.clear();
	vTea.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}

	cout << "当前老师数量" << vTea.size() << endl;
	ifs.close();
}

//去重
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

//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string filename;
	string tid;
	string errorTip;

	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)//学生
	{
		filename = STUDENT_FILE;
		tid = "请输入学号";
		errorTip = "学号重复，请重新输入";
	}
	else//老师
	{
		filename = TEACHER_FILE;
		tid = "请输入职工号";
		errorTip = "职工号重复，请重新输入";
	}

	ofs.open(filename, ios::out | ios::app);

	int id = 0;
	string name;
	string pwd;

	//id去重
	cout << tid << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)//有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;

	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->initVectorST();
}


void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名： " << s.m_Name << endl;
}
void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_empId << " 姓名： " << t.m_Name << endl;
}
//显示账号
void Manager::showPerson()
{
	cout << "请输入查看类型" << endl;
	cout << "1.查看学生" << endl;
	cout << "2.查看老师" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}

	else
	{
		cout << "老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//初始化容器--机房容器
void Manager::initVectorC()
{
	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房数量: " << vCom.size() << endl;
}

void printComputerRoom(ComputerRoom& com)
{
	cout << "机房编号：" << com.m_ComId << "  机房容量：" << com.m_MaxNum << endl;
}
//显示机房信息
void Manager::showComputer()
{
	cout << "机房的信息如下" << endl;

	for_each(vCom.begin(), vCom.end(), printComputerRoom);

	system("pause");
	system("cls");
}

//清空文件
void Manager::cleanFile()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

Manager::~Manager()
{}

