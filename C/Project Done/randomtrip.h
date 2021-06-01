//
// Created by niki_lauda on 02.01.2021.
//

#ifndef PROGRAMM_RANDOMTRIP_H
#define PROGRAMM_RANDOMTRIP_H

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

struct City getStadt(char line[]);
void readfromStadt(struct City storage[], char *filename);
struct Strasse getStrasse(char line[]);
void readfromStrasse(struct Strasse storage[], char *filename);
struct Gebiet getGebiet(char line[]);
void readfromGebiet(struct Gebiet storage[], char *filename);
void fillCity(struct City storage[], struct Strasse storage1[]);
int visited(int cityId);
int randomCity(int cityID);

struct City *getCityById(int cityId); //
int go(struct City *city);



#endif //PROGRAMM_RANDOMTRIP_H
