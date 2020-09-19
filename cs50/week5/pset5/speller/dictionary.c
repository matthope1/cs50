// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 150000; // change n to something larger when neeeded

unsigned int numOfWords;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    /*
    return true given any capitalization thereof;
    none of foo, foO, fOo, fOO, fOO, Foo, FoO, FOo,
    and FOO should be considered misspelled.
    */
    // TODO
    //tolower(c); //strcasecmp
    // result = strcasecmp(str1, str2);


    int index = hash(word);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        //printf("cursor->word: %s\n",cursor->word);
        //printf("word: %s\n",word);
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }



    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO input word,
    // output: numberical index between 0 and N - 1 inclusive
    const int p = 31;
    const int m = 150000; // 143,091 words
    unsigned int hash_value = 0;
    int p_pow = 1;

    char c;

    //printf("hash: %s\n",word);
    int i = 0;
    c = tolower(word[i]);

    while (c != '\0')
    {
        //printf("%c ",c);

        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % N;
        p_pow = (p_pow * p) % N;
        c = tolower(word[i++]);
    }

    //printf("\n");

    //printf("computed hash value: %d\n",hash_value);

    return hash_value;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO

    FILE *file;
    file = fopen(dictionary, "r");

    if (file != NULL)
    {
        char word[LENGTH + 1];
        while (fscanf(file, "%s", word) != EOF) //will return EOF once it reaches end of file
        {

            //printf("word: %s\n",word);
            // when using malloc itll return null cant allocate memory;
            int index = hash(word);

            node *n = malloc(sizeof(node));

            if (n == NULL)
            {
                return false;
            }
            // create node for each word

            // increment size;
            numOfWords++;

            strcpy(n->word, word);
            n->next = NULL;

            table[index] = n;

        }

    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numOfWords;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO

    node *cursor;
    node *temp;

    for (int i = 0; i < N; i ++)
    {
        //printf("i: %d\n",i);
        cursor = table[i];

        while (cursor != NULL)
        {
            temp = cursor;
            //printf("cursorvalue: %s\n",cursor->word);

            cursor = cursor->next;

            free(temp);

        }
    }



    if (cursor == NULL)
    {
        return true;
    }


    return false;
}


/*
hash function citation
“String Hashing.” String Hashing - Competitive Programming Algorithms, cp-algorithms.com/string/string-hashing.html#toc-tgt-0.
*/