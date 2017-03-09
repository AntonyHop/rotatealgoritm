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
	int gridSize;
	cout << "Введите размерность шифровального масива:";
	cin >> gridSize;
	cin.get();
	cout << "Введите строку :\n";
	int word_length = ((gridSize / 2)*(gridSize / 2)) * 4;
	for (int i = 0; i < word_length; i++) {
		cout << "a";
	}
	cout <<endl;
	getline(cin, original);
	
	clock_t tm;
	tm = clock();
	if (original.size() <= word_length) {
		//Заполняем недостающие символы
		while (original.size() <= word_length) {
			original += ' ';
		}

		//Выделяем память под масивы
		int **tmpCryptoGrid = new int*[gridSize];//поворот на 0
		int **first = new int*[gridSize];//поворот на -90
		int **second = new int*[gridSize];//поворот на -180
		int **third = new int*[gridSize];//поворот на -270
		//создаем шаблон
		CerateTemplate(tmpCryptoGrid, gridSize);
		//поворот копии масива
		CreateRotatedCopy(tmpCryptoGrid, first, second, third, gridSize);
		string cryptword = CryptWord(original, gridSize, tmpCryptoGrid, first, second, third);
		cout << "Шифровка:\n";
		cout << cryptword.c_str() << endl;
		string decryptword = DeCryptWord(cryptword, gridSize, tmpCryptoGrid, first, second, third);
		cout << "Розшифровка:\n";
		cout << decryptword.c_str() << endl;
		// скорость выполнения
		tm = clock() - tm;
		cout << endl << "Время выполнения: " << tm << "ms";
		//выбросить мусор
		ThrowTheTrush(gridSize, tmpCryptoGrid, first, second, third);
	}
	else{
		system("cls");
		cout << "Вы привысили лимит на количество символов попробуйте задать большую розмерность\n";
		return main();
	}
	cin.get();
	return 0;
}