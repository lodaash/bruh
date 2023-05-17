#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    printf("Enter the size of the universal set: ");
    scanf("%d", &n);

    int universalSet[n];
    printf("Enter the elements of the universal set:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &universalSet[i]);

    int m;
    printf("Enter the number of subsets: ");
    scanf("%d", &m);

    int subsets[m][n];
    int subsetSizes[m];

    for (int i = 0; i < m; i++)
    {
        printf("Enter the size of subset %d: ", i+1);
        scanf("%d", &subsetSizes[i]);

        printf("Enter the elements of subset %d:\n", i+1);
        for (int j = 0; j < subsetSizes[i]; j++)
            scanf("%d", &subsets[i][j]);
    }


    printf("Selected subsets in the cover:\n");
    bool covered[n];  //to keep track of which elements of the universal set are covered.
    for (int i = 0; i < n; i++)
        covered[i] = false;

    int selectedSubset[m];  //to keep track of the selected subsets.
    for (int i = 0; i < m; i++)
        selectedSubset[i] = 0;
// The variable maxUncoveredElements is used to store the maximum number of uncovered elements found so far, and maxSubsetIndex is used to store the index of the subset with the maximum number of uncovered elements. Both are initially set to 0 and -1, respectively.
    int maxUncoveredElements = 0;
    int maxSubsetIndex = -1;

    while (maxSubsetIndex != -2) // loop to iterate until no more subsets can be selected
    {
        maxUncoveredElements = 0;//resets maxUncoveredElements and maxSubsetIndex to their initial values.
        maxSubsetIndex = -1;

        for (int i = 0; i < m; i++)
        {
            if (selectedSubset[i] != 0)  //If a subset has already been selected (selectedSubset[i] != 0), it is skipped.
                continue;

            int uncoveredElements = 0;
            bool uniqueCovered[n];
            for (int j = 0; j < n; j++)
                uniqueCovered[j] = false;

            for (int j = 0; j < subsetSizes[i]; j++)
            {
                int element = subsets[i][j];

                if (!covered[element - 1] && !uniqueCovered[element - 1])
                { //Another loop is used to iterate over the elements of the current subset. If an element is not already covered (!covered[element - 1]) and has not been uniquely covered before (!uniqueCovered[element - 1]), it increments the count of uncovered elements and marks it as uniquely covered.
                    uncoveredElements++;
                    uniqueCovered[element - 1] = true;
                }
            }

            if (uncoveredElements > maxUncoveredElements)
            {
                maxUncoveredElements = uncoveredElements;
                maxSubsetIndex = i;
            }
        }
        //After finding the subset with the maximum number of uncovered elements, it checks if such a subset exists (maxSubsetIndex != -1)
        if (maxSubsetIndex != -1)
        {
            selectedSubset[maxSubsetIndex] = 1;  //if fpund marks as selected

            for (int j = 0; j < subsetSizes[maxSubsetIndex]; j++)
            {
                int element = subsets[maxSubsetIndex][j];
                covered[element - 1] = true;
            }

            printf("Subset %d\n", maxSubsetIndex + 1);
        }
    }

    return 0;
}