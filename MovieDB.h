//
// Created by Tiberiu Simion Voicu on 23/03/2017.
//

#ifndef MOVIEDB_MOVIEDATABASE_H
#define MOVIEDB_MOVIEDATABASE_H

#include "Movie.h"
#include <vector>

class MovieDB {
private:
    vector<Movie> movieChain;
public:

    MovieDB();
    friend std::ostream& operator << (std::ostream &out, MovieDB &movieDB);
    inline vector<Movie> getChain();
    inline void addMovie(Movie &aMovie);
};
inline vector<Movie> MovieDB::getChain() {
    return movieChain;
}
inline void MovieDB::addMovie(Movie &aMovie) {
    this->movieChain.push_back(aMovie);
}
inline std::ostream& operator << (std::ostream &out, MovieDB &movieDB){
    for(int i =0; i<movieDB.movieChain.size(); i++){
        out << movieDB.getChain()[i] << endl;
    }
    return out;
}
std::istream& operator>> (std::istream &in, MovieDB &movieDB);



#endif //MOVIEDB_MOVIEDATABASE_H
