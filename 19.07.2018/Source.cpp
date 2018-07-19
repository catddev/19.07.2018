#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			const int n = 5, m = 4, l = 3;
			int a[5][4][3];
			int i, j, k;
			int sum = 0;
			int maxsum = INT_MIN;
			int index = 0;

			for (i = 0; i < n; i++)
			{
				sum = 0;
				for (j = 0; j < n; j++)
				{
					for (k = 0; k < n; k++)
					{
						a[i][j][k] = rand() % 21;
						cout << a[i][j][k] << " ";
						sum += a[i][j][k];
					}
					cout << endl;
				}
				cout << endl << sum << endl;
				maxsum = sum > maxsum ? sum : maxsum;
				if (maxsum) index = i;
				cout << "__________________" << endl;
			}
			cout << maxsum << " index: " << i << endl << endl;

		}
		break;
		case 2:
		{
			const int n = 5, m = 5, l = 5;
			int a[5][4][3];
			int i, j=0, k=0;

			for (i = 0; i < n; i++)
			{
				cout << "matrix " << i << endl << endl;
				for (j = 0; j < n; j++)
				{
					for (k = 0; k < n; k++)
					{
						a[i][j][k] = rand() % 21;
						if (j == k || j + k == l - 1)
							cout << right << setw(3) << a[i][j][k] << " ";
						else cout << right << setw(3) << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		break;
		case 3:
		{
			// 8.	***Сжать(сдвинуть элементы) массив, удалив из него все 0, и заполнить освободившиеся справа элементы значениями -1

			const int n = 8;
			int a[n] = { 2, 3, 0, 0, 0, 0, 1, 5};
			int i;
			
			for (i = 0; i < n-1; i++)
			{
				for (int j = 0; j < n-1; j++)
				{
					if (a[j] == 0)
					{
						swap(a[j], a[j + 1]);
					}
				}
			}
			for (i = 0; i < n; i++)
			{
				if (a[i] == 0) a[i] = -1;
			}

			for (i = 0; i < n; i++)
				cout << a[i] << " ";
			cout << endl << endl;
		}
		break;
		case 4:
		{
			/*40.	***Создайте двухмерный массив.Заполните его случайными числами и покажите на экран.Выполните сортировку массива.Полученный результат покажите на экран.
			Пример: пусть у нас есть массив
				2 8 4
				0 1 9
				7 8 3
				4 5 6
			После сортировки получим :
				0 1 2
				3 4 4
				5 6 7
				8 8 9 */

			int a[100][100];
			const int n = 5;
			int i, j;
			/*int b[n*n];*/

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					a[i][j] = rand() % 50;
					cout << left << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					for (int pass = 0; pass < n - 1; pass++)
					{
						if (a[i][pass] > a[i][pass + 1])
							swap(a[i][pass], a[i][pass + 1]);

						if (a[i][pass] < a[i - 1][n - 1])
						{
							swap(a[i][pass], a[i - 1][n - 1]);
							i--;
						}
					}
				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					cout << left << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
		break;
		case 5:
		{
			/*46.	***Написать программу «Подсчет единичных островов».Заполнить двухмерный массив 12х12 0 и 1. 0 – это вода, 1 – это земля.
				Воды должно быть в три раза больше, чем земли.Необходимо посчитать количество единичных островов
				Единичным островом считается 1, окруженная  со всех сторон 0.
				11000
				00010
				10000
				Примечание: единичный остров, стоящий на углу, не будет окружен водой со всех сторон,
				учтите это при проверке, чтобы не выйти за пределы массива.*/

			const int n = 12;
			int a[n][n];
			int i, j;
			int island = 0;
			int zero = 0;
			int one = 0;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					a[i][j] = rand() % 2;
					if (a[i][j] == 0) zero++;
					else one++;
				}
			}

			while (one >(n*n) / 4)
			{
				i = rand() % 12;
				j = rand() % 12;
				if (a[i][j] == 1)
				{
					a[i][j] = 0;
					one--;
				}
			}

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "координаты островов:" << endl;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (i != 0 && i != n - 1 && j != 0 && j != n - 1)
						if (a[i][j] == 1)
							if (a[i - 1][j - 1] == 0 && a[i - 1][j + 1] == 0 && a[i - 1][j] == 0 && a[i][j - 1] == 0 && a[i][j + 1] == 0 && a[i + 1][j - 1] == 0 && a[i + 1][j + 1] == 0 && a[i + 1][j] == 0)
							{
								island++;
								cout << i << ", " << j << endl;
							}
				}
			}
			cout << endl << "Единичных островов " << island << endl << endl;
		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{

		}
		break;
		case 10:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}