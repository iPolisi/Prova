//
// Created by Cristian on 25/02/2025.
//
#include "Transazione.h"

Transazione::Transazione(double imp, string desc) : importo(imp), descrizione(desc) {}

void Transazione::salvaSuFile(ostream &file, const string &iban) const {
    file << iban << "," << tipo() << "," << importo << "," << descrizione << "\n";
}
//non puramente virtuale dato che non necessito (almeno per il momento se non apporto modifiche) di un'implementazione nelle derivate

double Transazione::getImporto() const {
    return importo;
}

string Transazione::tipo() const {
    return "Generica"; // Può essere una stringa di default, oppure un comportamento generale
}

string Transazione::getDescrizione() const {
    return descrizione;
}
