#include "funkcijos.h"

using namespace std;

bool sort1(const duom &a, const duom &b){
    return(a.vard<b.vard);
}
bool sort2(const duom &a, const duom &b){
    return(a.pav<b.pav);
}
bool sort3(const duom &a, const duom &b){
    return(a.galvid<b.galvid);
}
bool sort4(const duom &a, const duom &b){
    return(a.galmed<b.galmed);
}
bool sort1u(const duom &a, const duom &b){
    return(a.vard>b.vard);
}
bool sort2u(const duom &a, const duom &b){
    return(a.pav>b.pav);
}
bool sort3u(const duom &a, const duom &b){
    return(a.galvid>b.galvid);
}
bool sort4u(const duom &a, const duom &b){
    return(a.galmed>b.galmed);
}

template <typename sk=int, typename talpa> 
void rusiuoti(sk &x, sk &t, talpa &mok){
    if(t==1){
        if(x==1) sort(mok.begin(), mok.end(), sort1);
        if(x==2) sort(mok.begin(), mok.end(), sort2);
        if(x==3) sort(mok.begin(), mok.end(), sort3);
        if(x==4) sort(mok.begin(), mok.end(), sort4);
    }
    else{
        if(x==1) sort(mok.begin(), mok.end(), sort1u);
        if(x==2) sort(mok.begin(), mok.end(), sort2u);
        if(x==3) sort(mok.begin(), mok.end(), sort3u);
        if(x==4) sort(mok.begin(), mok.end(), sort4u);
    }
}

template <typename sk=int>
void rusiuotilist(sk &x, sk &t, list<duom> &mok) {
    if(t==1) {
        if(x==1) mok.sort(sort1);
        if(x==2) mok.sort(sort2);
        if(x==3) mok.sort(sort3);
        if(x==4) mok.sort(sort4);
    } else {
        if(x==1) mok.sort(sort1u);
        if(x==2) mok.sort(sort2u);
        if(x==3) mok.sort(sort3u);
        if(x==4) mok.sort(sort4u);
    }
}

void calc(duom &m){
    int a=accumulate(m.ndrez.begin(), m.ndrez.end(), 0);
    double sum=a;
    double egz=0;
    double med=0;

    // m.ndrez.sort();
    sort(m.ndrez.begin(), m.ndrez.end());

    if(m.ndrez.size()!=0){
        sum=sum/(m.ndrez.size());

        auto it = m.ndrez.begin();
        advance(it, m.ndrez.size()/2);

        if (m.ndrez.size()%2==0){
            auto it1 = it;
            std::advance(it1, -1);
            med = (*it + *it1) / 2.0;
        } 
        else{
            med = *it;
        }
    }
    egz=m.egzrez;

    m.galvid=sum*0.4+egz*0.6;
    m.galmed=med*0.4+egz*0.6;
}

bool pagalVid(const duom &x, const double d){
    return x.galvid<d;
}
bool pagalMed(const duom &x, const double d){
    return x.galmed<d;
}

template <typename talpa, typename sk> 
void skirstymas(talpa &x, talpa &y, sk t){
    auto it=x.begin();
    auto end=x.end();
    auto tarp=end;

    if(t==3){
        tarp=lower_bound(x.begin(), x.end(), 5.0, pagalVid);
    }
    if(t==4){
        tarp=lower_bound(x.begin(), x.end(), 5.0, pagalMed);
    }

    copy(tarp, x.end(), back_inserter(y));

    x.erase(tarp, x.end());
}

template <typename sk, typename talpa>
void skaitymas(sk &moksk, sk &ndsk, talpa &mok){
    string temp;

    cin>>temp;
    cin>>temp;

    while(true){
        cin>>temp;
        if(temp.back()>='0'&&temp.back()<='9'){
            ndsk++;
        }
        else{
            getline(cin, temp);
            break;
        }
    }    

    mok.reserve(moksk);

    for(int i=0; i<moksk; i++){
        duom m;

        string vardas;

        cin>>m.vard>>m.pav;

        m.ndrez.reserve(ndsk);

        for(int j=0; j<ndsk; j++){
            int a;
            cin>>a;
            m.ndrez.push_back(a);
        }

        cin>>m.egzrez;

        calc(m);

        mok.push_back(m);
        
        cin.ignore(255, '\n');
    }
}

