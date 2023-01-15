#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"
#include "EvenInterior.h"
#include<vector>

string input;
int main() {

	while (true) {
		int s=1;
		cout << "                                  ---------- EventsOnline ----------";
		cout << "\nDaca doriti sa va conectati pentru a administra evenimentul dvs. alegeti 1. ";
		cout << "\nPentru a parasi site-ul, selectati 2.\n";
		cin >> input;
		if (input == "2")
		{
			cout << "Multumim pentru vizita!";
			break;
		}
		else if (input == "1") {
			system("cls");
			
			
			Eveniment e;
			cout << "Introduceti detaliile evenimentului dumneavoastra:" << endl;
	
             	cin >> e;
			


			cout << "In urmatorul pas, introduceti informatiile referitoare la locatia evenimentului:" << endl;
			Locatie l;
			cin >> l;
			int ok = 1;
			cout << "Ultimul pas, generarea biletului! Introduceti zona, randul, locul si pretul biletului pe care doriti sa il generati!" << endl;
			string getZona;
			cout << "Introduceti zona pentru care doriti sa generati biletul: "; cin >> getZona;
			string* copie2 = e.getTipuriZone();
			int index = -1;
			for (int i = 0; i < e.getNrZone(); i++) {
				if (getZona == copie2[i]) {
					index = i;
				}
			}
			while (index == -1) {
				cout << "Introduceti o zona valida: "; cin >> getZona;
				for (int i = 0; i < e.getNrZone(); i++) {
					if (getZona == copie2[i]) {
						index = i;
					}
				}
			}
			int* copie3 = e.getNrLocuriZona(index);
			bool locuriDisponibile = true;
			while (ok == 1 && locuriDisponibile == true && index != -1) {
				Bilet b;
				cin >> b;
				

				long id = (rand() % 10) * 100000 + (rand() % 10) * 10000 + (rand() % 10) * 1000 + (rand() % 10) * 100 + (rand() % 10) * 10 + (rand() % 10);
				if (id < 0)
					id = -id;
				vector<long> coduri;

				for (int i = 0; i < coduri.size(); i++) {
					if (id == coduri.at(i))
						while (id == coduri.at(i))
							id = (rand() % 10) * 100000 + (rand() % 10) * 10000 + (rand() % 10) * 1000 + (rand() % 10) * 100 + (rand() % 10) * 10 + (rand() % 10);
					if (id < 0)
						id = -id;
				}
				
				

				if (s == 1) {
					if (index != -1 && locuriDisponibile == true) {
						int setat = 0;
						for (int i = 0; i < e.getRanduriZona(index) && setat == 0; i++) {
							if (copie3[i] > 0) {
								b.setZona(getZona);
								b.setLoc(copie3[i]);
								b.setRand(i+1);
								copie3[i]--;
								setat = 1;
							}
						}
						if (copie3[e.getRanduriZona(index) - 1] == 0) {
							locuriDisponibile = false;
						}
					}
					else if (locuriDisponibile == false) {
						cout << "Nu mai sunt locuri disponibile la aceasta zona!";
					}
				}
				
				
				cout << "-----------------GenerareBilet------------------"<<endl;
				cout << "Id bilet: " << id << endl;
				if (s == 1)
					cout << e<<endl;
			
				cout << b << endl;
				cout << l<<endl;
			
				
				
				cout << "Doriti sa mai generati un bilet? Apasati 1." << endl;
				cout << "\nDaca nu, apasati 2."<<endl;
					cin >> input;
				
				    if (input == "2" || locuriDisponibile == false) {
						if (locuriDisponibile == false) {
							cout << "Nu mai sunt locuri disponibile la aceasta zona!" << endl;
						}
						ok = 0;
						cout << "Va asteptam data viitoare!" << endl;
						coduri.clear();
						
					}
			}
			delete[] copie2;
			delete[] copie3;
		}
		else {
			cout << "Valoarea nu este valida!";
		}
	}
}