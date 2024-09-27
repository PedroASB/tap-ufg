#include <stdio.h>

#define MAX_CARDS 100

int main() {
    int i, n, k;
    int cards[MAX_CARDS];

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    for (i = n - k; i < n; i++) {
        printf("%d ", cards[i]);
    }

    for (i = 0; i < n - k; i++) {
        printf("%d ", cards[i]);
    }

    printf("\n");

    return 0;
}