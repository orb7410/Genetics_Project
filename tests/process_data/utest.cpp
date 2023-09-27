#include "mu_test.h"

#include <iostream>

#include "common_types.hpp"
#include "data_base.hpp"
#include "iget_patient_data.hpp"
#include "patient.hpp"
#include "get_patient_data.hpp"
#include "process_data.hpp"

BEGIN_TEST(testGenerateSummaryLetter)
    using namespace Genetics;
	Patient p{};

    GetPatientData getData(p);
    DataBase db("genes.json");

    ProcessData proccesData(getData,db);
    proccesData.generateSummaryLetter();
END_TEST

TEST_SUITE(因果応報 [genetics])
    TEST(testGenerateSummaryLetter)
END_SUITE