template <typename talpa, typename sk>
double isfailo(sk &moksk, talpa &mok){
    int ndsk=0;

    cout<<"Kiek asmenu nuskaityti nuo duoto failo?"<<endl;
    while(!(cin>>moksk)||moksk<0){
        try{
            throw runtime_error("Klaidingai ivesti duomenys\n");
        }
        catch(const runtime_error &e){
            cin.clear();
            cin.ignore();
            cout<<e.what();
        }
    }

    int x;
    int t;

    cout<<"Rusiuoti pagal: 1-varda; 2-pavarde; 3-galutini(vid); 4-galutini(med)"<<endl;
    while(!(cin>>x)||x<1||x>4){
        try{
            throw runtime_error("Klaidingai ivesti duomenys\n");
        }
        catch(const runtime_error &e){
            cin.clear();
            cin.ignore();
            cout<<e.what();
        }
    }

    cout<<"Tvarka: 1-didejimo; 2-mazejimo"<<endl;
    while(!(cin>>t)||t<1||t>2){
        try{
            throw runtime_error("Klaidingai ivesti duomenys\n");
        }
        catch(const runtime_error &e){
            cin.clear();
            cin.ignore();
            cout<<e.what();
            cout<<"Pasirinkite viena is variantu"<<endl;
        }
    }

    bool uzd4;

    cout<<"Ar atliekama 0.4 uzduotis?(1/0)"<<endl;
    while(!(cin>>uzd4)){
        try{
            throw runtime_error("Klaidingai ivesti duomenys\n");
        }
        catch(const runtime_error &e){
            cin.clear();
            cin.ignore();
            cout<<e.what();
            cout<<"Pasirinkite viena is variantu"<<endl;
        }
    }

    string failas;

    while(true){
        cout<<"Iveskite faila is kurio imti duomenis"<<endl;
        cin>>failas;

        ifstream file(failas+".txt");

        if(!file.is_open()){
            try{
                throw runtime_error("Klaidingai ivesti duomenys\n"); 
            }
            catch(const runtime_error &e){
                cout<<e.what();
            }
        }
        else{
            file.close();
            freopen((failas+".txt").c_str(), "r", stdin);
            break;
        };
    }

    auto start = high_resolution_clock::now();

    skaitymas(moksk, ndsk, mok);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout<<"Skaitymo laikas: "<<duration.count()<<endl;

    start = high_resolution_clock::now();

    if constexpr (is_same<talpa, list<duom>>::value){
        rusiuotilist(x, t, mok);
    }
    else{
        rusiuoti(x, t, mok);
    }

    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    cout<<"Rusiavimo laikas: "<<duration.count()<<endl;

    vector<duom> pazenge;

    if(uzd4==true){
        start = high_resolution_clock::now();

        skirstymas(mok, pazenge, x);

        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        cout<<"Skirstymo laikas: "<<duration.count()<<endl;
    }

    if(uzd4==true){
        start = high_resolution_clock::now();

        ifstream file("pazenge.txt");

        if(file.is_open()){
            remove("pazenge.txt");
        }
        file.close();
        freopen("pazenge.txt", "r", stdin);
        freopen("pazenge.txt", "w", stdout);

        cout<<setw(25)<<left<<"Vardas"<<setw(25)<<left<<"Pavarde";
    
        for(int i=1; i<=ndsk; i++){
            cout<<"ND"<<setw(6)<<left<<i;
        }

        cout<<"Egz."<<endl;

        for (const auto& elem : pazenge) {
            cout<<setw(25)<<left<<elem.vard<<setw(25)<<left<<elem.pav;
            for (int j : elem.ndrez) {
                cout<<std::setw(8)<<j;
            }
            cout<<elem.egzrez<<endl;
        }

        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        freopen("CON", "r", stdin);
        freopen("CON", "w", stdout);

        cout<<"Pazengusiu spausdinimo laikas: "<<duration.count()<<endl;

        auto start = high_resolution_clock::now();

        ifstream filez("zluge.txt");

        if(filez.is_open()){
            remove("zluge.txt");
        }
        filez.close();
        freopen("zluge.txt", "r", stdin);
        freopen("zluge.txt", "w", stdout);

        cout<<setw(25)<<left<<"Vardas"<<setw(25)<<left<<"Pavarde";
    
        for(int i=1; i<=ndsk; i++){
            cout<<"ND"<<setw(6)<<left<<i;
        }

        cout<<"Egz."<<endl;

        for (const auto& elem : mok) {
            cout<<setw(25)<<left<<elem.vard<<setw(25)<<left<<elem.pav;
            for (int j : elem.ndrez) {
                cout<<std::setw(8)<<j;
            }
            cout<<elem.egzrez<<endl;
        }

        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);

        freopen("CON", "r", stdin);
        freopen("CON", "w", stdout);

        cout<<"Zlugusiu spausdinimo laikas: "<<duration.count();

        exit(0);
    }

    return(duration.count());
}

