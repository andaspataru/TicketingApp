#include "Locatie.h"
#include <string>
#include<iostream>
using namespace std;


string Locatie::tara = "Romania";

//constructor fara parametri
Locatie::Locatie() {
	strada = " ";
	numar = 0;
	oras = " ";
}
//constructor cu parametri
Locatie::Locatie(string strada, int numar, string oras) {
	this->strada = strada;
	this->numar = numar;
	this->oras = oras;
}
//destructor - nu exista membru pointer

//operator= - nu exista membru pointer


//getteri
string Locatie::getStrada() {
	return strada;
}

int Locatie::getNumar() {
	return numar;
}


string Locatie::getOras() {
	return oras;
}

string Locatie::getTara() {
	return tara;
}

//setteri
void Locatie::setStrada(string strada) {
	if (strada.length() > 0)
		this->strada = strada;
}

void Locatie::setNumar(int numar) {
	if (numar > 0)
		this->numar = numar;
}


void Locatie::setOras(string oras) {
	if (oras.length() > 0)
		this->oras = oras;

}

void Locatie::setTara(string tara) {
	if (tara.length() > 0)
		Locatie::tara = tara;
}
//operator>>
istream& operator>>(istream& in, Locatie& l) {

	cout << "Strada: ";
	in >> l.strada;
	while(l.strada.length()<=0)
	{
		cout << "Introduceti o valoare valida";
		in >> l.strada;
	}

	cout << "Numar: ";
	in >> l.numar;
	while(l.numar<=0)
	{
		cout << "Introduceti o valoare valida";
		in >> l.numar;
	}

	cout << "Orasul: ";
	in >> l.oras;
	while (l.oras.length() <= 0) {
		cout << "Introduceti o valoare valida";
		in >> l.oras;
	}



	return in;
}
//operator<<

ostream& operator<<(ostream& out, Locatie l) {
	out << "Strada:" << l.strada << ", numarul " << l.numar << endl;
	out << "Oras: " << l.oras << ", " << l.tara << endl;

	return out;
}
