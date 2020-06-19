#include "_string.h"


String::String() {
	str = nullptr;
	str = new char[size + 1];
	str[size] = '\0';
}

String::String(const char sym)
{
	size = 2;
	this->str = new char[size];
	this->str[0] = sym;
	this->str[1] = '\0';
}

String::String(const char* str) {
	int length = strlen(str) + 1;
	this->str = new char[length];
	strcpy_s(this->str, length, str);
}

String::~String()
{
	delete[] str;
}



void String::input() {
	cin.getline(str, size);
}

void String::output()const {
	cout << str << endl;
}

void String::to_upper()
{
	this->size = strlen(str);
	for (int i = 0; i < size; i++)
		this->str[i] = toupper(this->str[i]);
}

void String::to_lower()
{
	this->size = strlen(str);
	for (int i = 0; i < size; i++)
		this->str[i] = tolower(this->str[i]);
}

int String::length()
{
	this->size = strlen(str);
	int length = 0;
	for (int i = 0; i < size; i++)
		length++;
	return length;
}

String::String(const String& other)
{
	int length = strlen(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->str[i] = other.str[i];
	this->str[length] = '\0';
}


String& String::operator=(const String& other)
{
	if (this->str != nullptr)
		delete[] str;
	int length = strlen(other.str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; i++)
		this->str[i] = other.str[i];
	this->str[length] = '\0';

	return *this;
}

String String::operator+(const String& other)
{
	String new_str;
	int this_length = strlen(this->str);
	int other_length = strlen(other.str);
	new_str.str = new char[this_length + other_length + 1];
	int i = 0;
	for (; i < this_length; i++)
		new_str.str[i] = this->str[i];
	for (int j = 0; j < other_length; j++, i++)
		new_str.str[i] = other.str[j];
	new_str.str[this_length + other_length] = '\0';
	return new_str;
}

const bool String::operator==(const String& other) {
	bool result = true;
	int other_size = strlen(other.str);
	int current_size = strlen(this->str);
	if (current_size != other_size)
		result = false;
	for (int i = 0; i < current_size; i++)
		if (str[i] != other.str[i])
			result = false;

	return result;
}

const bool String::operator!=(const String& other)
{
	bool result = false;
	int other_size = strlen(other.str);
	int current_size = strlen(this->str);
	if (current_size != other_size)
		result = true;
	for (int i = 0; i < current_size; i++)
		if (str[i] != other.str[i])
			result = true;

	return result;
}

const bool String::operator<(const String& other) {
	int other_size = strlen(other.str);
	int current_size = strlen(this->str);
	if (current_size < other_size)
		return true;
	else
		return false;
}

const bool String::operator<=(const String& other) {
	int other_size = strlen(other.str);
	int current_size = strlen(this->str);
	if (current_size <= other_size)
		return true;
	else
		return false;
}

const bool String::operator>(const String& other)
{
	int other_size = strlen(other.str);
	int current_size = strlen(this->str);
	if (current_size > other_size)
		return true;
	else
		return false;
}

const bool String::operator>=(const String& other)
{
	int other_size = strlen(other.str);
	int current_size = strlen(this->str);
	if (current_size >= other_size)
		return true;
	else
		return false;
}

const String& String::operator+=(const String& other)
{
	*this = *this + other;

	return *this;
}

char& String::operator[](size_t index)
{
	return str[index];
}

String& String::operator-()
{
	int length = strlen(this->str);
	for (int i = 0; i < length / 2; i++)
	{
		char temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}

	return *this;
}

istream& operator>>(istream& stream, String& orig)
{
	stream >> orig.str;
	return stream;
}

ostream& operator<<(ostream& stream, const String& orig)
{
	stream << orig.str;
	return stream;
}
