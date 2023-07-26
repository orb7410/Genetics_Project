#include "mu_test.h"

#include <string> // std::string
#include <vector> // std::vector
#include <cstdint> // uint32_t


BEGIN_TEST(search_query)
	using namespace se;
	SearchEngine s;
	s.execute("../utils/configuration.json");
	ASSERT_PASS();
END_TEST


TEST_SUITE(因果応報 [m1 search engine])
	TEST(search_query)
END_SUITE
