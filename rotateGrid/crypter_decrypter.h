#include <string>

#pragma once
string CryptWord(string original, int gridSize, int **first, int **second, int **third, int **four) {
	int word_length = strlen(original.c_str());
	int i = 0;
	string first_part;
	string second_part;
	string third_part;
	string four_part;
	string result;

	//cout << word_length<<endl;
	for (int i = 0; i < 1*(word_length/4); i++) {
		first_part += original[i];
	}
	//cout << first_part << endl;

	for (int i = 1 * (word_length / 4); i < 2 * (word_length / 4); i++) {
		second_part += original[i];
	}
	//cout << second_part << endl;

	for (int i = 2 * (word_length / 4); i < 3 * (word_length / 4); i++) {
		third_part += original[i];
	}
	//cout << third_part << endl;

	for (int i = 3 * (word_length / 4); i < 4 * (word_length / 4); i++) {
		four_part += original[i];
	}
	//cout << four_part << endl;
	//ShowGrid(first,gridSize);
	int counter = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if(first[i][j] == 0 && counter<  first_part.size()){
				result += first_part [counter];
				//cout << counter << " " << first_part[counter] <<" " << first_part.size()<< endl;
				counter++;
			}
			else {
				result += char(97 + rand() % 122);
			}
		}
	}

	counter = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (second[i][j] == 0 && counter<  second_part.size()) {
				result += second_part[counter];
				//cout << counter << " " << second_part[counter] << " " << second_part.size() << endl;
				counter++;
			}
			else {
				result += char(97 + rand() % 122);
			}
		}
	}
	counter = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (third[i][j] == 0 && counter<  third_part.size()) {
				result += third_part[counter];
				//cout << counter << " " << third_part[counter] << " " << third_part.size() << endl;
				counter++;
			}
			else {
				result += char(97 + rand() % 122);
			}
		}
	}
	counter = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (four[i][j] == 0 && counter<  four_part.size()) {
				result += four_part[counter];
				//cout << counter << " " << four_part[counter] << " " << four_part.size() << endl;
				counter++;
			}
			else {
				result += char(97 + rand() % 122);
			}
		}
	}
	return result;
}


string DeCryptWord(string original, int gridSize, int **first, int **second, int **third, int **four) {
	string result;
	string first_part;
	string second_part;
	string third_part;
	string four_part;

	for (int i = 0; i < 1*(original.size()/4); i++) {
		first_part+= original[i];
	}
	int counter = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if(first[i][j] == 0 && counter<  first_part.size()){
				result += first_part [counter];
				//cout << counter << " " << first_part[counter] <<" " << first_part.size()<< endl;
			}
			counter++;
		}
	}
	for (int i = 1*(original.size()/4); i < 2*(original.size()/4); i++) {
		second_part+= original[i];
	}
	counter = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if(second[i][j] == 0 && counter<  second_part.size()){
				result += second_part [counter];
				//cout << counter << " " << second_part[counter] <<" " << second_part.size()<< endl;
			}
			counter++;
		}
	}

	for (int i = 2*(original.size()/4); i < 3*(original.size()/4); i++) {
		third_part+= original[i];
	}
	counter = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if(third[i][j] == 0 && counter<  third_part.size()){
				result += third_part [counter];
				//cout << counter << " " << third_part[counter] <<" " << third_part.size()<< endl;
			}
			counter++;
		}
	}

	for (int i = 3*(original.size()/4); i < 4*(original.size()/4); i++) {
		four_part+= original[i];
	}
	counter = 0;
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if(four[i][j] == 0 && counter<  four_part.size()){
				result += four_part [counter];
				//cout << counter << " " << four_part[counter] <<" " << four_part.size()<< endl;
			}
			counter++;
		}
	}
	cout << endl;
	return result;
}
