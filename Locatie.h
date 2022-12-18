#pragma once
#include<string>
using namespace std;

class Locatie
{
private:
	string adresa;
	string zi;
	int dataZi;
	int luna;
	int an;
	int ora;
	int min;
	string oras;
	static string tara;
	const long telefonContact;

public:
	Locatie();
	Locatie(string, string , int, int, int , int ,int, string);
	

	string getAdresa();
	string getZi();
	int getDataZi();
	int getLuna();
	int getAn();
	int getOra();
	int getMin();
	string getOras();
	static string getTara();

	void setAdresa(string);
	void setDataZi(int);
	void setZi(string);
	void setLuna(int);
	void setAn(int);
	void setOra(int);
	void setMin(int);
	void setOras(string);
	static void setTara(string);

	void intarziereOra(int);
	void intarziereMinute(int);
	void intarziereMinute(int, int);
	Locatie operator+(int);

	bool operator!();


	friend Locatie operator+(int, Locatie);
	friend ostream& operator<<(ostream& out, Locatie l);
	friend istream& operator>>(istream& in, Locatie& l);
};

Locatie operator+(int, Locatie);
