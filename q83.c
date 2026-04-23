/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

// enqueue
void enqueue(int x)
{
    queue[++rear] = x;
}

// dequeue
int dequeue()
{
    return queue[front++];
}

// push into stack
void push(int x)
{
    stack[++top] = x;
}

// pop from stack
int pop()
{
    return stack[top--];
}

int main()
{
    int n;

    scanf("%d", &n);

    // input queue elements
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: queue → stack
    for(int i = 0; i < n; i++)
        push(dequeue());

    // Step 2: stack → queue
    for(int i = 0; i < n; i++)
        enqueue(pop());

    // print reversed queue
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    return 0;
}