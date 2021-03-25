#include "Institution.h"
Institution::Institution(unsigned int& id,const char* name) {
	institutionID = id;
	id++;
	institution_name = name;
}
Institution::Institution(const Institution& other) {
	institutionID = other.institutionID;
	institution_name = other.institution_name;
}
Institution& Institution::operator=(const Institution& other) {
	if (this != &other) {
		institutionID = other.institutionID;
		institution_name = other.institution_name;
	}
	return *this;
}
Institution* Institution::copy() {
	return nullptr;
}
bool Institution::compatible(Institution* i) { return true; }
void Institution::print() {
	std::cout << institutionID << ". " << institution_name << '\n';
}