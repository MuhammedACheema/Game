#include <iostream>
#include <cmath>
// Could also consider using the 
// Z-Scores are the standard method in Fantasy NBA to normalize player stats and calculate their value.

// A z-score indicates how many standard deviations a value is from the average of a dataset. In other words, the z-score equals the value minus the average, 
// divided by the standard deviation.

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

// approximation of std of spread for all vals info provided by chat
float std_ppg = 5.2;
float std_rpg = 2.67;
float std_apg = 1.20;
float std_chip = .3;
float std_all_star = .4;
float std_awards = .05;


float player_val(const Player& x){
    float total = 0;

    float z_ppg = (x.points - avg_ppg) / std_ppg;
    float z_rpg = (x.rebounds - avg_rpg) / std_rpg;
    float z_apg = (x.assists - avg_apg) / std_apg;
    float z_chip = (x.championships - avg_chip) / std_chip;
    float z_awards = (x.awards - avg_awards) / std_awards;
    float z_allstars = (x.allstars - avg_all_star) / std_all_star;

    total = z_apg + z_ppg + z_rpg + z_chip + z_awards + z_allstars;

    return total;
}

void userinputs(std::string& name, float& points, float& rebounds, float& assists, int& championships, int& awards, int& allstars) {
    std::cout << "Enter the player's name and press Enter: ";
    std::getline(std::cin, name);

    std::cout << "Enter the player's career average points per game and press Enter: ";
    while (!(std::cin >> points)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the player's career average rebounds per game and press Enter: ";
    while (!(std::cin >> rebounds)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the player's career average assists per game and press Enter: ";
    while (!(std::cin >> assists)) {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the number of championships the player has won and press Enter: ";
    while (!(std::cin >> championships)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the number of individual awards the player has won (excluding All-Star appearances) and press Enter: ";
    while (!(std::cin >> awards)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the number of All-Star appearances the player has had and press Enter: ";
    while (!(std::cin >> allstars)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Clear the input buffer after numeric inputs
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main() {
    std::string name1, name2;
    float points1, rebounds1, assists1, points2, rebounds2, assists2;
    int championships1, awards1, allstars1, championships2, awards2, allstars2;

    std::cout << "You can provide me with details of two basketball players, and I will compare their careers.\n";
    std::cout << "For each player, please provide the following: name, career average points, rebounds, assists, championships, individual awards, and All-Star appearances.\n";
    std::cout << "For clarification individual awards includes mvps, dpoy, roy, all team selection etc, everything but all star selections.\n";

    std::cout << "\n--- Player 1 Details ---\n";
    userinputs(name1, points1, rebounds1, assists1, championships1, awards1, allstars1);

    std::cout << "\n--- Player 2 Details ---\n";
    userinputs(name2, points2, rebounds2, assists2, championships2, awards2, allstars2);

    Player player1(name1, points1, rebounds1, assists1, championships1, awards1, allstars1);
    Player player2(name2, points2, rebounds2, assists2, championships2, awards2, allstars2);

    float val1 = player_val(player1);
    float val2 = player_val(player2);

    // Example Output
    std::cout << "\nComparison Results:\n";
    std::cout << "Player 1: " << player1.name << "\n"
              << "Points: " << player1.points << ", Rebounds: " << player1.rebounds << ", Assists: " << player1.assists
              << ", Championships: " << player1.championships << ", Awards: " << player1.awards << ", All-Stars: " << player1.allstars << ", Player Career Score: " << val1 << "\n";
              

    std::cout << "Player 2: " << player2.name << "\n"
              << "Points: " << player2.points << ", Rebounds: " << player2.rebounds << ", Assists: " << player2.assists
              << ", Championships: " << player2.championships << ", Awards: " << player2.awards << ", All-Stars: " << player2.allstars << ", Player Career Score: " << val2 << "\n";
    
    if(val1 > val2){
        std::cout << player1.name << " is the better player. \n";
    } else if (val2 > val1){
        std::cout << player2.name << " is the better player. \n";
    } else{
        std::cout << "Both players are equally matched";
    }

    return 0;
}