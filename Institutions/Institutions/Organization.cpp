#include "Organization.h"
Organization::Organization(unsigned int& i_id, const char* name,Group& group,const String& address) : Institution(i_id,name) {
	i_list.push_back(group.copy());
	organization_address = address;
	payer = &group.getPayer();
}
Organization::Organization(unsigned int& i_id, const char* name, std::vector<Institution*>& list, const String& address) :Institution(i_id,name){
	for (Institution* i : list) {
		i_list.push_back(i->copy());
	}
	organization_address = address;
	mainPayer();
}
Organization::Organization(const Organization& other) :Institution(other){
	for (Institution* i : other.i_list) {
		i_list.push_back(i->copy());
	}
	organization_address = other.organization_address;
	payer = &other.getPayer();
}
Organization& Organization::operator=(const Organization& other) {
	if (this != &other) {
		Institution::operator=(other);
		for (Institution* i : other.i_list) {
			i_list.push_back(i->copy());
		}
		organization_address = other.organization_address;
		payer = &other.getPayer();
	}
	return *this;
}
bool Organization::hasMember(const Person& person) {
	for (unsigned int i = 0; i < i_list.size(); i++) {
		if (i_list[i]->hasMember(person))
			return true;
	}
	return false;
}
const Payer& Organization::getPayer() const{
	return *payer;
}
void Organization::mainPayer() {
	int j = 0;
	for (unsigned int i = 0; i < i_list.size(); i++) {
		if (i_list[i]->getPayer().getCounter() > i_list[j]->getPayer().getCounter())
			j = i;
	}
	payer = &i_list[j]->getPayer();
}
bool Organization::valid() {
	bool result = true;
	for (unsigned int i = 0; i < i_list.size(); i++) {
		result = result && i_list[i]->valid();
	}
	return result;
}
Institution* Organization::copy() {
	return new Organization(*this);
}
Organization::~Organization() {
	for (Institution* i : i_list) {
		delete i;
	}
}
bool Organization::compatible(const Organization& other) {
	return payer == other.payer;
}
void Organization::addInstitution(Group& group) {
	if (group.valid()){
		i_list.push_back(group.copy());
		mainPayer();
	}
	else std::cout << "Not valid group\n";
}
void Organization::addInstitution(Organization& org) {
	if (compatible(org)) 
		i_list.push_back(org.copy());
	else std::cout << "Not compatible organizations\n";
}
void Organization::print() {
	std::cout << "Organization's name: " << getName()<<'\n';
	std::cout << "Main payer:" << getPayer().getName()<<'\n';
	for (Institution* i : i_list) {
		i->print();
	}
}