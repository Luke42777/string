/*
 * String.h
 *
 *  Created on: 4 Sept 2022
 *      Author: Lukasz
 */

#ifndef STRING_H_
#define STRING_H_

#include <iostream>

class String {
public:
	static const int CAPACITY_MULTIPLIER = 2;
	String();
	String(const char*);
	~String();
	String(const String &other);

	size_t Length()const;
	String Reserve(size_t newCapacity);
	String operator+(const String& other)const;
	String& operator+=(const char cc);
	friend std::ostream& operator<<(std::ostream& consoleOut, const String& str);
	bool operator==(const String& other)const;
	int FindSubstring(const char* sub)const;//return -1 if not found or index of the first letter of that substring
	String GetSubstring(const size_t startPos,const size_t length)const;
	char GetCharacter(size_t index)const;

public://TODO change for private
	 char* moptrData;
	 size_t mSize;
	 size_t mCapacity;
};



#endif /* STRING_H_ */
