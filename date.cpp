#include "date.h"

#include <sstream>
	
Date::Date (const int& year, const int& month, const int& day) {
    year_ = year;
    if (month > 12 || month < 1) {
        throw logic_error("Month value is invalid: " + to_string(month));
    }
    month_ = month;
    if (day > 31 || day < 1) {
        throw logic_error("Day value is invalid: " + to_string(day));
    }
    day_ = day;
}
	
int Date::GetYear () const {
	return year_;
}

int Date::GetMonth() const {
	return month_;
}

int Date::GetDay() const {
	return day_;
}

bool operator<(const Date& lhs, const Date& rhs) {
  return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} <
      vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator!=(const Date& lhs, const Date& rhs) {
  return vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} !=
      vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

Date ParseDate(istream& is) {
    string date;
    is >> date;
    istringstream date_stream(date);
    bool ok = true;
    
    int year;
    ok = ok && (date_stream >> year);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);
    
    int month;
    ok = ok && (date_stream >> month);
    ok = ok && (date_stream.peek() == '-');
    date_stream.ignore(1);
    
    int day;
    ok = ok && (date_stream >> day);
    ok = ok && date_stream.eof();
    
    if (!ok) {
        throw logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<
        "-" << setw(2) << setfill('0') << date.GetMonth() <<
        "-" << setw(2) << setfill('0') << date.GetDay();
    return stream;
}