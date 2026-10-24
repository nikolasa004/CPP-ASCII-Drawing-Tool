#pragma once
#include <vector>
#include"Tacka.h"
#include "Oblik.h"

class Trougao:public Oblik
{
	public:
	Trougao(int a, bool pun, int nivo, int x, int y,std::string rotacija) :Oblik(a, pun, nivo, x, y),rotacija(rotacija) {}
	Trougao() :Oblik(),rotacija("gore") {}
	std::vector<Tacka> vratiTacke() const override;
	void unosOblika() override;
private:
	std::string rotacija;
};

