#include <iostream>
using namespace std;
#include <string>
int res[99999], a[99999], b[99999];
int main()
{
	int dot, num;
	int n;
	int i, j;
	string str;
	int lena, lenb;
	while (cin >> str >> n)
	{
		if (n >= 1)
		{
			num = n;
			n--;
			memset(res, 0, sizeof(res));
			memset(a, 0, sizeof(a));
			memset(b, 0, sizeof(b));
			lena = lenb = 5;
			for (i = lena, j = 1; i >= 0; i--)
			{
				if (str[i] == '.')
				{
					dot = i;
				}
				else
				{
					a[j] = str[i] - '0';
					b[j] = a[j];
					j++;
				}
			}

			while (n--)
			{
				for (i = 1; i <= lena; i++)
				{
					for (j = 1; j <= lenb; j++)
					{
						res[i + j - 1] += b[j] * a[i];
						if (res[i + j - 1] > 9)
						{
							res[i + j] += res[i + j - 1] / 10;
							res[i + j - 1] %= 10;
						}
					}
				}
				lena = lena + lenb;
				for (i = 1; i <= lena; i++)
				{
					a[i] = res[i];
					if (n != 0)
						res[i] = 0;
				}
			}
			dot = 5 - dot;
			dot = num * dot;

			for (i = lena; i > dot; i--)
			{
				if (a[i] != 0)
					break;
			}

			for (j = 1; j <= dot; j++)
			{
				if (a[j] != 0)
					break;
			}

			for (i; i >= j; i--)
			{
				if (i == dot)
					cout << ".";
				cout << a[i];
			}

		}
		cout << endl;
	}
	return 0;
}
