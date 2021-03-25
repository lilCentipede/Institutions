#pragma once
#include <iostream>
#include <cstring>
#include <cassert>
#pragma warning(disable : 4996)
const int INCREASE_FACTOR = 10;
class String
{
private:
	char* str;
	int size;
	int capacity;
	
public:
	String();
	String(char c);
	String(const char* s);
	String(const String& other);
	~String() { delete[] str; }
	int length()const { return size; }
	char* getName()const { return str; }
	void boostcapacity(int _size);
	char& operator[](int i);
	char operator[](int i) const;
	String& operator=(const String& other);
	String& operator=(const char* s);
	String& operator=(char c);
	String& operator+=(char c);
	bool operator==(const String& other);
	bool operator==(const char* s);
	bool operator==(char c);
	bool operator!=(const String& other);
	bool operator!=(const char* s);
	bool operator!=(char c);
	


};
std::ostream& operator<<(std::ostream& out, const String& s);

