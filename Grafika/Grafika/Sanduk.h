#pragma once
#include <vector>
#include "Tacka.h"
#include "Oblik.h"

class Sanduk : public Oblik {
public:
    Sanduk(int nivo, int x, int y) : Oblik(0, false, nivo, x, y) {}
    Sanduk() : Oblik() {}
    std::vector<Tacka> vratiTacke() const override;
    void unosOblika() override;
};
