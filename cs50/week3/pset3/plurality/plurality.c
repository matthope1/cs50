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
    // TODO
    /*
    name represents the name of the candidate who was voted for
    if name matches on the the names of the candidates in the election
    then update that condidates total vote count by 1
    then return True to signify a successful ballot

    if name does not match any of the names, no vote totals should change
    then return false
    */

    //printf("candidate count: %i\n",candidate_count);

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes ++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    /*
    this function should print out the name of the candidate who
    received the most votes in the election, then print a newline
    it's possible that the election could end in a tie if
    multiple candidates each have the max num of votes
    in that case you need to output the names of each
    of the winning candidates on a seperate line
    */

    int winner_index = 0;
    int highest_vote_count = 0;

    string winners[MAX];
    int tie_index = 0;


    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest_vote_count)
        {
            winner_index = i;
            highest_vote_count = candidates[i].votes;
        }

    }

    //printf("%s\n",candidates[winner_index].name);

    // we can find the person with the highest amount of votes
    // then we can go thru the list again and if we find anyone else with the same amount of votes
    // we can add them to our "to be printed" list

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highest_vote_count)
        {
            winners[tie_index] = candidates[i].name;
            tie_index++;
        }
    }


    for (int i = 0; i < tie_index; i ++)
    {
        printf("%s\n", winners[i]);
    }

    return;
}

