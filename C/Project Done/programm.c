#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randomtrip.h"


//main method
int main(int argc, char *argv[]){
    //init Randomizes
    //srand(time(NULL));
    /* Intializes random number generator */

    struct City cities[38];
    struct Strasse ListOfStrassen[52];
    struct Gebiet listofGebiets [32];

    struct City *start;
    struct City city[38];

    readfromStadt(cities, argv[1]);
    readfromStrasse(ListOfStrassen, argv[2]);
    readfromGebiet(listofGebiets,argv[3]);

    fillCity(cities,ListOfStrassen);

    time_t t;
    srand((unsigned) time(&t));
    start = &city[rand() % (sizeof city / sizeof city[0])]; // тут генерирует рандомный город    //----

    int roundTrip = go(start);

    if(roundTrip == -1)
        printf("\nReturned to %s", start->name);

    return 0;
}
