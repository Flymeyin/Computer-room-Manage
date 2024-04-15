#include"Student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化机房信息
	this->initVectorC();

}

//重写父类---菜单
void Student::operMenu()
{
	cout << "欢迎学生： " << this->m_Name << " 登陆！ " << endl;
	cout << "\t\t ------------------------------------ \n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           1.申请预约               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           2.查看我的预约           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           3.查看所有预约           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           4.取消预约               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           0.注销登陆               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------ \n";
	cout << "请选择你的操作：" << endl;
}

//初始化机房信息
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

//申请预约
void Student::applyOrder()
{
	int data = 0;//日期
	int interval = 0;//时间段
	int room = 0;//机房号

	cout << "机房开放时间周一至周五" << endl;
	cout << "请输入申请预约时间" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}

	cout << "请输入申请预约时间段" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}

	cout << "请输入申请机房" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << " 号机房容量为：" << vCom[i].m_MaxNum << endl;
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
			cout << "输入有误，请重新输入" << endl;
		}
	}
	cout << "预约中，审核中" << endl;

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

//查看预约
void Student::showOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		//把string转为C语言int
		//string 利用 .c_str()转为const char*
		//利用atoi（const char*）转为int
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))//找到自己预约
		{
			cout << "预约日期：周" << of.m_orderData[i]["data"] << " ";
			cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房号：" << of.m_orderData[i]["roomId"] << " ";

			string status = "状态 ";
			//1审核中 2已预约 -1预约失败 0取消预约
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败";
			}
			else
			{
				status += "取消预约";
			}
			cout << status << " " << endl;
		}
	}
	system("pause");
	system("cls");
}

//查看所有预约
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["data"] << " ";
		cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号：" << of.m_orderData[i]["stuId"] << " ";
		cout << "姓名：" << of.m_orderData[i]["stuName"] << " ";
		cout << "机房号：" << of.m_orderData[i]["roomId"] << " ";

		string status = "状态 ";
		//1审核中 2已预约 -1预约失败 0取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "取消预约";
		}
		cout << status << " " << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核或者预约成功的记录可以取消，请输入取消的记录" << endl;
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

				cout << "预约日期：周" << of.m_orderData[i]["data"] << " ";
				cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
				cout << "机房号：" << of.m_orderData[i]["roomId"] << " ";
				string status = "状态 ";
				//1审核中 2已预约 -1预约失败 0取消预约
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消记录，0代表返回" << endl;
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
				cout << "已经取消预约" << endl;
				break;
			}
		}
		cout << "输入错误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}

Student::~Student()
{

}

