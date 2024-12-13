#include <vector>
#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int rebro, versh, k = 0;
	bool flag = false;
	cout << "Ââåäèòå êîë-âî âåðøèí â íåîðèåíòèðîâàííîììóëüòèãðàôå: ";
	cin >> versh;
	cout << endl << "Ââåäèòå êîë-âî ðåáåð â íåîðèåíòèðîâàííîììóëüòèãðàôå: ";
	cin >> rebro;
	vector<vector<int>> matricaINC(versh, vector<int>(rebro));
	do {
		flag = false;
		cout << endl << "Çàïîëíèòå ìàòðèöó èíöèäåíòíîñòè: " << endl << "   ";
		for (int i = 0; i < rebro; i++)
			cout << 'R' << i + 1 << " ";
		for (int i = 0; i < versh; i++) {
			cout << endl << 'V' << i + 1 << ' ';
			for (int j = 0; j < rebro; j++) {
				cin >> matricaINC[i][j];
				if (matricaINC[i][j] != 0 && matricaINC[i][j] != 1) {
					cout << "ýòî íå ìàòðèöà èíöèäåíòíîñòè ìóëüòèãðàôà";
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
						cout << "ýòî íå ìàòðèöà èíöèäåíòíîñòè ìóëüòèãðàôà";
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
		} while (flag);
		cout << endl << "Ñïèñîê èíöèäåíòíîñòè ïî ð¸áðàì è èõ ñòåïåíè:";
		cout << endl<<"Ð¸áðà" << " " << "Âåðøèíû" << " Ñòåïåíè";
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
