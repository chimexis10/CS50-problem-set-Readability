#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define function prototypes
int count_letters(string words);
int count_words(string typings);
int count_sentences(string wordings);
int main(void)
{
    // Get string input from user
    string s = get_string("Input: ");

    // Obtain the index number using necessary functions and formula
    int let = count_letters(s);
    int wor = count_words(s);
    int sen = count_sentences(s);
    float L = (let * 100) / wor;
    float S = (sen * 100) / wor;
    float num = 0.0588 * L - 0.296 * S - 15.8;
    int index = (int) round(num);

    // Determine reading grade level using index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade: %i\n", index);
    }
}

// Get number of letters in input string
int count_letters(string words)
{
    int nch = strlen(words);
    printf("nch: %i\n", nch);
    int count1 = 0;
    for (int i = 0; i < nch; i++)
    {
        if (isalpha(words[i]))
        {
            count1++;
        }
        else
        {
            count1+=0;
        }
    }
    return count1;
}

// Get number of words in input string
int count_words(string typings)
{
    int n = strlen(typings);
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (isspace(typings[i]))
        {
            count2++;
        }
        else
        {
            count2+=0;
        }
    }
    int count3 = count2 + 1;
    return count3;
}

//Get number of sentences in input string
int count_sentences(string wordings)
{
    int m = strlen(wordings);
    int count4 = 0;
    for (int i = 0; i < m; i++)
    {
        if (wordings[i] == '.' || wordings[i] == '?' || wordings[i] == '!')
        {
            count4++;
        }
        else
        {
            count4+=0;
        }
    }
    return count4;
}
