#include "TimeCode.h"

using namespace std;
TimeCode::~TimeCode(){

};
TimeCode::TimeCode(const TimeCode &that) {
	this->days = that.days;
	this->months = that.months;
	this->years = that.years;
	this->hours = that.hours;
	this->minutes = that.minutes;
	this->seconds = that.seconds;
}
void swap(TimeCode &one, TimeCode &another) {
	using std::swap;

	swap(one.days,another.days);
	swap(one.months,another.months);
	swap(one.years, another.years);
	swap(one.hours, another.hours);
	swap(one.minutes, another.minutes);
	swap(one.seconds, another.seconds);
}
TimeCode& TimeCode::operator=(const TimeCode &that) {
	if (this != &that){
		this->days = that.days;
		this->months = that.months;
		this->years = that.years;
		this->hours = that.hours;
		this->minutes = that.minutes;
		this->seconds = that.seconds;
	}
	return *this;
}

TimeCode::TimeCode(int days, int months, int years,
	int hours, long int minutes, long long int seconds) {
	seconds = seconds + 60 *(minutes + 60 *(hours + 24 * (days + 31 *( months + (12 * years)))));
	minutes = seconds / 60;
	hours = minutes / 60;
	days = hours / 24;
	months = days / 31;
	this->days = (days % 31);
	this->months = (months % 12);
	this->years = months / 12;
	this->hours = hours % 24 ;
	this->minutes = minutes % 60;
	this->seconds = seconds % 60;
}
std::istream& operator>> (std::istream &in, TimeCode &aTime) {
	char c;
	int index;
	string temp;
	int data[6];
	// get input char by char and append to temp
	while(in.get(c)){
		temp += c;
		// if char is delimiter add to array
		// and clear temp for next run of loop
		if(c == '/' || c == ':' || c == 'T' || c == 'Z'){
			temp.erase(temp.end()-1);
			data[index] = stoi(temp);
			index++;
			temp = string();
		}
		if(c == 'Z'){
			break;
		}
	}
	aTime = TimeCode(data[0],data[1],data[2],data[3],data[4],data[5]);
	return in;
}
