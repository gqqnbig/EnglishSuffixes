#include <gtest/gtest.h>

#include <utility>

#include "EnglishSuffixes.h"

using namespace ens;




TEST(Suffixes, addSuffix)
{
	EXPECT_EQ(addSuffix("clock", "wise"), "clockwise");

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

std::string BuildTestName(const testing::TestParamInfo<std::pair<const char*, const char*>>& info)
{
	std::string word{ info.param.first };
	std::string suffix{ info.param.second };
	// Comment out in gtest-param-util.h
	// GTEST_CHECK_(IsValidParamName(param_name))
	return word + "-" + suffix;
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

