#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int get_score(string word1)
{
    int sub = 65;
    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int word2[20];
    int temp = 0;
    int score = 0;
    int length = strlen(word1);
    int tempc;
    for (int x = 0; x < length; x++)
    {
        tempc = toupper(word1[x]);
        word2[x] = tempc;
    }
    for (int i = 0; i < length; i++)
    {
        temp = word2[i];
        temp -= sub;
        if ((temp < 26) && (temp >= 0))
        {
            score += values[temp];
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
