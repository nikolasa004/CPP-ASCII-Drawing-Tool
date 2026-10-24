#pragma once
#include <vector>
#include "Tacka.h"

class Tekst
{
public:
	Tekst(int x, int y, int nivo,std::string tekst,std::string pravac) :x(x), y(y), nivo(nivo), tekst(tekst),pravac(pravac) {}
	Tekst() :x(0),y(0), nivo(0), tekst(""),pravac("lr") {}
	std::vector<Tacka> vratiTacke() const;
	void unosOblika();
	int getNivo() const { return nivo; }
private:
	int x;
	int y;
	int nivo;
	std::string tekst;
	std::string pravac;
};

