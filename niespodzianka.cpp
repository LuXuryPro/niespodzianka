#include<iostream>
#include<vector>
#include<string>
// sprawdzanie czy dane ciagi sa permutacjami

int main()
{
	std::string first;
	std::string second;
	std::cin >> first;
	std::cin >> second;

	if (first.size() != second.size())
	{
		std::cout<< "Wynik: false"<<std::endl;
		return 0;
	}
	for (int i = 0; i < first.size(); ++i)
	{
		size_t index2 = second.find(first[i]);
		if (index2 != std::string::npos)
			second.replace(index2, 1, "\0");
		else
		{
			std::cout<< "Wynik: false"<<std::endl;
			return 0;
		}
	}
	std::cout<< "Wynik: true" <<std::endl;
	return 0;
}
