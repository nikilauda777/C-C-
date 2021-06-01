#ifndef PROGRAMM1_RANDOMTRIP_H
#define PROGRAMM1_RANDOMTRIP_H


#include "stadt.h"
#include "strasse.h"
#include <iostream>


///****************************************************************************/
//Structure City enthält eindeutige ID, Stadtbezeichnung und Eigenschaft visited

auto *cities = (City *) malloc(100 * sizeof(City));

//Stellt die Kanten eines ungerichteten Graphen dar.
int street[100][2];

//Pointer auf erste besuchte Stadt
struct City *start;

int counter = 0;
int streetCounter = 0;

// Befüllen mit den Städten aus der Liste
void fillCity(struct City storage[], struct Strasse storage1[]) {
    for (int i = 0; !storage[i].isEmpty(); i++) {
        cities[i] = *new City (storage[i].getCityId(), storage[i].getName(), 0);
        counter++;
    }
    for (int i = 0; !storage1[i].isEmpty(); i++) {   // befüllen mit allen möglichen Wege auch hin und her
        street[i][0] = storage1[i].vonCityId();
        street[i][1] = storage1[i].nachCityId();
        streetCounter++;
    }
}


//Funktion liefert die Eigenschaft visited zurück. 0=nicht besucht, 1= besucht.
int visited(int cityId) {

       int res = 0;
    for (int i = 0; i < counter; i++) {
        if (cities[i].getCityId() == cityId) {
            if (cities[i].getVisit() == 1)
                res = 1;
        }
    }
    return res;
}




struct City *randomCitychoice (){


    start = (&cities[rand() % counter]);  //

    return start;
}

/**
Funktion durchsucht alle Verbindungen zu und von der Stadt mit der id cityID.
Aus den möglichen Ziel-IDs wir ein Array gebildet und ein
zufälliges Element daraus zurückgeliefert.
**/
int randomCity(int cityID){

    int streets[10];
    int cnt = 0;
    int vis;

    for (int i = 0; i < streetCounter; i++) {

        //Verbindungen von der Stadt weg
        if (street[i][0] == cityID) {
            vis = visited(street[i][1]);
            if (vis == 0 || start->getCityId() == street[i][1]) {
                streets[cnt] = street[i][1];
                cnt++;
            }
        }
        //Verbindungen zu der Stadt hin
        if (street[i][1] == cityID) {
            vis = visited(street[i][0]);
            if (vis == 0 || start->getCityId() == street[i][0]) {
                streets[cnt] = street[i][0];
                cnt++;
            }
        }
    }

    if (cnt > 0) {
        //Zufälliges Element zurückliefern
        return streets[rand() % cnt];
    } else {
        //Sackgasse, cnt = 0
        return cnt;
    }
}

/**
Liefert einen Pointer auf die Stadt mit der id cityID
**/
struct City *getCityById(int cityId){
    for(int i = 0; i < counter; i++){
        if(cities[i].getCityId()== cityId){
            return &cities[i];
        }
    }
    return &cities[0];
}
/**
Rekursive Funktion
Liefert -1, falls wieder am Ausgangspunkt angelangt.
Liefert 0, wenn keine weiteren Verbindungen möflich (Sackgasse)
Ruft sich selbst auf, um weitere zufällige Städte zu besuchen.
**/


template <class T>
void remove_item( std::vector<T> &v, int i )
{
    // Сохраняем последний элемент
    const T item = v.back();
    // Удаляем последний элемент из массива
    v.pop_back();
    // Вставляем сохраненный элемента вместо элемента с индексом i
    v[i] = item;
}

//
// vector<int> representRoad ( int cityTo ){
//
//     std::vector<int> randomWay;
//     randomWay.push_back(cityTo);
//
//    for ( int a : randomWay){
//        cout << " Visiting :" << a << endl;
//    }
//    return randomWay;
//}


vector<int> representRoad(int cityTo , int index ){

    std::vector<int> randomWay;
    randomWay.push_back(cityTo);   // add all cities to the list
//
//
//
//    // das Löschen
//    for(int i = 0; i < randomWay.size();i++){
//        if(index == 1 && randomWay.at(i) == cityTo){
//
//          //  cout << "To Delete :" << randomWay.at(i) << endl;
//            vector<int>::iterator new_end;
//
//            new_end = remove(randomWay.begin(), randomWay.end(), randomWay.at(i));
//        }
//    }
//    // Printing
//        for(int i=0;i<randomWay.size(); i++){
//        cout << " Trip: " << randomWay[i] << " ";
//    }


    return randomWay;
}



int cityTotrip(struct City *city) {

   static int notPossible = 0;
    //std::vector<int> randomWay ;
    //Wenn in der Start-Stadt angelangt, die schon besucht wurde.
    //Hier wird nicht unterschieden, ob man am Ausgangspunkt deshalb zurückkehrt, weil man aus einer Sackgasse zurückgekommen ist ud noch weitere Routen möglich wären.
    if (city->getCityId()== start->getCityId() && start->getVisit() == 1) {
                if (notPossible == 2){
                    printf("\nThe Way is not possible, try again %s", city->getName().c_str());
                    exit(0);
                }
                else
                printf("\nReturned to %s", city->getName().c_str());

        return -1;
    } else {
        notPossible++;
        printf("\nVisiting %s", city->getName().c_str());  //(pointer_name)->(variable_name)

        //randomWay.push_back(city->getCityId()); // add all cities to trip
            representRoad(city->getCityId(),0);

        //Stadt als besucht markieren´

        city->setVisit();   // make to visit
        //rndCity enthält die ID einer zufälligen Stadt, die besucht werden kann, oder 0 in Sackgasse.
        int rndCity;
        //alle Nachbarstädte in zufälliger Reihenfolge besuchen, falls nicht zuerst die Rundreise am Ausgangspunkt endet.

        do {
            rndCity = randomCity(city->getCityId());
            if (rndCity == 0) {
                printf("\nSackgasse in %s", city->getName().c_str());

            //das Löschen von Sackgasse
                representRoad(city->getCityId(),1);

            }
            if (rndCity > 0) {
                struct City *nextCity = getCityById(rndCity);
                //Rekursiver Aufruf
                int next = cityTotrip(nextCity);
                if (next == -1) {
                    //Rundreise zu Ende
                    return next;
                } else {
                    printf("\nZurück in %s", city->getName().c_str());

                    //здесь должно происходить удаление из листа

                    rndCity = randomCity(city->getCityId());
                }
            }
        }
        while (rndCity > 0);
        return rndCity;
    }
}

#endif //PROGRAMM1_RANDOMTRIP_H
