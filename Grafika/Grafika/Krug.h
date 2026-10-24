#pragma once
#include <vector>
#include "Tacka.h"
#include "Oblik.h"
class Krug:public Oblik
{
public:
	Krug(int a, bool pun, int nivo, int x, int y) :Oblik(a, pun, nivo, x, y) {}
	Krug() :Oblik() {}
	std::vector<Tacka> vratiTacke() const override;
	void unosOblika() override;
};

