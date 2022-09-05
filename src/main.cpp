//============================================================================
// Name        : string.cpp
// Author      : Lukasz Komsta
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "String.h"

using namespace std;

int main() {

	String str1("Hello");
	String str2("there");


	cout <<  (str1 + str2).mCapacity;

}
