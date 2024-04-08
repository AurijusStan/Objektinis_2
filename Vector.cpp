// #include <iostream>
// #include <iomanip>
// #include <numeric>
// #include <vector>
// #include <random>
// #include <string>
// #include <chrono>

#include "funkcijos.h"

using namespace std;

int main(){   
    int s; 

    while(true){
        cout<<"1-Vector; 2-List; 3-Deque"<<endl;
        if(!(cin>>s)||s<1||s>3){
            try{
                throw runtime_error("Klaidingai ivesti duomenys\n");
            }
            catch(const runtime_error &e){
                cin.clear();
                cin.ignore();
                cout<<e.what();
            }
        }
        else break;
    }

    vector<duom> mok;

    if(s==2){
        list<duom> temp_mok;
        mok.assign(temp_mok.begin(), temp_mok.end());
    }
    else if(s==3){
        deque<duom> temp_mok;
        mok.assign(temp_mok.begin(), temp_mok.end());
    }

    double duration = 0.0;

    int moksk = -1;

    input(mok, moksk, duration);

    cout<<setw(19)<<left<<"Vardas"<<setw(19)<<left<<"Pavarde"<<setw(19)<<left<<"Galutinis (Vid.)"<<setw(19)<<left<<"Galutinis (Med.)"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    for(const auto& elem : mok){
        cout<<setw(19)<<left<<elem.vard<<setw(19)<<left<<elem.pav<<setw(19)<<left<<setprecision(3)<<elem.galvid<<setw(19)<<left<<setprecision(3)<<elem.galmed<<endl;
    }

    cout<<duration;
    
    return 0;
}