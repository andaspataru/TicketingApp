#include "Eveniment.h"

#include <string>
#include<iostream>
using namespace std;

//constructor fara parametri
Eveniment::Eveniment() {

	nrLocuri = nullptr;
	randuriZone = nullptr;
	nrZone = 0;
	tipuriZone = nullptr;
	tipEveniment = nullptr;
	denumireEveniment = " ";
	durata = 0;




}

//constructor cu parametri
Eveniment::Eveniment(int* randuriZone, int** nrLocuri, int nrZone, string* tipuriZone, char* tipEveniment, string denumireEveniment,int durata) :Eveniment() {
	this->denumireEveniment = denumireEveniment;
	this->durata = durata;
	if (nrLocuri != nullptr && randuriZone != nullptr) {
		int nrRanduriMax = 0;
		for (int i = 0; i < nrZone; i++) {
			if (nrRanduriMax < randuriZone[i]) {
				nrRanduriMax = randuriZone[i];
			}
		}
		this->nrLocuri = new int* [nrZone];
		for (int i = 0; i < nrZone; i++) {
			this->nrLocuri[i] = new int[nrRanduriMax];
		}
		for (int i = 0; i < nrZone; i++)
			for (int j = 0; j < nrRanduriMax; j++) {
				this->nrLocuri[i][j] = nrLocuri[i][j];

			}
	}
	else {
		this->nrLocuri = nullptr;
	}
	if (tipEveniment != nullptr) {
		this->tipEveniment = new char[strlen(tipEveniment) + 1];
		strcpy_s(this->tipEveniment, strlen(tipEveniment) + 1, tipEveniment);
	}
	else tipEveniment = nullptr;
	if (randuriZone != nullptr && nrZone > 0) {
		this->nrZone = nrZone;
		this->randuriZone = new int[nrZone];
		for (int i = 0; i < nrZone; i++) {
			this->randuriZone[i] = randuriZone[i];
		}
	}
	else {
		this->randuriZone = nullptr;
		this->nrZone = 0;
	}

	if (tipuriZone != nullptr && nrZone > 0) {
		this->nrZone = nrZone;
		this->tipuriZone = new string[nrZone];
		for (int i = 0; i < nrZone; i++) {
			this->tipuriZone[i] = tipuriZone[i];
		}
	}
	else {
		this->tipuriZone = nullptr;
		this->nrZone = 0;
	}



}

Eveniment::Eveniment(const Eveniment& b) {

	this->denumireEveniment = b.denumireEveniment;
	this->durata = b.durata;

	if (b.nrLocuri != nullptr && b.randuriZone != nullptr) {
		int nrRanduriMax = 0;
		for (int i = 0; i < b.nrZone; i++) {
			if (nrRanduriMax < b.randuriZone[i]) {
				nrRanduriMax = b.randuriZone[i];
			}
		}
		this->nrLocuri = new int* [b.nrZone];
		for (int i = 0; i < b.nrZone; i++) {
			this->nrLocuri[i] = new int[nrRanduriMax];
		}
		for (int i = 0; i < b.nrZone; i++)
			for (int j = 0; j < nrRanduriMax; j++) {
				this->nrLocuri[i][j] = b.nrLocuri[i][j];

			}
	}
	else {
		this->nrLocuri = nullptr;
	}
	if (b.randuriZone != nullptr && b.nrZone > 0) {
		this->nrZone = b.nrZone;
		this->randuriZone = new int[b.nrZone];
		for (int i = 0; i < b.nrZone; i++) {
			this->randuriZone[i] = b.randuriZone[i];
		}
	}
	else {
		this->randuriZone = nullptr;
		this->nrZone = 0;
	}

	if (b.tipuriZone != nullptr && b.nrZone > 0) {
		this->nrZone = b.nrZone;
		this->tipuriZone = new string[b.nrZone];
		for (int i = 0; i < b.nrZone; i++) {
			this->tipuriZone[i] = b.tipuriZone[i];
		}
	}
	else {
		this->tipuriZone = nullptr;
		this->nrZone = 0;
	}
	if (b.tipEveniment != nullptr) {
		tipEveniment = new char[strlen(b.tipEveniment) + 1];
		strcpy_s(tipEveniment, strlen(b.tipEveniment) + 1, b.tipEveniment);
	}
	else tipEveniment = nullptr;

}

