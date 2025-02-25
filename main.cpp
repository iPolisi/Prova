//
// Created by Cristian on 25/02/2025.
//

#include "ContoCorrente.h"
#include "Entrata.h"
#include "Uscita.h"
#include <iostream>

using namespace std;

int main() {
    ContoCorrente conto1("IT60X0542811101000000123456", "Mario Rossi", "transazioni.csv");

    ContoCorrente conto2("IT80Y0326812311000000987654", "Luigi Bianchi", "transazioni.csv");


    ContoCorrente contoCaricato1("IT60X0542811101000000123456", "Mario Rossi", "transazioni.csv");
    contoCaricato1.caricaDaFile();
    contoCaricato1.stampaTransazioni();

    cout << " " << endl;
    cout << " " << endl;
    cout << " " << endl;

    ContoCorrente contoCaricato2("IT80Y0326812311000000987654", "Luigi Bianchi", "transazioni.csv");
    contoCaricato2.caricaDaFile();
    contoCaricato2.stampaTransazioni();
 return 0;
}