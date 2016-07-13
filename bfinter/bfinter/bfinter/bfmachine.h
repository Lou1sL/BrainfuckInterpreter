#include <conio.h>
#include "memprt.h"
/*
*   -------------------------------------------我不得不滋磁一下嘛
*   ctlcode 与 brainfuck 语言操作符的对应关系
*
*	+  0	值+1
*	-  1	值-1
*	>  2	指针+1
*	<  3	指针-1
*	.  4	输出指针指向单元内容（ASCII）
*	,  5	输入到指针指向单元（ASCII）
*	[  6	if指针指向单元值=0，跳转至下一]后
*	]  7	if指针指向单元值!=0，跳转至前一[后
*/

//数组长度
const int charlength = 18000;


//指针
int cell = 0;
//数组
char c[charlength];

//数组初始化
void bfinit()
{
	for (int i = 0; i < charlength; i++)
	{
		c[i] = 0;
	}
}





void bfmainnocir(char ctl)
{

	switch (ctl)
	{
	case '+':
		++c[cell];
		break;
	case '-':
		--c[cell];
		break;
	case '>':
		++cell;
		break;
	case '<':
		--cell;
		break;
	case '.':
		putchar(c[cell]);
		break;
	case ',':
		c[cell] = _getch();
		break;

	default:break;
	}

}

//brainfuck入口函数 string 指令，int 指令长度， 是否开启内存跟踪
void bfmain(std::string code, int codelength, bool showmem = false)
{


	int ctlposi = 0;

	while (ctlposi < codelength)
	{
		//内存跟踪
		if (showmem)
		{
			printmem(c);
			system("pause>nul");
		}


		bfmainnocir(code[ctlposi]);


		if (code[ctlposi] == '[' && c[cell] == 0)
		{
			int layer = 1;

			while (layer)
			{
				ctlposi++;
				if ('[' == code[ctlposi])
				{
					++layer;
				}
				if (']' == code[ctlposi])
				{
					--layer;
				}
			}

			ctlposi--;
		}

		if (code[ctlposi] == ']' && c[cell] != 0)
		{
			int layer = 1;

			while (layer)
			{
				ctlposi--;
				if (']' == code[ctlposi])
				{
					++layer;
				}
				if ('[' == code[ctlposi])
				{
					--layer;
				}
			}

		}

		ctlposi++;
	}

}

