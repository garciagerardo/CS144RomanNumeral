//
//  RomanNumeral.cpp
//  RomanNumerals
//
//  Created by Jerry Garcia on 3/4/19.
//  Copyright © 2019 Jerry Garcia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "RomanNumeral.h"

using namespace std;

RomanNumeral::RomanNumeral() : roman(""), decimal(0) {}

RomanNumeral::RomanNumeral(int dec) : decimal(dec) {
    roman = to_roman(dec);
}

RomanNumeral::RomanNumeral(string rome) : roman(rome) {
    decimal = to_decimal(rome);
}


string RomanNumeral::getRoman() const{
    return roman;
}

int RomanNumeral::getDecimal() const{
    return decimal;
}

RomanNumeral RomanNumeral::operator -(const RomanNumeral& rn2){
    int num = decimal - rn2.decimal;
    RomanNumeral rn(num); // @suppress("Ambiguous problem")
    return rn;
}
RomanNumeral RomanNumeral::operator +(const RomanNumeral& rn2){
    int num = decimal + rn2.decimal;
    RomanNumeral rn(num); // @suppress("Ambiguous problem")
    return rn;
}
RomanNumeral RomanNumeral::operator *(const RomanNumeral& rn2){
    int num = decimal * rn2.decimal;
    RomanNumeral rn(num); // @suppress("Ambiguous problem")
    return rn;
}
RomanNumeral RomanNumeral::operator /(const RomanNumeral& rn2){
    int num = decimal / rn2.decimal;
    RomanNumeral rn(num); // @suppress("Ambiguous problem")
    return rn;
}
bool RomanNumeral::operator ==(const RomanNumeral& rn2){
    return decimal == rn2.decimal;
}
bool RomanNumeral::operator !=(const RomanNumeral& rn2){
    return decimal != rn2.decimal;
}
ostream& operator <<(ostream& os, const RomanNumeral& rn){
    cout << "[" << rn.decimal << ":" << rn.roman << "]";
    return os;
}
istream& operator >>(istream& ins, RomanNumeral& rn){
    string rome;
    ins >> rome;
    rn.roman = rome;
    rn.decimal = rn.to_decimal(rome);
    return ins;
}

string RomanNumeral::to_roman(int& dec){
    int num = dec;
    string roman;
    int decimal[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1}; //base values
    string symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};  //roman symbols
    int i = 0;

    while(num){ //repeat process until num is not 0
        while(num/decimal[i]){  //first base value that divides num is largest base value
            roman += symbol[i];    //print roman symbol equivalent to largest base value
            num -= decimal[i];  //subtract largest base value from num
        }
        i++;    //move to next base value to divide num
    }
    return roman;
}
int RomanNumeral::to_decimal(string& rome){

    map<char, int> mp;
    mp['M'] = 1000;
    mp['D'] = 500;
    mp['C'] = 100;
    mp['L'] = 50;
    mp['X'] = 10;
    mp['V'] = 5;
    mp['I'] = 1;

    int res = 0;
    for (int i = 0; i < rome.size() - 1; ++i)
    {
        if (mp[rome[i]] < mp[rome[i+1]])
            res -= mp[rome[i]];
        else
            res += mp[rome[i]];
    }
    res += mp[rome[rome.size()-1]];
    return res;
}

/***** Complete this class implementation. *****/
