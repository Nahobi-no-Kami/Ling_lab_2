#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include "SprialGeneration.h"
#include "NumbersProcessing.h"

using namespace std;

void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((static_cast<int>(background) << 4) | static_cast<int>(text)));
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void SpiralGenerator(int spiralSize) {
        system("cls");
        cout << "Полученная спираль (Красным выделены простые числа): " << endl;
        SetColor(ConsoleColor::LightGray, ConsoleColor::Black);

        vector<vector<int>> spiralVectorColumns(spiralSize, vector<int>(spiralSize));

        int i = 0, j = spiralSize - 1;

        int spiralValue = spiralSize * spiralSize;

        while (spiralSize != 0)
        {
            int k = 0;
            do { 
                spiralVectorColumns[i][j--] = spiralValue--; 
            }
            while (++k < spiralSize - 1);
            for (k = 0; k < spiralSize - 1; k++) 
                spiralVectorColumns[i++][j] = spiralValue--;
            for (k = 0; k < spiralSize - 1; k++) 
                spiralVectorColumns[i][j++] = spiralValue--;
            for (k = 0; k < spiralSize - 1; k++) 
                spiralVectorColumns[i--][j] = spiralValue--;
            ++i; 
            --j; 
            spiralSize = spiralSize < 2 ? 0 : spiralSize - 2;
        }

       
        for (const auto& spiralVectorRows : spiralVectorColumns)
        {
            SetColor(ConsoleColor::Green, ConsoleColor::Black);
            cout << " | ";
            SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
            for (int x : spiralVectorRows) {
                if (isPrime(x))
                    SetColor(ConsoleColor::Red, ConsoleColor::Black);
                cout << setw(3) << x << ' ';
                SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
                

            }
            cout << endl;
        }
        for (int i = 0; i < spiralVectorColumns.size()*5; i++) {
            if (i >= 2) {
                SetColor(ConsoleColor::Green, ConsoleColor::Black);
                cout << '—';
                SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
            }
            else
                cout << " ";
        }
        SetColor(ConsoleColor::Green, ConsoleColor::Black);
        cout << "->" << endl;
        SetColor(ConsoleColor::LightGray, ConsoleColor::Black);
        
        OnlyPrimalSpiral(spiralVectorColumns);
}