//destructor
Eveniment::~Eveniment() {
	if (this->randuriZone != nullptr)
	{
		delete[] randuriZone;
		randuriZone = nullptr;
	}

	if (this->tipuriZone != nullptr)
	{
		delete[] tipuriZone;
		tipuriZone = nullptr;
	}

	if (nrLocuri != nullptr) {
		for (int i = 0; i < nrZone; ++i)
			delete[] nrLocuri[i];
		delete[] nrLocuri;
	}
	if (tipEveniment != nullptr)
	{
		delete[] tipEveniment;
		tipEveniment = nullptr;
	}
}


//getteri



int* Eveniment::getRanduriZone() {
	if (randuriZone != nullptr && nrZone != 0) {
		int* copy = new int[nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			copy[i] = randuriZone[i];
		}
		return copy;
	}
	else return nullptr;

}

int Eveniment::getLocRand(int zona, int rand) {
	return nrLocuri[zona][rand];
}

int** Eveniment::getNrLocuri() {
	int** copy;
	if (nrLocuri != nullptr && randuriZone != nullptr) {
		int nrRanduriMax = 0;
		for (int i = 0; i < nrZone; i++) {
			if (nrRanduriMax < randuriZone[i]) {
				nrRanduriMax = randuriZone[i];
			}
		}
		copy = new int* [nrZone];
		for (int i = 0; i < nrZone; i++) {
			copy[i] = new int[nrRanduriMax];
		}
		for (int i = 0; i < nrZone; i++)
			for (int j = 0; j < nrRanduriMax; j++) {
				copy[i][j] = nrLocuri[i][j];

			}
	}
	else {
		copy = nullptr;
	}
	return copy;
}

string* Eveniment::getTipuriZone() {
	if (tipuriZone != nullptr && nrZone != 0) {
		string* copy = new string[nrZone];
		for (int i = 0; i < nrZone; i++)
		{
			copy[i] = tipuriZone[i];
		}
		return copy;
	}
	else return nullptr;

}

int* Eveniment::getNrLocuriZona(int zona) {
	int* copy = new int[randuriZone[zona]];
	for (int i = 0; i < randuriZone[zona]; i++) {
		copy[i] = nrLocuri[zona][i];
	}
	return copy;
}

int Eveniment::getRanduriZona(int zona) {
	return randuriZone[zona];
}



int Eveniment::getNrZone() {
	return nrZone;
}

string Eveniment::getDenumireEveniment() {
	return denumireEveniment;
}

char* Eveniment::getTipEveniment() {
	if (tipEveniment != nullptr) {
		char* copie = new char[strlen(tipEveniment) + 1];
		strcpy_s(copie, strlen(tipEveniment) + 1, tipEveniment);
		return copie;
	}
	return nullptr;
}

int Eveniment::getDurata() {
	return durata;
}



//setteri


void Eveniment::setRanduriZone(int* randuriZone, int nrZone) {
	if (randuriZone != nullptr && nrZone > 0) {
		{delete[] this->randuriZone;
		this->randuriZone = nullptr;
		this->nrZone = 0;
		}

		this->randuriZone = new int[nrZone];
		for (int i = 0; i < nrZone; i++) {
			this->randuriZone[i] = randuriZone[i];
		}
		this->nrZone = nrZone;
	}
}

void Eveniment::setTipuriZone(string* tipuriZone, int nrZone) {
	if (tipuriZone != nullptr && nrZone > 0) {
		{delete[] this->tipuriZone;
		this->tipuriZone = nullptr;
		this->nrZone = 0;
		}

		this->tipuriZone = new string[nrZone];
		for (int i = 0; i < nrZone; i++) {
			this->tipuriZone[i] = tipuriZone[i];
		}
		this->nrZone = nrZone;
	}
}

void Eveniment::setDenumireEveniment(string denumire) {
	if (denumire.length() > 0)
		denumireEveniment = denumire;
}

void Eveniment::setNrZone(int numar) {
	if (numar > 0)
		nrZone = numar;
}

void Eveniment::setTipEveniment(const char* tipEveniment) {
	if (tipEveniment != nullptr) {
		if (this->tipEveniment != nullptr) {
			delete[] this->tipEveniment;
		}
		this->tipEveniment = new char[strlen(tipEveniment) + 1];
		strcpy_s(this->tipEveniment, strlen(tipEveniment) + 1, tipEveniment);
	}
}

void Eveniment::setDurata(int durataNoua) {
	if (durataNoua > 0)
		durata = durataNoua;
}




