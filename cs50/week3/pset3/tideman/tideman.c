#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{

    //todo: if the candidate isnt found keep asking for user input
    // until they give a valid candidate name
    int candidate_found = 0;

    for (int i = 0; i < candidate_count; i ++)
    {
        printf("Candidates[i] %s\n",candidates[i]);

        if(strcmp(candidates[i],name) == 0)
        {
            printf("candidate found: %s\n",candidates[i]);

            ranks[i] = rank;

            //strcpy(ranks[rank],candidates[i]);
            return true;
        }
    }


    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO

    int higher = 0;
    int lower = 1;


    for (int i = 0; i < candidate_count ; i ++)
    {
        printf("ranks[%i]: %i\n", i , ranks[i]);
        printf("candidate: %s\n",candidates[i]);
    }

    printf("\n\n");


    for (int i = 0; i < candidate_count; i ++)
    {
        //printf("i: %i ranks[i]: %i\n", i, ranks[i]);

        for (int j = lower; j < candidate_count; j ++)
        {
            //printf("j: %i ranks[j]: %i\n", j, ranks[j]);
            printf("higher: %i lower:  %i\n", higher, j);
            printf("%s         %s\n",candidates[ranks[higher]],candidates[ranks[j]]);

            preferences[ranks[higher]][ranks[lower]] ++; //preferences[i][j] should represent the number of voters who prefer candidate i over candidate j

        }

        higher ++;
        lower ++;
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO

    printf("\n\n add_pairs function \n\n");

    for (int i = 0; i < MAX; i ++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("preferences[%i][%i] = %i\n", i, j, preferences[i][j]);
        }
    }




    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

