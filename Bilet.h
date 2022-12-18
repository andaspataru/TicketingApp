#pragma once
#include <string>
using namespace std;


class Bilet
{
private:
	int id;
	int nrRanduri;
	int nrLocuri;
	int* scaune; //vector pt fiecare rand
	int bileteVandute; //bilRamase=nrLocuri-bileteVandute
	int nrCateg;
	float* listaPreturi;
	string zona;
	float pret;
	string metodaLivrare; //eTicket- gratuita sau livrare la domiciliu
	float costLivrare;

public:


	Bilet();
	Bilet(int, int, int*, int, int,float*,string,float, string, float);
	~Bilet();

	int getId();
	int getNrRanduri();
	int getNrLocuri();
	int* getScaune();
	int getBileteVandute();
	int getNrCateg();
	float* getListaPreturi();
	string getZona();
	float getPret();
	string getMetoda();
	float getCostLivrare();
	
	

	void setNrRanduri(int);
	void setNrLocuri(int);
	void setScaune(int*, int);
	void setBileteVandute(int);
	void setNrCateg(int);
	void setListaPreturi(float*, int);
	void setZona(string);
	void setPret(float);
	void setMetoda(string);
	void setCostLivrare(float);
	

	Bilet& operator=(const Bilet&);
	Bilet operator+= (int);
	Bilet& operator-(int);
	Bilet& operator++();
	Bilet operator++(int);

	float pretMediu();
	float pretMax();
	int bileteRamase();
	int locuriPeRand();
	bool capacitate();
	void discountCopil();
	float totalComanda();
	
	
	friend ostream& operator<<(ostream&, Bilet );
	friend istream& operator>>(istream&, Bilet&);

};

