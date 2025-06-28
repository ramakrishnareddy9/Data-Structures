#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
char infix[100];
char prefix[100];
int top = -1;

void push(char a)
{
    if (top >= 100 - 1)
    {
        printf("Stack Overflow\n");
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
            prefix[j] = a;
            j++;
        }
        else if (a == ')')
        {
            push(a);
        }
        else if (a == '(')
        {
            while (top != -1 && stack[top] != ')')
            {
                prefix[j] = pop();
                j++;
            }
            if (top != -1 && stack[top] == ')')
            {
                pop();
            }
        }
        else if (operator(a))
        {
            while (top != -1 && precedence(stack[top]) > precedence(a))
            {
                prefix[j] = pop();
                j++;
            }
            push(a);
        }
    }
    while (top != -1)
    {
        prefix[j] = pop();
        j++;
    }
    prefix[j] = '\0';
}

void reverse(char *s)
{
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }
}

int main()
{
    printf("Enter the infix expression: ");
    gets(infix);
    reverse(infix);
    check();
    printf("The prefix expression is: ");
    reverse(prefix);
    puts(prefix);
    return 0;
}
