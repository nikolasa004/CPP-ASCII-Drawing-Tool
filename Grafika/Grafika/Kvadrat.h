#pragma once
#include <vector>
#include<utility>
#include "Tacka.h"
#include "Oblik.h"
class Kvadrat:public Oblik
{
public:
	Kvadrat(int a,bool pun,int nivo,int x,int y):Oblik(a,pun,nivo,x,y){}
	Kvadrat():Oblik() {}
	std::vector<Tacka> vratiTacke() const override;
	void unosOblika() override;
};

