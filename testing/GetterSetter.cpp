#include <iostream>
#include <cmath>
using namespace std;

//GETTER AND SETTER

class Movie{
    private:
        string rating;

    public:
        string title;
        string director;
        
        //object constructor
        Movie(string aTitle, string aDirector, string aRating){
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        };


        //set function for rating
        void setRating(string aRating)
        {
            if(aRating == "G" ||aRating == "PG"||aRating == "PG-13"||aRating == "R"||aRating == "NR"){
                rating = aRating;
            }
            else{
                rating = "NR";
            }
                
        };

        //getter function for rating
        string getRating(){
            return rating;
        };
};

int main(){
    
    Movie Avengers ("The Avengers","Joss Whedon","PG-13");

    Avengers.setRating("PG-13");

    cout << Avengers.getRating();

    return 0;
};