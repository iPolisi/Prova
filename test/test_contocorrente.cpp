#include "gtest/gtest.h"
#include "../ContoCorrente.h"
#include "../Entrata.h"
#include "../Uscita.h"
#include <fstream>

class ContoCorrenteTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Creiamo un file temporaneo per i test
        testFilePath = "test_transazioni.csv";
        std::ofstream file(testFilePath);
        if (file) {
            file << "IT123456789,Entrata,100,Stipendio\n";
            file << "IT123456789,Uscita,50,Spesa\n";
            file.close();
        }
    }

    void TearDown() override {
        // Puliamo il file dopo i test
        remove(testFilePath.c_str());
    }

    std::string testFilePath;
};

// **Test per la creazione del conto**
TEST_F(ContoCorrenteTest, CreazioneConto) {
    ContoCorrente conto("IT123456789", "Mario Rossi", testFilePath);
    EXPECT_EQ(conto.getIban(), "IT123456789");
    EXPECT_EQ(conto.getSaldo(), 0);
}

// **Test per aggiungere una transazione**
TEST_F(ContoCorrenteTest, AggiuntaTransazione) {
    ContoCorrente conto("IT123456789", "Mario Rossi", testFilePath);
    Transazione* entrata = new Entrata(200.0, "Bonus");
    conto.aggiungiTransazione(entrata);
    EXPECT_EQ(conto.getSaldo(), 200.0);
}

// **Test per salvare su file**
TEST_F(ContoCorrenteTest, SalvataggioSuFile) {
    ContoCorrente conto("IT123456789", "Mario Rossi", testFilePath);
    conto.aggiungiTransazione(new Entrata(150.0, "Bonus"));
    conto.aggiungiTransazione(new Uscita(50.0, "Spesa"));

    std::ofstream file(testFilePath);
    conto.salvaSuFile(file, "IT123456789");
    file.close();

    // Controlliamo se il file Ã¨ stato scritto correttamente
    std::ifstream inFile(testFilePath);
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    inFile.close();

    std::string output = buffer.str();
    EXPECT_NE(output.find("IT123456789,Entrata,150,Bonus"), std::string::npos);
    EXPECT_NE(output.find("IT123456789,Uscita,50,Spesa"), std::string::npos);
}

// **Test per caricare da file**
TEST_F(ContoCorrenteTest, CaricamentoDaFile) {
    ContoCorrente conto("IT123456789", "Mario Rossi", testFilePath);
    conto.caricaDaFile();

    EXPECT_EQ(conto.getSaldo(), 50.0);  // 100 - 50 = 50
}
