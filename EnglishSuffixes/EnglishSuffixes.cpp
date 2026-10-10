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
	// https://our-languages.canada.ca/en/writing-tips-plus/spelling-words-ending-in-a-silent-e
	if (word.length() <= 1 || suffix.length() == 0)
		return false;

	if (word.ends_with("ue"))
	{
		word = word.substr(0, word.length() - 1);
		return true;
	}

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

	// picnic -> picnicker
	// minic -> minicked
	if (word.ends_with("c") && isVowel(suffix[0]))
		return std::string(word) + "k" + suffix;

	// Change y to i if the suffix doesn't start with i.
	if (word.ends_with("y")
		&& isVowel(word[word.length() - 2]) == false
		&& suffix[0] != 'i')
		return std::string(word.substr(0, word.length() - 1)) + "i" + suffix;

	// Without this rule, the final e will be removed.
	// If the penultimate letter is i and the suffix starts with i,
	// we will get "ii".
	if (word.ends_with("ie") && suffix[0] == 'i')
		return std::string(word.substr(0, word.length() - 2)) + "y" + suffix;

	bool isERemoved = dropFinalE(word, suffix);


	char lastLetter = word[word.length() - 1];
	if (isVowel(lastLetter) ||
		isVowel(suffix[0]) == false)
		return std::string(word) + suffix;

	// check the sound of second to last and third to last letters. We can only guess.

	if (isLongI(word) || isLongU(word) ||
		isEI(word, isERemoved) || isAI(word, isERemoved) || isAU(word) || isOI(word) || isOU(word))
		return  std::string(word) + suffix; // long vowel. No doubling.



	return std::string(word) + lastLetter + suffix;
}
