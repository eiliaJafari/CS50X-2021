#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototype for formula
int formula(int pi, int key, int flag);

int main(int argc, string argv[])
{
    int key;

    // For more than one entry or non entry
    if (argc == 1 || argc > 2)
    {
        printf("No argument or more than one argument!\n");
        return 1;
    }

    // If it was one entry
    else
    {
        int len = strlen(argv[1]);
        // To check if the input is int
        int check;

        for (int i = 0; i < len; i++)
        {
            check = (int)argv[1][i];

            // Anything except digits
            if (check <= 47 || check >= 58)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }

            // It's only digits and it's a valid input
            else
            {
                key = atoi(argv[1]);
            }
        }

    }

    // To get the plain text from user and calculating the length
    string plain_text;
    plain_text = get_string("plaintext:  ");
    int len = strlen(plain_text);

    // To encrypt the plain text
    char ch;
    char ciphertext[len];

    // the encrypted index and the actual index
    int ci;
    int pi;

    for (int i = 0; i < len; i++)
    {
        // if the char is a lowercase letter
        if (islower(plain_text[i]) != 0)
        {
            pi = (int)plain_text[i];

            ci = formula(pi, key, 0);

            ch = (char)ci;
            ciphertext[i] = ch;
        }

        // if the char is a uppercase letter
        else if (isupper(plain_text[i]) != 0)
        {
            pi = (int)plain_text[i];

            ci = formula(pi, key, 1);

            ch = (char)ci;
            ciphertext[i] = ch;
        }

        // If it's not alphabet
        else
        {
            ciphertext[i] = plain_text[i];
        }
    }

    // Because check50 didn't pass 2 of the test cases
    ciphertext[len] = '\0';

    // Printing the cipher
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

int formula(int pi, int key, int flag)
{
    int ci;
    int mod;
    int res;

    // If it's uppercase letter
    if (flag == 1)
    {
        mod = 91;

        res = pi - 65;
        ci = ((res + key) % 26) + 65;

        return ci;
    }

    // If it's lowercase letter
    else if (flag == 0)
    {
        mod = 123;

        res = pi - 97;
        ci = ((res + key) % 26) + 97;

        return ci;
    }

    printf("flag was wrong !!!\n");
    return 1;
}
