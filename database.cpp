#include "database.h"

void Database::Add (const Date& date, const string& event) {
	if (events.count(date) == 0) {
		events[date].push_back(event);
	} else {
		if (count(begin(events.at(date)), end(events.at(date)), event) == 0) {
			events[date].push_back(event);
		}
	}
}

void Database::Print (ostream& os) const {
	for (const auto& item : events) {
      for (const string& event : item.second) {
        os << item.first << " " << event << endl;
      }
    }
}

pair<Date, string> Database::Last (const Date& date) const {
	if(events.size() == 0)
		throw invalid_argument("");
	
	auto it = events.upper_bound(date);
	
	if (it == begin(events))
		throw invalid_argument("");
	
	--it;
	return {it->first, *rbegin(it->second)};
}

int Database::RemoveIf (
	function<bool(const Date&, const string&)> predicate
	) {
	int amount_removed_elements = 0;
	for (auto& item : events) {
		auto it = stable_partition(begin(item.second), end(item.second), 
			[&](const string& event) {
			if (predicate(item.first, event)) {
				amount_removed_elements++;
				return false;
			} else {
				return true;
			}
		});
		item.second.erase(it, end(item.second));
	}
	return amount_removed_elements;
}

vector<pair<Date, string>> Database::FindIf (
	function<bool(const Date&, const string&)> predicate
	) const {
	vector<pair<Date, string>> found;
	for (const auto& item : events) {
		for (const string& s : item.second) {
			if(predicate(item.first, s)) {
				found.push_back(make_pair(item.first, s));
			}
		}
	}
	return found;
}

