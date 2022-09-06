/*
 * String.cpp
 *
 *  Created on: 4 Sept 2022
 *      Author: Lukasz
 */

#include "String.h"
#include <cstring>
#include <cassert>


//////////////////////////constructors and destructor//////////////////////////////////////
String::String():String(""){};
String::String(const  char* str){
	size_t size = 0;
	while (str[size] != '\0') size++;

	moptrData = new char[size + 1];
	for(size_t i = 0; i < size;i++){
		moptrData[i] = str[i];
	}
	moptrData[size] = 0; // string ending
	mSize = size;
	mCapacity = size + 1;
}
String::~String() {
	delete [] moptrData;
}

String::String(const String &other) {
	moptrData = new char[other.mCapacity];
	assert(moptrData);
	for(size_t i = 0; i <= other.mSize;i++){
		moptrData[i] = other.moptrData[i];
	}

	mSize = other.mSize;
	mCapacity = other.mCapacity;
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
String& String::operator+=(const char cc){

	moptrData[mSize] = cc;

	char * oldData = moptrData;

	moptrData = new char [mCapacity + 1];
	mCapacity += 1;
	mSize += 1;
	for(size_t i = 0; i < mSize;i++){
		moptrData[i] = oldData[i];
	}

	moptrData[mSize] = 0;

	return *this;
}
bool String::operator==(const String& other)const{
	size_t index = 0;
	while(this->moptrData[index]){
		if(this->moptrData[index] != other.moptrData[index]){
			return false;
		}
		index++;
	}
	return true;
}

int String::FindSubstring(const char* sub)const{
	size_t subLength = strlen(sub);
	if(subLength > mSize) return -1;
	for(size_t i =  0; i < mSize;i++){
		if(moptrData[i] == sub[0]){
			if(subLength == 1) return i;
			for(size_t k = i + 1,l = 1;l < subLength;k++,l++){
				if(moptrData[k] != sub[l]) break;
				if(l + 1 == subLength) return i;
			}
		}
	}
	return - 1;
}
String String::GetSubstring( const size_t startPos,const size_t length)const{
	assert(startPos < mSize && "GetSubstring() starting pos out of bound" && moptrData);
	assert(startPos  + length - 1  < mSize && "GetSubstring() starting pos + length out of bound");

	String result;
	for(size_t i = startPos; i < length + startPos;i++){
		result += moptrData[i];
	}
	return result;
}
char String::GetCharacter(size_t index)const{
	assert(index < mSize && "GetSubstring() starting pos out of bound" && moptrData);
	return moptrData[index];

}


