#include "Locatie.h"
#include <string>
#include<iostream>
using namespace std;


string Locatie::tara = "Romania";

//constructor fara parametri
Locatie::Locatie():telefonContact(0) {
	adresa = " ";
	zi = " ";
	dataZi = 0;
	luna = 0;
	an = 0;
	ora = 0;
	min = 0;
	oras = " ";
}
//constructor cu parametri
Locatie::Locatie(string adresa, string zi, int dataZi, int luna, int an, int ora, int min,string oras) : telefonContact(0) {
	this->adresa = adresa;
	this->zi = zi;
	this->dataZi = dataZi;
	this->luna = luna;
	this->an = an;
	this->ora = ora;
	this->min = min;
	this->oras = oras;
}
//destructor - nu exista membru pointer

//operator= - nu exista membru pointer


//getteri
string Locatie::getAdresa() {
	return adresa;
}

string Locatie::getZi() {
	return zi;
}

int Locatie::getDataZi() {
	return dataZi;
}

int Locatie::getLuna() {
	return luna;
}

int Locatie::getAn() {
	return an;
}

int Locatie::getOra() {
	return ora;
}

int Locatie::getMin() {
	return min;
}

string Locatie::getOras() {
	return oras;
}

string Locatie::getTara() {
	return tara;
}

//setteri
void Locatie::setAdresa(string adresa) {
	if(adresa.length()>0)
	this->adresa = adresa;
}

void Locatie::setDataZi(int dataZi) {
	if(dataZi>0 && dataZi<32)
	this->dataZi = dataZi;
}

void Locatie::setZi(string zi) {
	if (zi.length() > 0)
		this->zi = zi;
}

void Locatie::setLuna(int luna) {
	if (luna > 0 && luna < 12)
		this->luna = luna;
}

void Locatie::setAn(int an) {
	if (an > 2021)
		this->an = an;
}

void Locatie::setOra(int ora) {
	if (ora >= 0 && ora <= 24)
		this->ora = ora;
}
void Locatie::setMin(int min) {
	if (min > 0 && min < 60)
		this->min = min;
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

	cout << "Adresa: ";
	in >> l.adresa;

	cout << "Zi: ";
	in >> l.zi;

	cout << "Luna: ";
	in >> l.luna;
	
	cout << "Data zilei: ";
	in >> l.dataZi;

	cout << "Luna :";
	in >> l.luna;

	cout << "Anul: ";
	in >> l.an;

	cout << "Ora: ";
	in >> l.ora;

	cout << "Minutul: ";
	in >> l.min;

	cout << "Orasul: ";
	in >> l.oras;


	return in;
}
//operator<<

ostream& operator<<(ostream& out, Locatie l) {
	out << "Adresa:" << l.adresa << endl;
	out << "Ziua saptamanii: " << l.zi << endl;
	out << "Data zilei evenimentului: " << l.dataZi << endl;
	out << "Luna :" << l.luna << endl;
	out << "Anul: " << l.an << endl;
	out << "Ora: " << l.ora << endl;
	out << "Minutul:" << l.min << endl;
	out << "Orasul: " << l.oras << endl;
	return out;
}

//operator +
//aduna zilele care au fost amanate
Locatie Locatie::operator+(int zileNoi) {
	Locatie copie = *this;
	copie.dataZi = copie.dataZi + zileNoi;
	return copie;
}

Locatie operator+(int zileNoi, Locatie l) {
	l.dataZi = zileNoi + l.dataZi;
	return l;
}
//operator!
bool Locatie::operator!() {
	if (dataZi > 31) return false;
	else return true;
}

//metode
//se decaleaza ora si se amana pt mai tarziu

void Locatie::intarziereOra(int oreIntarziate) {
	ora = ora + oreIntarziate;
}

void Locatie::intarziereMinute(int minIntarziate) {
	min = min + minIntarziate;
}

void Locatie::intarziereMinute(int oreIntarziate, int minIntarziate) {
	ora = ora + oreIntarziate;
	min = min + minIntarziate;
}
