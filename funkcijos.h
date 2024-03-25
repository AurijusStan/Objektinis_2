#ifndef FUNKCIJOS_H_  
#define FUNKCIJOS_H_  

#include <bits/stdc++.h> 

using namespace std;
using namespace std::chrono;

struct duom{
    string vard;
    string pav;
    vector<int> ndrez;
    int egzrez;
    double galvid, galmed;
};

bool sort1(const duom &, const duom &);
bool sort2(const duom &, const duom &);
bool sort3(const duom &, const duom &);
bool sort4(const duom &, const duom &);
bool sort1u(const duom &, const duom &);
bool sort2u(const duom &, const duom &);
bool sort3u(const duom &, const duom &);
bool sort4u(const duom &, const duom &);

template <typename sk=int, typename talpa>
void rusiuoti(sk &, sk &, talpa &);

void calc(duom &);

template <typename talpa, typename sk> 
void skirstymas(talpa &, talpa &, sk);

template <typename sk, typename talpa>
void skaitymas(sk &, sk &, talpa &);

template <typename talpa, typename sk=int>
double isfailo(sk &, talpa &);

void kurtifaila();

void input(int &, vector<duom>&, double &);

#endif 