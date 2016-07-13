
using std::cout;
using std::endl;
using std::cin;
using std::string;

void printmem(char mem[], int memsize = 15)
{
	cout << endl;

	for (int i = 0; i < memsize; i++)
	{
		int a = mem[i];
		cout << a << " ";
	}

	cout << endl << endl;
}