#ifndef _STRING_VALUE_H
#define _STRING_VALUE_H

class StringValue {
	char *value = nullptr;
	size_t len = 0;
public:
	void assign(const char* );
	void assign(const StringValue& );
	void assign(StringValue&&);
	StringValue();
	StringValue(const char*);
	StringValue(const StringValue&);
	StringValue(StringValue&&);

	const StringValue& operator=(const StringValue&);
	const StringValue& operator=(StringValue&&);

	const StringValue& operator+=(const StringValue&);
	const StringValue operator+(const StringValue&) const;



	char* c_str() const;
	size_t length();
	~StringValue();
};
#endif

