#include <stdio.h>

int main()
{
    int n, i, j;
    int files[50], temp;
    int totalCost = 0;

    printf("LIBRARY BOOK FILE MERGING\n");
    printf("-------------------------\n");

    printf("Enter number of book files: ");
    scanf("%d", &n);

    printf("Enter size of each book file (in MB):\n");

    for (i = 0; i < n; i++)
    {
        printf("File %d: ", i + 1);
        scanf("%d", &files[i]);
    }

    /* Sort file sizes in ascending order */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (files[i] > files[j])
            {
                temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }

    printf("\nOptimal Merge Process:\n");

    while (n > 1)
    {
        int mergeCost = files[0] + files[1];

        printf("Merge %d MB + %d MB = %d MB\n",
               files[0], files[1], mergeCost);

        totalCost += mergeCost;

        /* Replace first two files with merged file */
        files[0] = mergeCost;

        for (i = 1; i < n - 1; i++)
        {
            files[i] = files[i + 1];
        }

        n--;

        /* Sort again */
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (files[i] > files[j])
                {
                    temp = files[i];
                    files[i] = files[j];
                    files[j] = temp;
                }
            }
        }
    }

    printf("\nMinimum Total Merge Cost = %d MB\n", totalCost);

    return 0;
}