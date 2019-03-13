//
//  RomanNumeral.hpp
//  RomanNumerals
//
//  Created by Jerry Garcia on 3/4/19.
//  Copyright © 2019 Jerry Garcia. All rights reserved.
//

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_

#include <string>
using namespace std;

class RomanNumeral
{
public:
    /**
     * Default constructor.
     */
    RomanNumeral();
    RomanNumeral(string rome);
    RomanNumeral(int dec);

    /***** Complete this class declaration. *****/
    string getRoman() const;
    int getDecimal() const;
    RomanNumeral operator -(const RomanNumeral& rn2);
    RomanNumeral operator +(const RomanNumeral& rn2);
    RomanNumeral operator *(const RomanNumeral& rn2);
    RomanNumeral operator /(const RomanNumeral& rn2);
    bool operator ==(const RomanNumeral& rn2);
    bool operator !=(const RomanNumeral& rn2);
    friend ostream& operator <<(ostream& os, const RomanNumeral& rn);
    friend istream& operator >>(istream& os, RomanNumeral& rn);

private:
    int decimal;
    string roman;
    string to_roman(int& dec);
    int to_decimal(string& rome);
};

#endif /* ROMANNUMERAL_H_ */
