#pragma once
#include "Institution.h"
class Group : public Institution
{
private:
	unsigned int groupID;
	const Payer* group_payer;
public:
	Group(unsigned int& i_id , unsigned int id = 0, const char* name = "");
	Group(unsigned int& i_id , unsigned int id, const char* name, Payer& payer);
	Group(const Group& other);
	Group& operator=(const Group&);
	bool hasMember(const Person&);
	const Payer& getPayer() const;
	bool valid();
	unsigned int getID()const;
	void print();
	Institution* copy();
	~Group();
};

