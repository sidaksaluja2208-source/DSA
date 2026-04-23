/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};

    // Step 1: Count frequency
    for(int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find first non-repeating character
    for(int i = 0; s[i] != '\0'; i++) {
        if(freq[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // Step 3: If none found
    printf("$\n");

    return 0;
}