#include "node.h"

bool EmptyNode::Evaluate (
	const Date& date, 
	const string& event
	) const {
	return true;
}
	
bool LogicalOperationNode::Evaluate (
	const Date& date, 
	const string& event
	) const {
	switch (logical_operation_) {
		case LogicalOperation::And:
			return left_->Evaluate(date, event) && right_->Evaluate(date, event);
		case LogicalOperation::Or:
			return left_->Evaluate(date, event) || right_->Evaluate(date, event);
	}
	return false;
}
	
bool DateComparisonNode::Evaluate (
	const Date& date, 
	const string& event
	) const {
	switch (cmp_) {
		case Comparison::Less:
			return date < date_;
		case Comparison::LessOrEqual:
			return date <= date_;
		case Comparison::Greater:
			return date > date_;
		case Comparison::GreaterOrEqual:
			return date >= date_;
		case Comparison::Equal:
			return date == date_;
		case Comparison::NotEqual:
			return date != date_;
	}
	return false;
}
		
bool EventComparisonNode::Evaluate (
	const Date& date, 
	const string& event
	) const {
//	TestFind(event, event_);
	switch (cmp_) {
		case Comparison::Less:
			return event < event_;
		case Comparison::LessOrEqual:
			return event <= event_;
		case Comparison::Greater:
			return event > event_;
		case Comparison::GreaterOrEqual:
			return event >= event_;
		case Comparison::Equal:
			return event == event_;
		case Comparison::NotEqual:
			return event != event_;
	}
	return false;
}

void TestFind(const string s1, const string s2) {
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s1 << "/" << s2 << endl;
}