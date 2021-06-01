//
// Created by niki_lauda on 13.01.2021.
//

#ifndef PROGRAMM1_STRASSE_H
#define PROGRAMM1_STRASSE_H


#include <fstream>

class Strasse {
private:
    int vonStadtId;
    int nachStadtId;
    int entfernung;



public:
    Strasse(int fI, int tI, int d) {
        vonStadtId = fI;
        nachStadtId = tI;
        entfernung = d;
    }


    int vonCityId(){

        return vonStadtId;
    }

    int nachCityId(){

        return nachStadtId;
    }


    bool isEmpty() {
        return vonStadtId == 0 || nachStadtId == 0;
    }


};

static void createAndStoreStrasses(string path_to_file, Strasse *where_to_store) {

    path_to_file = "/home/niki_lauda/CLionProjects/programm1/strasse.dat";

    std::ifstream input(path_to_file);

    int index = 0;

    for (std::string line; getline(input, line);) {
        string word;
        int i = 0;
        string attrs[3];

        for (auto x : line) {

            if (x == ' ') {
                attrs[i++] = word;
                word = "";
            } else {
                word += x;
            }
        }
        attrs[i] = word;

        Strasse a(std::stoi(attrs[0]), std::stoi(attrs[1]), std::stoi(attrs[2]));
        where_to_store[index++] = a;
    }


}


#endif //PROGRAMM1_STRASSE_H
