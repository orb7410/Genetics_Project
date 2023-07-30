#include "mu_test.h"
#include <string>

#include "data_base.hpp"

BEGIN_TEST(test1)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "SMN1";
    std::string variantNotation = "c.840C>T";

    std::string info = db.getGeneDetail(geneName, variantNotation);

	ASSERT_EQUAL(info, "Pathogenic variant associated with spinal muscular atrophy (SMA).");

	if (!info.empty()) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Info: " << info << std::endl;
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST

TEST_SUITE(因果応報 [genetics])
    TEST(test1)
END_SUITE
