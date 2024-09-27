#include <stdio.h>

#define MAX 100

int main() {
    int i, p, q, r, s, n;
    int numbers[MAX];

    scanf("%d %d %d %d %d", &n, &p, &q, &r, &s);

    p--; q--; r--; s--;

    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    for (i = 0; i < p; i++)
        printf("%d ", numbers[i]);

    for (i = r; i <= s; i++)
        printf("%d ", numbers[i]);

    for (i = q + 1; i < r; i++)
        printf("%d ", numbers[i]);

    for (i = p; i <= q; i++)
        printf("%d ", numbers[i]);

    for (i = s + 1; i < n; i++)
        printf("%d ", numbers[i]);

    printf("\n");

    return 0;
}