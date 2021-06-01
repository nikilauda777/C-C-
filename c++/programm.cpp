#include <string>
#include <vector>  //for std::vector

#include "stadt.h"
#include "gebiet.h"
#include "strasse.h"
#include "randomtrip.h"


using namespace std;

int main(int argc, char *argv[]) {


    auto *cities = (City *) malloc(100 * sizeof(City));
    auto *regions = (Gebiet *) malloc(100 * sizeof(Gebiet));
    auto *streets = (Strasse *) malloc(100 * sizeof(Strasse));
    struct City *start1;

    createAndStoreStadts("", cities);
    createAndStoreGebiets("", regions);
    createAndStoreStrasses("", streets);


    fillCity(cities, streets);

    time_t t;
    srand((unsigned) time(&t));
    start1 = randomCitychoice();
    cityTotrip(start1);


    return 0;
}
