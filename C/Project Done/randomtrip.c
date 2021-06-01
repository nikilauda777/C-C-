#include <stdio.h>
#include "stdlib.h"
#include <string.h>

//
// Created by Nikita Semkin on 02.01.2021.
//


struct Gebiet {
    int gebietID;
    char *name;
    int obergebietId;
    char typ;
};


struct City {
    int id;
    char *name;
    int visited;
};


struct Strasse {
    int vonStadtID;
    int nachStadtID;
    int entfernung;
};

struct City getStadt(char line[]) {

    int stadtID;
    int einwohner;
    int gebietId;
    int meereshoehe;
    int whitespace = 0;
    int index = 0;

    char *name = (char *) malloc(sizeof(char) * 13);
    char element[13];

    for (int i = 0; i < strlen(line); i++) {

        if (line[i] == ' ' || (i + 1 == strlen(line))) {
            // add attributes
            if (whitespace == 0) {
                stadtID = atoi(element);

            } else if (whitespace == 1) {
                for (int j = 0; j < strlen(element); j++) {
                    name[j] = element[j];
                }
            }
            if (whitespace == 2) {
                einwohner = atoi(element);
            }
            if (whitespace == 3) {
                gebietId = atoi(element);
            }
            if (whitespace == 4) {
                meereshoehe = atoi(element);
            }
            whitespace++;
            index = 0;

            //remove the line
            for (int i = 0; i < 13; i++) {
                element[i] = '\0';
            }
            continue;
        }
        element[index++] = line[i];
    }
    struct City city = {stadtID, name, 0};
    return city;
}


void readfromStadt(struct City storage[], char *filename) {
    int newLine = 0;
    int c;
    FILE *file;
    file = fopen(filename, "r");
    if (file) {
        char line[35];
        int index = 0;
        while ((c = getc(file)) != EOF) {
            if (c == '\n' || c == '\0') {    // wenn die Zeile endet
                storage[newLine++] = getStadt(line); // create new Stadt and add to array
                for (int i = 0; i < 35; i++) { // clear var line   // delete from
                    line[i] = '\0';
                }
                index = 0; // index of line is zero
            }
            line[index++] = c;   // идет дальше , записывает по символьно
        }
        fclose(file);
    }
}

//strasse.dat   vonStadtId nachStadtId entfernung
struct Strasse getStrasse(char line[]) {

    int vonStadtId;
    int nachStadtId;
    int entfernung;
    int whitespace = 0;
    int index = 0;
    char element[13];

    for (int i = 0; i < strlen(line); i++) {

        if (line[i] == ' ' || (i + 1 == strlen(line))) {
            // add attributes
            if (whitespace == 0) {
                vonStadtId = atoi(element);
            }
            if (whitespace == 1) {
                nachStadtId = atoi(element);
            }
            if (whitespace == 2) {
                entfernung = atoi(element);
            }

            whitespace++;
            index = 0;

            //remove the line
            for (int i = 0; i < 13; i++) {
                element[i] = '\0';
            }
            continue;
        }
        element[index++] = line[i];
    }
    struct Strasse street = {vonStadtId, nachStadtId, entfernung};
    return street;
}

/** reading of files+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++**/
void readfromStrasse(struct Strasse storage[], char *filename) {
    int newLine = 0;
    int c;
    FILE *file;
    file = fopen(filename, "r");

    if (file) {
        char line[35];
        int index = 0;

        while ((c = getc(file)) != EOF) {

            if (c == '\n' || c == '\0') {    // wenn die Zeile endet
                storage[newLine++] = getStrasse(line); // create new Stadt and add to array
                //storage[newLine++] = getStrasse2(line); // create new Stadt and add to array

                for (int i = 0; i < 35; i++) { // clear var line   // delete from
                    line[i] = '\0';
                }
                index = 0; // index of line is zero
            }
            line[index++] = (char)c;   // идет дальше , записывает по символьно
        }
        fclose(file);
    }
}
///gebiet.dat   gebietId name obergebietId typ
struct Gebiet getGebiet(char line[]) {

    int gebietId;
    int obergebietId;
    char typ;
    int whitespace = 0;
    int index = 0;
    char *name = (char *) malloc(sizeof(char) * 20);
    char element[20];


    for (int i = 0; i < strlen(line); i++) {

        if (line[i] == ' ' || (i + 1 == strlen(line))) {    // add attributes
            if (whitespace == 0) {
                gebietId = atoi(element);
            } else if (whitespace == 1) {
                for (int j = 0; j < strlen(element); j++) {
                    name[j] = element[j];
                }}
            if (whitespace == 2) {
                obergebietId = atoi(element);
            }
            if (whitespace == 3) {
                typ = atoi(element);
            }
            whitespace++;
            index = 0;
            //remove the line
            for (int i = 0; i < 20; i++) {
                element[i] = '\0';
            }
            continue;
        }

        element[index++] = line[i];
    }
    struct Gebiet region = {gebietId, name, obergebietId, typ};
    return region;
}

