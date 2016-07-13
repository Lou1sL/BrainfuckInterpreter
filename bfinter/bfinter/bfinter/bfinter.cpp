// bfinter.cpp : �������̨Ӧ�ó������ڵ㡣
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


	::cout << "Brainfuck���Խ�����v-1.0   via����" << endl;
	bfinit();
	::cout << "��������ʼ����ɣ��ڴ��ѷ��䣺18000 byte(s)" << endl << endl;


	if (showmem)::cout << "���������ѿ���" << endl;;

	bfmain(srcode, srcode.length(), showmem);



	return 0;
}


void argumentchk(int getargc)
{
	//argc Ϊ1 0�Σ�Ϊ2 1��
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
			//����ԭ�ȵ��ַ���
			string oritemp = srcontents;
			//��ȡ�µ�һ���ַ���
			getline(srcFile, srcontents);
			//�ϲ��ַ���
			srcontents = oritemp + srcontents;
		}

	}
	else
	{
		cout << "File open faild" << endl;
		exit(0);
	}


	//ֻ�����ؼ�ָ���ַ�������ɾ��
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

