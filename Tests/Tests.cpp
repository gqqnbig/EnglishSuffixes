#include <gtest/gtest.h>

#include <utility>

#include "EnglishSuffixes.h"

using namespace ens;




TEST(Suffixes, lengths)
{
	EXPECT_EQ(addSuffix("", ""), "");
	EXPECT_EQ(addSuffix("x", ""), "x");
	EXPECT_EQ(addSuffix("", "y"), "y");
	EXPECT_EQ(addSuffix("x", "y"), "xy");
}

TEST(Suffixes, test)
{
	EXPECT_EQ(addSuffix("wipe", "ing"), "wiping");
}


std::string BuildTestName(const testing::TestParamInfo<std::pair<const char*, const char*>>& info)
{
	std::string word{ info.param.first };
	std::string suffix{ info.param.second };
	// Comment out in gtest-param-util.h
	// GTEST_CHECK_(IsValidParamName(param_name))
#ifdef _DEBUG
	// Visual Studio Test Runner can't properly debug an instance of a parameterized test
	// if the instance name has a dash.
	return word + std::to_string(info.index) + suffix;
#else
	return word + "-" + suffix;
#endif

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
		std::pair("hope", "ing"),
		// subsection 2
		std::pair("true", "ly")
	), BuildTestName);

INSTANTIATE_TEST_SUITE_P(PracticalEnglishUsage346, SimpleConnect,
	testing::Values(
		std::pair("see", "ing"),
		std::pair("canoe", "ist"),
		std::pair("agree", "able"),
		std::pair("dye", "ing"),
		std::pair("replace", "able"),
		std::pair("courage", "ous"),
		// subsection 2
		std::pair("excite", "ment"),
		std::pair("complete", "ness"),
		std::pair("definite", "ly")
	), BuildTestName);


class CKRule : public testing::TestWithParam<std::pair<const char*, const char*>>
{
};

TEST_P(CKRule, run) {
	std::pair<const char*, const char*> p = GetParam();
	std::string word{ p.first };
	std::string suffix{ p.second };

	EXPECT_EQ(addSuffix(word, suffix), word + "k" + suffix);
}

INSTANTIATE_TEST_SUITE_P(PracticalEnglishUsage347, CKRule,
	testing::Values(
		std::pair("picnic", "er"),
		std::pair("panic", "ing"),
		std::pair("minic", "ed")
	), BuildTestName);


class Y2IRule : public testing::TestWithParam<std::pair<const char*, const char*>>
{
};

TEST_P(Y2IRule, run) {
	std::pair<const char*, const char*> p = GetParam();
	std::string word{ p.first };
	std::string suffix{ p.second };

	EXPECT_EQ(addSuffix(word, suffix), word.substr(0, word.length() - 1) + "i" + suffix);
}

INSTANTIATE_TEST_SUITE_P(PracticalEnglishUsage348, Y2IRule,
	testing::Values(
		std::pair("hurry", "ed"),
		std::pair("marry", "age"),
		std::pair("happy", "ly")
	), BuildTestName);

INSTANTIATE_TEST_SUITE_P(PracticalEnglishUsage348, SimpleConnect,
	testing::Values(
		std::pair("try", "ing"),
		std::pair("baby", "ish"),
		std::pair("tory", "ism"),
		// subsection 4: no change after a vowel
		std::pair("buy", "ing"),
		std::pair("play", "ed")
	), BuildTestName);


class IE2YRule : public testing::TestWithParam<std::pair<const char*, const char*>>
{
};

TEST_P(IE2YRule, run) {
	std::pair<const char*, const char*> p = GetParam();
	std::string word{ p.first };
	std::string suffix{ p.second };

	EXPECT_EQ(addSuffix(word, suffix), word.substr(0, word.length() - 2) + "y" + suffix);
}

INSTANTIATE_TEST_SUITE_P(PracticalEnglishUsage348, IE2YRule,
	testing::Values(
		std::pair("die", "ing"),
		std::pair("lie", "ing")
	), BuildTestName);