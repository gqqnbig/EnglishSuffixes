#include <assert.h>


#include "SoundGuess.h"

/// <summary>
/// /i:/
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
bool ens::isLongI(std::string_view word)
{
	assert(word.ends_with("y") == false);


	word = word.substr(0, word.length() - 1);
	if (word.ends_with("ee") ||
		word.ends_with("ea") ||
		word.ends_with("ie") ||
		word.ends_with("ei"))
		return true;

	return false;
}



/// <summary>
/// /u:/
/// </summary>
/// <param name="word"></param>
/// <returns></returns>
bool ens::isLongU(std::string_view word)
{
	assert(word.ends_with("y") == false);

	if (word.ends_with("ew"))
		return true;

	word = word.substr(0, word.length() - 1);
	if (word.ends_with("oo") ||
		word.ends_with("ue") ||
		word.ends_with("ui"))
		return true;
	return false;
}


bool ens::isAI(std::string_view word, bool isERemoved)
{
	assert(word.ends_with("y") == false);

	if (word.ends_with("ight"))
		return true;

	word = word.substr(0, word.length() - 1);
	if (word.ends_with("ie") ||
		(word.ends_with("i") && isERemoved))
		return true;
	return false;
}

bool ens::isEI(std::string_view word, bool isERemoved)
{
	assert(word.ends_with("y") == false);


	word = word.substr(0, word.length() - 1);
	if (word.ends_with("ai") ||
		word.ends_with("ea") ||
		(word.ends_with("a") && isERemoved))
		return true;
	return false;
}

bool ens::isOI(std::string_view word)
{
	assert(word.ends_with("y") == false);

	word = word.substr(0, word.length() - 1);
	if (word.ends_with("oi"))
		return true;
	return false;
}

bool ens::isAU(std::string_view word)
{
	assert(word.ends_with("y") == false);

	if (word.ends_with("ow"))
		return true;

	word = word.substr(0, word.length() - 1);
	if (word.ends_with("ou"))
		return true;
	return false;
}


bool ens::isOU(std::string_view word)
{
	if (word.ends_with("ow"))
		return true;

	word = word.substr(0, word.length() - 1);
	if (word.ends_with("oa") ||
		word.ends_with("oe") ||
		word.ends_with("o"))
		return true;
	return false;
}