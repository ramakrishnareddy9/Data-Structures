#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
char infix[100];
char postfix[100];
int top = -1;

void push(char a)
{
    if (top >= 100 - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        stack[++top] = a;
    }
}

char pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int operator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a == ')' || a == '%')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}

void check()
{
    int j = 0;
    int len = strlen(infix);
    for (int i = 0; i < len; i++)
    {
        char a = infix[i];
        if (isalnum(a))
        {
            postfix[j] = a;
            j++;
        }
        else if (a == '(')
        {
            push(a);
        }
        else if (a == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            if (top != -1 && stack[top] == '(')
            {
                pop();
            }
        }
        else if (operator(a))
        {
            while (top != -1 && precedence(stack[top]) >= precedence(a))
            {
                postfix[j] = pop();
                j++;
            }
            push(a);
        }
    }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

int main()
{
    printf("enter the infix :");
    gets(infix);
    check();
    printf("The postfix expression is :");
    puts(postfix);
    return 0;
}