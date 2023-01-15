#pragma once
#include <string>
#include<iostream>
using namespace std;
class Locatie
{
private:
	string strada;
	int numar;
	string oras;
	static string tara;


public:
	Locatie();
	Locatie(string, int, string);


	string getStrada();
	int getNumar();
	string getOras();
	static string getTara();

	void setStrada(string);
	void setNumar(int);
	void setOras(string);
	static void setTara(string);


	friend ostream& operator<<(ostream& out, Locatie l);
	friend istream& operator>>(istream& in, Locatie& l);
};

