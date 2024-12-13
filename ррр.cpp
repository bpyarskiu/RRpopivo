#include <vector>
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int rebro, versh, k = 0;
	bool flag = false;
	cout << "Введите кол-во вершин в неориентированноммультиграфе: ";
	cin >> versh;
	cout << endl << "Введите кол-во ребер в неориентированноммультиграфе: ";
	cin >> rebro;
	vector<vector<int>> matricaINC(versh, vector<int>(rebro));
	do {
		flag = false;
		cout << endl << "Заполните матрицу инцидентности: " << endl << "   ";
		for (int i = 0; i < rebro; i++)
			cout << 'R' << i + 1 << " ";
		for (int i = 0; i < versh; i++) {
			cout << endl << 'V' << i + 1 << ' ';
			for (int j = 0; j < rebro; j++) {
				cin >> matricaINC[i][j];
				if (matricaINC[i][j] != 0 && matricaINC[i][j] != 1) {
					cout << "это не матрица инцидентности мультиграфа";
					flag = true;
					break;
				}
			}
		}
			for (int m = 0; m < versh-1; m++) {
				for (int j = 0; j < rebro; j++) {
					k = 0;
					for (int i = m + 1; i < versh; i++)
						if (matricaINC[m][j] == matricaINC[i][j] && matricaINC[m][j] == 1)
							k++;
					if (k >= 2) {
						cout << "это не матрица инцидентности мультиграфа";
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
		} while (flag);
		cout << endl << "Список инцидентности по рёбрам и их степени:";
		cout << endl<<"Рёбра" << " " << "Вершины" << " Степени";
		vector<int> stepeni(versh);
		for (int i = 0; i < versh; i++)
			stepeni[i] = 0;
		for (int j = 0; j < versh; j++)
			for (int i = 0; i < rebro; i++)
				if (matricaINC[j][i] == 1)
					stepeni[j]++;
		for (int j = 0; j < rebro; j++) {
			cout << endl<<"R" << j+1 << "      ";
			flag = false;
			for (int m = 0; m < versh-1; m++) {
				for (int i = m + 1; i < versh; i++)
					if (matricaINC[m][j] == matricaINC[i][j] && matricaINC[m][j] == 1) {
						cout << 'V' << m+1 << ", " << 'V' << i+1<<"	   "<<stepeni[m] * stepeni[i];
						flag = true;
						break;
					}
				if (flag)
					break;
			}
		}
		return -105;
	}
