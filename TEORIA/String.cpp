#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "String.h"

String::String()
{
	mem_capacity = 1;
	str = new char[mem_capacity];
	str = '\0';
}

String::~String()
{
	if (str != '\0')
		delete[] str;
}

String::String(const char* str_c)
{
	mem_capacity = strlen(str_c) + 1;
	str = new char[mem_capacity];
	strcpy_s(str, mem_capacity, str_c);

}

String::String(const String& string)
{
	mem_capacity = strlen(string.str) + 1;
	str = new char[mem_capacity];
	strcpy_s(str, mem_capacity, string.str);
}

String::String(uint memory)
{
	mem_capacity = memory;
}

uint String::Capacity()const
{
	return mem_capacity;
}

bool String::operator==(const char* strng_c) const
{
	if (strcmp(str, strng_c) != 0)
		return false;

	return true;
}

bool String::operator==(const String& c) const
{
	if (strcmp(str, c.str) != 0)
		return false;

	return true;
}

bool String::operator!=(const char* strng_c) const{

	if (strcmp(str, strng_c) != 0)
		return true;

	return false;
}

bool String::operator!=(const String& c) const{

	if (strcmp(str, c.str) != 0)
		return true;

	return false;
}

const String& String::operator=(const String& string)
{
	unsigned int need_size = string.Capacity() + 1;
	if (need_size > mem_capacity)
	{
		delete[] str;
		mem_capacity = need_size;
		str = new char[need_size];
	}
	strcpy_s(str, mem_capacity, string.str);
	return(*this);
}


const String& String::operator+=(const String& string)
{
	if (string.c_str() != NULL && str != NULL)
	{
		int sizeToFill = strlen(str) + strlen(string.c_str()) + 1;



		if (sizeToFill > Capacity())
		{

			int finalSize = GetChunkSizeNeeded(sizeToFill);

			char* tmp = new char[finalSize];
			strcpy_s(tmp, strlen(str) + 1, str);
			delete[] str;
			strcat_s(tmp, sizeToFill, string.str);
			str = tmp;

		}
		else
		{
			strcat_s(str, strlen(string.c_str()) + 1, string.c_str());
		}
	}

	return (*this);
}


const String& String::operator+=(const char* str_c)
{

	if (str_c != NULL && str != NULL)
	{
		int size_to_fill = strlen(str) + strlen(str_c) + 1;

		if (size_to_fill > Capacity())
		{

			int final_size = GetChunkSizeNeeded(size_to_fill);

			char* tmp = new char[final_size];
			memset(tmp, 0, final_size);
			strcpy_s(tmp, strlen(str) + 1, str);
			delete[] str;

			strcat_s(tmp, size_to_fill, str_c);

			str = tmp;
			mem_capacity = final_size;
		}
		else
		{
			strcat_s(str, size_to_fill, str_c);
			mem_capacity = size_to_fill;
		}
	}

	return (*this);
}

int String::GetChunkSizeNeeded(int size)const
{
	int numChunksdiv = size / MEMORY_CHUNK;
	int finalInt = ((numChunksdiv + 1) * MEMORY_CHUNK);

	return finalInt;
}

const char* String::c_str()const
{
	return str;
}

