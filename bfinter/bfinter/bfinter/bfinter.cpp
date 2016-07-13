// bfinter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "bfmachine.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ifstream;
using std::ios_base;

int CellNum = 1;



void argumentchk(int getargc);

string readfile(char* filepath);

void clean_string(char* str);

int main(int argc, char* argv[])
{
	argumentchk(argc);

	string srcode = readfile(argv[1]);

	bool showmem = false;

	if (argv[2] == "/p")showmem = true;


	::cout << "Brainfuck语言解释器v-1.0   via留白" << endl;
	bfinit();
	::cout << "解释器初始化完成，内存已分配：18000 byte(s)" << endl << endl;


	if (showmem)::cout << "单步跟踪已开启" << endl;;

	bfmain(srcode, srcode.length(), showmem);



	return 0;
}


void argumentchk(int getargc)
{
	//argc 为1 0参，为2 1参
	if (getargc > 3 || getargc == 1)
	{
		cout << "Usage: command <filename> [/p]" << endl;
		exit(0);
	}

}


string readfile(char* filepath)
{
	ifstream srcFile;

	string srcontents;

	srcFile.open(filepath, ios_base::in);

	if (srcFile.is_open())
	{
		//cout << "File open successful" << endl;


		while (srcFile.good())
		{
			//保存原先的字符串
			string oritemp = srcontents;
			//获取新的一行字符串
			getline(srcFile, srcontents);
			//合并字符串
			srcontents = oritemp + srcontents;
		}

	}
	else
	{
		cout << "File open faild" << endl;
		exit(0);
	}


	//只保留关键指令字符，其它删掉
	string srcontentsbuff;
	for (unsigned int i = 0; i < srcontents.length(); ++i)
	{
		if (srcontents[i] == '+' ||
			srcontents[i] == '-' ||
			srcontents[i] == '>' ||
			srcontents[i] == '<' ||
			srcontents[i] == '.' ||
			srcontents[i] == ',' ||
			srcontents[i] == '[' ||
			srcontents[i] == ']')
		{
			srcontentsbuff = srcontentsbuff + srcontents[i];
		}

	}

	//cout << srcontents << endl;
	return srcontentsbuff;
}

