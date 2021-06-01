#ifndef PROGRAMM1_GEBIET_H
#define PROGRAMM1_GEBIET_H

#include <fstream>

class Gebiet {
private:
    int gebietId;
    std::string name;
    int oberGebietId;
    char typ;

public:
    Gebiet(int id, std::string n, int ogid, string t) {
        gebietId = id;
        name = std::move(n);
        oberGebietId = ogid;
        typ = t.at(0);
    }

    int getGebietId() const {
        return gebietId;
    }
    string &getName() {
        return name;
    }
    int getOberGebietId() {
        return oberGebietId;
    }


    char getTyp() const {
        return typ;
    }



    bool isEmpty() {
        return gebietId == 0;
    }


};

static void createAndStoreGebiets(string path_to_file, Gebiet *where_to_store) {

    path_to_file = "/home/niki_lauda/CLionProjects/programm1/gebiet.dat";

    std::ifstream input(path_to_file);

    int index = 0;

    for (std::string line; getline(input, line);) {
        string word;
        int i = 0;
        string attrs[4];

        for (char x : line) { // char

            if (x == ' ') {
                attrs[i++] = word;
                word = "";
            } else {
                word += x;
            }
        }
        attrs[i] = word;

        Gebiet a(std::stoi(attrs[0]), attrs[1], std::stoi(attrs[2]), attrs[3]);
        where_to_store[index++] = a;
    }

}
#endif //PROGRAMM1_GEBIET_H
