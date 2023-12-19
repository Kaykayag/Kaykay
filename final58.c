#include <stdio.h>
#include <math.h>

// Function declaration
int calcTime        (char types, int entryHr, int entryMins, int outHr, int outMins);
double chargeFare   (char types, float hour);
void printResult    (char type, int entryHr, int entryMins, int outHr, int outMins, float fare, int time);

int main() 
{//local declaration
    char _types;
    float fare;
    int _entryHr, _entryMins,_outHr,_outMins, time;

//statement 
    printf("Please enter the following details\n\n");
    printf("Type of vehicle : ");
    scanf("%c", &_types);
    printf("Hour vehicle entered the lot (0-24) :\n ");
    scanf("%d", &_entryHr);
    printf("Minute vehicle entered the lot (0-60) :\n");
    scanf("%d", &_entryMins);
    printf("Hour vehicle left the lot (0-24) :\n ");
    scanf("%d", &_outHr);
    printf("Minute vehicle left the lot (0-60) : \n");
    scanf("%d", &_outMins);

    // Function to calculate parking time
    time = calcTime(_types,_entryHr, _entryMins,_outHr, _outMins);

    // Function to calculate parking fare
    fare = chargeFare(_types, time);
    // Function to print the details
    printResult(_types, _entryHr,_entryMins,_outHr,_outMins, fare, time);

    if (_outHr < _entryHr || (_outHr == 0 && _outMins > 0))
    {
        printf("\n your vehicle has been towed away since you park later than midnight");
    }

    return 0;
}
int calcTime(char types, int entryHr, int entryMins, int outHr, int outMins)
{//local declaration 
    float hour, netMin, netHours;
//statement
    netMin = outMins - entryMins;
    netHours = outHr - entryHr;
    hour = netHours;
    
    if (entryMins > outMins)
    {
        outMins += 60;
        outHr--;
    }

    if (netMin > 0)
    
       hour += ceil(netMin / 60.0);
    
    return hour;
}

double chargeFare(char types, float hours)
{
    double fare = 0.0;

    switch (types)
    {
    case 'C':
        if (hours > 3)
        {
            hours = hours - 3;
            fare = 1.50 * hours;
        }
        break;

    case 'T':
        if (hours > 2)
        {
            fare = 2.00;
            hours = hours - 2;
            fare = fare + 2.30 * hours;
        }
        else
            fare = 1.00 * hours;
            
        break;

    case 'B':
        if (hours > 1){
        
            fare = 3.70 * (hours - 1);
        }
        else
           fare += 2.00;
           
        break;

    }
    return fare;
}

void printResult(char type, int entryHr, int entryMins, int outHr, int outMins, float fare, int time)
{//local declaration 
    int netMin,netHours;
//process
    netMin = outMins - entryMins;
    netHours = outHr - entryHr;
  
    printf(" PARKING LOT CHARGES\n ");
    printf("Type of vehicle \t %c \n", type);
    printf("Time in \t %d : %d\n", entryHr, entryMins);
    printf("Time out \t %d : %d", outHr, outMins);
    printf("\n\t\t ------------");
    printf("\n Parking time \t %d : %d", netHours, netMin);
    printf("\nRound off hours \t %d", time);
    printf("\n\t\t ------------");
    printf("\nTotal charges generated \t $%.2f", fare);
    
    return;
    
}