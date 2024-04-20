#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { CONTINUE, WON, LOST}; //keeps track of game status
int numRolls;
int n = 1000, wins = 0, losses = 0, gameLen = 0; //initialize variables
int winAmount[21] = {0}; //creates two arrays of length 21 initialized to zero
int lossAmount[21] = {0};

int rollDice(void); //function signature
void printResults(void);

int main(void){
    srand(time(NULL)); //seeds random with time function
    int count = 1;
    while(count <= n){ //plays game 1000 times
        numRolls = 0;
        ++count;
        
        int myPoint;
        enum Status gameStatus;
        int sum = rollDice();
        
        switch(sum) { //sets the game status depending on the outcome of roll
            case 7:
            case 11:
                gameStatus = WON;
                break;
            case 2:
            case 3:
            case 12:
                gameStatus = LOST;
                break;
            default:
                gameStatus = CONTINUE;
                myPoint = sum;
                break;
        }
        
        while(gameStatus == CONTINUE){ //if you have to reroll to continue game
            sum = rollDice();
            if(sum == myPoint){
                gameStatus = WON;
            } else{
                if(sum == 7){
                    gameStatus = LOST;
                }
            }
        }
        
        if(gameStatus == WON){ //for a win this adds to correct column and continues to next game
            ++wins;
            if(numRolls <= 20) ++winAmount[numRolls-1];
            else ++winAmount[20];
        } else{
            ++ losses;
            if(numRolls <= 20) ++lossAmount[numRolls-1];
            else ++lossAmount[20];
        }
        
        gameLen += numRolls;
    }
    printResults();
}

int rollDice(void) {//rolls dice and returns the sum of the two
    ++numRolls;
    int die1 = 1 + (rand() % 6);
    int die2 = 1 + (rand() % 6);
    return die1 + die2;
}

void printResults(void) { //answers the questions asked and displays to user
    printf("\na\tHow many games are won on each roll:\n");
    for(int i = 0; i < 20; ++i) {
        printf("\tRoll %d: %d\n", i+1, winAmount[i]);
    }
    printf("\t>20 Rolls: %d\n", winAmount[20]);

    printf("\nb\tHow many games are lost on each roll:\n");
    for(int i = 0; i < 20; ++i) {
        printf("\tRoll %d: %d\n", i+1, lossAmount[i]);
    }
    printf("\t>20 Rolls: %d\n", lossAmount[20]);

    printf("\nc.\n");
    printf("\tWin Percentage: %.2f %%\n", (double)wins/n * 100);
    
    printf("\nd.\n");
    printf("\t%d rolls on average\n", gameLen/n);

    printf("\ne\tThe win percentage at each game length to show you odds with increased length:\n");
    for(int i = 0; i < 20; ++i) {
        printf("\t%d Rolls to Win: %.2f %%\n", i+1, (float)winAmount[i]/n * 100);
    }
    printf("\t>20\t%.2f %%\n", (float)winAmount[20]/n * 100);
}
