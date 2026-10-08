#include <gtest/gtest.h>

#include <utility>

#include "EnglishSuffixes.h"

using namespace ens;




TEST(Suffixes, addSuffix)
{
	EXPECT_EQ(addSuffix("clock", "wise"), "clockwise");

}


std::string BuildTestName(const testing::TestParamInfo<std::pair<const char*, const char*>>& info)
{
	std::string word{ info.param.first };
	std::string suffix{ info.param.second };
	// Comment out in gtest-param-util.h
	// GTEST_CHECK_(IsValidParamName(param_name))
	return word + "-" + suffix;
}

class SimpleConnect : public testing::TestWithParam<std::pair<const char*, const char*>>
{

};

TEST_P(SimpleConnect, run) {
	std::pair<const char*, const char*> p = GetParam();
	std::string word{ p.first };
	std::string suffix{ p.second };

	EXPECT_EQ(addSuffix(word, suffix), word + suffix);
}


// https://our-languages.canada.ca/en/writing-tips-plus/spelling-final-consonants-doubled-before-a-suffix
INSTANTIATE_TEST_SUITE_P(OurLanguageCanada, SimpleConnect,
	testing::Values(
		std::pair("clock", "wise"),
		std::pair("commit", "ment"),
		std::pair("correct", "ness"),
		std::pair("delight", "ful"),
		std::pair("direct", "ly"),
		std::pair("down", "ward"),
		std::pair("regard", "less")
	), BuildTestName);


class RemoveE : public testing::TestWithParam<std::pair<const char*, const char*>>
{

};

TEST_P(RemoveE, run) {
	std::pair<const char*, const char*> p = GetParam();
	std::string word{ p.first };
	std::string suffix{ p.second };

	EXPECT_EQ(addSuffix(word, suffix), word.substr(0, word.length() - 1) + suffix);
}


INSTANTIATE_TEST_SUITE_P(PracticalEnglishUsage346, RemoveE,
	testing::Values(
		std::pair("shade", "y"),
		std::pair("note", "able"),
		std::pair("make", "ing"),
		std::pair("fame", "ous"),
		std::pair("hope", "ing")
	), BuildTestName);

INSTANTIATE_TEST_SUITE_P(PracticalEnglishUsage346, SimpleConnect,
	testing::Values(
		std::pair("see", "ing"),
		std::pair("canoe", "ist"),
		std::pair("agree", "able"),
		std::pair("dye", "ing"),
		std::pair("replace", "able"),
		std::pair("courage", "ous")
	), BuildTestName);

//INSTANTIATE_TEST_SUITE_P(PracticalEnglishUsage346, SimpleConnect,
//	testing::Values(
//		std::pair("excite", "ment")
//		//std::pair("note", "able"),
//		//std::pair("make", "ing"),
//		//std::pair("fame", "ous"),
//		//std::pair("hope", "ing")
//	), BuildTestName);

