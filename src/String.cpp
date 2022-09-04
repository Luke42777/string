/*
 * String.cpp
 *
 *  Created on: 4 Sept 2022
 *      Author: Lukasz
 */

#include "String.h"


//////////////////////////constructors and destructor//////////////////////////////////////
String::String(): String("") {}
String::String(const  char* str){
	size_t size = 0;
	while (str[size] != '\0') size++;

	moptrData = new char[size + 1];
	for(size_t i = 0; i < size;i++){
		moptrData[i] = str[i];
	}
	mSize = size;
	mCapacity = size + 1;
}
String::~String() {
	delete [] moptrData;
}

String::String(const String &other) {
	// TODO Auto-generated constructor stub

}
////////////////////////////////////////////////////////////////////////////////////////////
size_t String::Length()const{
return mSize;
}
void String::Reserve(size_t newCapacity){
	if(moptrData){
		delete [] moptrData;
		mSize = 0;
		mCapacity = 0;
	}

	moptrData = new char [newCapacity];

	for(size_t i = 0; i < newCapacity;i++){
		moptrData[i] = 0;
	}

}
std::ostream& operator<<(std::ostream& consoleOut, const String& str){
	consoleOut << str.moptrData << std::endl;
	return consoleOut;
}
//String String::operator+(const String& other)const{
//	size_t capacity = this->Length() + other.Length() + 1;
//	for
//	String newStr;
//
//
//}


