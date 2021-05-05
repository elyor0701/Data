#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Date {
public:
	Date (const int& year, const int& month, const int& day);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
  
  
private:
	int year_;
	int month_;
	int day_;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& stream, const Date& date);

bool operator<(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);
