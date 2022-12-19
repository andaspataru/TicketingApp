#include "Eveniment.h"
#include <string>
#include<iostream>
using namespace std;
char invalidChar2 = -1;
//constructor fara parametri
Eveniment::Eveniment() {
	categorie = " ";
	tipEveniment = nullptr;
	denumireEveniment = nullptr;
	sala = " ";
	durata = 0;

}


//constructor cu parametri
Eveniment::Eveniment(string categ, const char* tip, const char* denumire, string sala, int durata) {
	categorie = categ;
	if (tip != nullptr) {
		tipEveniment = new char[strlen(tip) + 1];
		strcpy_s(tipEveniment, strlen(tip) + 1, tip);
	}else tipEveniment = nullptr;
	if (denumire != nullptr) {
		denumireEveniment = new char[strlen(denumire) + 1];
		strcpy_s(denumireEveniment, strlen(denumire) + 1, denumire);
	}else denumireEveniment = nullptr;
	this->sala = sala;
	this->durata = durata;
}

//destructor 
Eveniment::~Eveniment() {
	if (tipEveniment != nullptr)
	{
		delete[] tipEveniment;
		tipEveniment = nullptr;
	}
	if (denumireEveniment != nullptr)
	{
		delete[] denumireEveniment;
		denumireEveniment = nullptr;
	}
}

Eveniment::Eveniment(const Eveniment& e) {
	this->categorie = e.categorie;
	if (e.tipEveniment != nullptr) {
		tipEveniment = new char[strlen(e.tipEveniment) + 1];
		strcpy_s(tipEveniment, strlen(e.tipEveniment) + 1, e.tipEveniment);
	}
	else tipEveniment = nullptr;
	if (e.denumireEveniment != nullptr) {
		denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
		strcpy_s(denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
	}
	else denumireEveniment = nullptr;
	this->sala = e.sala;
	this->durata = e.durata;
}

//operator de atribuire
Eveniment& Eveniment::operator=(const Eveniment& e) {
	if (this != &e) {
		if (tipEveniment != nullptr)
		{
			delete[] tipEveniment;
			tipEveniment=nullptr;
		}
		if (e.tipEveniment != nullptr) {
			tipEveniment = new char[strlen(e.tipEveniment) + 1];
			strcpy_s(tipEveniment, strlen(e.tipEveniment) + 1, e.tipEveniment);
		}
		else tipEveniment = nullptr;
		
		if (denumireEveniment != nullptr) {
			delete[] denumireEveniment;
			denumireEveniment=nullptr;
		}
		if (e.denumireEveniment != nullptr)
		{
			denumireEveniment = new char[strlen(e.denumireEveniment) + 1];
			strcpy_s(denumireEveniment, strlen(e.denumireEveniment) + 1, e.denumireEveniment);
		}
		else denumireEveniment = nullptr;

		this->categorie = e.categorie;
		this->sala = e.sala;
		this->durata = e.durata;

		
	}
	return *this;
}

//getteri
string Eveniment::getCategorie() {
	return categorie;
}

char* Eveniment::getTipEveniment() {
	if (tipEveniment != nullptr) {
		char* copie = new char[strlen(tipEveniment) + 1];
		strcpy_s(copie, strlen(tipEveniment) + 1, tipEveniment);
		return copie;
	}
	return nullptr;
}

char* Eveniment::getDenumireEveniment() {
	if (denumireEveniment != nullptr) {
		char* copie = new char[strlen(denumireEveniment) + 1];
		strcpy_s(copie, strlen(denumireEveniment) + 1, denumireEveniment);
		return copie;
	}
	return nullptr;
}

string Eveniment::getSala() {
	return sala;

}

int Eveniment::getDurata() {
	if(durata>0 && durata!=0)
	return durata;
}

//setteri
void Eveniment::setCategorie(string categorie) {
   if(categorie.length()>0)
	this->categorie = categorie;
}

void Eveniment::setTipEveniment(const char* tipEveniment) {
	if (tipEveniment != nullptr) {
		if (this->tipEveniment!= nullptr) {
			delete[] this->tipEveniment;
		}
		this->tipEveniment = new char[strlen(tipEveniment) + 1];
		strcpy_s(this->tipEveniment, strlen(tipEveniment) + 1, tipEveniment);
	}
}

void Eveniment::setDenumireEveniment(const char* denumireEveniment) {
	if (denumireEveniment != nullptr) {
		if (this->denumireEveniment != nullptr) {
			delete[] this->denumireEveniment;
		}
		this->denumireEveniment = new char[strlen(denumireEveniment) + 1];
		strcpy_s(this->denumireEveniment, strlen(denumireEveniment) + 1, denumireEveniment);
	}
}

void Eveniment::setSala(string sala) {
	if (sala.length() > 0)
	this->sala = sala;
}

void Eveniment::setDurata(int durata) {
	if(durata>0 && durata!=0)
	this->durata = durata;
}

//operator>>
istream& operator>>(istream& in, Eveniment& e) {
	cout << "Numiti categoria: ";
	in >> e.categorie;

	cout << " Tipul evenimentului(teatru, film, meci de handbal etc): ";
	char buffer[100];
	in >> buffer;
	e.setTipEveniment(buffer);

	cout << "Denumirea evenimentului: ";
	string valoare;
	in >> valoare;
	delete[] e.denumireEveniment;
	e.denumireEveniment = new char[valoare.length() + 1];
	strcpy_s(e.denumireEveniment, valoare.length() + 1,valoare.c_str());

	cout << " Denumire sala(in cazul in care evenimentul se desfasoara in interior): ";
	in >> e.sala;

	cout << " Durata(minute): ";
	in >> e.durata;



	return in;
}

//opeartor<<
ostream& operator<<(ostream& out, Eveniment e) {
	out << "Categorie:" << e.categorie << endl;
	out << "Tipul evenimentului" << e.tipEveniment << endl;
	out << "Denumirea evenimentului:" << e.denumireEveniment << endl;
	out << "Sala(in cazul in care evenimentul se desfasoara in interior):" << e.sala << endl;
	out << "Durata(minute): " << e.durata << endl;
	
	return out;
}
//indica false daca evenimentul este exterior, si true daca e in interior
bool Eveniment::operator!() {
	if (sala.length()==0)
		return false;
	else return true;
}


//op[]
char& Eveniment::operator[](int index) {
	if (index >= 0 && denumireEveniment != nullptr && index < strlen(denumireEveniment)) {
		return denumireEveniment[index];

	}
	else return invalidChar2;

}

Eveniment Eveniment::operator-=(int minuteMinus) {
	this->durata -= minuteMinus;
	return *this;
}

//metode

//adauga cateva minute in plus daca exista o pauza/publicitate
void Eveniment::durataNoua(int minutePauza) {
	durata += minutePauza;
}

//durata medie a mai multor evenimente
static int durataMedie(Eveniment* l, int nr) {
	int suma = 0;
	for (int i = 0; i < nr; i++)
		suma += l[i].getDurata();

}

//numarati cate even de tip "Concert" sunt printre toate evenimentele
static int nrConcerte(Eveniment* eveniment, int nr, char* tipEveniment) {
	int k = 0;
	for (int i = 0; i < nr; i++)
		if (strcmp(eveniment[i].getTipEveniment(), "Concert") == 1)
			k++;

	return k;
}
