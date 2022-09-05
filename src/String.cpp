/*
 * String.cpp
 *
 *  Created on: 4 Sept 2022
 *      Author: Lukasz
 */

#include "String.h"
#include <cassert>


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
String String::Reserve(size_t capacity){
	String newString;

	newString.moptrData = new char [capacity];
	assert(moptrData && "Couldn't allocate memory");

	for(size_t i = 0; i < capacity;i++){
		moptrData[i] = 0;
	}
	newString.mSize = capacity - 1;
	newString.mCapacity = capacity;
	return newString;

}
std::ostream& operator<<(std::ostream& consoleOut, const String& str){
	consoleOut << str.moptrData << std::endl;
	return consoleOut;
}
String String::operator+(const String& other)const{
	size_t capacity = this->Length() + other.Length() + 1;
     String result = result.Reserve(capacity);

     for(size_t i = 0; i < this->mSize;i++){
    	 result.moptrData[i] = this->moptrData[i];
     }
     size_t firstFinishIndex = this->mSize;
     for(size_t i = 0,j = firstFinishIndex; i < other.mSize;i++,j++){
         	 result.moptrData[j] = other.moptrData[i];
          }


     return result;


}


