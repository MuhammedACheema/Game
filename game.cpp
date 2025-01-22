#include <iostream>

// How I will base each scoring measure:

// // Weights for each category
// float weight_points = 0.20;       // 20% of the total score
// float weight_rebounds = 0.10;     // 10%
// float weight_assists = 0.10;      // 10%
// float weight_championships = 0.30;// 30%
// float weight_awards = 0.20;       // 20%
// float weight_allstars = 0.10;     // 10%

// consider building another func that will return score for the player, and then return the better player

class Player{
    public:
        std::string name;
        float points;
        float rebounds;
        float assists;
        int championships;
        int awards;
        int allstars;
        
    
        Player(std::string name, float points, float rebounds, float assists, int championships, int awards, int allstars){
            this-> name = name;
            this-> points = points;
            this-> rebounds = rebounds;
            this-> assists = assists;
            this-> championships = championships;
            this-> awards = awards; 
            this-> allstars = allstars;
        }
};

int main(){
    // info on player 1
    std::string name1;
    float points1;
    float rebounds1;
    float assists1;
    int championships1;
    int awards1;
    int allstars1;

    // info needed on player 2
    std::string name2;
    float points2;
    float rebounds2;
    float assists2;
    int championships2;
    int awards2;
    int allstars2;

    std::cout << "You have the ability to provide me 2 basketball players, and I will compare them for you and provide you statistical reasoning who had a better career.\n" << "You must provide a name, career avg in points, rebounds assists, championships, individual awards(mvps, dpoy, roy, all team selection etc), and finally allstar selections \n" << "Are you ready to play" << std::endl;
    
    Player player1(name1, points1, rebounds1, assists1, championships1, awards1, allstars1);
    Player player1(name2, points2, rebounds2, assists2, championships2, awards2, allstars2);

    return 0;
}