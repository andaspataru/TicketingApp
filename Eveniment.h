#pragma once
#include <string>
#include<iostream>
using namespace std;

class Eveniment
{
private:
	string categorie; 
	char* tipEveniment;
	char* denumireEveniment;
	string sala;
	int durata;//in minute

public:
	Eveniment();
	Eveniment(string, const char*, const char*, string, int);
	~Eveniment();
	Eveniment(const Eveniment& );

	Eveniment& operator=(const Eveniment& );
	bool operator!();
	char& operator[](int index);
	Eveniment operator-=(int );

	string getCategorie();
	char* getTipEveniment();
	char* getDenumireEveniment();
	string getSala();
	int getDurata();

	void setCategorie(string);
	void setTipEveniment(const char*);
	void setDenumireEveniment(const char*);
	void setSala(string);
	void setDurata(int);

	void durataNoua(int);
	static int durataMedie(Eveniment, int);
	static int nrConcerte(Eveniment*, int, char*);




	friend istream& operator>>(istream& in, Eveniment& e);
	friend ostream& operator<<(ostream& out, Eveniment e);
};


