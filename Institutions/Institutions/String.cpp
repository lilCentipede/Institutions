#include "String.h"

String::String() {
	size = 0;
	capacity = size;
	boostcapacity(size);
	str = new char[capacity]; 
	str[0] = '\0';
}
String::String(char c) {
	*this = c;
}
String::String(const char* s) {
	size = strlen(s);
	capacity = size;
	boostcapacity(size);
	strcpy(str, s);
	
}
String::String(const String& other) {
	size = other.size;
	capacity = size;
	boostcapacity(size);
	strcpy(str, other.str);
}

void String::boostcapacity(int _size) {
	if (capacity <= _size) {
		capacity = _size + INCREASE_FACTOR;
		str = new char[capacity];
	}
}
char& String::operator[](int i) {
	assert(i <= size && i>=0);
	return str[i];
}
char String::operator[](int i) const {
	assert(i <= size && i>=0);
	return str[i];
}
String& String::operator=(const String& other) {
	if (this != &other) {
		
		size = other.size;
		if (capacity <= size) {
			capacity = size + INCREASE_FACTOR;
			delete[] str;	
			str = new char[capacity];
		}
		strcpy(str, other.str);
	}
	return *this;
}
String& String::operator=(const char* s) {
	size = strlen(s);
	if (capacity <= size) {
		capacity = size + INCREASE_FACTOR;
		delete[] str;
		str = new char[capacity];
	}
	strcpy(str, s);
	return *this;
}
String& String::operator=(char c) {
	size = 1;
	capacity = size;
	boostcapacity(size);
	str[0] = c;
	str[1] = '\0';
	return *this;
}
String& String::operator+=(char c) {
	size++;
	if (capacity <= size) {
		capacity = size + INCREASE_FACTOR;
		char* result;
		result = new char[capacity];
		strcpy(result, str);
		result[size -1] = c;
		result[size] = '\0';
		delete[] str;
		str = result;
	}
	else {
		str[size - 1] = c;
		str[size ] = '\0';
	}
	return *this;
}
bool String::operator==(char c) {
	if (size == 1) {
		if ((*this)[0] == c)
			return true;
		else return false;
	}
	return false;
}
bool String::operator==(const String& other) {
	if (size == other.size) {
		if (strcmp(str, other.getName()) == 0)
			return true;
		else return false;
	}
	return false;
}
bool String::operator==(const char* s) {
	if (size = strlen(s)) {
		if (strcmp(str, s) == 0)
			return true;
		return false;
	}
	return false;
}
bool String::operator!=(const String& other) {
	return !(*this == other);
}
bool String::operator!=(const char* s) {
	return !(*this == s);
}
bool String::operator!=(char c) {
	return!(*this == c);
}

std::ostream& operator<<(std::ostream& out, const String& s) {
	out << s.getName();
	return out;
}
