//
// Created by niki_lauda on 13.01.2021.
//

#ifndef PROGRAMM1_STADT_H
#define PROGRAMM1_STADT_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;




class City{
private:
    int cityId;
    std::string name;
    int visited;


public:
    City(int ci, std::string n, int visit) {
        cityId = ci;
        name = std::move(n);
        visited = visit;    // Anfang nicht besuchte Stadt
    }

    int getCityId() const {
        return cityId;
    }

    int setVisit(){
        visited = 1;
        return visited;
    }

    int getVisit(){
        return visited;
    }

    const string &getName() const {
        return name;
    }

    bool isEmpty() {
        return cityId == 0;
    }

};



static void createAndStoreStadts(std::string path_to_file, City *where_to_store) {

    path_to_file = "/home/niki_lauda/CLionProjects/programm1/stadt.dat";


    std::ifstream input(path_to_file);

    int index = 0;

    for (std::string line; getline(input, line);) {


        string word;
        int i = 0;
        string attrs[5];

        for (auto x : line) {

            if (x == ' ') {
                attrs[i++] = word;
                word = "";
            } else {
                word += x;
            }
        }
        attrs[i] = word;
        City a(std::stoi(attrs[0]), attrs[1],0);
        where_to_store[index++] = a;
    }
}

#endif //PROGRAMM1_STADT_H
