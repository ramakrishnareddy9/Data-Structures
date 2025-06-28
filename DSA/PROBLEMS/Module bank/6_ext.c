#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack
{
    char a[100];
    int value;
    struct stack *next, *previous;
};
struct stack *top = NULL;

void push(char a[], int value)
{
    struct stack *new;
    new = (struct stack *)malloc(sizeof(struct stack));
    strcpy(new->a, a);
    new->value = value;
    if (top == NULL)
    {
        new->next = new->previous = NULL;
        top = new;
    }
    else
    {
        new->next = NULL;
        top->next = new;
        new->previous = top;
        top = new;
    }
}

struct stack pop()
{
    struct stack temp;
    if (top == NULL)
    {
        printf("Stack is empty\n");
        temp.value = -1;
        return temp;
    }
    else
    {
        temp = *top;
        if (top->previous != NULL)
        {
            top = top->previous;
            top->next = NULL;
        }
        else
        {
            top = NULL;
        }
        return temp;
    }
}

void add(char formula[])
{
    FILE *f;
    f = fopen("formula.csv", "a");
    fprintf(f, "%s", formula);
    printf("formula entered successfully\n");
    fclose(f);
}

int check(char formula[])
{
    FILE *f;
    f = fopen("formula.csv", "r");
    int flag = 0;
    char check[10000];
    while (fgets(check, sizeof(check), f) != NULL)
    {
        check[strcspn(check, "\n")] = 0;
        if (strcmp(formula, check) == 0)
        {
            flag = 1;
            break;
        }
    }
    fclose(f);
    return flag;
}

void no_atoms(char formula[])
{
    int len = strlen(formula);
    int i = 0;
    int capital = 0;
    while (i < len)
    {
        if (isupper(formula[i]))
        {
            char a[100];
            int j = 0;
            int value = 0;
            a[j++] = formula[i++];
            while (islower(formula[i]))
            {
                a[j++] = formula[i++];
            }
            a[j] = '\0';
            while (isdigit(formula[i]))
            {
                value = (value * 10) + (formula[i++] - '0');
            }
            if (value == 1)
            {
                printf("Not possible %s", formula);
                return;
            }
            if (value == 0)
            {
                value = 1;
            }
            push(a, value);
        }
        else if (formula[i] == '(')
        {
            char a[2] = "(";
            push(a, -1);
            i++;
        }
        else if (formula[i] == ')')
        {
            i++;
            int value = 0;
            while (isdigit(formula[i]))
            {
                value = (value * 10) + (formula[i++] - '0');
            }
            if (value == 0)
            {
                value = 1;
            }
            for (int j = 0; j < len; j++)
            {
                if (isupper(formula[j]))
                {
                    capital++;
                }
            }
            struct stack temp_stack[capital];
            int k = 0;
            while (1)
            {
                struct stack temp = pop();
                if (temp.value == -1)
                {
                    break;
                }
                temp.value *= value;
                temp_stack[k++] = temp;
            }
            for (int j = 0; j < k; j++)
            {
                push(temp_stack[j].a, temp_stack[j].value);
            }
        }
    }

    char formula_[capital][10];
    int elements[capital];
    int index = 0;
    while (top != NULL)
    {
        struct stack element = pop();
        int found = 0;
        for (int j = 0; j < index; j++)
        {
            if (strcmp(formula_[j], element.a) == 0)
            {
                elements[j] += element.value;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(formula_[index], element.a);
            elements[index] = element.value;
            index++;
        }
    }
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if (strcmp(formula_[i], formula_[j]) > 0)
            {
                char temp[10];
                strcpy(temp, formula_[i]);
                strcpy(formula_[i], formula_[j]);
                strcpy(formula_[j], temp);
                int temp_value = elements[i];
                elements[i] = elements[j];
                elements[j] = temp_value;
            }
        }
    }
    printf("Element counts:\n");
    for (int j = 0; j < index; j++)
    {
        printf("%s: %d\n", formula_[j], elements[j]);
    }
}

int main()
{
    char formula[100];
    printf("Enter formula: ");
    scanf("%s", formula);
    printf("1.count size of the formula\n2.Add a formula\n");
    int n;
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        if (check(formula))
        {
            no_atoms(formula);
        }
        else
        {
            printf("No formula exist \n");
        }
        break;
    case 2:
        add(formula);
        break;
    default:
        printf("invalid choice");
    }
    return 0;
}