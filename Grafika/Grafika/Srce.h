#pragma once
#include <vector>
#include "Tacka.h"
#include "Oblik.h"

class Srce : public Oblik {
public:
    Srce(int nivo, int x, int y) : Oblik(0, false, nivo, x, y) {}
    Srce() : Oblik() {}
    std::vector<Tacka> vratiTacke() const override;
    void unosOblika() override;
};


