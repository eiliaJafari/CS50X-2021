#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // To check if the vote is valid
    for (int i = 0; i < candidate_count; i++)
    {
        // If the candidate exists
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Add a vote
            candidates[i].votes++;
            return true;
        }
    }

    // If the candidate doesn't exist
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // For loops and sorting
    int i, j, temp;
    // Number of votes for each candidate
    int numbers[candidate_count];

    // Add the number of votes for each candidate to the array
    for (i = 0; i < candidate_count; i++)
    {
        numbers[i] = candidates[i].votes;
    }

    // Sorting the array
    for (i = 0; i < candidate_count; i++)
    {
        for (j = i + 1; j < candidate_count; j++)
        {
            if (numbers[i] < numbers[j])
            {
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    // Printing the winner(s)
    for (i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == numbers[0])
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}

