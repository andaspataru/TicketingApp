#pragma once
#include <string>
using namespace std;


class Eveniment
{
private:

	int* randuriZone;
	int** nrLocuri;//matrice pt locuri
	int nrZone;
	string* tipuriZone;
	char* tipEveniment;
	string denumireEveniment;
	int durata;//in minute



public:


	Eveniment();
	Eveniment(int*, int**, int, string*, char*, string, int);
	~Eveniment();
	Eveniment(const Eveniment&);
	Eveniment& operator=(const Eveniment&);
	Eveniment operator-=(int);


	int* getRanduriZone();
	int** getNrLocuri();
	string* getTipuriZone();
	int getDurata();
	int getNrZone();
	string getDenumireEveniment();
	char* getTipEveniment();
	int getLocRand(int , int );
	int* getNrLocuriZona(int);
	int getRanduriZona(int);


	void setRanduriZone(int*, int);
	void setNrZone(int);
	void setTipuriZone(string*, int);
	void setDenumireEveniment(string);
	void setTipEveniment(const char* t);
	void setDurata(int);
	
	void transformareOre();
	void durataNoua(int);
	void nrLocuriZone();
	int  nrMax();

	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
};

