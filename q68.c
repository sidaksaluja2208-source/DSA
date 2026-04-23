/*Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) return 0;

    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int calculate(char s[]) {
    int num = 0;
    char sign = '+';

    for (int i = 0; i <= strlen(s); i++) {

        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }

        if ((!isdigit(s[i]) && s[i] != ' ') || s[i] == '\0') {

            if (sign == '+')
                push(num);

            else if (sign == '-')
                push(-num);

            else if (sign == '*') {
                int temp = pop();
                push(temp * num);
            }

            else if (sign == '/') {
                int temp = pop();
                push(temp / num);
            }

            sign = s[i];
            num = 0;
        }
    }

    int result = 0;

    while (top != NULL) {
        result += pop();
    }

    return result;
}

int main() {

    char s[1000];

    printf("Enter expression:\n");
    fgets(s, sizeof(s), stdin);

    int result = calculate(s);

    printf("Result = %d\n", result);

    return 0;
}