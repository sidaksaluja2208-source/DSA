/*Given a 2d matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

Examples:

Input: cost[][] = [[0, 111], 
                [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112.
Input: cost[][] = [[0, 1000, 5000],
                [5000, 0, 1000],
                [1000, 5000, 0]]
Output: 3000
Explanation: We can visit 0->1->2->0 and cost = 1000 + 1000 + 1000 = 3000
Constraints:
1 ≤ cost.size() ≤ 15
0 ≤ cost[i][j] ≤ 104*/


#include <stdio.h>
#include <limits.h>

#define MAXN 15
#define INF INT_MAX

int n;
int cost[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int totalMask = 1 << n;

    // Initialize DP
    for (int i = 0; i < totalMask; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = INF;

    // Start from city 0
    dp[1][0] = 0;

    for (int mask = 1; mask < totalMask; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;

            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;

                int newMask = mask | (1 << v);
                dp[newMask][v] = min(dp[newMask][v],
                                     dp[mask][u] + cost[u][v]);
            }
        }
    }

    int ans = INF;
    int fullMask = (1 << n) - 1;

    for (int i = 1; i < n; i++) {
        if (dp[fullMask][i] != INF) {
            ans = min(ans, dp[fullMask][i] + cost[i][0]);
        }
    }

    printf("%d\n", ans);
    return 0;
}


