#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int maxJump(int _n, int _distance)
{	
	std::vector<int> stoneArray;
	stoneArray.push_back(0); // Left bank init
	stoneArray.push_back(0);
	for (size_t i = 1; i <= _n; i++)
	{
		std::string stone;
		std::stringstream ss;
		char separate = '-';
		std::vector<std::string> stoneInfo;
		std::cin >> stone;
		ss << stone;
		while (std::getline(ss, stone, separate))
		{
			stoneInfo.push_back(stone);
		}
		if (stoneInfo[0] == "S" || stoneInfo[0] == "s")
		{
			stoneArray.push_back(stoi(stoneInfo[1]));
		}
		else if (stoneInfo[0] == "B" || stoneInfo[0] == "b")
		{
			stoneArray.push_back(stoi(stoneInfo[1]));
			stoneArray.push_back(stoi(stoneInfo[1]));
		}
	}
	stoneArray.push_back(_distance); // Right bank init
	stoneArray.push_back(_distance);
	std::cout << "Stones: ";
	for (std::vector<int>::iterator it = stoneArray.begin(); it != stoneArray.end(); ++it)
	{
		std::cout << *it << ' ';
	}

	int maxJump = 0;
	//Greedy Algorithm
	for (size_t i = 0; i < stoneArray.size()-2; i+=2) // jump-> even stones
	{
		if (stoneArray[i + 2] - stoneArray[i] > maxJump)
			maxJump = stoneArray[i + 2] - stoneArray[i];
	}

	if (stoneArray.size() % 2 != 0)
	{
		for (size_t i = stoneArray.size() - 2; i > 1; i -= 2) // <-jump odd stones (-1)
		{
			if (stoneArray[i] - stoneArray[i - 2] > maxJump)
				maxJump = stoneArray[i] - stoneArray[i - 2];
		}
	}
	else 
		for (size_t i = stoneArray.size() - 1; i > 1; i -= 2) // <-jump odd stones (+1)
		{
			if (stoneArray[i] - stoneArray[i - 2] > maxJump)
				maxJump = stoneArray[i] - stoneArray[i - 2];
		}

	return maxJump;
}

int main()
{
	int tests;
	std::cout << "Enter tests amount: \n";
	std::cin >> tests;
	for (size_t i = 1; i <= tests; ++i)
	{
		int n, distance;
		std::cin >> n >> distance;
		std::cout << "\nCase "<< i <<": " << maxJump(n, distance) << '\n';
	}


	std::cin.get();
}