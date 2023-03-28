#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


// Functions prototypes
int formula(float, float);
float char_count(string);
float word_count(string);
float sentence_count(string);

int main(void)
{
    // To get the text from user
    string text = get_string("Text: ");

    // Counting characters, words and sentences
    float char_counted = char_count(text);
    float word_counted = word_count(text);
    float sentence_counted = sentence_count(text);

    // Calculating L and S
    float L = (char_counted * 100) / word_counted;
    float S = (sentence_counted * 100) / word_counted;

    // Calculating the grade
    int grade = formula(L, S);

    // Printing the grade
    // If it was betweeen 1 and 16
    if (grade >= 1 && grade < 16)
    {
        printf("Grade %i\n", grade);
    }

    // If it was grater than 16
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    // If it was lesser than 1
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

}

// All the functions

// The formula
int formula(float L, float S)
{
    int result;
    float grade = (0.0588 * L) + (-0.296 * S) - 15.8;
    grade = round(grade);
    result = (int)grade;

    return result;
}

// Character count
float char_count(string text)
{
    int length = strlen(text);
    char ch;
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        ch = tolower(text[i]);

        if (ch >= 'a' && ch <= 'z')
        {
            count += 1;
        }
    }
    return (float)count;
}

// Word count
float word_count(string text)
{
    int length = strlen(text);
    int space_count = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            space_count += 1;
        }
    }

    if (space_count == 0)
    {
        return (float)space_count;
    }

    else
    {
        space_count += 1;
        return (float)space_count;
    }
}

// Sentence count
float sentence_count(string text)
{
    int length = strlen(text);
    int count = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count += 1;
        }
    }

    return (float)count;
}