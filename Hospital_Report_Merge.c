#include <stdio.h>

int main()
{
    int n, i, j;
    int reports[50], temp;
    int totalCost = 0;

    printf("HOSPITAL MEDICAL REPORT MERGING\n");
    printf("------------------------------\n");

    printf("Enter number of report files: ");
    scanf("%d", &n);

    printf("Enter size of each report file (in MB):\n");

    for (i = 0; i < n; i++)
    {
        printf("Report %d: ", i + 1);
        scanf("%d", &reports[i]);
    }

    /* Sort report sizes in ascending order */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (reports[i] > reports[j])
            {
                temp = reports[i];
                reports[i] = reports[j];
                reports[j] = temp;
            }
        }
    }

    printf("\nOptimal Merge Process:\n");

    while (n > 1)
    {
        int mergeCost = reports[0] + reports[1];

        printf("Merge %d MB + %d MB = %d MB\n",
               reports[0], reports[1], mergeCost);

        totalCost += mergeCost;

        /* Replace first two reports with merged report */
        reports[0] = mergeCost;

        for (i = 1; i < n - 1; i++)
        {
            reports[i] = reports[i + 1];
        }

        n--;

        /* Sort again */
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (reports[i] > reports[j])
                {
                    temp = reports[i];
                    reports[i] = reports[j];
                    reports[j] = temp;
                }
            }
        }
    }

    printf("\nMinimum Total Merge Cost = %d MB\n", totalCost);

    return 0;
}