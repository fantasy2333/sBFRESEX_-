#include <fstream>  
#include <string>  
#include <iostream>  
using namespace std;

int main()
{
	char addr_c[256];
	char szCmd[256] = { 0 };

	string Raddr;
	string addr;
	string sbname = "sBFRESEX ";
	cout << "输入模型文件目录";
	cin >> addr;
	string faddr = addr + "\\1.txt";
	ifstream in(faddr);
	string filename[5658];
	string line;
	int i = 0;
	if (in) // 有该文件  
	{
		while (getline(in, line)) // line中不包括每行的换行符  
		{
			filename[i] = line;
			i++;
		}
	}
	else // 没有该文件  
	{
		cout << "no such file" << endl;
	}
	for (i = 0; i < 5658; i++)
	{
		Raddr = sbname + addr + "\\\\"+filename[i];
		strcpy(addr_c,Raddr.c_str());
		//cout << addr_c << endl;
		system(addr_c);
	}
	return 0;
}