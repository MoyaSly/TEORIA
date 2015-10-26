#ifndef __STRING__
#define __STRING__
typedef unsigned int uint;

class String
{
private:
	char* str;
	uint mem_capacity;

public:
	String();
	String(char* c_str, uint c_mem_capacity);
	String(char* c_str);
	String(uint c_mem_capacity);
	~String()
	{
		delete this;
	}

	bool operator == (const String& c) const
	{

	}
	bool operator != (const String& c)const
	{

	}

};
#endif
