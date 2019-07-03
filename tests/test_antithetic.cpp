#include <iostream>
#include <cstdlib>
#include <vector>
#include "options/parkmiller.h"
#include "options/antithetic.h"

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[]) {
    int DIMENSION=12;
    int SEED=45;

    if (argc==2) {
        SEED=atoi(argv[1]);
    }

    RandomParkMiller rand(DIMENSION, SEED);
    MJArray ary(DIMENSION);

    rand.GetUniforms(ary);

    cout << "Simulation #1" << endl;

    for (int i=0; i<DIMENSION; ++i) {
        cout << "x= " 
            << ary[i] 
            << endl;
    }

    RandomParkMiller rand2(DIMENSION, SEED);
    AntiThetic atRand(rand2);
    MJArray ary2(DIMENSION);

    rand.GetUniforms(ary2);

    cout << "Simulation #2" << endl;

    for (int i=0; i<DIMENSION; ++i) {
        cout << "x= " 
            << ary[i] 
            << endl;
    }

    return 0;
}