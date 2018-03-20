#include<string>
#include<iostream>
#include<fstream>
using namespace std;
#define	MAX_PATH_LENGTH			80
struct Command {
	bool _c;
	bool _w;
	bool _l;
	bool _o;
	Command() {
		_c = false;
		_w = false;
		_l = false;
		_o = false;
	}
};
void count(fstream &outfile, int *cnt)  //统计函数  
{
	char str[256];
	int flag;
	while (outfile.getline(str, 256))
	{
		cnt[2]++;
		cnt[0] = cnt[0] + strlen(str);
		flag = 1;
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] >= 'A' && str[i] <= 'z'&& flag == 1)

			{
				cnt[1]++;//统计单词数  
				flag = 0;
			}
			if (str[i] == ' ' || str[i] == ',' || str[i] == '\t' || str[i] == '\n')
				flag = 1;
		}

	}

	return;
}

int main(int argc, char* argv[])
{

	int i;
	char filename[MAX_PATH_LENGTH];
	char outputfile[MAX_PATH_LENGTH] = "result.txt";
	int cnt[3] = { 0 };
	Command command;
	for (i = 1;i < argc;i++) {
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'c')
				command._c = true;
			if (argv[i][1] == 'w')
				command._w = true;
			if (argv[i][1] == 'l')
				command._l = true;
			if (argv[i][1] == 'o')
			{
				command._o = true;
				i++;
				strcpy_s(outputfile, argv[i]);
			}
		}
		else
			strcpy_s(filename, argv[i]);
	}
	fstream infile(filename, ios::in);//打开文件用于读取
	count(infile, cnt);
	for (i = 0;i < argc;i++)
	{
		if (strcmp(argv[i], "-c") == 0)
			cout << filename << "," << "字符数:" << cnt[0] << endl;
		if (strcmp(argv[i], "-w") == 0)
			cout << filename << "," << "单词数:" << cnt[1] << endl;
		if (strcmp(argv[i], "-l") == 0)
			cout << filename << "," << "行数:" << cnt[2] << endl;
		if (strcmp(argv[i], "-o") == 0)
		{
			ofstream in;//将结果输出到output文件
			in.open(outputfile, ios::trunc);
			in << "characters:" << cnt[0] << endl;
			in << "words:" << cnt[1] << endl;
			in << "lines:" << cnt[2] << endl;
		}
	}


	infile.close();
	system("pause");
	return 0;

	system("pause");
	return 0;
}
