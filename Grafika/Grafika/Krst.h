#pragma once
#include <vector>
#include "Tacka.h"
#include "Oblik.h"

class Krst : public Oblik {
public:
    Krst(int nivo, int x, int y) : Oblik(0, false, nivo, x, y) {}
    Krst() : Oblik() {}
    std::vector<Tacka> vratiTacke() const override;
    void unosOblika() override;
};
