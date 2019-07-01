#include <iostream>
#include <cstdlib>
#include "options/parkmiller.h"

using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
    int DIMENSION=12;
    int SEED=45;

    cout << "argscount: "<< argc << endl;

    if (argc==2) {
        SEED=atoi(argv[1]);
    }

    RandomParkMiller rand(DIMENSION, SEED);
    MJArray ary(DIMENSION);

    rand.GetUniforms(ary);

    for (int i=0; i<DIMENSION; ++i) {
        cout << "x= " 
            << ary[i] 
            << endl;
    }

    return 0;
}