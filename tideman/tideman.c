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

bool find_path(int from, int to);

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
    for (int i = 0; i < candidate_count; i++) {
        string cand_name = candidates[i];
        if (strcmp(cand_name, name) == 0) {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    printf("\nRank: %d %d %d", ranks[0], ranks[1], ranks[2]);
    int prefs_length = sizeof(preferences) / sizeof(preferences[0]);
    for (int i = 0; i < prefs_length; i++) {
        int vote = preferences[i][0];
        if (vote == 0 && vote == preferences[i][1]) {
            // empty ballot? Fill it then
            for (int j = 0; j < candidate_count; j++) {
                preferences[i][j] = ranks[j];
            }
            return;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    int prefs_length = sizeof(preferences) / sizeof(preferences[0]);
    for (int i = 0; i < prefs_length; i++) {
        for (int j = 0; j < (candidate_count - 1); j++) {
            int rank0 = preferences[i][j];
            int rank1 = preferences[i][j+1];
            if (rank0 != rank1) {
                pair pair;
                pair.winner = rank0;
                pair.loser = rank1;
                pairs[pair_count] = pair;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // record strengths in a winner-loser two-dimensional array:
    //          loser   loser   loser
    // winner   0       2       0
    // winner   1       0       1
    // etc
    int pair_strengths[candidate_count][candidate_count];
    for (int i = 0; i < pair_count; i++) {
        pair pair = pairs[i];
        pair_strengths[pair.winner][pair.loser]++;
    }

    printf("Filled pair strengths");

    // there cannot be more votes per each pair than there are voters.
    // record pairs in a two-dimensional array, where first dimension
    // is the vote strengths, descending
    pair grouped_pairs[MAX][MAX];
    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            int strength = pair_strengths[i][j];
            if (strength > 0 && strength <= 50) {
                printf("\nPair %d:%d strength %d", i, j, strength);
                for (int k = 0; k < candidate_count; k++) {
                    if (grouped_pairs[(MAX-strength)][k].winner == 0 && grouped_pairs[(MAX-strength)][k].loser == 0) {
                        pair pair;
                        pair.winner = i;
                        pair.loser = j;
                        grouped_pairs[(MAX-strength)][k] = pair;
                        break;
                    }
                }
            }
        }
    }

    printf("\nGrouped pairs");

    int sorted_pair_count = 0;
    pair sorted_pairs[MAX];
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            int winner = grouped_pairs[i][j].winner;
            int loser = grouped_pairs[i][j].loser;
            if (!((winner == 0 && loser == 0) || winner < 0 || loser < 0 || winner > candidate_count || loser > candidate_count)) {
                sorted_pairs[sorted_pair_count] = grouped_pairs[i][j];
                sorted_pair_count++;
            }
        }
    }
    for (int i = 0; i < (MAX * (MAX - 1) / 2); i++) {
        pairs[i] = sorted_pairs[i];
    }
    pair_count = sorted_pair_count;

    printf("\nFinished sorting");
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    printf("\nGoing to lock");
    for (int i = 0; i < (MAX * (MAX - 1) / 2); i++) {
        pair pair = pairs[i];
        int loser = pair.loser;
        int winner = pair.winner;
        if (!(loser < 0 || winner < 0 || loser > MAX || winner > MAX)) {
            bool path = find_path(loser, winner);
            if (!path) {
                locked[winner][loser] = true;
            }
        }
    }
    printf("\nLocked");
}

bool find_path(int from, int to) {
    printf("\nGoing to find path from %d to %d", from, to);
    // check whether there will be a cycle from:via
    if (from == to) {
        return false;
    }
    if (locked[from][to]) {
        printf("\nFound lock from %d to %d", from, to);
        return true;
    }
    for (int i = 0; i < MAX; i++) {
        if (locked[from][i]) {
            printf("\nFound lock from %d to %d", from, i);
            if (find_path(i, to)) {
                return true;
            }
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    printf("\nGoing to find winner");
    int pointed_to[candidate_count];
    int pointed_count = 0;
    for (int i = 0; i < (MAX * (MAX - 1) / 2); i++) {
        for (int j = 0; j < (MAX * (MAX - 1) / 2); j++) {
            if (locked[i][j]) {
                printf("\nFound lock from %d to %d", i, j);
                pointed_to[pointed_count] = j;
                pointed_count++;
            }
        }
    }
    for (int i = 0; i < candidate_count; i++) {
        bool pointed = false;
        for (int j = 0; j < pointed_count; j++) {
            if (i == pointed_to[j]) {
                pointed = true;
                break;
            }
        }
        if (!pointed) {
            printf("Winner: %s", candidates[i]);
        }
    }
    // TODO
    return;
}