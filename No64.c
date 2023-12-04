#include <stdio.h>
#include <math.h>

void userInput(int* _a, int* _b, int* _c);
void checkTheSolution(int a, int b, int c);

int main()
{
    int _a, _b, _c;

    userInput(&_a, &_b, &_c);
    checkTheSolution(_a, _b, _c);

    return 0;
}

void userInput(int* _a, int* _b, int* _c)
{
    // Prompt the user to input the value of a,b, and c
    printf("Quadratic Equation : a*x^2 + b*x + c = 0\n");
    printf("Input the value of a:\n ");
    scanf("%d", _a);
    printf("Input the value of b:\n ");
    scanf("%d", _b);
    printf("Input the value of c:\n ");
    scanf("%d", _c);

    return;
}

void checkTheSolution(int a, int b, int c)
{
    int d;
    float root, root1, root2;



    // Check if the equation is not quadratic
    if (a == 0 && b == 0)
    {
        printf("\nTheres No solution !!");
        return;
    }

    // Check if the equaton is not a quadratic
    if (a == 0)
    {
        root=-(c/b);
        printf("\nTheres Only One Root/ solution : %0.2f ",root);
        return;
    }


    if (d < 0) // here we check if the equation is linear
    {
        d = b * b - 4 * a * c; //the discriminant

        printf("\nThere are No real roots ");
        return;
    }
    if (d>0) //here we calculate and display the root if they exist
    {
        root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);


        printf("\nThe two roots are : %0.2f, %0.2f \n", root1, root2);
    }
}