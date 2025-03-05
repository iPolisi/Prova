//
// Created by Cristian Polisi on 28/02/2025.
//
#include "gtest/gtest.h"
#include "../Entrata.h"
#include <sstream>

TEST(EntrataTest, CreazioneEntrata) {
    Entrata e(100.0, "Stipendio");

    EXPECT_EQ(e.getImporto(), 100.0);
    EXPECT_EQ(e.getDescrizione(), "Stipendio");
    EXPECT_EQ(e.tipo(), "Entrata");
}

TEST(EntrataTest, SalvaSuFile) {
    Entrata e(50.0, "Bonus");

    std::stringstream ss;
    e.salvaSuFile(ss, "IT123456789");

    std::string output = ss.str();
    EXPECT_NE(output.find("IT123456789"), std::string::npos);
    EXPECT_NE(output.find("Entrata"), std::string::npos);
    EXPECT_NE(output.find("50"), std::string::npos);
    EXPECT_NE(output.find("Bonus"), std::string::npos);
}