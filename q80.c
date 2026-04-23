/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100*/

#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int temps[], int n) 
{
    int *ans = (int*)calloc(n, sizeof(int));
    int *stack = (int*)malloc(n * sizeof(int));
    
    int top = -1;

    for(int i = 0; i < n; i++)
    {
        while(top >= 0 && temps[i] > temps[stack[top]])
        {
            int index = stack[top--];
            ans[index] = i - index;
        }

        stack[++top] = i;
    }

    free(stack);
    return ans;
}

int main()
{
    int n;

    printf("Enter number of days: ");
    scanf("%d",&n);

    int temps[n];

    printf("Enter temperatures:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&temps[i]);

    int *result = dailyTemperatures(temps,n);

    printf("Output:\n");
    for(int i=0;i<n;i++)
        printf("%d ",result[i]);

    free(result);
    return 0;
}