#pragma once
#include <functional>
#include "Person.h"
class Group;

class Payer
{
private:
	String payer_name;
	std::function<bool(const Person&,const Group&)> member_rule;
public:
	int associated_counter;
	Payer(const char* name,const std::function<bool(const Person&,const Group&)>& rule);
	int getCounter()const { return associated_counter; }
	const char* getName()const;
	bool applyRule(const Person& p,const Group& g) const;
};

