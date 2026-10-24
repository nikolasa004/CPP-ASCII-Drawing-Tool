#pragma once
#include<string>
class Tacka
{
public:
	Tacka(int x, int y, std::string znak) :x(x), y(y), znak(znak) {}
	int getX() { return x;}
	int getY() { return y; }
	std::string getZnak() { return znak; }
private:
	int x;
	int y;
	std::string znak;
};

