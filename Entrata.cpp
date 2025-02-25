//
// Created by Cristian on 25/02/2025.
//
#include "Entrata.h"

Entrata::Entrata(double imp, string desc) : Transazione(imp, desc) {}

string Entrata::tipo() const {
    return "Entrata";
}