#include <stdio.h>

int main()
{
    int n, i, j;
    int chunks[50], temp;
    int totalCost = 0;

    printf("VIDEO CHUNK MERGING\n");
    printf("-------------------\n");

    printf("Enter number of video chunks: ");
    scanf("%d", &n);

    printf("Enter size of each video chunk (in MB):\n");

    for (i = 0; i < n; i++)
    {
        printf("Chunk %d: ", i + 1);
        scanf("%d", &chunks[i]);
    }

    /* Sort chunk sizes in ascending order */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (chunks[i] > chunks[j])
            {
                temp = chunks[i];
                chunks[i] = chunks[j];
                chunks[j] = temp;
            }
        }
    }

    printf("\nOptimal Merge Process:\n");

    while (n > 1)
    {
        int mergeCost = chunks[0] + chunks[1];

        printf("Merge %d MB + %d MB = %d MB\n",
               chunks[0], chunks[1], mergeCost);

        totalCost += mergeCost;

        /* Replace first two chunks with merged chunk */
        chunks[0] = mergeCost;

        for (i = 1; i < n - 1; i++)
        {
            chunks[i] = chunks[i + 1];
        }

        n--;

        /* Sort again */
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (chunks[i] > chunks[j])
                {
                    temp = chunks[i];
                    chunks[i] = chunks[j];
                    chunks[j] = temp;
                }
            }
        }
    }

    printf("\nMinimum Total Merge Cost = %d MB\n", totalCost);

    return 0;
}