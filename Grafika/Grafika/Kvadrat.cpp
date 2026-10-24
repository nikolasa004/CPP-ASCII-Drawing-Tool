#include "Kvadrat.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<Tacka> Kvadrat::vratiTacke() const
{
	std::vector<Tacka>tacke;

	for (int i = 0; i <= a; ++i)
	{
		for (int j = 0; j <= a*2; ++j)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == a*2) || (i == a && j == 0) || (i == a && j == a*2))
			{
				tacke.push_back(Tacka(x + j, y + i, "+"));
			}
			else if (i == 0 || i==a)
			{
				tacke.push_back(Tacka(x + j, y + i, "-"));
			}
			else if (j == 0 || j == a*2)
			{
				tacke.push_back(Tacka(x + j, y + i, "|"));
			}
			else
			{
				if (pun)
				{
					tacke.push_back(Tacka(x + j, y + i, "/"));
				}
			}
		}
	}

	return tacke;
}

void Kvadrat::unosOblika()
{
	cout << "Krenite da unosite podatke, obavezni atributi imaju zvezdicu (*)" << endl;
	cout << "Ukoliko ne zelite da unosite vrednost za neki atribut, unesite /" << endl;

	int a;
	cout << "Unesite stranicu kvadrata*" << endl;

	try
	{
		cin >> a;
	}
	catch (...)
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	if (a < 1)
	{
		cout << "Stranica kvadrata mora biti veca od 0" << endl;
		return;
	}

	bool pun = false;
	cout << "Da li zelite da kvadrat bude pun, da ili ne" << endl;
	string punUnos;
	cin >> punUnos;

	if (punUnos == "da")
	{
		pun = true;
	}
	else if (punUnos != "ne" && punUnos != "/")
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	string nivo;
	int nivoInt = 0;
	cout << "Unesite nivo kvadrata" << endl;
	cin >> nivo;

	if (nivo != "/")
	{
		try
		{
			nivoInt = stoi(nivo);

			if (nivoInt < 0)
			{
				cout << "Nivo mora biti veci od 0" << endl;
				return;
			}
		}
		catch (...)
		{
			cout << "Unos nije validan" << endl;
			return;
		}
	}

	int x;
	cout << "Unesite x koordinatu*" << endl;
	try
	{
		cin >> x;
	}
	catch (...)
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	if (x < 0 || x > 39)
	{
		cout << "X koordinata mora biti izmedju 0 i 39" << endl;
		return;
	}

	int y;
	cout << "Unesite y koordinatu*" << endl;
	try
	{
		cin >> y;
	}
	catch (...)
	{
		cout << "Unos nije validan" << endl;
		return;
	}

	if (y < 0 || y > 39)
	{
		cout << "Y koordinata mora biti izmedju 0 i 39" << endl;
		return;
	}
	
	//namestanje pravog x zbog koordinatnog sistema
	x*=2;
	x += 1;

	//namestanje pravog y zbog koordinatnog sistema
	y+=1;

	this->a = a;
	this->pun = pun;
	this->nivo = nivoInt;
	this->x = x;
	this->y = y;
}