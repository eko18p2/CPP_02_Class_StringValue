#include "StringValue.h"
#include <iostream>
using std::move;

void StringValue::assign(const char* value) {
	if (this->value != nullptr) delete[] this->value;
	this->value = new char[(len = strlen(value)) + 1];
	strcpy_s(this->value, len + 1, value);
}

void StringValue::assign(const StringValue& src) {
	assign(src.value);
}


void StringValue::assign(StringValue&& src) {
	if (value != nullptr) delete[] value;
	len = src.len;
	value = src.value;
	src.value = nullptr;
	src.len = 0;
}
StringValue::StringValue() :StringValue("") {}
StringValue::StringValue(const char* value) {
	assign(value);
}
StringValue::StringValue(const StringValue& src) {
	assign(src);
}
StringValue::StringValue(StringValue&& src) {
	assign(move(src));
}
const StringValue & StringValue::operator=(const StringValue &src)
{
	this->assign(src);
	return *this;
}
const StringValue & StringValue::operator=(StringValue &&src)
{
	assign(move(src));
	return *this;
}
const StringValue & StringValue::operator+=(const StringValue &right)
{
	char* buf = value;
	len += right.len;
	value = new char[len+ 1];
	strcpy_s(value, len + 1, buf);
	strcpy_s(value+(len-right.len), right.len + 1, right.value);
	delete[] buf;
	
	return *this;
}
const StringValue StringValue::operator+(const StringValue &right) const
{
	StringValue copy = *this;
	copy += right;
	return copy;
}

char* StringValue::c_str() const {
	return value;
}

size_t StringValue::length() {
	return len;
}

StringValue::~StringValue() {
	if (value != nullptr) delete[] value;
}