#pragma once
#include<iostream>
using namespace std;


class String {

private:
	char* str;
	int size = 0;

public:

	String();
	String(const char sym);
	String(const char* str);
	String(const String& other);
	~String();

	String& operator =(const String& other);
	String operator +(const String& other);
	String& operator -();
	char& operator[](size_t index);
	const bool operator ==(const String& other);
	const bool operator !=(const String& other);
	const bool operator <(const String& other);
	const bool operator <=(const String& other);
	const bool operator >(const String& other);
	const bool operator >=(const String& other);
	const String& operator+=(const String& other);

	friend istream& operator >> (istream& stream, String& orig);
	friend ostream& operator << (ostream& stream, const String& orig);

	void input();
	void output()const;
	void to_upper();
	void to_lower();
	int length();

};



