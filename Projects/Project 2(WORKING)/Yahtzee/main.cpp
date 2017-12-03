#include <iostream>
#include <string>       
#include <sstream>       
#include <vector>       
#include <algorithm>

using namespace std;

//The global constants
const int MAX_DIE = 5;
const int MAX_TURNS = 13;
const int MAX_ROUNDS = 8;
const int SCORE_CATEGORIES = 14;

// The title for the program
void tiTLE()
{
    cout << "======================================================================" << endl;
    cout << "  *Multiplayer*   \t | YAHTZEE GAME |" << endl;
    cout << "======================================================================" << endl;
}
// Game instructions
void instruCTIONS()
{
    cout << "\n    \t\t    ---Game Rules--" << endl;
    cout << "\n The game consists of 13 rounds. Each player rolls five dice and";
    cout << "\n attempts to score different combinations. Each turn consists of 3 rolls.";
    cout << "\n A round is complete when each player has taken their turn. For each";
    cout << "\n roll, the player may choose to keep any number of dice he or she wishes.";
    cout << "\n The object of the game is to fill every possible scoring combination,";
    cout << "\n and the player with the highest total score wins! For each round, each";
    cout << "\n player must enter a score into one of the combinations. The player may";
    cout << "\n enter a 0 into any box if he or she does not wish to enter a score for";
    cout << "\n the current dice combination left at the end of the turn." << endl;
    cout << "======================================================================" << endl;
    cout << endl;
}
// The function to see how many players are going to play
int getPlayerCount()
{
    int input = 0;
    bool valid = false;
    do
    {
        cout << "Enter the number of players: ";
        cin >> input;
        if (cin.good() && input > 0)
        {
            valid = true;
        }
        else
        {
            // Clean up (if there is invalid input)
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "---------------------------------------------------" << endl;
            cout << "Sorry only numbers allow as input! please try again" << endl;
            cout << "---------------------------------------------------" << endl;
        }
    } while (!valid);
    return input;
}
// The function to get players names
string getName(int i)
{
    string input;
    cout << "Please enter Player " << i + 1 << "'s name: ";
    cin >> input;
        cout << "WELCOME! To the game " << input << endl;
        cout << endl;
    return input;
}
// Dice Function(The heart of the game)
void rollDie(int die[])
{
    const int MAX_TURNS = 3;
    cout << "First roll, your dice are: ";
    for (int i = 0; i < MAX_DIE; ++i)
    {
        die[i] = rand() % 6 + 1;
        cout << die[i] << " ";
    }
    for (int turn = 1; turn < MAX_TURNS; ++turn)
    {
        cout << "\n Do you want to reroll any dice? (y/n)" << endl;
        char reroll; cin >> reroll;
        // Determine which dice to reroll
        if (toupper(reroll) == 'Y')
        {
            for (int i = 0; i < MAX_DIE; ++i)
            {
                cout << "Reroll Die " << die[i] << "? (y/n)";
                char rerollDie; cin >> rerollDie;
                // Reroll die
                if (toupper(rerollDie) == 'Y') die[i] = rand() % 6 + 1;
            }
            //  Display new and current roll, if a reroll was selected
            cout << "\n New roll, your dice are: ";
            for (int i = 0; i < MAX_DIE; ++i)
            {
                cout << die[i] << " ";
            }
        }
        // If there no reroll requested by the player
        else turn = MAX_TURNS;
    }
}

