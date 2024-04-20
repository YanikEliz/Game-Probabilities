#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5

//all function signatures needed in main function

void shuffle(unsigned int wDeck[][FACES]);
void deal(unsigned int wDeck[][FACES], int hand[][2], const char *face[], const char *suit[]);
int pair(int hand[][2], const char *suit[], const char *face[]);
int threeOfAKind(int hand[][2], const char *suit[], const char *face[]);
int fourOfAKind(int hand[][2], const char *suit[], const char *face[]);

int main(void){
    const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six",
                            "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    //seed random function with time and initialize all game results to zero
    srand(time(NULL));
    int pairs = 0;
    int threes = 0;
    int fours = 0;
    for(int i = 0; i < 100; i++){
        //initialize deck to zero, declare the array for a hand and deals from shuffled deck
        unsigned int deck[SUITS][FACES] = {0};
        int hand[HAND][2];
        shuffle(deck);
        deal(deck, hand, suit, face);
        //each time a win type is seen 1 is added to the sum
        pairs += pair(hand, suit, face);
        threes += threeOfAKind(hand, suit, face);
        fours += fourOfAKind(hand, suit, face);
    }
    //neatly displays results after 100 runs have been made and calculates win percentage
    printf("%s","100 poker hands have been run and their results are displayed below: \n");
    printf("Two of a kind: %d\n", pairs);
    printf("Three of a kind: %d\n", threes);
    printf("Four of a kind: %d\n", fours);
    printf("Losses: %d\n", 100-(pairs+threes+fours));
    printf("Percentage of Wins: %.2f\n", (float)(pairs+threes+fours)/100);
    return 0;
}

void shuffle(unsigned int wDeck[][FACES]){
    //overides the zeros in deck with randomly assigned so if not overridden the "card" is zero otherwise takes up that space
    for(size_t card = 1; card <= CARDS; ++card){
        size_t row, column;
        do{
            row = rand() % SUITS;
            column = rand() % FACES;
        } while (wDeck[row][column] != 0);
        wDeck[row][column] = card;
    }
}

void deal(unsigned int wDeck[][FACES], int hand[][2], const char *face[], const char *suit[]){
    //uses the first 5 indices of the deck to create a hand and assigns to the correct array
    int r = 0;
    for (size_t card = 0; card < HAND; ++card){
        for (size_t row = 0; row < SUITS; ++row){
            for (size_t column = 0; column < FACES; ++column){
                if (wDeck[row][column] == card){
                    hand[r][0] = row;
                    hand[r][1] = column;
                    r++;
                }
            }
        }
    }
}

int pair(int hand[][2], const char *suit[], const char *face[]){
    //determines count of each face value then returns 1 if there is a pair else 0
    int count[FACES] = {0};
    for(int r = 0; r < HAND; r++){
        count[hand[r][1]]++;
    }
    for(int faceCount = 0; faceCount < FACES; faceCount++){
        if(count[faceCount] == 2) return 1;
        else return 0;
    }
}

int threeOfAKind(int hand[][2], const char *suit[], const char *face[]){
    //determines count of each face value then returns 1 if there is threeOfAKind else 0
    int count[FACES] = {0};
    for(int r = 0; r < HAND; r++){
        count[hand[r][1]]++;
    }
    for(int faceCount = 0; faceCount < FACES; faceCount++){
        if(count[faceCount] == 3) return 1;
        else return 0;
    }
}

int fourOfAKind(int hand[][2], const char *suit[], const char *face[]){
    //determines count of each face value then returns 1 if there is fourOfAKind else 0
    int count[FACES] = {0};
    for(int r = 0; r < HAND; r++){
        count[hand[r][1]]++;
    }
    for(int faceCount = 0; faceCount < FACES; faceCount++){
        if(count[faceCount] == 4) return 1;
        else return 0;
    }
}
