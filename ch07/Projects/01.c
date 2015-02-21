#include <stdio.h>

int main(void)
{
    int n;
    long i;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%15d%15d\n", i, i * i);

        if ((i * i) < 0)
            break;
    }

    return 0;
}
/* When i * i is assigned to a short, it overflows at 182^2. This means it reaches its
 * limit between the values 181^2 (32,761) and 182^2 (33,124). I can conclude from this
 * that short is assigned 16 bits on this system.
 *
 * When i * i is assigned to an int, it overflows at 46341^2 (2,147,479.015). This means
 * it reaches the limit between the values 46340^2 (2,147,395,600) and 46341^2
 * (2,147,479.015). I can conclude from this that int is assigned 32 bits on this
 * system
 *
 * When i * i is assigned to a long int, it overflows at the same result for int. 
 * Therefore it also is assigned 32 bits on this system.
 */
