#pragma once
#include <string>
#include "Eveniment.h"
class EvenInterior :
    public Eveniment
{
private:
    string sala;
    int etaj;


public:
    EvenInterior();
    EvenInterior(int* , int** , int , string* , char* , string ,int, string , int);
    EvenInterior& operator=(const EvenInterior&);
    EvenInterior(const EvenInterior&);

    string getSala();
    int getEtaj();

    void setEtaj(int);
    void setSala(string);

    friend ostream& operator<<(ostream&, EvenInterior);
    friend istream& operator>>(istream&, EvenInterior&);
};

