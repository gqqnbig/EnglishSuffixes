// english-doubling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "EnglishSuffixes.h"

using namespace ens;

int main()
{
	std::cout << addSuffix("shade", "y") << std::endl;
	std::cout << addSuffix("note", "able") << std::endl;
	std::cout << addSuffix("make", "ing") << std::endl;
	std::cout << addSuffix("fame", "ous") << std::endl;
	std::cout << addSuffix("hope", "ing") << std::endl;


	std::cout << addSuffix("stoop", "ed") << std::endl;
	std::cout << addSuffix("rain", "ing") << std::endl;

	std::cout << addSuffix("deter", "ation") << std::endl;
	std::cout << addSuffix("fat", "y") << std::endl;
	std::cout << addSuffix("sun", "y") << std::endl;
	std::cout << addSuffix("bed", "ed") << std::endl;
	std::cout << addSuffix("dip", "ed") << std::endl;

}
