#include "Person.h"
Person::Person(int id,const char* name) : insuranceID(id){
	person_name = name;
}
Person::Person(const char* name ) {
	person_name = name;
}
Person::Person(const Person& other) {
	person_name = other.person_name;
	insuranceID = other.insuranceID;
}
char* Person::getName() const { return person_name.getName(); }
int Person::getInsuranceID()const {
	return insuranceID;
}