void readfromGebiet(struct Gebiet storage[], char *filename) {
    int newLine = 0;
    int c;
    FILE *file;
    file = fopen(filename, "r");

    if (file) {
        char line[35];
        int index = 0;

        while ((c = getc(file)) != EOF) {

            if (c == '\n' || c == '\0') {    // wenn die Zeile endet
                storage[newLine++] = getGebiet(line); // create new Stadt and add to array

                for (int i = 0; i < 35; i++) { // clear var line   // delete from
                    line[i] = '\0';
                }
                index = 0; // index of line is zero
            }
            line[index++] = (char) c;   // идет дальше , записывает по символьно
        }
        fclose(file);
    }
}

/****************************************************************************
Structure City enthält eindeutige ID, Stadtbezeichnung und Eigenschaft visited
**/

struct City city[38];



//Stellt die Kanten eines ungerichteten Graphen dar.
int street[][2];


//Pointer auf erste besuchte Stadt
struct City *start;


// Befüllen mit den Städten aus der Liste
void fillCity(struct City storage[], struct Strasse storage1[]) {
    for (int i = 0; i < (sizeof city / sizeof city[0]); i++) {
        city[i] = storage[i];

    }

    for (int i = 0; i < 52; i++) {   // befüllen mit allen möglichen Wege auch hin und her
        street[i][0] = storage1[i].vonStadtID;
        street[i][1] = storage1[i].nachStadtID;
    }
}

//Pointer auf erste besuchte Stadt
struct City *start;

//Funktion liefert die Eigenschaft visited zurück. 0=nicht besucht, 1= besucht.
int visited(int cityId) {
    int res = 0;
    for (int i = 0; i < (sizeof city / sizeof city[0]); i++) {
        if (city[i].id == cityId) {
            if (city[i].visited == 1) res = 1;
        }
    }
    return res;
}

/**
Funktion durchsucht alle Verbindungen zu und von der Stadt mit der id cityID.
Aus den möglichen Ziel-IDs wir ein Array gebildet und ein
zufälliges Element daraus zurückgeliefert.
**/
int randomCity(int cityID) {

    int streets[10];
    int cnt = 0;
    int vis;

    for (int i = 0; i < 52; i++) {

        //Verbindungen von der Stadt weg
        if (street[i][0] == cityID) {
            vis = visited(street[i][1]);
            if (vis == 0 || start->id == street[i][1]) {
                streets[cnt] = street[i][1];
                cnt++;
            }
        }
        //Verbindungen zu der Stadt hin
        if (street[i][1] == cityID) {
            vis = visited(street[i][0]);
            if (vis == 0 || start->id == street[i][0]) {
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
struct City *getCityById(int cityId) {
    for (int i = 0; i < (sizeof city / sizeof city[0]); i++) {
        if (city[i].id == cityId) {
            return &city[i];
        }
    }
    return &city[0];
}

/**
Rekursive Funktion
Liefert -1, falls wieder am Ausgangspunkt angelangt.
Liefert 0, wenn keine weiteren Verbindungen möflich (Sackgasse)
Ruft sich selbst auf, um weitere zufällige Städte zu besuchen.
**/

int go(struct City *city) {

    //Wenn in der Start-Stadt angelangt, die schon besucht wurde.
    //Hier wird nicht unterschieden, ob man am Ausgangspunkt deshalb zurückkehrt, weil man aus einer Sackgasse zurückgekommen ist ud noch weitere Routen möglich wären.
    if (city->id == start->id && start->visited == 1) {
        return -1;

    } else {
        printf("\nVisiting %s", city->name);
        //Stadt als besucht markieren´
        city->visited = 1;
        //rndCity enthält die ID einer zufälligen Stadt, die besucht werden kann, oder 0 in Sackgasse.
        int rndCity;
        //alle Nachbarstädte in zufälliger Reihenfolge besuchen, falls nicht zuerst die Rundreise am Ausgangspunkt endet.

        do {
            rndCity = randomCity(city->id);
            if (rndCity == 0) printf("\nSackgasse in %s", city->name);
            if (rndCity > 0) {
                struct City *nextCity = getCityById(rndCity);
                //Rekursiver Aufruf
                int next = go(nextCity);
                if (next == -1) {
                    //Rundreise zu Ende
                    return next;
                } else {
                    printf("\nZurück in %s", city->name);
                    rndCity = randomCity(city->id);
                }
            }
        } while (rndCity > 0);
        return rndCity;
    }
}

