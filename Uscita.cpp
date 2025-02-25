//
// Created by Cristian on 25/02/2025.
//
#include "Uscita.h"

Uscita::Uscita(double imp, string desc) : Transazione(imp, desc) {}

string Uscita::tipo() const {
    return "Uscita";
}
