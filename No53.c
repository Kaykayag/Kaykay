#include <stdio.h>

//function declaration
void readScore(int* score1,int*score2,int*score3);/*use pointers because it was mentioned not to put anything in the main except the subfunction and function calls*/
char determineGrade(int x,int y, int z); //this is were we do the else if statements to egt the grade mark
void printResult( char finalScore); // where we put print th result; the grade equivalent .

int main()
{
    int score1,score2,score3,readScores,grade;
//function call here and im using pointers to get the data from downward to upward
    readScore(&score1,&score2,&score3);
//fnction call so when the data returned, ill put it inside the print result as statement
    grade= determineGrade(score1,score2,score3);

    printResult(grade);

    return 0;
}
//function definition, using pointers or its the upward type
void readScore(int* score1,int*score2,int*score3)
{
    printf("input your first test score:");
    scanf("%d",score1);

    printf("input your second test score:");
    scanf("%d",score2);

    printf("input your third test score:");
    scanf("%d",score3);

    return;
}
// using char because it was in the instruction, you have to use one letter which mean we used char over string.
char determineGrade(int x,int y,int z)

{
    float average,averageOfTwo;

    average=( x +  y+  z )/3;// calculate thr average here
    averageOfTwo=( y + z)/2;// it was stated to calculate the second and third score and get the average

    if (average >=90)
    {
        return 'A';
    }
    else if (average >=70)
    {
        if (z > 90) {
            return 'A';
        }
        else {
            return 'B';
        }
    }
    else if (average >=50) {
        if (averageOfTwo>70) {
            return 'C';
        }
        else {
            return 'D';
        }
    }
    else {

        return 'F';
    }
}
//print out the result; showcase the letter of your grade
void printResult(char finalScore)
{

    printf(" given by your scores, your grade is equivalent to %c",finalScore );

    return ;
}