void kurtifaila(){
    string failas;
    while(true){
        cout<<"Iveskite failo pavadinima"<<endl;
        cin>>failas;

        ifstream file(failas+".txt");

        if(file.is_open()){
            try{
                throw runtime_error("Toks failas jau yra\n"); 
            }
            catch(const runtime_error &e){
                cout<<e.what();
            }
            file.close();
        }
        else{
            file.close();
            freopen((failas+".txt").c_str(), "r", stdin);
            break;
        };
    }
    freopen("CON", "r", stdin);

    cout<<"Iveskite kiek asmenu bus faile"<<endl;
    int moksk;
    while(!(cin>>moksk)||moksk<0){
        try{
            throw runtime_error("Klaidingai ivesti duomenys\n");
        }
        catch(const runtime_error &e){
            cin.clear();
            cin.ignore();
            cout<<e.what();
        }
    }

    cout<<"Iveskite kiek namu darbu buvo paskirta"<<endl;
    int ndsk;
    while(!(cin>>ndsk)||ndsk<0){
        try{
            throw runtime_error("Klaidingai ivesti duomenys\n");
        }
        catch(const runtime_error &e){
            cin.clear();
            cin.ignore();
            cout<<e.what();
        }
    }

    auto start = high_resolution_clock::now();

    freopen((failas+".txt").c_str(), "r", stdin);
    freopen((failas+".txt").c_str(), "w", stdout);

    cout<<setw(25)<<left<<"Vardas"<<setw(25)<<left<<"Pavarde";
    
    for(int i=1; i<=ndsk; i++){
        cout<<"ND"<<setw(6)<<left<<i;
    }

    cout<<"Egz."<<endl;

    for(int i=1; i<=moksk; i++){
        cout<<"Vardas"<<setw(19)<<left<<i;
        cout<<"Pavarde"<<setw(19)<<left<<i;

        for(int j=1; j<=ndsk; j++){
            cout<<setw(8)<<rand()%10+1;
        }

        cout<<rand()%10+1<<endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);

    cout<<"Failo kurimo laikas: "<<duration.count()<<endl;
}

void input(int &moksk, vector<duom>& mok, double &duration){

    srand(time(nullptr));

    int x;

    if(moksk==-1){
        while(true){
            cout<<"1-ranka; 2-generuoti pazymius; 3-generuoti pazymius ir varda/pavarde; 4-skaityti duomenis is failo; 5-sukurti nauja faila; 6-baigti darba"<<endl;
            if(!(cin>>x)||x<1||x>6){
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
    }
    else{
        while(true){
            cout<<"1-ranka; 2-generuoti pazymius; 3-generuoti pazymius ir varda/pavarde; 5-sukurti nauja faila; 6-baigti darba"<<endl;
            if(!(cin>>x)||x<1||x>6||x==4){
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
    }

    if(x==6) exit(0);

    if(x==5){
        kurtifaila();
        input(moksk, mok, duration);
    }

    if(x==4){
        duration=isfailo(moksk, mok);
        return;
    }
    else{
        duom m;
        moksk++;

        if(x==3){
            for(int i=0; i<4+rand()%6; i++){
                if(i==0) m.vard+=(char) (65+rand()%25);
                else m.vard+=(char) (97+rand()%25);
            }
            for(int i=0; i<4+rand()%8; i++){
                if(i==0) m.pav+=(char) (65+rand()%25);
                else m.pav+=(char) (97+rand()%25);
            }
        }
        else{
            cout<<"Irasykite varda"<<endl;
            while(!(cin>>m.vard)){
                try{
                    throw runtime_error("Klaidingai ivesti duomenys\n");
                }
                catch(const runtime_error &e){
                    cin.clear();
                    cin.ignore();
                    cout<<e.what();
                }
            }
            cout<<"Irasykite pavarde"<<endl;
            while(!(cin>>m.pav)){
                try{
                    throw runtime_error("Klaidingai ivesti duomenys\n");
                }
                catch(const runtime_error &e){
                    cin.clear();
                    cin.ignore();
                    cout<<e.what();
                }
            }
        }
        
        if(x==2||x==3){
            for(int i=0; i<1+rand()%15; i++){
                m.ndrez.push_back(rand()%11);
            }
        }
        else{
            cout<<"Irasykite nd rezultatus po kiekvieno spaudziant enter, jei baigete parasykite skaiciu netelpanti i desimtbales sistemos intervala"<<endl;
            int h;
            while(true){
                while(!(cin>>h)){
                    try{
                        throw runtime_error("Klaidingai ivesti duomenys\n");
                    }
                    catch(const runtime_error &e){
                        cin.clear();
                        cin.ignore();
                        cout<<e.what();
                    }
                }
                if(h<0||h>10){
                    break;
                }
                m.ndrez.push_back(h);
            }
        }
        if(x==2||x==3){
            m.egzrez=rand()%11;
        }
        else{
            cout<<"Irasykite egzamino rezultata"<<endl;
            while(!(cin>>m.egzrez)||m.egzrez<0||m.egzrez>10){
                try{
                    throw runtime_error("Klaidingai ivesti duomenys\n");
                }
                catch(const runtime_error &e){
                    cin.clear();
                    cin.ignore();
                    cout<<e.what();
                }
            }
        }

        calc(m);
        
        cout<<"Jei norite prideti daugiau mokiniu spauskite 1, jei baigete, spauskite bet koki kita svaika skaiciu"<<endl;
        int a;

        while(!(cin>>a)){
            try{
                throw runtime_error("Klaidingai ivesti duomenys\n");
            }
            catch(const runtime_error &e){
                cin.clear();
                cin.ignore();
                cout<<e.what();
            }
        }

        mok.push_back(m);

        if(a==1) input(moksk, mok, duration);

        moksk++;
    }

    return;
}