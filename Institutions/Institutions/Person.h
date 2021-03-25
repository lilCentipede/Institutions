#pragma once
#include "String.h"
class Person
{
private:
	int insuranceID;
	String person_name;
public:
	Person(int id = 0, const char* name = "");
	Person(const char* name = "");
	Person(const Person& person);
	char* getName() const;
	int getInsuranceID()const ;
};

