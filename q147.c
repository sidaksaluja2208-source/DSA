/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.*/

#include <stdio.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 50

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][NAME_LEN];
    
    // Input votes
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char unique[MAX][NAME_LEN];
    int count[MAX] = {0};
    int unique_count = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int found = 0;
        
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(votes[i], unique[j]) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(unique[unique_count], votes[i]);
            count[unique_count] = 1;
            unique_count++;
        }
    }

    // Find winner
    int max_votes = 0;
    char winner[NAME_LEN];

    for (int i = 0; i < unique_count; i++) {
        if (count[i] > max_votes) {
            max_votes = count[i];
            strcpy(winner, unique[i]);
        }
        else if (count[i] == max_votes) {
            if (strcmp(unique[i], winner) < 0) {
                strcpy(winner, unique[i]);
            }
        }
    }

    printf("%s %d\n", winner, max_votes);

    return 0;
}