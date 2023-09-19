#include "mu_test.h"

#include "get_patient_data.hpp"
#include "update_patient_data.hpp"
#include "iget_patient_data.hpp"
#include "iupdate_patient_data.hpp"
#include "patient.hpp"
#include "common_types.hpp"

std::string name = "Or";
std::string id = "23862577";
bool gender = false;
std::string genes[] = {"ABT", "EEF", "KLL"};
std::string variant1[] = {"c<52.0", "g<51.0", "t<42.0"};
std::string variant2[] = {"c<57.0"};
std::string variant3[] = {"g<2.0", "t<77.0"};

BEGIN_TEST(Update_get_data)

	using namespace Genetics;
	Patient p{};
	UpdatePatientData update(p);
	GetPatientData getD(p);

	p.updateName(name);
    p.updateId(id);
    p.updateGender(gender);


	for (auto g : genes) {
		if (g == "ABT") {
			for (auto v : variant1) {
				p.updateGene(g, v);
			}
		} else if (g == "EEF") {
			for (auto v : variant2) {
				p.updateGene(g, v);
			}
		} else if (g == "KLL") {
			for (auto v : variant3) {
				p.updateGene(g, v);
			}
		}
	}

	ASSERT_EQUAL(p.getName(), name);
	ASSERT_EQUAL(p.getId(), id);
	ASSERT_EQUAL(p.getGender(), 0);

	int i = 0;
	GenesVec v = p.getVariants();
	ASSERT_EQUAL(v.size(), 3);

	for (auto const& g : v) {
		int j = 0;
		for (auto const& var : g.second) {
			// Compare the variant with the original variant arrays based on the gene name
			if (g.first == "ABT" && j < 3) {
				ASSERT_EQUAL(var, variant1[j]);
			} else if (g.first == "EEF" && j < 1) {
				ASSERT_EQUAL(var, variant2[j]);
			} else if (g.first == "KLL" && j < 2) {
				ASSERT_EQUAL(var, variant3[j]);
			}
			++j;
		}
		++i;
	}

END_TEST

BEGIN_TEST(get_data_no_update)
	using namespace Genetics;
	Patient p{};
	UpdatePatientData update(p);
	GetPatientData getD(p);

	ASSERT_EQUAL(p.getName(), "");
	ASSERT_EQUAL(p.getId(), "");
	ASSERT_EQUAL(p.getGender(), true);
	GenesVec v = p.getVariants();
	ASSERT_EQUAL(v.size(), 0);
END_TEST

BEGIN_TEST(update_empty_input)
	using namespace Genetics;
	Patient p{};
	UpdatePatientData update(p);
	GetPatientData getD(p);

	p.updateName("");
    p.updateId("");
	p.updateGene("", "A<5");
	p.updateGene("AAA", "");
	p.updateGene("", "");

	ASSERT_EQUAL(p.getName(), "");
	ASSERT_EQUAL(p.getId(), "");
	GenesVec v = p.getVariants();
	ASSERT_EQUAL(v.size(), 0);
END_TEST


TEST_SUITE(因果応報 [m1 Genetic project])
	TEST(Update_get_data)
	TEST(update_empty_input)
	TEST(get_data_no_update)
END_SUITE