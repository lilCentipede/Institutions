#pragma once
#include "Organization.h"
Institution* findMostPopularInstitution(std::vector<Institution*> i_list, std::vector<Person> p_list) {
	int final = 0;	
	int number = 0;
	int counter = 0;
	for (unsigned int i = 0; i < i_list.size();i++) {
		for (unsigned int j = 0; j < p_list.size(); j++) {
			if (i_list[i]->hasMember(p_list[j]))
				counter++;
		}
		if (number < counter) {
			number = counter;
			final = i;
		}
		counter = 0;
	}
	return i_list[final];
}
std::vector<Institution*>& clearInstitutions(std::vector<Institution*> i_list) {
	std::vector<Institution*> result;
	for (Institution* i : i_list) {
		if (i->valid())
			result.push_back(i->copy());
	}
	return result;
}
void starting() {
	unsigned int ID = 1;
	std::vector<Person> gods = { {111,"Balder"},{222,"Odin"},{333,"Fenrir"},{444,"Tyr"},{555,"Thor"},{666,"Loki"},{777,"Freya"} };
	std::vector<Payer> payers = { {"One",[](const Person& p,const Group& g) -> bool {return (p.getInsuranceID() + g.getID()) % 2 == 0; }},
									{"Two",[](const Person& p,const Group& g) -> bool {return (p.getInsuranceID() + g.getID()) % 2 != 0; }} };
	Group g1(ID,110, "Uaaaaah",payers[0]);
	Group g2(ID, 121, "UHHH", payers[0]);
	Group g3(ID, 144, "AAAAAA", payers[0]);
	Group g4(ID, 160, "Normal shriek",payers[0]);
	Group g5(ID, 127, "Abnormal shriek", payers[0]);
	Group g6(ID, 146, "Too tired", payers[0]);
	Group g7(ID, 333, "to think ", payers[0]);
	Group g8(ID, 456, "of normal names", payers[0]);

	Organization org1(ID, "IDK", g2, "someaddress");
	org1.addInstitution(g3);
	org1.addInstitution(g4);

	Organization org2(ID, "IDK2", g3, "otheraddress");
	org2.addInstitution(org1);

	Organization shrek(ID, "IDK3", g5, "andanotherone");
	shrek.addInstitution(g6);
	shrek.addInstitution(g7);
	shrek.addInstitution(g8);
	
	std::vector<Institution*> list = { org1.copy(),org2.copy(),shrek.copy() };
	findMostPopularInstitution(list, gods)->print();

	
}
