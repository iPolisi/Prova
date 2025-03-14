//
// Created by Cristian on 25/02/2025.
//

#ifndef TRANSAZIONE_H
#define TRANSAZIONE_H

#include <string>
#include <fstream>

using namespace std;

class Transazione {
protected:
    double importo;
    string descrizione;
    //protected dato che sono attributi che verranno ereditati da Uscita ed Entrata

public:
    Transazione(double imp, string desc);
    virtual ~Transazione() = default;
    virtual string tipo() const;

    void salvaSuFile(ostream &file, const string &iban) const;

    double getImporto() const;
    string getDescrizione() const;
};

#endif // TRANSAZIONE_H

