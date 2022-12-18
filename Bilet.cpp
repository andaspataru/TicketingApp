#include "Bilet.h"
#include <string>
#include<iostream>
using namespace std;

//constructor fara parametri
Bilet::Bilet() {
	nrRanduri = 0;
	nrLocuri = 0;
	scaune = nullptr;
	bileteVandute = 0;
	nrCateg = 0;
	listaPreturi = nullptr;
	zona = " ";
	pret = 0.0;
	metodaLivrare = " ";
	costLivrare = 0.0;
	id = rand();

	
}

//constructor cu parametri
Bilet::Bilet(int nrRanduri, int nrLocuri,int* scaune, int bileteVandute, int nrCateg, float* listaPreturi,string zona, float pret, string metodaLivrare, float costLivrare):Bilet() {

	this->nrRanduri = nrRanduri;
	this->bileteVandute = bileteVandute;
	this->zona = zona;
	this->pret = pret;
	this->metodaLivrare = metodaLivrare;
	this->costLivrare = costLivrare;

	if (scaune != nullptr && nrLocuri > 0) {
		this->nrLocuri = nrLocuri;
		this->scaune = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			this->scaune[i] = i+1;
		}
	}
	else {
		this->scaune = nullptr;
		this->nrLocuri = 0;
	}

	if (listaPreturi != nullptr && nrCateg > 0) {
		this->nrCateg = nrCateg;
		this->listaPreturi = new float[nrCateg];
		for (int i = 0; i < nrCateg; i++)
		{
			this->listaPreturi[i] = listaPreturi[i];
		}
	}
	else {
		this->listaPreturi = nullptr;
		this->nrCateg = 0;
	}

	
}

//destructor
Bilet::~Bilet() {
	if (this->scaune != nullptr)
	{
		delete[] scaune;
		scaune = nullptr;
	}

	if (this->listaPreturi != nullptr)
	{
		delete[] listaPreturi;
		listaPreturi = nullptr;
	}
}


//getteri

int Bilet::getId() {
	return id;
}

int Bilet::getNrRanduri() {
		return nrRanduri;
	
}

int Bilet::getNrLocuri() {
		return nrLocuri;
}

int* Bilet::getScaune() {
	if (scaune != nullptr && nrLocuri!=0) {
		int* copy = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++)
		{
			copy[i] = scaune[i];
		}
		return copy;
	}
	else return nullptr;
	
}

int Bilet::getBileteVandute() {
	return bileteVandute;
}

int Bilet::getNrCateg() {
	return nrCateg;
}

float* Bilet::getListaPreturi() {
	if (listaPreturi != nullptr && nrCateg!=0) {
		float* c = new float[nrCateg];
		for (int i = 0; i < nrCateg; i++)
		{
			c[i] = listaPreturi[i];
		}
		return c;
	}
	else return nullptr;
}

string Bilet::getZona() {
	return zona;
}

float Bilet::getPret() {
	if (pret > 0.0)
		return pret;
}



string Bilet::getMetoda() {
	return metodaLivrare;
}
float Bilet::getCostLivrare() {
	return costLivrare;
}

//setteri

void Bilet::setNrRanduri(int nrRanduri) {
	if(nrRanduri>0)
	this->nrRanduri = nrRanduri;
}

void Bilet::setNrLocuri(int nrLocuri) {
	if(nrLocuri>0)
	this->nrLocuri = nrLocuri;
}

void Bilet::setScaune(int* scaune, int nrLocuri) {
	if (scaune != nullptr && nrLocuri > 0) {
		{delete[] this->scaune;
		this->scaune=nullptr;
		this->nrLocuri = 0;
		}

		this->scaune = new int[nrLocuri];
		for (int i = 0; i < nrLocuri; i++) {
			this->scaune[i] = scaune[i];
		}
		this->nrLocuri = nrLocuri;
	}
}

void Bilet::setBileteVandute(int nrBilete) {
	if (nrBilete >= 0)
		bileteVandute = nrBilete;
}

void Bilet::setNrCateg(int numar) {
	if (numar > 0)
		nrCateg = numar;
}

void Bilet::setListaPreturi(float* listaPreturi, int nrCateg) {
	if (listaPreturi != nullptr && nrCateg > 0) {
		{delete[] this->listaPreturi;
		this->listaPreturi = nullptr;
		this->nrCateg = 0;
		}
		this->listaPreturi = new float[nrCateg];
		for (int i = 0; i < nrCateg; i++) {
			this->listaPreturi[i] = listaPreturi[i];
		}
		this->nrCateg = nrCateg;
	}
}

void Bilet::setZona(string zona) {
	if (zona.length() > 0)
		this->zona = zona;
}

void Bilet::setPret(float pret) {
	if (pret > 0.0)
		this->pret = pret;
}

void Bilet::setMetoda(string metoda) {
	if (metoda == "eTicket" || metoda == "livrare domiciliu")
		this->metodaLivrare = metoda;
}

