#include "Bilet.h"
#include<string>
#include<iostream>
using namespace std;

Bilet::Bilet() {
	zona = " ";
	rand = 0;
	loc = 0;
	pret = 0.0;
}

Bilet::Bilet(string zona, int rand, int loc, float pret) {
	this->zona = zona;
	this->rand = rand;
	this->loc = loc;
	this->pret = pret;
}

//getteri
string Bilet::getZona() {
	return zona;
}

int Bilet::getRand() {
	return rand;
}

int Bilet::getLoc() {
	return loc;
}

float Bilet::getPret() {
	return pret;
}

//setteri

void Bilet::setZona(string zona) {
	if (zona.length() > 0)
		this->zona = zona;
		
}

void Bilet::setLoc(int loc) {
	if (loc > 0) {
		this->loc = loc;
	}
}


void Bilet::setRand(int rand) {
	if (rand > 0) {
		this->rand = rand;
	}
}

void Bilet::setPret(float pret) {
	if (pret > 0) {
		this->pret = pret;
	}
}

ostream& operator<<(ostream& out, Bilet b) {
	out << "Zona: " << b.zona << endl;
	out << "Rand: " << b.rand << endl;
	out << "Loc: " << b.loc << endl;
	out << "Pret: " << b.pret << endl;
	return out;
}
istream& operator>>(istream& in, Bilet& b) {
	/*cout << "Rand: ";
	in >> b.rand;
	while(b.rand<=0)
	{
		cout << "Introduceti o valoare valida";
		in >> b.rand;
	}

	cout << "Loc: ";
	in >> b.loc;
	while(b.loc<=0)
	{
		cout << "Introduceti o valoare valida";
		in >> b.loc;
	}*/
	cout << "Pret: ";
	in >> b.pret;
	while(b.pret<0) {
		cout << "Introduceti o valoare valida";
		in >> b.pret;
	}

	return in;
}


static float sumaIncasata(Bilet* b, int nrBilete) {
	float suma = 0.0;
	if (b != nullptr && nrBilete > 0) {
		for (int i = 0; i < nrBilete; i++) {
			suma += b[i].getPret();
		}
	}
	return suma;
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
	copie.pret++;
	return copie;
}
