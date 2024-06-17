#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string word1) //calculates the score of a single word
{
    int sub = 65;
    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; 
    //values associated for each letter in the alphabet, sorted by alphabetical order where A is index 0 and Z is index 25
    int word2[20];
    int temp = 0;
    int score = 0;
    int length = strlen(word1);
    int tempc;
    for (int x = 0; x < length; x++) //converts each letter in the word into uppercase
    {
        tempc = toupper(word1[x]);
        word2[x] = tempc;
    }
    for (int i = 0; i < length; i++) //
    {
        temp = word2[i];
        temp -= sub; //calculates the index from a letter using ASCII to convert a letter "A" to the number 0
        if ((temp < 26) && (temp >= 0))
        {
            score += values[temp]; //uses the index to attain the score assigned to that letter and add it to the total
        }
    }
    return score;
}

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    int score1 = get_score(word1);
    int score2 = get_score(word2);
    //score of each player is calculated and compared
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}
