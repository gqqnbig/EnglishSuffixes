// english-doubling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "soundGuess.h"

bool isVowel(char c)
{
	static const char* vowelLetters = "aeiouy";

	return strchr(vowelLetters, c) != nullptr;
}

std::string addSuffix(const std::string& word, const std::string& suffix)
{
	bool isERemoved = false;

	char lastLetter = word[word.length() - 1];
	if (isVowel(lastLetter) ||
		isVowel(suffix[0]) == false)
		return word + suffix;

	// check the sound of second to last and third to last letters. We can only guess.

	if (isLongI(word) || isLongU(word) ||
		isEI(word) || isAI(word) || isAU(word) || isOI(word))
		return  word + suffix; // long vowel. No doubling.



	return word + lastLetter + suffix;
}

int main()
{
	std::cout << addSuffix("close", "wise") << std::endl;
	std::cout << addSuffix("commit", "ment") << std::endl;
	std::cout << addSuffix("correct", "ness") << std::endl;
	std::cout << addSuffix("delight", "ful") << std::endl;
	std::cout << addSuffix("direct", "ly") << std::endl;
	std::cout << addSuffix("down", "ward") << std::endl;
	std::cout << addSuffix("regard", "less") << std::endl;

	std::cout << addSuffix("stoop", "ed") << std::endl;
	std::cout << addSuffix("rain", "ing") << std::endl;

	std::cout << addSuffix("deter", "ation") << std::endl;
	std::cout << addSuffix("fat", "y") << std::endl;
	std::cout << addSuffix("sun", "y") << std::endl;
	std::cout << addSuffix("bed", "ed") << std::endl;
	std::cout << addSuffix("dip", "ed") << std::endl;

}