//operator=
Eveniment& Eveniment:: operator=(const Eveniment& b) {

	if (this != &b) {
		denumireEveniment = b.denumireEveniment;
		this->durata = b.durata;
		if (nrLocuri != nullptr) {
			for (int i = 0; i < nrZone; ++i)
				delete[] nrLocuri[i];
			delete[] nrLocuri;
		}
		if (b.nrLocuri != nullptr && b.randuriZone != nullptr) {
			int nrRanduriMax = 0;
			for (int i = 0; i < b.nrZone; i++) {
				if (nrRanduriMax < b.randuriZone[i]) {
					nrRanduriMax = b.randuriZone[i];
				}
			}
			this->nrLocuri = new int* [b.nrZone];
			for (int i = 0; i < nrZone; i++) {
				this->nrLocuri[i] = new int[nrRanduriMax];
			}
			for (int i = 0; i < b.nrZone; i++)
				for (int j = 0; j < nrRanduriMax; j++) {
					this->nrLocuri[i][j] = b.nrLocuri[i][j];

				}
		}
		else {
			this->nrLocuri = nullptr;
		}

		if (tipEveniment != nullptr)
		{
			delete[] tipEveniment;
			tipEveniment = nullptr;
		}
		if (b.tipEveniment != nullptr) {
			tipEveniment = new char[strlen(b.tipEveniment) + 1];
			strcpy_s(tipEveniment, strlen(b.tipEveniment) + 1, b.tipEveniment);
		}
		else tipEveniment = nullptr;

		if (randuriZone != nullptr) {
			delete[] randuriZone;
			randuriZone = nullptr;
		}
		if (b.randuriZone != nullptr && b.nrZone > 0) {

			randuriZone = new int[b.nrZone];
			for (int i = 0; i < b.nrZone; i++) {
				randuriZone[i] = b.randuriZone[i];
			}
			nrZone = b.nrZone;

		}
		else {
			randuriZone = nullptr;
			nrZone = 0;
		}

		if (tipuriZone != nullptr) {
			delete[] tipuriZone;
			tipuriZone = nullptr;
		}
		if (b.tipuriZone != nullptr && b.nrZone > 0) {

			tipuriZone = new string[b.nrZone];
			for (int i = 0; i < b.nrZone; i++) {
				tipuriZone[i] = b.tipuriZone[i];
			}
			nrZone = b.nrZone;

		}
		else {
			tipuriZone = nullptr;
			nrZone = 0;
		}



	}
	return *this;
}

