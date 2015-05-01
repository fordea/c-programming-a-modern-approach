#include <stdio.h>

int main(void)
{
    char str[] = "$%###1,162,620*$!234";
    /* char str[] = "#989"; */
    char sales_rank[sizeof(str)];

    sscanf(str,
            str[0] == '#' ? "%*[#]%[0123456789,]" : "%*[^#]%*[#]%[0123456789,]",
            sales_rank);

    printf("%s\n", sales_rank);

    return 0;
}
