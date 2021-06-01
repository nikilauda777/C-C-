#include <stdio.h>
#include "stdlib.h"
#include <string.h>



//// Created by Aleksandr Grek on 18.11.2020.

struct Stadt {
    int cityId;
    char name[15];
    int population;
    int regionId;
    int seeLevel;

};

struct Gebiet {
    int gebietId;
    char name[20];
    int oberGebietId;
    char typ;

};


//// Created by Aleksandr Grek on 18.11.2020.

struct Strasse {
    int fromCityId;
    int toCityId;
    int distance;
    char land[15];

};

void representStrasse(struct Strasse a) {
    printf("\nFROM_CITY_ID : %d \n TO_CITY_ID : %d \n DISTANCE : %d \n", a.fromCityId, a.toCityId, a.distance);

    if (a.land[0] != '\0') {
        printf("LAND : %s \n", a.land);
    }

}

int compare(const void *s1, const void *s2) {
    struct Strasse *e1 = (struct Strasse *) s1;
    struct Strasse *e2 = (struct Strasse *) s2;
    int comp = strcmp(e2->land, e1->land);
    if (comp == 0)
        return e1->distance - e2->distance;
    else
        return -comp;
}

struct Strasse createStrasse(char line[]) {


    int ai = 0, ei = 0;
    char element[15];
    struct Strasse a;


    for (int i = 0; i < strlen(line) + 1; i++) {

        if (line[i] == ' ' || i == strlen(line)) {
            // add attributes

            if (ai == 0) {
                a.fromCityId = atoi(element);


            } else if (ai == 1) {


                a.toCityId = atoi(element);


            } else if (ai == 2) {

                a.distance = atoi(element);

            }

            ai++;
            ei = 0;

            for (int j = 0; j < 15; j++) {
                element[j] = '\0';
            }

            continue;

        }

        element[ei++] = line[i];

    }


    return a;
}


void storeStrasse(struct Strasse *storage, char *filename) {

    int is = 0;

    int c;
    FILE *file;
    file = fopen(filename, "r");
    if (file) {

        char line[35];
        int il = 0;

        while ((c = getc(file)) != EOF) {

            // || c == NULL
            if (c == '\n') {
                //refresh line and il

                storage[is++] = createStrasse(line); // create new Stadt and add to array

                for (int i = 0; i < 35; i++) { // clear var line
                    line[i] = '\0';
                }

                il = 0; // index of line is zero
            }

            line[il++] = (char) c;

        }
        fclose(file);

    }

}


//// Becomes a line of file as an input
//// Creates struct Stadt from it and returns it
struct Stadt createStadt(char line[]) {

    int ai = 0, ei = 0;
    char element[15];
    struct Stadt a;


    for (int i = 0; i < strlen(line); i++) {


        if (line[i] == ' ' || (i + 1 == strlen(line))) {
            // add attributes

            if (ai == 0) {
                a.cityId = atoi(element);
            } else if (ai == 1) {


                for (int j = 0; j < 15; j++) {
                    a.name[j] = element[j];
                }

            } else if (ai == 2) {

                a.population = atoi(element);

            } else if (ai == 3) {

                a.regionId = atoi(element);

            } else if (ai == 4) {
                a.seeLevel = atoi(element);
            }

            ai++;
            ei = 0;

            for (int j = 0; j < 15; j++) {
                element[j] = '\0';
            }

            continue;

        }


        element[ei++] = line[i];

    }


    return a;
}


//// Prints a city in a cute form
void representStadt(struct Stadt a) {
    printf("\nID : %d \n NAME : %s \n POPULATION : %d \n REGION_ID : %d \n SEE_LEVEL : %d \n", a.cityId, a.name,
           a.population,
           a.regionId, a.seeLevel);

}

