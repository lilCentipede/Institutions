#include "Group.h"
Group::Group(unsigned int& i_id,unsigned int id, const char* name) : Institution(i_id,name),groupID(id) {
	group_payer = nullptr;
}
Group::Group(unsigned int& i_id,unsigned int id, const char* name, Payer& payer) : Institution(i_id,name),groupID(id) {
	group_payer = &payer;
	payer.associated_counter++;
}
Group::Group(const Group& other) : Institution(other){
	groupID = other.groupID;
	group_payer = other.group_payer;
}
Group& Group::operator=(const Group& other) {
	if (this != &other) {
		Institution::operator=(other);
		groupID = other.groupID;
		group_payer = other.group_payer;
	}
	return *this;
}
bool Group::hasMember(const Person& person) {
	if (group_payer != nullptr) {
		return group_payer->applyRule(person,*this);
	}
	else return false;
}
const Payer& Group::getPayer() const {
		return (*group_payer);
}
bool Group::valid() {
	if (group_payer != nullptr) return true;
	else return false;
}
unsigned int Group::getID()const { 
	return groupID; 
}
void Group::print() {
	Institution::print();
	std::cout << "GroupID: " << groupID << '\n';
	if (valid())
		std::cout << "Payer: " << getPayer().getName()<<'\n';
}
Institution* Group::copy() {
	return new Group(*this);
}
Group::~Group() {}