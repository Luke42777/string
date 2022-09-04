/*
 * String.h
 *
 *  Created on: 4 Sept 2022
 *      Author: Lukasz
 */

#ifndef STRING_H_
#define STRING_H_

namespace std {

class String {
public:
	String();
	virtual ~String();
	String(const String &other);
};

} /* namespace std */

#endif /* STRING_H_ */
