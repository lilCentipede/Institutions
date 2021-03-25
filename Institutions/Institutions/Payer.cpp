#include "Payer.h"
Payer::Payer(const char* name,const std::function<bool(const Person&,const Group& )>& rule) {
	payer_name = name;
	member_rule = rule;
	associated_counter = 0;
}
const char* Payer::getName()const {
	return payer_name.getName();
}
bool Payer::applyRule(const Person& p,const Group& g) const{
	return member_rule(p,g);
}