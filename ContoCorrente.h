//
// Created by Cristian on 25/02/2025.
//

#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H

#include "Transazione.h"
#include <vector>
#include <string>

class ContoCorrente {
private:
    string iban;
    string intestatario;
    double saldo;
    vector<Transazione*> transazioni;
    string filePath;

public:
    ContoCorrente(string ib, string intest, string file);
    ~ContoCorrente();

    void aggiungiTransazione(Transazione* t);
    void salvaSuFile();
    void caricaDaFile();
    void stampaTransazioni() const;
    string getIban() const;

};

#endif // CONTOCORRENTE_H

