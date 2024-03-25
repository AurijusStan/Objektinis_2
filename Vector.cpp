// #include <iostream>
// #include <iomanip>
// #include <numeric>
// #include <vector>
// #include <random>
// #include <string>
// #include <chrono>

#include "funkcijos.h"

using namespace std;
using std::setw;
using std::left;

int main(){    
    vector<duom> mok;

    double duration=0;

    int moksk=-1;

    input(moksk, mok, duration);

    cout<<setw(19)<<left<<"Vardas"<<setw(19)<<left<<"Pavarde"<<setw(19)<<left<<"Galutinis (Vid.)"<<setw(19)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    for(const auto& elem : mok){
        cout<<setw(19)<<left<<elem.vard<<setw(19)<<left<<elem.pav<<setw(19)<<left<<setprecision(3)<<elem.galvid<<setw(19)<<left<<setprecision(3)<<elem.galmed<<endl;
    }

    cout<<duration;
    
    return 0;
}