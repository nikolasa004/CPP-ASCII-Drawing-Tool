#pragma once
#include <vector>
#include "Tacka.h"
class Oblik
{
protected:
	int x;
	int y;
	int a;
	bool pun;
	int nivo;
public:
	Oblik(int a,bool pun,int nivo,int x,int y):a(a),pun(pun),nivo(nivo),x(x),y(y){}
	Oblik():a(0),pun(false),nivo(0),x(0),y(0){}
	virtual void unosOblika() = 0;
	virtual std::vector<Tacka> vratiTacke() const = 0;
	int getNivo() const { return nivo; }
};

