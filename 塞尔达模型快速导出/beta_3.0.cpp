#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool isnum_str(char str)  //�ж��Ƿ����ַ�������
{
	if ((str >= 'A' && str <= 'z') || (str >= '0' && str <= '9'))
		return true;
	else
		return false;
}
void count(fstream &outfile, int *cnt)  //ͳ�ƺ���
{
	char str[256];
	while (outfile.getline(str, 256))
	{
		int tmp = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (isnum_str(str[i]))
			{
				tmp++;
			}    //ͳ���ַ�����tmp�ֲ��������������ǲ���һ�����С�
		}

		if (tmp != 0)
			cnt[2]++;                 //ͳ������
		tmp = 0;
	}
	return;
}
int main()
{
	/*��������*/
	int count_txt;
	int i = 0;
	char FPath[256];
	char addr_c[256];
	char szCmd[256];
	string del_cmd;
	string Raddr;
	string addr;
	string sbname;
	string Txtaddr;
	string bat_n;
	string *filename1;

	bool isFileH;
	int input_del;
	bool isDel;

	/*
	ͳ������
	��ִ��Bat�ļ�
	��bat���ɵ�txt����ͳ��
	*/
	char T_filename[256];
	int cnt[3] = { 0 };
	cout << "����ģ���ļ�Ŀ¼";
	cin >> addr;
	Txtaddr = addr + "\\1.txt";
	cout << "�Ƿ�������ɾ�� 1 = YES,2 = NO" << endl;
	cin >> input_del;
	isFileH = true;
	sbname = "sBFRESEX ";
	/*����bat*/
	string f_addr = addr + "\\dir.bat";
	string file_in = "dir /a-d /b *.sbfres>1.txt";
	ofstream out(f_addr);
	if (out)
	{
		out << file_in << endl;//ʹ��cout��������д�롤
	}
	out.close();
	/*��ִ��bat�ļ�*/
	char addr_bat[256];
	string temp = addr + "\\dir.bat";
	strcpy(addr_bat, temp.c_str());
	cout << addr_bat << endl;
	system(addr_bat);
	/*��ʼͳ������*/
	fstream outfile(Txtaddr.c_str(), ios::in);
	count(outfile, cnt);
	outfile.close();
	count_txt = cnt[2];
	cout << "lines: " << count_txt << endl;;

	ifstream in(Txtaddr);
	string line;
	filename1 = new string[count_txt];//ʹ�ö�̬���飬����չ
		if (in) //�и��ļ�  
		{
			isFileH = false;
			while (getline(in, line)) // line�в�����ÿ�еĻ��з�  
			{
				filename1[i] = line;
				i++;
			}
		}
		else // û�и��ļ�  
		{
			isFileH = true;
			cout << "no such file" << endl << "press enter quit";
			return -1;
		}
		/*ִ��*/

		for (i = 0; i < count_txt; i++)
		{
			Raddr = sbname + addr + "\\\\" + filename1[i];
			cout << "��������ļ�" << filename1[i] << endl;
			strcpy(addr_c, Raddr.c_str());
			system(addr_c);
		}
		outfile.close();
		in.close();
		//ɾ���ļ��ڶ��ְ취(Ч�ʽϵ�)
		//for (i = 0; i < count_txt; i++)
		//{
		//	if (input_del == 1)
		//	{
		//		/*ִ����ɾ���ļ�*/
		//		Raddr = addr + "\\\\" + filename1[i];
		//		del_cmd = "del /F /S /Q" + Raddr;
		//		strcpy(FPath, del_cmd.c_str());
		//		cout << FPath << endl;
		//		system(FPath);
		//	}
		//}
		//�����ļ�
		//ɾ��Դ��Դ�ļ�
		del_cmd = "del /F /S /Q " + addr + "\\*.sbfres";
		strcpy(FPath, del_cmd.c_str());
		system(FPath);
		//ɾ��bat�ļ�
		del_cmd = "del /F /S /Q " + f_addr;
		strcpy(FPath,del_cmd.c_str());
		system(FPath);
		//ɾ�����ɵ�txt�ļ�
		del_cmd = "del /F /S /Q " + Txtaddr;
		strcpy(FPath, del_cmd.c_str());
		system(FPath);
		system("pause");
		return 0;
}
