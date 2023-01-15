#pragma once
#include<string>
#include<iostream>
using namespace std;

class Bilet
{
private:
	string zona;
	float pret;
	int rand;
	int loc;


public:
	Bilet();
	Bilet(string, int, int, float);
	Bilet& operator++();
	Bilet operator++(int );

	string getZona();
	int getRand();
	int getLoc();
	float getPret();

	void setZona(string);
	void setLoc(int);
	void setRand(int);
	void setPret(float);

	static float sumaIncasata(Bilet* , int );

	friend ostream& operator<<(ostream& , Bilet );
	friend istream& operator>>(istream& , Bilet& );

};