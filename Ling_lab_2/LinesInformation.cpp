#include "LinesInformation.h"
#include <iostream>
#include <iomanip>
#include "SprialGeneration.h"

void LinesInformation::DrawALine(vector<vector<int>> spiral) {
	cout << formula << endl << "Количество простых чисел: " << numberOfPrimes << endl;
	if (isHorizontal) {
		for (int i = 0; i < spiral.size(); i++)
			for (int j = 0; j < spiral.size(); j++) {
				if (i == numberOfColumn) {
					if (isPrime(spiral[i][j]))
						SetColor(ConsoleColor::Red, ConsoleColor::Black);
					else
						SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
					cout << setw(3) << spiral[i][j] << ' ';
					SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
				}

			}

		cout << endl << endl;
	}
	
	else {
		for (int i = 0; i < spiral.size(); i++)
			for (int j = 0; j < spiral.size(); j++) {
				if (j == numberOfRow) {
					if (isPrime(spiral[i][j]))
						SetColor(ConsoleColor::Red, ConsoleColor::Black);
					else
						SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
					cout << setw(3) << spiral[i][j] << ' ' << endl;
					SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
				}
			}

		cout << endl;
	}
}
