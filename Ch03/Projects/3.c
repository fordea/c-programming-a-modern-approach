#include <stdio.h>

int main(void)
{
    int gs1_pr, g_id, p_code, i_no, c_digit;

    printf("Enter ISBN: ");
    scanf("%d -%d -%d -%d -%d", &gs1_pr, &g_id, &p_code, &i_no, &c_digit);

    printf("GS1 prefix: %d\n"
            "Group identifier: %d\n"
            "Publisher code: %d\n"
            "Item number: %d\n"
            "Check digit: %d\n",
            gs1_pr, g_id, p_code, i_no, c_digit);

    return 0;
}
