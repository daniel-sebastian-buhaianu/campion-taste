#include <fstream>
#define INFINIT 2000000000 // 2B
using namespace std;
struct Punct { int x, y; };
Punct t[10];
int calorii(int, int);
void retineTaste(int, int, char*);
int main()
{
	ifstream f("taste.in");
	for (int i = 0; i <= 9; i++)
		f >> t[i].x >> t[i].y;
	char ora[5];
	f >> ora;
	f.close();
	int hh = (ora[0]-'0')*10 + ora[1]-'0';
	int mm = (ora[2]-'0')*10 + ora[3]-'0';
	int cmin = INFINIT;
	char taste[5];
	for (int i = 0; i <= (99-hh)/24; i++)
	{
		int h = 24*i + hh;
		int ch = calorii(h/10, h%10);
		for (int j = 0; j <= (99-mm)/60; j++)
		{
			int m = 60*j + mm;
			int cm = calorii(h%10, m/10)
			         + calorii(m/10, m%10);
			if (ch+cm < cmin)
			{
				cmin = ch+cm;
				retineTaste(h, m, taste);
			}
		}
	}
	ofstream g("taste.out");
	g << cmin << '\n' << taste;
	g.close();
	return 0;
}
void retineTaste(int h, int m, char* t)
{
	t[0] = '0' + h/10;
	t[1] = '0' + h%10;
	t[2] = '0' + m/10;
	t[3] = '0' + m%10;
	t[4] = 0;
}
int abs(int x)
{
	return x >= 0 ? x : x*(-1);
}
int calorii(int a, int b)
{
	int x = t[a].x - t[b].x;
	int y = t[a].y - t[b].y;
	return abs(x) + abs(y);
}
