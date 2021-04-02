// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"
#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
unsigned int h;

int words;
// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    h = hash(word);
    node *trav = table[h];
    while (trav != NULL)
    {
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
        else
        {
            trav = trav->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //djb2 by Dan Bernstein
    unsigned long hash = 5381;
    int c;
    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;

}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char newword[LENGTH+1];
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    while (fscanf(dict, "%s", newword) != EOF)
    {
        node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return false;
    }
    strcpy(n->word, newword);
    h = hash(newword);
    n->next = table[h];
    table[h] = n;
    words ++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (words > 0)
    {
        return words;
    }
    else
    {
        return 0;
    }

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    for (int i = 0; i < N; i++)
    {

        node *traverse = table[i];

        while (traverse)
        {

            node *buffer = traverse;

            traverse = traverse->next;

            free(buffer);
        }

        if (i == N - 1 && traverse == NULL)
        {
            return true;
        }
    }
    return false;
}
