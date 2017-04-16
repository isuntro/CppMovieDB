//
// Created by Tiberiu Simion Voicu on 23/03/2017.
//

#ifndef TIMECODE_TIMECODE_H
#define TIMECODE_TIMECODE_H
#include <iostream>

class TimeCode {
private:
	int day,month,year;
	long int hour,minute,second;
public:
	TimeCode(int day = 1, int month = 1, int year = 1
		, long int hour = 0, long int minute = 0, long int second = 0);
	TimeCode(int date);
	inline int getDay() const;
	inline int getMonth() const;
	inline int getYear() const;
	inline long int getHour() const;
	inline long int getMinute() const;
	inline long int getSecond() const;
	inline operator int() const;
	friend std::ostream& operator<< (std::ostream &out, const TimeCode &atime);

};
inline int TimeCode::getDay() const {
	return day;
}
inline int TimeCode::getMonth() const {
	return month;
}
inline int TimeCode::getYear() const {
	return year;
}
inline long int TimeCode::getHour() const {
	return hour;
}
inline long int TimeCode::getMinute() const {
	return minute;
}
inline long int TimeCode::getSecond() const {
	return second;
}
inline TimeCode::operator int() const {
	long long int intrep = second + 60 *(minute + 60 *(hour + 24 *
		(day + 31 *( month + (12 * year)))));
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
	out << aTime.getDay() << '/' << aTime.getMonth() << '/' << aTime.getYear() <<
	'T' << aTime.getHour() << ':' << aTime.getMinute() << ":" <<
	aTime.getSecond() << "Z" << std::endl;
	return out;
}
std::istream& operator>> (std::istream &in, TimeCode &atime);
#endif //TIMECODE_TIMECODE_H
