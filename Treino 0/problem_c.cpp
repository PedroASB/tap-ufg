#include <stdio.h>

#define MAX 100

int main() {
    int i, n, k;
    int numbers[MAX];

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    for (i = 0; i < n; i++) {
        if (numbers[i] % k == 0)
            printf("%d ", numbers[i] / k);
    }

    printf("\n");

    return 0;
}