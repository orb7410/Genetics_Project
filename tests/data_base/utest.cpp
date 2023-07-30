#include "mu_test.h"
#include <string>

#include "data_base.hpp"


BEGIN_TEST(test_LoadData_ValidFile)
    using namespace genetics;
    DataBase db("genes.json");

	ASSERT_THAT(db.getGenesSize() == 6);
	ASSERT_THAT(db.getGenesSize() != 0);

END_TEST

BEGIN_TEST(test_LoadData_InvalidFile)
    using namespace genetics;
    DataBase db("invalid_file.json");

	ASSERT_THAT(db.getGenesSize() == 0);
END_TEST

BEGIN_TEST(test_LoadData_EmptyFile)
    using namespace genetics;
    DataBase db("empty_file.json");

	ASSERT_THAT(db.getGenesSize() == 0);
END_TEST

BEGIN_TEST(test_GetGeneDetail_ValidVariant)
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

BEGIN_TEST(test_GetGeneDetail_NonExistingGene)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "S2";
    std::string variantNotation = "c.840C>T";

    std::string info = db.getGeneDetail(geneName, variantNotation);

	ASSERT_THAT(info != "Pathogenic variant associated with spinal muscular atrophy (SMA).");
	ASSERT_EQUAL(info, "");

	if (!info.empty()) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Info: " << info << std::endl;
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST

BEGIN_TEST(test_GetGeneDetail_InvalidGene)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "";
    std::string variantNotation = "c.840C>T";

    std::string info = db.getGeneDetail(geneName, variantNotation);

	ASSERT_THAT(info != "Pathogenic variant associated with spinal muscular atrophy (SMA).");
	ASSERT_EQUAL(info, "");

	if (!info.empty()) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Info: " << info << std::endl;
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST

BEGIN_TEST(test_GetGeneDetail_InvalidVariant)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "SMN1";
    std::string variantNotation = "";

    std::string info = db.getGeneDetail(geneName, variantNotation);

	ASSERT_THAT(info != "Pathogenic variant associated with spinal muscular atrophy (SMA).");
	ASSERT_EQUAL(info, "");

	if (!info.empty()) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Info: " << info << std::endl;
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST

TEST_SUITE(因果応報 [genetics])
	TEST(test_LoadData_ValidFile)
	TEST(test_LoadData_InvalidFile)
	TEST(test_LoadData_EmptyFile)
    TEST(test_GetGeneDetail_ValidVariant)
	TEST(test_GetGeneDetail_NonExistingGene)
	TEST(test_GetGeneDetail_InvalidGene)
	TEST(test_GetGeneDetail_InvalidVariant)
END_SUITE
