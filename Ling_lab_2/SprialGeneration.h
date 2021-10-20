#pragma once

enum class ConsoleColor
{
    Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray
};

void SetColor(ConsoleColor text, ConsoleColor background);
bool isPrime(int n);
void SpiralGenerator(int columnVector);