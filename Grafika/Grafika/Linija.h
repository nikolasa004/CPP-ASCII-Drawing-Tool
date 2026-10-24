#pragma once
#include <vector>
#include "Tacka.h"
class Linija
{
public:
	Linija(int x1, int y1, int x2, int y2,int nivo) :x1(x1),x2(x2),y1(y1),y2(y2),nivo(nivo), gumica(false) {}
	Linija() :x1(0), x2(0), y1(0), y2(0),nivo(0), gumica(false) {}
	Linija(bool gumica) :x1(0), x2(0), y1(0), y2(0),nivo(0), gumica(gumica) {}
	std::vector<Tacka> vratiTacke() const;
	void unosOblika();
	int getNivo() const {return nivo; }
private:
	int x1;
	int y1;
	int x2;
	int y2;
	int nivo;
	bool gumica;
};

