#ifndef FUNKCIJOS_H_  
#define FUNKCIJOS_H_  

#include <bits/stdc++.h> 

using namespace std;
using namespace std::chrono;
using std::setw;
using std::left;

class duom{
    private:
        string vard_;
        string pav_;
        vector<int> ndrez_;
        int egzrez_;
        double galvid_, galmed_;
    public:
        duom() : galvid_(0), galmed_(0) {}
        ~duom() {}
        duom(istream &cin);

        // copy c
        duom(const duom &temp)
            : vard_(temp.vard_), pav_(temp.pav_), ndrez_(temp.ndrez_), egzrez_(temp.egzrez_), galvid_(temp.galvid_), galmed_(temp.galmed_) {}

        // move c
        duom(duom&& temp) noexcept 
            : vard_(std::move(temp.vard_)), 
            pav_(std::move(temp.pav_)), 
            ndrez_(std::move(temp.ndrez_)), 
            egzrez_(temp.egzrez_), 
            galvid_(temp.galvid_), 
            galmed_(temp.galmed_) {}

        // copy a
        duom& operator=(const duom &temp) {
            vard_=temp.vard_;
            pav_=temp.pav_;
            ndrez_=temp.ndrez_;
            egzrez_=temp.egzrez_;
            galvid_=temp.galvid_;
            galmed_=temp.galmed_;
            return *this;
        }

        // move a
        duom& operator=(duom&& temp) noexcept {
            vard_ = std::move(temp.vard_);
            pav_ = std::move(temp.pav_);
            ndrez_ = std::move(temp.ndrez_);
            egzrez_ = temp.egzrez_;
            galvid_ = temp.galvid_;
            galmed_ = temp.galmed_;

            return *this;
        }


        inline string vard() const { return vard_; }
        inline string pav() const { return pav_; }
        inline double galvid() const { return galvid_; }
        inline double galmed() const { return galmed_; }

        void vardas(const string &va) { vard_=va; }
        void pavarde(const string &pa) { pav_=pa; }
        void nd(int nd) { ndrez_.push_back(nd); }
        void egz(int egz) { egzrez_=egz; }
        void calc();

        void vpskait();
        void skaitduom();
        void spausdinti();
        void vardoGen();
        void ndGen();
        void egzGen();

        friend istream& operator>>(istream &cin, duom &s);
        friend ostream& operator<<(ostream &cout, const duom &s);

};

bool sort1(const duom &, const duom &);
bool sort2(const duom &, const duom &);
bool sort3(const duom &, const duom &);
bool sort4(const duom &, const duom &);
bool sort1u(const duom &, const duom &);
bool sort2u(const duom &, const duom &);
bool sort3u(const duom &, const duom &);
bool sort4u(const duom &, const duom &);
bool pagalVid(const duom &x, const double d);
bool pagalMed(const duom &x, const double d);

template <typename sk=int, typename talpa>
void rusiuoti(sk &, sk &, talpa &);

template <typename talpa, typename sk> 
void strategija3(talpa &, talpa &, sk);

template <typename talpa, typename sk> 
void strategija2(talpa &, talpa &, sk);

template <typename talpa, typename sk> 
void strategija1(talpa &, talpa &, sk, talpa &);

template <typename sk, typename talpa>
void skaitymas(sk &, talpa &);

template <typename talpa, typename sk=int>
void isfailo(talpa &, sk &);

void kurtifaila();

template <typename sk, typename talpa>
double rankinis(sk &, talpa &, sk &);

void input();

void testas();

#endif