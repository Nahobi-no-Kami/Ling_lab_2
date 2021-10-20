#include <iostream>
#include <fstream>
#include <string>
#include "InterfaceInteraction.h"
#include "Interface.h"
#include "SprialGeneration.h"

using namespace std;

enum userChoice { About = 1, Spiral, Exit, Yes = 1, No, Minsize = 3, Maxsize = 100 };

int Menu()
{

	int menuOption;
	while (true)
	{
		SetColor(ConsoleColor::LightGray, ConsoleColor::Black);

		MainMenu();

		menuOption = 0;

		while (true) {
			cin >> menuOption;
			menuOption = Check(menuOption);
			if (menuOption < About || menuOption > Exit) {
				cout << "�������� ����� ����. ���������� ��� ���: ";
				continue;
			}
			break;
		}

		switch (menuOption) {
		case About: {
			system("cls");
			AboutMenu();
			if (MenuOrExit())
				return(0);
			system("cls");
			break;
		}

		case Spiral: {
			string text;
			cout << "������� ������ ������� (�� 3, �� 100) � ������� ������ \"Enter\": ";
			int size;
			
			while (true)
			{
				cin >> size;
				size = Check(size);
				if (size >= Minsize && size <= Maxsize)
					break;
				else {
					cout << "������������ ������. ���������� ��� ���! ������� �����: ";
				}
					 
			}
			size = Check(size);
			SpiralGenerator(size);
			if (MenuOrExit())
				return(0);
			system("cls");
			break;
		}
		case Exit:
			return 0;
		}

	}

}

int Check(int userChoice) {


	while (cin.fail()) {
		if (userChoice <= 0) {
			cout << "������������ ����. ���������� ��� ���." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			userChoice = 0;
			cin >> userChoice;
		}
	}
	return (userChoice);
}
