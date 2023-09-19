#include "mu_test.h"

#include <algorithm>
#include <iostream>
#include <ostream>

#include "string_utils.hpp"

BEGIN_TEST(test_remove_none_letters)
    using namespace genetics;
    std::string word = "adaya tovim12";
    std::string word2 = " ada ya t!ovim1-2";
    ASSERT_EQUAL(removeSpaces(word), "adayatovim12");
    ASSERT_EQUAL(removeSpaces(word2), "adayatovim12");

END_TEST

BEGIN_TEST(test_toLowercase)
    using namespace genetics;
    std::string word = "aDayA tovim12";
    std::string word2 = "adayaTovim12";
    ASSERT_EQUAL(toLowercase(word), "adaya tovim12");
    ASSERT_EQUAL(toLowercase(word2), "adayatovim12");

END_TEST

TEST_SUITE(因果応報 [search])
	TEST(test_remove_none_letters)
	TEST(test_toLowercase)

END_SUITE
