#include "mu_test.h"

#include <string> // std::string
#include <vector> // std::vector
#include <cstdint> // uint32_t

#include "get_patient_data.hpp"
#include "update_patient_data.hpp"
#include "iget_patient_data.hpp"
#include "iupdate_patient_data.hpp"
#include "patient.hpp"
#include "common_types.hpp"

std::string name = "Or";
std::string id = "23862577";
bool gender = false;
std::string gene = "ABT";
std::string varient = "c<52.0"

BEGIN_TEST(Update_get_data)

	IUpdatePatientData Iupdate;
	UpdatePatientData update(Iupdate);

	IGetPatientData IgetD;
	GetPatientData getD(Iget);

	update.updateName(name);
    update.updateId(id);
    update.updateGender(gender);
    update.updateGene(gene, varient);
	
	ASSERT_EQUAL(getD.getName(), name);
	ASSERT_EQUAL(getD.getId(), id);
	ASSERT_EQUAL(getD.getGender(), GENDER::MALE);
END_TEST

BEGIN_TEST(get_data_empty)
//empty var name too
END_TEST

BEGIN_TEST(update_many_varient_same_gene)
END_TEST


TEST_SUITE(因果応報 [m1 Genetic project])
	TEST(Update_get_data)
END_SUITE
