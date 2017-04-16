#ifndef RATINGS_RATING_H
#define RATINGS_RATING_H
#include "Rating.h"
#include <vector>
using namespace std;

class Ratings {
private:
	vector<Rating> ratingList;
public:
	Ratings();
	inline vector<Rating> getRatings() const;
	inline void addRating(Rating &aRating);
	friend std::ostream& operator<< (std::ostream &out, const Ratings &rList);

};
inline vector<Rating> Ratings::getRatings() const{
	return ratingList;
}
inline void Ratings::addRating(Rating &aRating){
	
	this->ratingList.push_back(aRating);
}
inline std::ostream& operator<< (std::ostream &out, const Ratings &rList) {
	for(int i =0; i<rList.getRatings().size(); i++){
        out << rList.getRatings()[i] << endl;
    }
	return out;
}
std::istream& operator>> (std::istream &in, Ratings &rList);
#endif //RATINGS_RATING_H
