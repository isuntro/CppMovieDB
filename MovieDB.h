//
// Created by Tiberiu Simion Voicu on 23/03/2017.
//

#ifndef MOVIEDB_MOVIEDATABASE_H
#define MOVIEDB_MOVIEDATABASE_H

#include "Movie.h"
#include <vector>
#include "Ratings.h"

class MovieDB {
private:
    vector<Movie*> movieList;
public:
    MovieDB();
	MovieDB(const MovieDB &that);
	~MovieDB();
    inline vector<Movie*> getList() const;
	inline int size() const;
	inline void addMovie(Movie *aMovie);
	friend std::ostream& operator << (std::ostream &out, MovieDB &movieDB);
	MovieDB& operator= (MovieDB that);
	friend void swap(MovieDB &one, MovieDB &another);
	void updateRatings(Ratings &rList);
};
inline vector<Movie*> MovieDB::getList() const{ return movieList; }
inline void MovieDB::addMovie(Movie *aMovie) {
    this->movieList.push_back(aMovie);
}
inline int MovieDB::size() const{ return movieList.size(); }

inline std::ostream& operator << (std::ostream &out, MovieDB &movieDB){
    for(int i =0; i<movieDB.movieList.size(); i++){
        out << *movieDB.getList()[i] << endl;
    }
    return out;
}
std::istream& operator>> (std::istream &in, MovieDB &movieDB);
template <typename T> bool ascending(const T &a,const T &b) { return a > b;}
template <typename T> bool descending(const T &a,const T &b) { return a < b;}
template <typename T> void SWAP(T *&a, T *&b) {
	T temp = *b;
	*b = *a;
	*a = temp;
}
template <typename T, typename F, typename L>
void sortList(T list, F compare, L criteria) {
	for(int i = 0; i < list.size(); ++i){
		int best = i;
		for (int j = i+1; j < list.size(); ++j){
			if (compare(criteria(list[best]),criteria(list[j]))){
				best = j;
			}
		}
		SWAP(list[i],list[best]);
	}
}
template <typename T, typename L>
MovieDB* extractDB(T &movies, L criteria) {
	MovieDB *newDB = new MovieDB();
	for(int i=0; i<movies.size(); i++ ) {
		if (criteria(movies.getList()[i])){
			Movie *aMovie = new Movie(*movies.getList()[i]);
			newDB->addMovie(aMovie);
		}
	}
	return newDB;
}
template <typename T, typename F, typename L>
auto getNthEntry(L list, T compare, F criteria, int nth){
	sortList(list, compare, criteria);
	return *list[nth];
}
template <typename T, typename F>
auto retrieveEntry(T list, F criteria) {
	auto entry = *list[0];
	for(int i=0; i < list.size(); i++) {
		if(criteria(entry,*list[i])){
			entry = *list[i];
		}
	}
	return entry;
}
#endif //MOVIEDB_MOVIEDATABASE_H
