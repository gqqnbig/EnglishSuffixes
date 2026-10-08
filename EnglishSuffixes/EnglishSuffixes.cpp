#include "SoundGuess.h"

#include "EnglishSuffixes.h"

using namespace ens;

bool isVowel(char c)
{
	static const char* vowelLetters = "aeiouy";

	return strchr(vowelLetters, c) != nullptr;
}

bool dropFinalE(std::string_view& word, const std::string& suffix)
{
	if (word.length() <= 1 || suffix.length() == 0)
		return false;

	if (word[word.length() - 1] != 'e' || isVowel(suffix[0]) == false)
		return false;

	_ASSERT(word.length() >= 2);
	//Final e is not dropped from words ending in -ee, -oe, or -ye.
	if (strchr("eoy", word[word.length() - 2]) != nullptr)
		return false;

	if (suffix[0] == 'a' || suffix[0] == 'o')
	{
		// If the suffix starts with a or o,
		// if the word ends with ce or ge,
		// do not drop the final e.
		if (strchr("cg", word[word.length() - 2]) != nullptr)
			return false;
	}


	word = word.substr(0, word.length() - 1);
	return true;
}

std::string ens::addSuffix(std::string_view word, const std::string& suffix)
{
	if (word.length() == 0)
		return suffix;

	bool isERemoved = dropFinalE(word, suffix);


	char lastLetter = word[word.length() - 1];
	if (isVowel(lastLetter) ||
		isVowel(suffix[0]) == false)
		return std::string(word) + suffix;

	// check the sound of second to last and third to last letters. We can only guess.

	if (isLongI(word) || isLongU(word) ||
		isEI(word, isERemoved) || isAI(word) || isAU(word) || isOI(word) || isOU(word))
		return  std::string(word) + suffix; // long vowel. No doubling.



	return std::string(word) + lastLetter + suffix;
}
