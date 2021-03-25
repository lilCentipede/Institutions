#pragma once
#include "Group.h"
#include <vector>
class Organization : public Institution
{
private:
	std::vector<Institution*> i_list;
	String organization_address;
	const Payer* payer;
public:
	
	Organization(unsigned int& i_id,const char* name,Group& group,const String& address);
	Organization(unsigned int& i_id, const char* name, std::vector<Institution*>& list, const String& address);
	Organization(const Organization& other);
	Organization& operator=(const Organization&);
	bool hasMember(const Person&);
	const Payer& getPayer() const;
	String getAddress()const { return organization_address; }
	void mainPayer();
	bool valid();
	Institution* copy();
	void addInstitution(Group& group);
	void addInstitution(Organization& org);
	~Organization();
	bool compatible(const Organization& other);
	void print();

};

