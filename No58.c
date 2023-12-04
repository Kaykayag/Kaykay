#include <stdio.h>
#include <math.h>

// Function prototype declaration
void inputInfo(char * _types, int * _entryHr, int * _entryMins, int * _outHr, int * _outMins);
int calcTime(char _types, int _entryHr, int _entryMins, int_outHr, int _outMins);
float chargeFare(char _types, int _hour);
void printResult(char _types, int _entryHr, int _entryMins, int _outHr, int _outMins, float _fare, int _time);

int main()
{
    char _types;
    float fare;
    int _entryHr, _entryMins,_outHr,_outMins, time;

    // Function to get information from the user
    inputInfo(& _types, & _entryHr, & _entryMins, & _outHr, & _outMins);

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

void inputInfo(char * _types, int * _entryHr, int * _entryMins, int * _outHr, int *_outMins)
{
    printf("Please enter the following details\n\n");
    printf("Type of vehicle : \n");
    scanf(" %c", _types);
    printf("Hour vehicle entered the lot (0-24) :\n ");
    scanf("%d", _entryHr);
    printf("Minute vehicle entered the lot (0-60) :\n");
    scanf("%d", _entryMins);
    printf("Hour vehicle left the lot (0-24) :\n ");
    scanf("%d", _outHr);
    printf("Minute vehicle left the lot (0-60) : \n");
    scanf("%d", _outMins);

    return;
}
int calcTime(char _types, int _entryHr, int _entryMins, int _outHr, int _outMins)
{
    int hour, netMin, netHours;


    netMin = _outMins - _entryMins;
    netHours = _outHr - _entryHr;
    hour = netHours;
    if (_entryMins > _outMins)
    {
        _outMins += 60;
        _outHr--;
    }

    if (netMin > 0)
    {
        hour++;
    }

    return hour;
}

float chargeFare(char _types, int _hours)
{
    float fare = 0.0;

    switch (_types)
    {
    case 'C':
    case 'c':
        if (_hours > 3)
        {
            _hours = _hours - 3;
            fare = 1.50 * _hours;
        }
        break;

    case 'T':
    case 't':
        if (_hours > 2)
        {
            fare = 2.00;
            _hours = _hours - 2;
            fare = fare + 2.30 * _hours;
        }
        else
        {
            fare = 1.00 * _hours;
        }
        break;

    case 'B':
    case 'b':
        if (_hours > 1)
        {
            fare = 3.70 * (_hours - 1);
        }
        else
        {
            fare += 2.00;
        } //
        break;

    }

    return fare;
}

void printResult(char _types, int _entryHr, int _entryMins, int _outHr, int _outMins, float _fare, int _time)
{

    int netMin,netHours;


    netMin = _outMins - _entryMins;
    netHours = _outHr - _entryHr;


    printf("\n\n\t\t***********************************");
    printf("\n\t\t* PARKING LOT CHARGES *");
    printf("\n\t\t***********************************");
    printf("\n\n\n\t\t* Type of vehicle \t %c", _types);
    printf("\n\n\n\t\t* Time in \t %d : %d", _entryHr, _entryMins);
    printf("\n\n\n\t\t* Time out \t %d : %d", _outHr, _outMins);
    printf("\n\t\t ------------");
    printf("\n\n\n\t\t* Parking time \t %d : %d", netHours, netMin);
    printf("\n\n\n\t\t* Round off hours \t %d", _time);
    printf("\n\t\t ------------");
    printf("\n\n\n\t\t* Total charges generated \t $%.2f", _fare);
}