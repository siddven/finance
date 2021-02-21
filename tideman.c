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
    for (int i = 0; i < pair_count; i++)
    {
       printf("%i over %i\n", pairs[i].winner, pairs[i].loser);
    }
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    int truorfalse = 0;
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(name,candidates[i]) == 0) {
            truorfalse = 1;
            ranks[rank] = i;
        }
    }
if (truorfalse == 1) {
        return true;
    }
    return false;
    }

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
   for (int i = 0; i < candidate_count; i++)
   {

               for (int j = i; j < candidate_count; j ++)
       {
           if (ranks[i] != ranks[j])
           {
          preferences[ranks[i]][ranks[j]] += 1;
}

       }
           }
   for (int i = 0; i < candidate_count; i++)
   {
       for (int j = 0; j < candidate_count; j++)
       {
           printf("%i\n", preferences[i][j]);
       }
   }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int a = 0;
    for (int i = 0; i < candidate_count; i++)
    {


        for (int j = 0; j < candidate_count; j++)
        {

                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[a].winner = i;
                    pairs[a].loser = j;
                    pair_count ++;
                    a++;
                }

        }


        }
        return;
    }




// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int sorts[36];
    int a = 0;
    int largest = -1;
    int x = 0;
    pair y;


     for (int i = 0; i < candidate_count; i++)
     {
         sorts[i] = -1;
     }

    for (int i = 0; i < pair_count; i++)
    {
        sorts[i] = preferences[pairs[a].winner][pairs[a].loser] - preferences[pairs[a].loser][pairs[a].winner];
        a++;
    }


    for (int i = 0; i < pair_count; i++)
    {
        largest = -1;
        for (int j = i; j < pair_count; j++)
        {
            if (largest < sorts[j])
            {
                largest = sorts[j];
                y = pairs[j];
                x = j;
            }
        }
        sorts[x] = sorts[i];
        sorts[i] = largest;
        pairs[x] = pairs[i];
        pairs[i] = y;


    }
    /*for (int i = 0; i < pair_count; i++)
    {
        printf("%i\n", sorts[i]);
    }*/


    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    int arrows[candidate_count];
    int memory = 0;
    bool go = false;
    for (int i = 0; i < candidate_count; i++)
    {
        arrows[i] = 0;
    }
    for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        memory = i;
    }
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            if (locked[i][j] == true)
            {
                arrows[j] += 1;
            }
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (arrows[i] == 0)
        {
            go = true;
        }
    }
    if (go == false)
    {
        locked[memory][memory] = false;
    }

    for (int j = 0; j < candidate_count; j++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            printf("%i\n", locked[j][i]);

        }

    }
    for (int i = 0; i < candidate_count; i++)
    {
        printf("arrow: %i\n", arrows[i]);
    }


    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

