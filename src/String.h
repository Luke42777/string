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
	String();
	String(const char*);
	~String();
	String(const String &other);

	size_t Length()const;
	void Reserve(size_t newCapacity);
	String operator+(const String& other)const;
	friend std::ostream& operator<<(std::ostream& consoleOut, const String& str);
public:
	 char* moptrData;
	 size_t mSize;
	 size_t mCapacity;
};



#endif /* STRING_H_ */
