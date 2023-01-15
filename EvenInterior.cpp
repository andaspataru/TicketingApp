#include "EvenInterior.h"
#include <string>
#include<iostream>
using namespace std;

EvenInterior::EvenInterior() {
	sala = " ";
	etaj = 0;
}

EvenInterior::EvenInterior(int* randuriZone, int** nrLocuri, int nrZone, string* tipuriZone, char* tipEveniment, string denumireEveniment,int durata, string sala, int etaj) : Eveniment(randuriZone, nrLocuri, nrZone, tipuriZone, tipEveniment, denumireEveniment, durata) {
	this->sala = sala;
	this->etaj = etaj;
}

int EvenInterior::getEtaj() {
	return etaj;
}
string EvenInterior::getSala() {
	return sala;

}
void EvenInterior::setEtaj(int etaj) {
	this->etaj = etaj;
}

void EvenInterior::setSala(string sala) {
	if (sala.length() > 0)
		this->sala = sala;
}


EvenInterior& EvenInterior::operator=(const EvenInterior& ev) {
	if (this != &ev) {
		Eveniment::operator=(ev);
		this->etaj = ev.etaj;
		this->sala = ev.sala;
	}
	return *this;
}

EvenInterior::EvenInterior(const EvenInterior& ev) : Eveniment(ev) {
	this->etaj = ev.etaj;
	this->sala = ev.sala;
}

ostream& operator<<(ostream& out, EvenInterior e)
{
	out << (Eveniment)e << endl;


	out << "Sala " << e.sala << ", etaj " << e.etaj << endl;

	return out;
}

istream& operator>>(istream& in, EvenInterior& e)
{
	

	cout << "Sala: ";
	in >> e.sala;
	while (e.sala.length() <= 0) {
		cout << "Introduceti o valoare valida!";
		in >> e.sala;
	}

	cout << "Etaj: ";
	in >> e.etaj;
	while (e.etaj < 0) {
		cout << "Introduceti o valoare valida!";
		in >> e.etaj;
	}
	in >> (Eveniment&)e;

	return in;
}