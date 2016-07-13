#include <conio.h>
#include "memprt.h"
/*
*   -------------------------------------------�Ҳ��ò��̴�һ����
*   ctlcode �� brainfuck ���Բ������Ķ�Ӧ��ϵ
*
*	+  0	ֵ+1
*	-  1	ֵ-1
*	>  2	ָ��+1
*	<  3	ָ��-1
*	.  4	���ָ��ָ��Ԫ���ݣ�ASCII��
*	,  5	���뵽ָ��ָ��Ԫ��ASCII��
*	[  6	ifָ��ָ��Ԫֵ=0����ת����һ]��
*	]  7	ifָ��ָ��Ԫֵ!=0����ת��ǰһ[��
*/

//���鳤��
const int charlength = 18000;


//ָ��
int cell = 0;
//����
char c[charlength];

//�����ʼ��
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

//brainfuck��ں��� string ָ�int ָ��ȣ� �Ƿ����ڴ����
void bfmain(std::string code, int codelength, bool showmem = false)
{


	int ctlposi = 0;

	while (ctlposi < codelength)
	{
		//�ڴ����
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

