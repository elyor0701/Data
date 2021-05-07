#include "database.h"

void Database::Add (const Date& date, const string& event) {
	if (set_events[date].find(event) == end(set_events[date])) {
		events[date].push_back(event);
		set_events[date].insert(event);
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
	for (auto it_ = begin(events); it_ != end(events); ) {
		auto it = stable_partition(begin(it_->second), end(it_->second), 
			[&](const string& event) {
			if (predicate(it_->first, event)) {
				amount_removed_elements++;
				set_events[it_->first].erase(event);
				return false;
			} else {
				return true;
			}
		});
		if (it == begin(it_->second)) {
			it_ = events.erase(it_);
			continue;					
		}
		it_->second.erase(it, end(it_->second));
		++it_;
	}
	return amount_removed_elements;
}

vector<pair<Date, string>> Database::FindIf (
	function<bool(const Date&, const string&)> predicate
	) const {
	vector<pair<Date, string>> found;
	for (auto it_ = begin(events); it_ != end(events); ++it_) {
		for (auto _it = begin(it_->second); _it != end(it_->second); ++_it) {
			if(predicate(it_->first, *_it)) {
				found.push_back(make_pair(it_->first, *_it));
			}
		}
	}
	return found;
}

