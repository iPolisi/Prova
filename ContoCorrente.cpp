//
// Created by Cristian on 25/02/2025.
//
#include "ContoCorrente.h"
#include "Entrata.h"
#include "Uscita.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

ContoCorrente::ContoCorrente(string ib, string intest, string file)
        : iban(ib), intestatario(intest), saldo(0), filePath(file) {}

ContoCorrente::~ContoCorrente() {
    for (auto t : transazioni) {
        delete t;
    }
}

void ContoCorrente::aggiungiTransazione(Transazione* t) {
    transazioni.push_back(t);
    saldo += (t->tipo() == "Entrata" ? t->getImporto() : -t->getImporto());
}
//aggiornamento in positivo o in negativo del saldo in base al tipo di importo (entrata o uscita) con un if in linea

void ContoCorrente::salvaSuFile() {
    ofstream file(filePath, ios::app); //ofstream è un tipo di oggetto per scrivere dati su un file. "filepath" indica la directory.
    // La modalità ios::app indica "append", quindi aggiunge una stringa al posto di sovrascrivere il contenuto
    if (!file) {
        cerr << "Errore nell'apertura del file!" << endl;
        return;
    }
    for (const auto &t : transazioni) {
        t->salvaSuFile(file, iban);
    }
    //si scorrono le transazioni e per ogni transazione t si aggiunge il file di destinazione e l'iban associato al movimento
}

void ContoCorrente::caricaDaFile() {
    for (auto t : transazioni) {
        delete t;
    }
    transazioni.clear();
    saldo = 0;
    //con questo for viene azzerata la memoria per poter ricalcolare il saldo grazie alle transazioni

    ifstream file(filePath); //ifstream è un tipo di oggetto per aprire in lettura un file. "filepath" indica la directory del file da aprire
    if (!file) {
        cerr << "Errore nell'apertura del file!" << endl; //controlla l'esistenza del file, se non c'è o è corrotto viene detto che non è possibile aprirlo
        return;
    }
    string linea;
    while (getline(file, linea)) { //prende in input il file "transazioni.csv" nel caso corrente e la riga letta viene salvata su linea
        istringstream ss(linea); //istringstream permette di trattare l'imnput come se fosse un cin, quindi input da tastiera almeno è più semplice da gestire
        string fileIban, tipo, importoStr, descrizione;
        if (getline(ss, fileIban, ',') && getline(ss, tipo, ',') &&
            getline(ss, importoStr, ',') && getline(ss, descrizione)) {
            if (fileIban == iban) {
                //si controlla se l'iban preso dalla stringa corrisponde ad un iban esistente, sennò viene saltata (possibile miglioria creando un conto vero e proprio leggendo dal file)
                double importo = stod(importoStr); //si converte la stringa dell'importo in un tipo double (string to double)
                if (tipo == "Entrata") {
                    transazioni.push_back(new Entrata(importo, descrizione));
                    saldo += importo;
                } else if (tipo == "Uscita") {
                    transazioni.push_back(new Uscita(importo, descrizione));
                    saldo -= importo;
                }
            }
        }
    }
}

void ContoCorrente::stampaTransazioni() const {
    cout << "Conto di " << intestatario << " (IBAN: " << iban << ")" << endl;
    for (const auto &t : transazioni) {
        cout << t->tipo() << ": " << t->getImporto() << " - " << t->getDescrizione() << endl;
    }
    cout << "Saldo attuale: " << saldo << endl;
}

string ContoCorrente::getIban() const {return iban;};