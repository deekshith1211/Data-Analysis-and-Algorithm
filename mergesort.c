#include <stdio.h>
#include <stdlib.h>

int count;

void merge(int A[10], int l, int m, int r)
{
    int i, j, k, B[10];

    i = l;
    j = m + 1;
    k = l;

    while (i <= m && j <= r)
    {
        count = count + 1;

        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    while (i <= m)
        B[k++] = A[i++];

    while (j <= r)
        B[k++] = A[j++];

    for (i = l; i <= r; i++)
        A[i] = B[i];
}

void Mergesort(int A[10], int l, int r)
{
    int m;

    if (l < r)
    {
        m = (l + r) / 2;

        Mergesort(A, l, m);
        Mergesort(A, m + 1, r);
        merge(A, l, m, r);   // ✅ Correct function call
    }
}

int main()
{
    int i, n, a[10];

    printf("\nRead array size: ");
    scanf("%d", &n);

    printf("\nRead array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Mergesort(a, 0, n - 1);

    printf("\nSorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    printf("\nTotal number of comparisons = %d", count);

    return 0;
}