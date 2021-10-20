#include "NumbersProcessing.h"
#include <iostream>
#include <vector>
#include <queue>
#include "SprialGeneration.h"
#include "LinesInformation.h"
#include "SprialGeneration.h"
#include "InterfaceInteraction.h"

using namespace std;

bool PredicateSort(LinesInformation a, LinesInformation b) {
	return a.numberOfPrimes < b.numberOfPrimes;
}


void OnlyPrimalSpiral(vector<vector<int>> spiral) 
{
	int sizeOfSpiral = spiral.size(), numberOfLines;
	vector<LinesInformation> linesWithMostPrimals;
	SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
	cout << "Введите количество линий, которые необходимо напечатать: ";
	cin >> numberOfLines;
	numberOfLines = Check(numberOfLines);
	while (true) {
		if (numberOfLines >= 2 * sizeOfSpiral || numberOfLines <= 0) {
			cout << "Некорректное число. Попробуйте еще раз: ";
			cin >> numberOfLines;
			numberOfLines = Check(numberOfLines);
			continue;
		}
		break;
	}

	linesWithMostPrimals.resize(numberOfLines);

	int numberOfPrimesInSpiral;

	//По горизонтали;
	int i, j, filledLines = 0;

	for (i = 0; i < sizeOfSpiral; i++) {
		numberOfPrimesInSpiral = 0;
		for (j = 0; j < sizeOfSpiral; j++)
		{
			if (isPrime(spiral[i][j]))
				numberOfPrimesInSpiral++;
		}
		if (filledLines < numberOfLines) {
			for (auto& elem : linesWithMostPrimals)

				if (elem.numberOfPrimes == 0) {
					elem.numberOfPrimes = numberOfPrimesInSpiral;
					elem.isHorizontal = true;
					elem.numberOfColumn = i;
					elem.numberOfRow = j;
					filledLines++;
					break;
				}
		}
		else {
			sort(linesWithMostPrimals.begin(), linesWithMostPrimals.end(), PredicateSort);		
			for (auto& elem : linesWithMostPrimals)

				if (elem.numberOfPrimes < numberOfPrimesInSpiral) {
					elem.numberOfPrimes = numberOfPrimesInSpiral;
					elem.isHorizontal = true;
					elem.numberOfColumn = i;
					elem.numberOfRow = j;
					break;
				}

		}
	
	}

	//По вертикали
	for (i = 0; i < sizeOfSpiral; i++) {
		numberOfPrimesInSpiral = 0;
		for (j = 0; j < sizeOfSpiral; j++)
		{
			if (isPrime(spiral[j][i]))
				numberOfPrimesInSpiral++;
		}
		if (filledLines < numberOfLines) {
			for (auto& elem : linesWithMostPrimals)

				if (elem.numberOfPrimes == 0) {
					elem.numberOfPrimes = numberOfPrimesInSpiral;
					elem.isHorizontal = false;
					elem.numberOfColumn = j;
					elem.numberOfRow = i;
					filledLines++;
					break;
				}
		}
		else {
			sort(linesWithMostPrimals.begin(), linesWithMostPrimals.end(), PredicateSort);
			for (auto& elem : linesWithMostPrimals)

				if (elem.numberOfPrimes < numberOfPrimesInSpiral) {
					elem.numberOfPrimes = numberOfPrimesInSpiral;
					elem.isHorizontal = false;
					elem.numberOfColumn = j;
					elem.numberOfRow = i;
					break;
				}

		}

	}

	for (auto& elem : linesWithMostPrimals) {
		if (elem.isHorizontal)
			elem.formula = "Уравнение прямой линии: y = " + to_string(elem.numberOfColumn+1);
		else 

			elem.formula = "Уравнение прямой линии: x = " + to_string(elem.numberOfRow+1);
	}

	for (auto& elem : linesWithMostPrimals)
		elem.DrawALine(spiral);
	
}
