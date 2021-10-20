#pragma once
#include <string>
#include <vector>

using namespace std;

class LinesInformation
{
	public:
		string formula = "";
		int numberOfPrimes = 0;
		bool isHorizontal = false;
		int numberOfRow = -1, numberOfColumn = -1;

		void DrawALine(vector<vector<int>> spiral);
};

