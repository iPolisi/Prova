#include <gtest/gtest.h>
#include "../Transazione.h"
#include "../Entrata.h"
#include "../Uscita.h"
#include <sstream>



// Test del costruttore e dei metodi getter di Transazione
TEST(TransazioneTest, CostruttoreGetters) {
    Transazione t(1000.0, "Stipendio");

    // Verifica che l'importo e la descrizione siano corretti
    EXPECT_EQ(t.getImporto(), 1000.0);
    EXPECT_EQ(t.getDescrizione(), "Stipendio");
}

// Test della funzione salvaSuFile per la classe Transazione
TEST(TransazioneTest, SalvaSuFile) {
    std::stringstream ss;
    Transazione t(200.0, "Acquisto");

    // Salva la transazione su un "file" in memoria
    t.salvaSuFile(ss, "IT123456789");

    // Verifica che il formato sia corretto
    std::string content = ss.str();
    EXPECT_NE(content.find("IT123456789,Generica,200,Acquisto"), std::string::npos);
}

// Test di Entrata (derivata da Transazione)
TEST(EntrataTest, Costruttore) {
    Entrata entrata(500.0, "Stipendio");

    // Verifica che i metodi siano corretti
    EXPECT_EQ(entrata.getImporto(), 500.0);
    EXPECT_EQ(entrata.getDescrizione(), "Stipendio");
    EXPECT_EQ(entrata.tipo(), "Entrata");  // Assumendo che tipo() ritorni "Entrata"
}

// Test di Uscita (derivata da Transazione)
TEST(UscitaTest, Costruttore) {
    Uscita uscita(150.0, "Benzina");

    // Verifica che i metodi siano corretti
    EXPECT_EQ(uscita.getImporto(), 150.0);
    EXPECT_EQ(uscita.getDescrizione(), "Benzina");
    EXPECT_EQ(uscita.tipo(), "Uscita");  // Assumendo che tipo() ritorni "Uscita"
}
