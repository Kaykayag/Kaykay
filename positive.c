#include <stdio.h>

int main()
{
//local declaration
    int n;
    float num, sum = 0, numCount = 0;

// Prompt user to enter the number of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n<=0)
    {
        printf("error. make it positive number");
        return 1;
    }
// Prompt user to enter floating-point numbers
    printf("Enter %d floating-point numbers:\n", n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &num);
        // Calculate the sum and count of positive numbers
        if (num > 0)
        {
            sum += num;
            numCount++;
        }
    }
    // Check if there were positive numbers entered
    if (numCount > 0)
    {
        float average = sum / numCount;
        printf("Average of positive numbers: %.f\n", average);
    }
    else
    {
        printf("No positive numbers were entered.\n");
    }
    return 0; // Exit program
}
