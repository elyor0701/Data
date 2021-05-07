#pragma once

#include "date.h"
#include "node.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>
#include <memory>

using namespace std;

class Database {
public:
	void Add (const Date& date, const string& event);
	void Print (ostream& os) const;
	int RemoveIf (function<bool(const Date&, const string&)> predicate);
	vector<pair<Date, string>> FindIf (
		function<bool(const Date&, const string&)> predicate
		) const;
	pair<Date, string> Last (const Date& date) const;
	
private:
	map<Date, vector<string>> events;
};

template <class K, class V>
ostream& operator << (ostream& os, const pair<K, V>& p) {
	os << p.first << " " << p.second;
	return os;
}
