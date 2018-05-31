//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//bool isnum_str(char str)  //判断是否是字符或数字
//{
//	if ((str >= 'A' && str <= 'z') || (str >= '0' && str <= '9'))
//		return true;
//	else
//		return false;
//}
//void count(fstream &outfile, int *cnt)  //统计函数
//{
//	char str[256];
//	while (outfile.getline(str, 256))
//	{
//		int tmp = 0;
//		for (int i = 0; i < strlen(str); i++)
//		{
//			if (isnum_str(str[i]))
//			{
//				tmp++;
//			}    //统计字符数，tmp局部变量用来区分是不是一个空行。
//		}
//
//		if (tmp != 0)
//			cnt[2]++;                 //统计行数
//		tmp = 0;
//	}
//	return;
//}
//int main()
//{
//	/*变量定义*/
//	int count_txt;
//	int i = 0;
//
//	char addr_c[256];
//	char szCmd[256];
//	string Raddr;
//	string addr;
//	string sbname;
//	string Txtaddr;
//	string bat_n;
//	string *filename1;
//
//	bool isFileH;
//	int input_del;
//	bool isDel;
//
//	/*
//	统计行数
//	先执行Bat文件
//	从bat生成的txt进行统计
//	*/
//	char T_filename[256];
//	int cnt[3] = { 0 };
//	cout << "输入模型文件目录";
//	cin >> addr;
//	Txtaddr = addr + "\\1.txt";
//	cout << "是否边输出边删除 1 = YES,2 = NO" << endl;
//	cin >> input_del;
//	isFileH = true;
//	sbname = "sBFRESEX ";
//	/*创建bat*/
//	string f_addr = addr + "\\dir.bat";
//	string file_in = "dir /a-d /b *.sbfres>1.txt";
//	ofstream out(f_addr);
//	if (out)
//	{
//		out << file_in << endl;//使用cout方法进行写入·
//	}
//	out.close();
//	/*先执行bat文件*/
//	char addr_bat[256];
//	string temp = addr + "\\dir.bat";
//	strcpy(addr_bat, temp.c_str());
//	cout << addr_bat << endl;
//	system(addr_bat);
//	/*开始统计行数*/
//	fstream outfile(Txtaddr.c_str(), ios::in);
//	count(outfile, cnt);
//	outfile.close();
//	count_txt = cnt[2];
//	cout << "lines: "<<count_txt << endl;;
//
//
//	ifstream in(Txtaddr);
//	string line;
//	filename1 = new string[count_txt];//使用动态数组，可扩展
//	while (isFileH)
//	{
//		if (in) //有该文件  
//		{
//			isFileH = false;
//			while (getline(in, line)) // line中不包括每行的换行符  
//			{
//				filename1[i] = line;
//				i++;
//			}
//		}
//		else // 没有该文件  
//		{
//			isFileH = true;
//			cout << "no such file" << endl << "press enter,return";
//		}
//		/*执行*/
//
//		for (i = 0; i < count_txt; i++)
//		{
//			Raddr = sbname + addr + "\\\\" + filename1[i];
//			cout << "正在输出文件" << filename1[i] << endl;
//			strcpy(addr_c, Raddr.c_str());
//			system(addr_c);
//		}
//		for (i = 0; i < count_txt; i++)
//		{
//			if (input_del == 1)
//			{
//				/*执行完删除文件*/
//				if (remove(Raddr.c_str()) == 0)
//				{
//					cout << "删除成功 删除文件:" << filename1[i] << endl;
//				}
//				else
//				{
//					cout << "删除失败 未删除文件:" << filename1[i] << endl;
//				}
//			}
//		}
//		system("pause");
//		return 0;
//	}
//}
