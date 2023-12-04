#include <stdio.h>

// Function declaration
void validateAngle(int *theAngle); // this us where i let the user input the value of an anglr
int determineQuadrant(int angle);

int main() {
    int angle;

    validateAngle(&angle); // function call para ma read ang angle and masulod nakos function
   determineQuadrant(angle);


    return 0;
}
// this is where we let the user input the value of an angle
void validateAngle(int *theAngle)
{
    printf("Input an angle between 0 and 360 degrees: ");
    scanf("%d", theAngle);

    return;
// yeah its a pointer so we can bring the angle up to the int main
}

int determineQuadrant(int angle)
{
    if (angle == 0)
    {
        printf("The angle %d degrees is on the positive X-axis.\n", angle);  // positive X-axis
    } else if (angle == 90)
    {
        printf("The angle %d degrees is on the positive X-axis.\n", angle); //  positive Y-axis
    } else if (angle == 180)
    {
        printf("The angle %d degrees is on the positive X-axis.\n", angle);  //  negative X-axis
    } else if (angle == 270)
    {
        printf("The angle %d degrees is on the positive X-axis.\n", angle); // negative Y-axis
    } else if (angle > 0 && angle < 90)
    {
        printf("the angle %d degrees is on quadrant I.\n",angle); // Quadrant I ni
    } else if (angle > 90 && angle < 180)
    {
        printf("the angle %d degrees is on quadrant I.\n",angle); // Quadrant II ni
    } else if (angle > 180 && angle < 270)
    {
        printf("the angle %d degrees is on quadrant I.\n",angle); // Quadrant III ni
    } else
    {
        printf("the angle %d degrees is on quadrant I.\n",angle); // Quadrant IV ni
    }
}
