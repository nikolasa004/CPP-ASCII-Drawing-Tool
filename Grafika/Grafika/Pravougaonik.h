#pragma once
#include "Kvadrat.h"
#include <vector>
#include "Tacka.h"
class Pravougaonik:public Kvadrat
{
public:
	Pravougaonik(int a,int b,bool pun,int nivo,int x,int y):Kvadrat(a,pun,nivo,x,y),b(b),gumica(false){}
	Pravougaonik():Kvadrat(),b(0),gumica(false){}
	Pravougaonik(bool gumica):Kvadrat(),b(0),gumica(gumica){}
	std::vector<Tacka> vratiTacke() const override;
	void unosOblika() override;
private:
	int b;
	bool gumica;
};

