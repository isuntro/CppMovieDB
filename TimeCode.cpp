#include "TimeCode.h"
#include <string>
using namespace std;

TimeCode::TimeCode(int days, int months, int years,
	long int hours, long int minutes, long int seconds) {
	seconds = seconds + 60 *(minutes + 60 *(hours + 24 * (days + 31 *( months + (12 * years)))));
	minutes = seconds / 60;
	hours = minutes / 60;
	days = hours / 24;
	months = days / 31;
	this->day = (days % 31);
	this->month = (months % 12);
	this->year = months / 12;
	this->hour = hours % 24 ;
	this->minute = minutes % 60;
	this->second = seconds % 60;
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
