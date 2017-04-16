//
// Created by Tiberiu Simion Voicu on 23/03/2017.
//

#ifndef RATING_RATING_H
#define RATING_RATING_H
#include <iostream>
#include "TimeCode.h"
using namespace std;

class Rating {
private:
	TimeCode date;
	string author,title;
	int rating;
public:
	Rating(TimeCode date = TimeCode(), string author = " ",string title = " ", int rating = 0);
	inline int getDate() const;
	inline string getAuthor() const;
	inline string getTitle() const;
	inline int getRating() const;
	friend std::ostream& operator<<(std::ostream &out, const Rating &aRating);
};
inline int Rating::getDate() const{
	return date;
}
inline string Rating::getAuthor() const{
	return author;
}
inline string Rating::getTitle() const{
	return title;
}
inline int Rating::getRating() const{
	return rating;
}
inline std::ostream& operator<<(std::ostream &out, const Rating &aRating) {
	out << aRating.getDate() << ',' << aRating.getAuthor() << ',' <<
	aRating.getTitle() << ',' << aRating.getRating() << endl;
	return out;
}
std::istream& operator >>(std::istream &in, Rating &arating);
#endif //RATING_RATING_H
