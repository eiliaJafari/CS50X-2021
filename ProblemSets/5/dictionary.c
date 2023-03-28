// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table = 2 ^ 16
const unsigned int N = 65536;

// Hash table
node *table[N];

// Counter for words
int counter = 0;
// Make an empty head
node *head = NULL;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int len = strlen(word);
    char clone[len + 1];
    clone[len] = '\0';

    for (int i = 0; i < len; i++)
    {
        clone[i] = tolower(word[i]);
    }

    int the_hash = hash(clone);
    node *temp = table[the_hash];

    if (temp == NULL)
    {
        return false;
    }

    while (temp != NULL)
    {
        if (strcasecmp(temp -> word, clone) == 0)
        {
            return true;
        }

        temp = temp -> next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    long hash = 5381;
    int temp = *word;

    while (temp == *word++)
    {
        hash = ((hash << 5) + hash) + temp;
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char buff[LENGTH + 1];
    while (fscanf(file, "%s", buff) != EOF)
    {
        node *the_node = malloc(sizeof(node));

        if (the_node == NULL)
        {
            fclose(file);
            return false;
        }

        else
        {
            strcpy(the_node -> word, buff);
            the_node -> next = NULL;
            int ind = hash(buff);
            the_node -> next = table[ind];
            table[ind] = the_node;
            counter++;
        }
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *t1 = table[i];
        while (t1 != NULL)
        {
            node *t2 = t1;
            t1 = t1 -> next;
            free(t2);
        }
    }

    return true;
}
