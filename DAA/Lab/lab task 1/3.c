#include <stdio.h>

int number_of_1bits(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", number_of_1bits(n));
}