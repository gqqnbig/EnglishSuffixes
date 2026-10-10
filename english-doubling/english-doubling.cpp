// english-doubling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> 
#include <format>

#include "EnglishSuffixes.h"

using namespace ens;

int main()
{

	try {

		std::ifstream dataset(R"(D:\english-doubling\verbs.csv)", std::ios::in);
		dataset.exceptions(std::ios::badbit);


		size_t total = 0;
		size_t ingPass = 0;
		size_t edPass = 0;
		std::string word;
		std::getline(dataset, word); // skip the header line
		while (std::getline(dataset, word, ','))
		{
			std::string baseForm{ word };

			std::getline(dataset, word, ',');
			std::string presentParticiple{ word };

			std::getline(dataset, word);
			std::string simplePast{ word };

			std::string n = ens::addSuffix(baseForm, "ing");
			if (n == presentParticiple)
				ingPass++;
			else
				std::cout << std::format("{} + ing. Expected {}. Actual {}", baseForm, presentParticiple, n) << std::endl;

			//n=ens::addSuffix(baseForm,"ed");

			//std::cout << baseForm << ", " << presentParticiple << ", " << simplePast << std::endl;
			total++;
		}
		dataset.close();

		std::cout << std::format("Total {} words. Pass {}. %= {:.3f}", total, ingPass, double(ingPass) / total) << std::endl;
	}
	catch (const std::ios_base::failure& ex)
	{
		char* buf = new char[30];
		strerror_s(buf, 30, errno);
		std::cerr << std::format("Failed to read because {}", ex.what());
		if (buf[0] != '\0')
			std::cerr << " (" << buf << ")";
		std::cerr << "." << std::endl;
		delete[] buf;
		return 0;
	}
}
