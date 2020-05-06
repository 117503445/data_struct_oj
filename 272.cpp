#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main(void)
{
    int n, W[1000];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &W[i]);
    int Result = 0;
    for (int i = 2; i <= n; i++)
    {
        qsort(W + i - 1, n - i + 2, sizeof(W[0]), cmp);
        Result += W[i] + W[i - 1];
        W[i] = W[i] + W[i - 1];
    }
    printf("%d\n", Result);

    return 0;
}