//operator>>
istream& operator>>(istream& in, Eveniment& b) {
	string input;
	cout << "Tipul evenimentului(teatru, film, meci etc): ";
	char buffer[100];
	in >> buffer;
	delete[] b.tipEveniment;
	b.tipEveniment = new char[strlen(buffer) + 1];
	strcpy_s(b.tipEveniment, strlen(buffer) + 1, buffer);

	cout << "Denumirea evenimentului: "<<endl;
	in >> b.denumireEveniment;
	

	while (b.denumireEveniment.length() <= 0) {
		cout << "Introduceti o valoare valida!";
		in >> b.denumireEveniment;
	}

	cout << "Durata evenimentului(in minute) este:" << endl;
	in >> b.durata;

	while (b.durata <= 0)
	{
		cout << "Introduceti o valoare valida!";
		in >> b.durata;
	}
	if (b.durata >= 60)
		 b.transformareOre();

	cout << "In cazul in care durata evenimentului se poate modifica, alegeti 1. Altfel alegeti 2.";
	in >> input;
	if (input == "1") {
		cout << "Daca evenimentul se va prelungi, apasati 1." << endl;
		cout << "Daca durata evenimentului se va micsora, apasati 2." << endl;
		in >> input;
		if (input == "1") {
			cout << "Introduceti cu cate minute va dura mai mult: " << endl;
			int m;
			in >> m;
			b.durataNoua(m);
			if (b.durata >= 60)
				b.transformareOre();
			else cout << "Noua durata este: " << b.getDurata()<<endl;
			
		}
		else if (input == "2") {
			cout << "Introduceti cu cate minute va dura mai putin: "<<endl;
			int min;
			in >> min;
			b -= min;
			if (b.durata >= 60)
				b.transformareOre();
			else cout << "Noua durata este: " << b.getDurata()<<endl;

		}
		else {
			cout << "Valoarea introdusa nu este valida!";
		}
	}
	else if (input == "2") {
		cout << "Am inteles, nu vom modifica durata." << endl;
	}
	else {
		cout << "Valoarea introdusa nu este valida!";
	
	}

	cout << "Numarul de zone al evenimentului: ";
	in >> b.nrZone;
	while (b.nrZone <= 0)
	{
		cout << "Introduceti o valoare valida!" << endl;
		in >> b.nrZone;
	}

	delete[] b.tipuriZone;
	b.tipuriZone = new string[b.nrZone];
	cout << "Aveti " << b.nrZone << " zone disponibile in cadrul evenimentului." << endl;
	cout << "Care sunt acestea? " << endl;
	for (int i = 0; i < b.nrZone; i++)
	{
		cout << i + 1 << ".";
		in >> b.tipuriZone[i];
		while (b.tipuriZone[i].length() <= 0)
		{
			cout << "Introduceti o valoare valida!" << endl;
			in >> b.tipuriZone[i];
		}

	}



	if (b.randuriZone != nullptr) {
		delete[] b.randuriZone;
	}

	b.randuriZone = new int[b.nrZone];
	int nrRanduriMax = 0;
	cout << "Numarul de randuri pe care il ocupa fiecare zona: " << endl;
	for (int i = 0; i < b.nrZone; i++) {
		cout << "Nr. de randuri al zonei " << b.tipuriZone[i] << " este: ";
		in >> b.randuriZone[i];
		while (b.randuriZone[i] <= 0)
		{
			cout << "Introduceti o valoare valida!";
			in >> b.randuriZone[i];
		}
		
		if (b.randuriZone[i] > nrRanduriMax) {
			nrRanduriMax = b.randuriZone[i];
		}
	}

	if (b.nrLocuri != nullptr) {
		delete[] b.nrLocuri;
	}
	b.nrLocuri = new int* [b.nrZone];
	for (int i = 0; i < b.nrZone; i++) {
		b.nrLocuri[i] = new int[nrRanduriMax];
	}
	for (int i = 0; i < b.nrZone; i++)
		for (int j = 0; j < b.randuriZone[i]; j++) {
			cout << "Numarul locurilor pentru randul " << j + 1 << " al zonei " << b.tipuriZone[i] << " este: ";
			in >> b.nrLocuri[i][j];
			while (b.nrLocuri[i][j] <= 0) {
				cout << "Introduceti o valoare valida!";
				in >> b.nrLocuri[i][j];
			}
		}
	cout << endl;
	 b.nrLocuriZone();
	cout << endl;

	return in;
}

//operator<<
ostream& operator<<(ostream& out, Eveniment b) {


	out << "Tipul evenimentului: " << b.tipEveniment << endl;
	out << "Denumirea evenimentului: " << b.denumireEveniment << endl;
	out << "Durata" << b.durata << endl;
	
	/*for (int i = 0; i < b.nrZone; i++) {
		out << "Zona " << b.tipuriZone[i] << " are " << b.randuriZone[i] << " randuri." << endl;
		for (int j = 0; j < b.randuriZone[i]; j++) {
			out << "Randul " << j + 1 << " are " << b.nrLocuri[i][j] << " locuri." << endl;
		}
	}*/

	return out;
}


Eveniment Eveniment::operator-=(int minuteMinus) {
	this->durata -= minuteMinus;
	return *this;
}



//adauga cateva minute in plus daca exista o pauza/publicitate
void Eveniment::durataNoua(int minutePauza) {
	durata += minutePauza;
}

void Eveniment::transformareOre() {
	int ore = 0;
	int minute=0;
	if(durata >= 60)
		 ore = durata / 60;
	     minute = durata - ore * 60;
		 if(minute>=10)
	cout << "Evenimentul dureaza: " << ore << ":" << minute<<endl;
		 else cout << "Evenimentul dureaza: " << ore << ":0" << minute << endl;
}
void Eveniment::nrLocuriZone() {
	int* l = new int[nrZone];
	cout << "Numarul de locuri disponibile pentru fiecare zona:" << endl;
	for (int i = 0; i < nrZone; i++) {
		int t = 0;
		for (int j = 0; j < randuriZone[i]; j++)
			t = t + nrLocuri[i][j];
		l[i] = t;
		cout << i + 1 << "." << tipuriZone[i] << ":" << l[i] << endl;
	}
	

}

int Eveniment::nrMax() {
	int nrRanduriMax = 0;
	for (int i = 0; i < nrZone; i++) {
		if (nrRanduriMax < randuriZone[i]) {
			nrRanduriMax = randuriZone[i];
		}
	}
	return nrRanduriMax;
}