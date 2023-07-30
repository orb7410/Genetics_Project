#include "mu_test.h"

#include <string>
#include <iostream>

#include "data_base.hpp"


BEGIN_TEST(test_LoadData_ValidFile)
    using namespace genetics;
    DataBase db("genes.json");

	ASSERT_THAT(db.numOfGenes() == 6);
	ASSERT_THAT(db.numOfGenes() != 0);

END_TEST

BEGIN_TEST(test_LoadData_InvalidFile)
    using namespace genetics;
    DataBase db("invalid_file.json");

	ASSERT_THAT(db.numOfGenes() == 0);

END_TEST

BEGIN_TEST(test_LoadData_EmptyFile)
    using namespace genetics;
    DataBase db("empty_file.json");

	ASSERT_THAT(db.numOfGenes() == 0);

END_TEST

BEGIN_TEST(test_getGeneDetails_ValidVariant)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "smn1";
    std::string variantNotation = "c.840c>t";

    std::string info = db.getGeneDetails(geneName, variantNotation);

	ASSERT_EQUAL(info, "pathogenic variant associated with spinal muscular atrophy (sma).");

	if (!info.empty()) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Info: " << info << std::endl;
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST


BEGIN_TEST(test_getGeneDetails_NonExistingGene)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "s2";
    std::string variantNotation = "c.840c>t";

    std::string info = db.getGeneDetails(geneName, variantNotation);

	ASSERT_THAT(info != "pathogenic variant associated with spinal muscular atrophy (sma).");
	ASSERT_EQUAL(info, "");

	if (!info.empty()) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Info: " << info << std::endl;
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST

BEGIN_TEST(test_getGeneDetails_InvalidGene)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "";
    std::string variantNotation = "c.840c>t";

    std::string info = db.getGeneDetails(geneName, variantNotation);

	ASSERT_THAT(info != "pathogenic variant associated with spinal muscular atrophy (sma).");
	ASSERT_EQUAL(info, "");

	if (!info.empty()) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Info: " << info << std::endl;
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST

BEGIN_TEST(test_getGeneDetails_InvalidVariant)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "smn1";
    std::string variantNotation = "";

    std::string info = db.getGeneDetails(geneName, variantNotation);

	ASSERT_THAT(info != "pathogenic variant associated with spinal muscular atrophy (sma).");
	ASSERT_EQUAL(info, "");

	if (!info.empty()) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Info: " << info << std::endl;
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST

BEGIN_TEST(test_IsGeneExist_ValidVariant)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "smn1";
    std::string variantNotation = "c.840c>t";

    bool result = db.isGeneExist(geneName, variantNotation);

	ASSERT_EQUAL(result, true);

	if (result) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Exist: ";
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST

BEGIN_TEST(test_IsGeneExist_NonExistingGene)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "s1";
    std::string variantNotation = "c.840c>t";

    bool result = db.isGeneExist(geneName, variantNotation);

	ASSERT_EQUAL(result, false);

	if (result) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Exist: ";
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST

BEGIN_TEST(test_IsGeneExist_InValidVariant)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "";
    std::string variantNotation = "c.840c>t";

    bool result = db.isGeneExist(geneName, variantNotation);

	ASSERT_EQUAL(result, false);

	if (result) {
        std::cout << "Gene: " << geneName << ", Variant: " << variantNotation << ", Exist: ";
    } else {
        std::cout << "Gene and variant combination not found in the database." << std::endl;
    }

END_TEST


BEGIN_TEST(test_getGeneDetails_CaseInsensitive)
    using namespace genetics;
    DataBase db("genes.json");

    std::string geneName = "sM n1";
    std::string variantNotation = "c.840c>t";

    std::string info = db.getGeneDetails(geneName, variantNotation);
	std::cout << info << std::endl;

	ASSERT_EQUAL(info, "pathogenic variant associated with spinal muscular atrophy (sma).");
END_TEST

TEST_SUITE(因果応報 [genetics])
	TEST(test_LoadData_ValidFile)
	TEST(test_LoadData_InvalidFile)
	TEST(test_LoadData_EmptyFile)

    TEST(test_getGeneDetails_ValidVariant)
	TEST(test_getGeneDetails_NonExistingGene)
	TEST(test_getGeneDetails_InvalidGene)
	TEST(test_getGeneDetails_InvalidVariant)

	TEST(test_IsGeneExist_ValidVariant)
	TEST(test_IsGeneExist_NonExistingGene)
	TEST(test_IsGeneExist_InValidVariant)

	TEST(test_getGeneDetails_CaseInsensitive)

END_SUITE
