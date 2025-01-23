#include <iostream>
#include <cmath>
// Could also consider using the 
// Z-Scores are the standard method in Fantasy NBA to normalize player stats and calculate their value.

// A z-score indicates how many standard deviations a value is from the average of a dataset. In other words, the z-score equals the value minus the average, divided by the standard deviation.



// How I will base each scoring measure:

// // Weights for each category
// float weight_points = 0.20;       // 20% of the total score
// float weight_rebounds = 0.10;     // 10%
// float weight_assists = 0.10;      // 10%
// float weight_championships = 0.30;// 30%
// float weight_awards = 0.20;       // 20%
// float weight_allstars = 0.10;     // 10%

// consider building another func that will return score for the player, and then return the better player


// finish up zscore func and then do the comparison and finish project
class Player{
    public:
        std::string name;
        float points;
        float rebounds;
        float assists;
        int championships;
        int awards;
        int allstars;
        // league avgs per player
        
    
        Player(std::string name, float points, float rebounds, float assists, int championships, int awards, int allstars){
            this-> name = name;
            this-> points = points;
            this-> rebounds = rebounds;
            this-> assists = assists;
            this-> championships = championships;
            this-> awards = awards; 
            this-> allstars = allstars;
        }

        // Static method to calculate the league average per player based on team avgs
        static float get_avg(float stat){
            int games = 2460;
            int players = 10;

            float total_stat = games * stat;
            int total_players = games * players;

            return total_stat / total_players;

        }
};

// gain each avg per player this is an approximation used the 2024-25 nba season and math for the avg chips all stars and awards
float avg_ppg = Player::get_avg(112.9);
float avg_rpg = Player::get_avg(44.1);
float avg_apg = Player::get_avg(26.3);
float avg_chip = .2;
float avg_all_star = .16;
float avg_awards = .54;

// approximation of std of spread for all vals
float std_ppg = 5.2;
float std_rpg = 2.67;
float std_apg = 1.20;
float std_chip = .3;
float avg_all_star = .4;
float avg_awards = .05;


float player_val(const Player& x){
    float total = 0;

    float z_ppg = (x.points - avg_ppg);


}




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

    std::cout << avg_rpg <<std::endl << avg_ppg <<std::endl << avg_apg <<std::endl;

    std::cout << "You have the ability to provide me 2 basketball players, and I will compare them for you and provide you statistical reasoning who had a better career.\n" << "You must provide a name, career avg in points, rebounds assists, championships, individual awards(mvps, dpoy, roy, all team selection etc), and finally allstar selections \n" << "Are you ready to play" << std::endl;
    
    Player player1(name1, points1, rebounds1, assists1, championships1, awards1, allstars1);
    Player player2(name2, points2, rebounds2, assists2, championships2, awards2, allstars2);

    return 0;
}