// Function so the player can choose where he or she wants the score to go
void placeScore(int die[], vector<vector<int>> &scoreCard, int player)
{
    // Check for the Yahtzee bonus 
    bool yahtzee = false;
    if (scoreCard[player][11] >= 50)
    {
        int temp[6];
        for (int i = 0; i < 6; ++i)
        {
            temp[i] = count(die, die + MAX_DIE, i + 1);
            if (temp[i] == 5)
            {
                yahtzee = true;
            }
        }
    }
    string category[13] = { "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", "3 of a Kind", "4 of a  Kind", "Full House", "Small Straight", "Large Straight", "Yahtzee", "Chance" };
    bool repeat;
    do
    {
        repeat = false;
        // Display Roll to score
        cout << "\n Roll to Score: ";
        for (int i = 0; i < MAX_DIE; ++i)
        {
            cout << die[i] << " ";
        }

        // Remove used categories from list
        for (int i = 0; i < 13; ++i)
        {
            if (scoreCard[player][i] != 0)
                category[i] = "----";
        }
        // Display score menu
        cout << "\n Select a Score Catagory:" << endl;
        cout << "1. " << category[0] << " \t 7. " << category[6] << endl;
        cout << "2. " << category[1] << " \t 8. " << category[7] << endl;
        cout << "3. " << category[2] << " \t 9. " << category[8] << endl;
        cout << "4. " << category[3] << " \t 10. " << category[9] << endl;
        cout << "5. " << category[4] << " \t 11. " << category[10] << endl;
        cout << "6. " << category[5] << " \t 12. " << category[11] << endl;
        cout << "\t\t 13. " << category[12] << endl;
        cout << "Enter your Selection: ";
        int option;
        cin >> option;
        cin.ignore();
        // Selection options
        switch (option)
        {
        case 1:
            if (scoreCard[player][0] == 0)
            {
                int tempScore = 0;
                for (int i = 0; i < MAX_DIE; ++i){
                    if (die[i] == 1)
                    {
                        tempScore += die[i];
                    }
                }
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][0] = tempScore;
                break;
            }
            // To make sure the player does not select an option all ready in use
            else if (scoreCard[player][0] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this socre option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 2:
            if (scoreCard[player][1] == 0)
            {
                int tempScore = 0;
                for (int i = 0; i < MAX_DIE; ++i)
                {
                    if (die[i] == 2)
                    {
                        tempScore += die[i];
                    }
                }
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][1] = tempScore;
                break;
            }
            else if (scoreCard[player][1] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this socre option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 3:
            if (scoreCard[player][2] == 0)
            {
                int tempScore = 0;
                for (int i = 0; i < MAX_DIE; ++i)
                {
                    if (die[i] == 3)
                    {
                        tempScore += die[i];
                    }
                }
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][2] = tempScore;
                break;
            }
            else if (scoreCard[player][2] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this socre option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 4:
            if (scoreCard[player][3] == 0)
            {
                int tempScore = 0;
                for (int i = 0; i < MAX_DIE; ++i)
                {
                    if (die[i] == 4)
                    {
                        tempScore += die[i];
                    }
                }
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][3] = tempScore;
                break;
            }
            else if (scoreCard[player][3] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this socre option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 5:
            if (scoreCard[player][4] == 0)
            {
                int tempScore = 0;
                for (int i = 0; i < MAX_DIE; ++i)
                {
                    if (die[i] == 5)
                    {
                        tempScore += die[i];
                    }
                }
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][4] = tempScore;
                break;
            }
            else if (scoreCard[player][4] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this socre option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 6:
            if (scoreCard[player][5] == 0)
            {
                int tempScore = 0;
                for (int i = 0; i < MAX_DIE; ++i)
                {
                    if (die[i] == 6)
                    {
                        tempScore += die[i];
                    }
                }
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][5] = tempScore;
                break;
            }
            else if (scoreCard[player][5] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this socre option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 7:
            if (scoreCard[player][6] == 0)
            {
                int temp[6];
                int tempScore = 0;
                for (int i = 0; i < 6; ++i)
                {
                    temp[i] = count(die, die + MAX_DIE, i + 1);
                    if (temp[i] == 3)
                    {
                        for (int j = 0; j < MAX_DIE; ++j)
                            tempScore += die[j];
                    }
                }
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][6] = tempScore;
                break;
            }
            else if (scoreCard[player][6] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this socre option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 8:
            if (scoreCard[player][7] == 0)
            {
                int temp[6];
                int tempScore = 0;
                for (int i = 0; i < 6; ++i)
                {
                    temp[i] = count(die, die + MAX_DIE, i + 1);
                    if (temp[i] == 4)
                    {
                        for (int j = 0; j < MAX_DIE; ++j)
                            tempScore += die[j];
                    }
                }
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][7] = tempScore;
                break;
            }
            else if (scoreCard[player][7] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this socre option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 9:
            if (scoreCard[player][8] == 0)
            {
                int temp[6];
                int fullHouse = 0;
                for (int i = 0; i < 6; ++i)
                {
                    temp[i] = count(die, die + MAX_DIE, i + 1);
                    if (temp[i] == 3)
                    {
                        ++fullHouse;
                    }
                    else if (temp[i] == 2)
                    {
                        ++fullHouse;
                    }
                }
                if (fullHouse == 2)
                {
                    scoreCard[player][8] = 25;
                    break;
                }
                else
                {
                    scoreCard[player][8] = -1;
                    break;
                }
            }
            else if (scoreCard[player][8] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this score option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 10:
            if (scoreCard[player][9] == 0)
            {
                int count = 0;
                sort(die, die + MAX_DIE);
                for (int i = 1; i < MAX_DIE; ++i)
                {
                    if (die[i] == die[i - 1] + 1)
                    {
                        ++count;
                    }
                }
                if (count > 3)
                {
                    scoreCard[player][9] = 30;
                    break;
                }
                else
                {
                    scoreCard[player][9] = -1;
                    break;
                }
            }
            else if (scoreCard[player][9] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this score option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 11:
            if (scoreCard[player][10] == 0)
            {
                int count = 0;
                sort(die, die + MAX_DIE);
                for (int i = 1; i < MAX_DIE; ++i)
                {
                    if (die[i] == die[i - 1] + 1)
                    {
                        ++count;
                    }
                }
                if (count > 4)
                {
                    scoreCard[player][10] = 30;
                    break;
                }
                else
                {
                    scoreCard[player][10] = -1;
                    break;
                }
            }
            else if (scoreCard[player][10] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this score option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 12:
            if (scoreCard[player][11] == 0)
            {
                int temp[6];
                int tempScore = 0;
                for (int i = 0; i < 6; ++i)
                {
                    temp[i] = count(die, die + MAX_DIE, i + 1);
                    if (temp[i] == 5)
                    {
                        tempScore = 50;
                    }
                }
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][11] = tempScore;
                break;
            }
            else if (scoreCard[player][11] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this score option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        case 13:
            if (scoreCard[player][12] == 0)
            {
                int tempScore = 0;
                for (int i = 0; i < MAX_DIE; ++i)
                    tempScore += die[i];
                if (tempScore == 0)
                {
                    tempScore = -1;
                }
                scoreCard[player][12] = tempScore;
                break;
            }
            else if (scoreCard[player][12] != 0)
            {
                cout << "---------------------------------------------------" << endl;
                cout << "Sorry you already use this score option, please pick another one." << endl;
                cout << "---------------------------------------------------" << endl;
                repeat = true;
                break;
            }

        default:
            cout << "---------------------------------------------------" << endl;
            cout << "Sorry that is an invalid choice! please try again." << endl;
            cout << "---------------------------------------------------" << endl;
            repeat = true;
        }

    } while (repeat);

    // Apply the Yahtzee bonus
    if (yahtzee)
    {
        scoreCard[player][11] += 100;
        cout << "Received Yahtzee Bonus!" << endl;
    }

}

// Calculates the players score and determines if any bonuses apply
void calcScore(vector<vector<int>> &scoreCard, int player)
{
    int upperScore = 0;
    int lowerScore = 0;
    // Reseting any negative values back to zero
    for (int i = 0; i < SCORE_CATEGORIES; ++i)
    {
        if (scoreCard[player][i] == -1)
            scoreCard[player][i] = 0;
    }
    // Upper score
    for (int i = 0; i < 5; ++i)
    {
        upperScore += scoreCard[player][i];
    }
    // Check for bonus
    if (upperScore > 62)
    {
        upperScore += 35;
        cout << "WOOHOOO Recieved Bonus Score!" << endl;
        cout << "-----------------------------" << endl;
    }
    // Lower score
    for (int i = 6; i < 12; ++i)
    {
        lowerScore += scoreCard[player][i];
    }
    // Assign players score
    scoreCard[player][13] = upperScore + lowerScore;
}

// Sorting the score
bool sortScore(const vector<string>& i, const vector<string>& j)
{
    return i[1] > j[1];
}

void scoreRanking(vector <vector<int>> &scoreCard, vector<string> &playerName, int MAX_PLAYERS)
{

    // To combine name and score
    vector<vector<string>> playerRank;
    for (int i = 0; i < MAX_PLAYERS; ++i)
    {

        // This creates temp vectors to hold data from game rows
        vector<string> temp;
        for (int j = 0; j < 2; ++j)
        {
            // To load names into first column
            if (j == 0)
                temp.push_back(playerName[i]);
            // To load scores into second column
            if (j == 1)
                temp.push_back(static_cast<ostringstream*>(&(ostringstream() << scoreCard[i] 
               [13]))->str());
        }
        // Push temp vector
        playerRank.push_back(temp);
    }

    // Sort player's rank by score in descending order
    sort(playerRank.begin(), playerRank.end(), sortScore);

    cout << playerRank[0][0] << " wins!" << endl << endl;

    // To display the player's rank
    cout << "Player Rankings: " << endl;
    for (unsigned int i = 0; i < playerRank.size(); ++i)
    {
        cout << i + 1 << ") ";
        for (unsigned int j = 0; j <playerRank[i].size(); ++j)
        {
            cout << playerRank[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

// The main function of the game
int main()
{
   

    tiTLE();
    instruCTIONS();
    const int MAX_PLAYERS = getPlayerCount();

    vector<string> playerName(MAX_PLAYERS);
    for (int i = 0; i < MAX_PLAYERS; ++i)
    {
        playerName[i] = getName(i);
    }

    vector<vector<int>> roundScore(MAX_ROUNDS, vector<int>(MAX_PLAYERS, 0));

    int round = 0;
    bool repeat = false;
    // Do while loop that controls the game interaction (Game engine!)
    do
    {
        vector<vector<int>> scoreCard(MAX_PLAYERS, vector<int>(SCORE_CATEGORIES, 0));
        srand(time(NULL)); // use this seed insted of srand(time(0));
        int die[MAX_DIE];

        for (int turn = 0; turn < MAX_TURNS; ++turn)
        {
            for (int player = 0; player < MAX_PLAYERS; ++player)
            {
                cout << "\n____________________________________" << endl;
                cout << " Turn " << turn + 1 << endl;
                cout << "--Is " << playerName[player] << "'s Turn.\n" << endl;

                rollDie(die);
                placeScore(die, scoreCard, player);
            }
        }
        cout << "\n____________________________________" << endl;
        cout << "\n The Round is Over!" << endl;
        cout << "\n____________________________________" << endl;

        // Calculating the Scores
        for (int i = 0; i < MAX_PLAYERS; ++i)
        {
            calcScore(scoreCard, i);
            scoreRanking(scoreCard, playerName, MAX_PLAYERS);
        }
        for (int i = 0; i < MAX_PLAYERS; ++i)
        {
            roundScore[round][i] = scoreCard[i][13];
        }

        // Ask to display round scores
        cout << "Display All Round Scores? (y/n)";
        char option;
        cin >> option;
        if (toupper(option) == 'Y')
        {
            // Display played round numbers
            for (int i = 0; i < round + 1; ++i)
            {
                cout << "\tRound " << round + 1;
            } cout << endl;

            // Display player names and their final scores for each round played
            for (int i = 0; i < MAX_PLAYERS; ++i)
            {
                cout << playerName[i] << "\t";
                for (int j = 0; j < round + 1; ++j)
                    cout << roundScore[j][i] << "\t";
                cout << endl;
            } cout << endl;
        }
        // Ask to play another round if max rounds have not been played
        if (round < MAX_ROUNDS)
        {
            cout << "Play another round? (y/n)";
            char replay;
            cin >> replay;
            if (toupper(replay) == 'Y')
            {
                repeat = true;
                ++round;
            }
        }
        else
        {     // Max rounds played, end of the game
            repeat = false;
        }
    } while (repeat);

    cout << "Thanks for playing....Game Over!" << endl;

    system("pause");
    return 0;
}
