//
// Created by Aleksandr Grek on 22.12.2020.
//

#ifndef C_HANDLER_H
#define C_HANDLER_H


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

void representGebiet(struct Gebiet a);

struct Gebiet createGebiet(char line[]);

void storeGebiet(struct Gebiet storage[], char *filename);

char *getGebietByCityId(int cityId, struct Stadt *cityStorage, struct Gebiet *gebietStorage);

void searchForBinnenStrassen(struct Strasse whereToStore[], struct Strasse whereToSearch[], struct Stadt cityStorage[],
                             struct Gebiet gebietStorage[]);


struct Stadt createStadt(char line[]);

void representStadt(struct Stadt a);

void storeStadt(struct Stadt *storage, char *filename);


void representStrasse(struct Strasse a);

int compare(const void *s1, const void *s2);

struct Strasse createStrasse(char line[]);

void storeStrasse(struct Strasse *storage, char *filename);


#endif //C_HANDLER_H
