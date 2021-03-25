#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <cassert>


template <typename T>
class Vector {
private:
	T* data;
	size_t size;
public:
	Vector();
	Vector(const Vector<T>&  other);
	~Vector() { delete[] data; }
	size_t getSize()const { return size; }
	void to_end(const T& x);
	void push(const T& x);
	void removeByIndex(size_t i);
	T& operator[](size_t i);
	T operator[](size_t i)const;
	Vector<T>& operator=(const Vector<T>& other);
	Vector<T>& operator+=(const T& x);
	Vector<T> operator+(const T& x)const; //there's no &!!!
	Vector<T> operator+(const Vector<T>& other)const;
	bool operator==(const Vector<T>& other)const;
	bool operator!=(const Vector<T>& other)const;
};
template<typename T>
Vector<T>::Vector(){
	data = nullptr;
	size = 0;
}
template<typename T>
Vector<T>::Vector(const Vector<T>& other) {
	data = new T[other.size];
	for (size_t i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
	size = other.size;
}
template<typename T>
void Vector<T>::to_end(const T& x) {
	T* bigger_buffer = new T[size + 1];
	for (size_t i = 0; i < size; i++) {
		bigger_buffer[i] = data[i];
	}
	bigger_buffer[size] = x;
	size++;
	delete[] data;
	data = bigger_buffer;
}
template<typename T>
void Vector<T>::push(const T& x) {
	T* bigger_buffer = new T[size + 1];
	for (size_t i = 0; i < size; i++) {
		bigger_buffer[i + 1] = data[i];
	}
	bigger_buffer[0] = x;
	size++;
	delete[] data;
	data = bigger_buffer;
}
template<typename T>
void Vector<T>::removeByIndex(size_t i) {
	assert(i < size && i >= 0);
	T* buffer = new T[size-1];
	for (size_t j = 0,k = 0; j < size -1 && k<size; j++,k++) {
		if (k == i)
		{
			k++;
			buffer[j] = data[k];
		}
		else 
			buffer[j] = data[k];
	}
	size--;
	delete[] data;
	data = buffer;
}
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		delete[] data;
		data = new T[other.size];
		for (size_t i = 0; i < other.size; i++) {
			data[i] = other.data[i];
		}
		size = other.size;
	}
	return *this;
}
template<typename T>
Vector<T>& Vector<T>::operator+=(const T& x) {
	to_end(x);
	return *this;
}
template<typename T>
Vector<T> Vector<T>::operator+(const T& x)const {
	Vector<T> result(*this); 
	result += x;
	return result;
}
template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)const {
	Vector<T> result;
	result.data = new T[size + other.size];
	for (size_t i = 0; i < size; i++) {
		result.data[i] = data[i];
	}
	for (size_t i = 0; i < other.size; i++) {
		result.data[size+i] = other.data[i];
	}
	result.size = size + other.size;
	return result;
}

template<typename T>
T& Vector<T>::operator[](size_t i) {
	return data[i];
}
template<typename T>
T Vector<T>::operator[](size_t i)const {
	return data[i];
}
template<typename T>
bool Vector<T>::operator==(const Vector<T>& other)const {
	if (size != other.size) 
		return false;
	for (size_t i = 0; i < size; i++) {
		if (data[i] != other.data[i]) 
			return false;
	}
	return true;
}
template<typename T>
bool Vector<T>::operator!=(const Vector<T>& other)const {
	return!(*this == other);
}
template<typename T>
std::ostream& operator<<(std::ostream& out,const Vector<T>& v) {
	for (size_t i = 0; i < v.getSize(); i++) {
		out << v[i] << " ";
	}
	return out;
}
template<typename T>
Vector<T> operator+(T x, Vector<T> v) {
	v.push(x);
	return v;
}
