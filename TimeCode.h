//
// Created by Tiberiu Simion Voicu on 23/03/2017.
//

#ifndef TIMECODE_TIMECODE_H
#define TIMECODE_TIMECODE_H
#include <iostream>

class TimeCode {
private:
	int days,months,years,hours,minutes,seconds;
public:
	TimeCode(int days = 1, int months = 1, int years = 1
		, int hours = 0,long int minutes = 0,long long int seconds = 0);
	TimeCode(int date);
	~TimeCode();
	TimeCode(const TimeCode &acode);
	inline int getDays() const;
	inline int getMonths() const;
	inline int getYears() const;
	inline int getHours() const;
	inline int getMinutes() const;
	inline int getSeconds() const;
	inline operator int() const;
	friend std::ostream& operator<< (std::ostream &out, const TimeCode &atime);
	TimeCode& operator=(const TimeCode &acode);
	friend void swap(TimeCode &one, TimeCode &another);

};
inline int TimeCode::getDays() const {
	return days;
}
inline int TimeCode::getMonths() const {
	return months;
}
inline int TimeCode::getYears() const {
	return years;
}
inline int TimeCode::getHours() const {
	return hours;
}
inline int TimeCode::getMinutes() const {
	return minutes;
}
inline int TimeCode::getSeconds() const {
	return seconds;
}
inline TimeCode::operator int() const {
	long long int intrep = seconds + 60 *(minutes + 60 *(hours + 24 *
		(days + 31 *( months + (12 * years)))));
	return intrep;
}
inline bool operator <(const TimeCode &lhs, const TimeCode &rhs) {
	return int(lhs) < int(rhs);
}
inline bool operator >=(const TimeCode &lhs, const TimeCode &rhs) {
	return !(lhs < rhs);
}
inline bool operator >(const TimeCode &lhs, const TimeCode &rhs) {
	return int(lhs) > int(rhs);
}
inline bool operator <= (const TimeCode &lhs, const TimeCode &rhs) {
	return !(lhs > rhs);
}
inline bool operator == (const TimeCode &lhs, const TimeCode &rhs) {
	return int(lhs) == int(rhs);
}
inline bool operator != (const TimeCode &lhs, const TimeCode &rhs) {
	return !(lhs == rhs);
}
inline TimeCode operator+ (const TimeCode &lhs, const TimeCode &rhs) {
	return TimeCode(0,0,0,0,0, int(lhs) + int(rhs));
}
inline TimeCode operator- (const TimeCode &lhs, const TimeCode &rhs) {
	return TimeCode(0,0,0,0,0, int(lhs) - int(rhs));
}
inline TimeCode operator* (const TimeCode &lhs, int t) {
	return TimeCode(0,0,0,0,0, int(lhs) * t);
}
inline TimeCode operator* (int t, const TimeCode &rhs) {
	return TimeCode(0,0,0,0,0, t * int(rhs));
}
inline TimeCode operator/ (const TimeCode &lhs, int t) {
	return TimeCode(0,0,0,0,0, int(lhs) / t);
}
inline int operator% (const TimeCode &lhs, int t) {
	return (int(lhs) % t);
}

inline std::ostream& operator<< (std::ostream &out, const TimeCode &aTime) {
	out << aTime.getDays() << '/' << aTime.getMonths() << '/' << aTime.getYears() <<
	'T' << aTime.getHours() << ':' << aTime.getMinutes() << ":" <<
	aTime.getSeconds() << "Z";
	return out;
}
std::istream& operator>> (std::istream &in, TimeCode &atime);
#endif //TIMECODE_TIMECODE_H
