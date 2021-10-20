#include <iostream>
#include <iomanip>
#include <vector>
#include "InterfaceInteraction.h"

enum Chouce { BackToMenu = 1, Exit };

using namespace std;

void MainMenu() {
	cout << "--------------------------------------------\n";
	cout << "--------------����� ����������--------------\n";
	cout << "-------��� ����������� ������� �����--------\n";
	cout << "-------������ ���� � ������� �������--------\n";
	cout << "------------------\"Enter\"-------------------\n";
	cout << "--------------------------------------------\n";
	cout << "--------------------����--------------------\n";
	cout << "------------   1. � ���������   ------------\n";
	cout << "--------   2. ��������� �������    ---------\n";
	cout << "---------------   3. �����   ---------------\n";
	cout << "--------------------------------------------\n\n";
	cout << "��� ����� : ";
}

void AboutMenu() 
{
	cout << "--------------------------------------------\n";
	cout << "������ ��������� ������������� ��� \n";
	cout << "����������� ����� ������������ �������� � ������ \n";
	cout << "������� ����� � ���\n";
	cout << "--------------------------------------------\n";
}

bool MenuOrExit() {
	int userChoice;
	cout << endl << "��������� � ���� ��� ����� �� ���������?" << endl;
	cout << "1. ��������� � ����" << endl;
	cout << "2. ����� �� ���������" << endl;
	cin >> userChoice;
	userChoice = Check(userChoice);
	if (userChoice == BackToMenu)
		return false;
	else if (userChoice == Exit)
		return true;
	else {
		cout << "������������ ����. ���������� ��� ���" << endl;
		MenuOrExit();
	}
}