void Bilet::setCostLivrare(float cost) {
	if (cost >= 0.0)
		this->costLivrare = cost;
}
//operator=
Bilet& Bilet:: operator=(const Bilet& b) {
	
	if (this != &b) {
		
		if (scaune != nullptr) {
			delete[] scaune;
			scaune = nullptr;
		}
		if (b.scaune != nullptr && b.nrLocuri > 0) {

			scaune = new int[b.nrLocuri];
			for (int i = 0; i < b.nrLocuri; i++) {
				scaune[i] = b.scaune[i];
			}
			nrLocuri = b.nrLocuri;
	
		}
		else {
			scaune = nullptr;
			nrLocuri = 0;
		}

		if (this->listaPreturi != nullptr) {
			delete[] this->listaPreturi;
			this->listaPreturi=nullptr;
		}
		if (b.listaPreturi != nullptr && b.nrCateg > 0) {
			this->nrCateg = b.nrCateg;
			this->listaPreturi = new float[b.nrCateg];
			for (int i = 0; i < b.nrCateg; i++) {
				this->listaPreturi[i] = b.listaPreturi[i];
			}
		}
		else { 
			this->listaPreturi = nullptr;
			this->nrCateg = 0;
		}
		this->nrRanduri = b.nrRanduri;
		this->bileteVandute = b.bileteVandute;
		this->zona = b.zona;
		this->pret = b.pret;
		this->metodaLivrare = b.metodaLivrare;
		this->costLivrare = b.costLivrare;
		this->id = b.id;

	}
   return *this;
}

//numar bilete vandute
Bilet Bilet::operator+= (int numarBileteVandute) {
	this->bileteVandute += numarBileteVandute;
	return *this;
}

//operator- care aplica dicount la pretul biletului

Bilet& Bilet::operator-(int discount) {
	if (discount > 0 && discount <= 100) {
		Bilet copie = *this;
		copie.pret = copie.pret - (discount * copie.pret) / 100;
		return copie;
	}
}


//daca cumparatorul doreste la final sa faca o donatie
//preincrementare
Bilet& Bilet::operator++() {
	pret++;
	return *this;
}
//postincremetare
Bilet Bilet::operator++(int i) {
	Bilet copie = *this;
	pret++;
	return copie;
}

//operator>>
istream& operator>>(istream& in, Bilet& b) {
	cout << "Numar de randuri:";
	in >> b.nrRanduri;
	
	cout << "Numarul de locuri";
	in >> b.nrLocuri;

	cout << "Codificarea scaunelor:";
	for (int i = 0; i < b.nrLocuri; i++)
	{
		in >> b.scaune[i];
		
	}

	cout << "Numarul de bilete vandute: ";
	in >> b.bileteVandute;

	cout << "Lista de preturi pentru fiecare cateorie: ";
	for (int i = 0; i < b.nrCateg; i++)
		in >> b.listaPreturi[i];
	cout << "Alegeti metoda de livrare a biletului(e-Ticket sau livrare domiciliu): ";
	in >> b.metodaLivrare;
	cout << "Cost livrare bilet(gratuit pentru eTicket, alltfel se percepe o taxa de transport):";
	in >> b.costLivrare;

	return in;
}

//operator<<
ostream& operator<<(ostream& out, Bilet b) {
	out << "Numar de randuri: " << b.getNrRanduri() << endl; //la vect facem un for
	out << "Numar locuri:" << b.getNrLocuri() << endl;
	out << "Numere scaune: ";
	for (int i = 0; i < b.getNrLocuri(); i++)
		out << b.scaune[i] << " ";
	out << endl;
	out << "Biletele vandute sunt in numar de: " << b.getBileteVandute() << endl;
	out << "Numarul de categorii al biletelor este de: " << b.nrCateg << endl;
	out << "Lista cu preturi: ";
	for (int i = 0; i < b.nrCateg; i++)
		out << b.listaPreturi[i] << " ";
	out << endl;
	out << "Zona: " << b.zona << endl;
	out << "Pretul biletului: " << b.pret << endl;
	out << "Id-ul biletului: " << b.id;
	out << endl;
	out << "Metoda de livrare biletului: " << b.metodaLivrare << endl;
	out << "Costul livrarii biletului: " << b.costLivrare << endl;

	return out;
}

int Bilet::bileteRamase() {
	return this->nrLocuri - this->bileteVandute;
}

//daca au mai ramas bilete - returneaza true daca mai sunt bilete, altfel returneaza false
bool Bilet::capacitate() {
	if (this->nrLocuri - this->bileteVandute > 0)
		return true;
	else return false;
}

//pretul mediu al biletelor
float Bilet::pretMediu() {
	float s = 0.0;
	for (int i = 0; i < this->nrCateg; i++)
		s = s + this-> listaPreturi[i];
	return s / this->nrCateg;
}

//biletul care are pretul cel mai mare
float  Bilet::pretMax() {
	float max=-1000000;
	for (int i = 0; i < this->nrCateg; i++)
		if (max < this->listaPreturi[i])
			max = this->listaPreturi[i];
	return max;
}

//nr locurilor de pe un rand
int Bilet::locuriPeRand() {
	return this->nrLocuri / this->nrRanduri;
}

//pentru copiii sub 5 ani se plateste doar jumatate din costul total al biletului

void Bilet::discountCopil() {
	this->pret = this->pret / 2;
}

//pretul total al comenzii
float Bilet::totalComanda() {
	return this->pret + this->costLivrare;
}