//a
// Created by Tiberiu Simion Voicu on 22/03/2017.
//  Sno : 100125468
//

#ifndef MOVIEDB_MOVIE_H
#define MOVIEDB_MOVIE_H

#include <string>
#include <iostream>
using namespace std;

class Movie {
private :
    string title;
    int year;
    string rated;
    string genre;
    int length;
    float meanRating;
	int ratings;
public :
	// declaration of default constructor / overloaded in movie.cpp
    Movie(string title ="", int year = 0, string rated = "",
	 string genre = "", int length = 0, float meanRating = 0.0, int ratings = 0);
	~Movie();
	Movie(const Movie &that);
    inline string getTitle() const;
    inline int getYear() const;
    inline string getRated() const;
    inline string getGenre() const;
    inline int getLength() const;
    inline float getMeanRating() const;
	inline int getRatings() const;
	inline void setRatings(int noRatings);
	inline void setMean(float meanRatings);
	Movie& operator= ( Movie that);
	friend std::ostream& operator<< (std::ostream &out, const Movie &aMovie);
	friend void swap(Movie &one, Movie &another);

};

inline string Movie::getTitle() const{ return title; }
inline int Movie::getYear() const{ return year; }
inline string Movie::getRated() const{ return rated; }
inline string Movie::getGenre() const { return genre; }
inline int Movie::getLength() const { return length; }
inline float Movie::getMeanRating() const {  return meanRating; }
inline int Movie::getRatings() const { return ratings; }
inline void Movie::setRatings(int noRatings) { this->ratings = noRatings; }
inline void Movie::setMean(float meanRatings) { this->meanRating = meanRatings ;}


inline ostream& operator << (ostream &out, const Movie &aMovie){
    return out << aMovie.getTitle() << "," << aMovie.getYear() << "," << aMovie.getRated()
               << "," << aMovie.getGenre() << "," << aMovie.getLength() << ","
			   << aMovie.getMeanRating() << "," << aMovie.getRatings() << endl;
}

std::istream& operator>>(std::istream &in, Movie &aMovie);

#endif //MOVIEDB_MOVIE_H
