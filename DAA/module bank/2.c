#include <stdio.h>

int towerOfHanoi(int n, char source, char auxiliary, char destination, int count)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return count + 1;
    }
    count = towerOfHanoi(n - 1, source, destination, auxiliary, count);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    count = towerOfHanoi(n - 1, auxiliary, source, destination, count + 1);
    return count;
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int count = towerOfHanoi(n, 'A', 'B', 'C', 0);
    printf("Total moves: %d\n", count);
    return 0;
}
