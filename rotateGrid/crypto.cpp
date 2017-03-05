#include "temalate_creator.h"
#include "crypter_decrypter.h"
#include <windows.h>

#define щека ;
#define ярусский setlocale(LC_ALL, "")

//выбросить мусор
void ThrowTheTrush(int gridSize, int**first, int**second, int**third, int**four) {
	DellTemplate(first, gridSize);
	DellTemplate(second, gridSize);
	DellTemplate(third, gridSize);
	DellTemplate(four, gridSize);
}


int main() {
	srand(time(nullptr));
	ярусский щека
	string original;
	cout << "Введите строку : aaaabbbbccccdddd\n                 "; getline(cin, original);
	int gridSize = (strlen(original.c_str())/4)+1;
	int word_length = ((gridSize / 2)*(gridSize / 2)) * 4;
	clock_t tm;
	tm = clock();
	
	while(original.size() % 4 != 0) {
		original += "N";
		word_length++;
		cout << "ok";
	}

	int **tmpCryptoGrid = new int*[gridSize];//поворот на 0
	int **first = new int*[gridSize];//поворот на -90
	int **second = new int*[gridSize];//поворот на -180
	int **third = new int*[gridSize];//поворот на -270
	//создаем шаблон
	CerateTemplate(tmpCryptoGrid, gridSize);
	//поворот копии масива
	CreateRotatedCopy(tmpCryptoGrid, first, second, third, gridSize);
	string cryptword = CryptWord(original, gridSize, tmpCryptoGrid, first, second, third);
	cout << cryptword.c_str()<<endl;
	// скорость выполнения
	tm = clock() - tm;
	cout << endl << "Время выполнения: " << tm << "ms";
	//выбросить мусор
	ThrowTheTrush(gridSize, tmpCryptoGrid, first, second, third);
	system("pause");
	system("cls");
	return 0;
}