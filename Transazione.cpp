//
// Created by Cristian on 25/02/2025.
//
#include "Transazione.h"

Transazione::Transazione(double imp, string desc) : importo(imp), descrizione(desc) {}

Transazione::~Transazione() {}

void Transazione::salvaSuFile(ofstream &file, const string &iban) const {
    file << iban << "," << tipo() << "," << importo << "," << descrizione << "\n";
}
//non puramente virtuale dato che non necessito (almeno per il momento se non apporto modifiche) di un'implementazione nelle derivate

double Transazione::getImporto() const {
    return importo;
}

string Transazione::getDescrizione() const {
    return descrizione;
}
