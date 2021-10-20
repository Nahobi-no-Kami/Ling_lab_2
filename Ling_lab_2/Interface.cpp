#include <iostream>
#include <iomanip>
#include <vector>
#include "InterfaceInteraction.h"

enum Chouce { BackToMenu = 1, Exit };

using namespace std;

void MainMenu() {
	cout << "--------------------------------------------\n";
	cout << "--------------Добро пожаловать--------------\n";
	cout << "-------Для продолжения введите номер--------\n";
	cout << "-------Пункта меню и нажмите клавишу--------\n";
	cout << "------------------\"Enter\"-------------------\n";
	cout << "--------------------------------------------\n";
	cout << "--------------------Меню--------------------\n";
	cout << "------------   1. О программе   ------------\n";
	cout << "--------   2. Отрисовка спирали    ---------\n";
	cout << "---------------   3. Выход   ---------------\n";
	cout << "--------------------------------------------\n\n";
	cout << "Ваш выбор : ";
}

void AboutMenu() 
{
	cout << "--------------------------------------------\n";
	cout << "Данная программа предназначена для \n";
	cout << "отображения чисел определенным способом и поиска \n";
	cout << "простых чисел в нем\n";
	cout << "--------------------------------------------\n";
}

bool MenuOrExit() {
	int userChoice;
	cout << endl << "Вернуться в меню или выйти из программы?" << endl;
	cout << "1. Вернуться в меню" << endl;
	cout << "2. Выйти из программы" << endl;
	cin >> userChoice;
	userChoice = Check(userChoice);
	if (userChoice == BackToMenu)
		return false;
	else if (userChoice == Exit)
		return true;
	else {
		cout << "Некорректный ввод. Попробуйте еще раз" << endl;
		MenuOrExit();
	}
}
