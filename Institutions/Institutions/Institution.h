#pragma once
#include "Payer.h"
class Institution
{
protected:
	int institutionID;
	String institution_name;
public:
	Institution(unsigned int& id,const char* name = "");
	Institution(const Institution& other);
	Institution& operator=(const Institution& other);
	const char* getName() const { return institution_name.getName(); }
	virtual bool hasMember(const Person& person) = 0;
	virtual const Payer& getPayer() const = 0;
	virtual bool valid() = 0;
	virtual Institution* copy();
	virtual bool compatible(Institution*) ;
	virtual ~Institution() {}
	virtual void print();
};