//// becomes an empty array of cityies and file name as input
//// stores all collected from the input file in the given array
void storeStadt(struct Stadt *storage, char *filename) {

    int is = 0;

    int c;
    FILE *file;
    file = fopen(filename, "r");
    if (file) {

        char line[35];
        int il = 0;

        while ((c = getc(file)) != EOF) {

            if (c == '\n' || c == '\0') {
                //refresh line and il
                storage[is++] = createStadt(line); // create new Stadt and add to array

                for (int i = 0; i < 35; i++) { // clear var line
                    line[i] = '\0';
                }

                il = 0; // index of line is zero
            }

            line[il++] = (char) c;

        }
        fclose(file);

    }

}


void representGebiet(struct Gebiet a) {
    printf("\nGEBIET_ID : %d \n NAME : %s \n OBERGEBIET_ID : %d \n TYP : %c\n", a.gebietId, a.name, a.oberGebietId,
           a.typ);

}


struct Gebiet createGebiet(char line[]) {


    int ai = 0, ei = 0;
    char element[20];

    struct Gebiet a;


    for (int i = 0; i < strlen(line) + 1; i++) {

        if (line[i] == ' ' || i == strlen(line)) {
            // add attributes

            if (ai == 0) {
                a.gebietId = atoi(element);


            } else if (ai == 1) {


                for (int j = 0; j < 20; j++) {
                    a.name[j] = element[j];
                }


            } else if (ai == 2) {

                a.oberGebietId = atoi(element);

            } else if (ai == 3) {
                a.typ = element[0];
            }

            ai++;
            ei = 0;

            for (int j = 0; j < 20; j++) {
                element[j] = '\0';
            }

            continue;

        }

        element[ei++] = line[i];

    }


    return a;
}


void storeGebiet(struct Gebiet storage[], char *filename) {

    int is = 0;

    int c;
    FILE *file;
    file = fopen(filename, "r");
    if (file) {

        char line[35];
        int il = 0;

        while ((c = getc(file)) != EOF) {

            // || c == NULL
            if (c == '\n') {
                //refresh line and il

                storage[is++] = createGebiet(line); // create new Stadt and add to array

                for (int i = 0; i < 35; i++) { // clear var line
                    line[i] = '\0';
                }

                il = 0; // index of line is zero
            }

            line[il++] = (char) c;

        }
        fclose(file);

    }

}


char *getGebietByCityId(int cityId, struct Stadt *cityStorage, struct Gebiet *gebietStorage) {

    struct Stadt city;
    struct Gebiet gebiet;
    struct Gebiet oberGebiet;
    char *name;

    for (int i = 0; i < 38; i++) {
        if (cityId == cityStorage[i].cityId) {
            city = cityStorage[i];
        }
    }

    for (int i = 0; i < 32; i++) {

        if (city.regionId == gebietStorage[i].gebietId) {
            gebiet = gebietStorage[i];
        }

    }

    for (int i = 0; i < 32; i++) {

        if (gebiet.oberGebietId == gebietStorage[i].gebietId) {
            oberGebiet = gebietStorage[i];
        }

    }

    if (oberGebiet.typ != 'L') {
        struct Gebiet oberOberGebiet;

        for (int i = 0; i < 32; i++) {


            if (oberGebiet.oberGebietId == gebietStorage[i].gebietId) {
                oberOberGebiet = gebietStorage[i];
            }

        }

        name = oberOberGebiet.name;
        return name;

    }


    name = oberGebiet.name;
    return name;
}


void searchForBinnenStrassen(struct Strasse whereToStore[], struct Strasse whereToSearch[], struct Stadt cityStorage[],
                             struct Gebiet gebietStorage[]) {
    int index = 0;

    for (int i = 0; i < 55; i++) {

        int from = whereToSearch[i].fromCityId;
        int where = whereToSearch[i].toCityId;

        char *gebietFrom = getGebietByCityId(from, cityStorage, gebietStorage);
        char *gebietTo = getGebietByCityId(where, cityStorage, gebietStorage);

        if (gebietFrom == gebietTo) {

            char *land = gebietFrom;

            for (int j = 0; j < 15; j++) {
                whereToSearch[i].land[j] = land[j];
            }

            whereToStore[index++] = whereToSearch[i];

        }

    }

}




