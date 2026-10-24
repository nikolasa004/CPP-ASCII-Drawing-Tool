#include "Krug.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<Tacka> Krug::vratiTacke() const
{
	std::vector<Tacka>tacke;

	int b = a / 3;
	int a = b * 4;

	for (int i = 0; i < a+2; i++)
	{
		if (i == 0 || i == a + 1)
		{
			tacke.push_back(Tacka(x+i, y, " "));
			tacke.push_back(Tacka(x+i, y + 3*b+1, " "));
		}
		else
		{
			tacke.push_back(Tacka(x+i, y, "-"));
			tacke.push_back(Tacka(x+i, y + 3*b+1, "-"));
		}
	}

	for (int i = 0; i < b; i++)
	{
		tacke.push_back(Tacka(x - 1 - i, y + 1 + i, "/"));
		tacke.push_back(Tacka(x + a + 2 + i, y + 1 + i, "\\"));
		if (pun)
		{
			for (int j = 0; j <= a + 2*i+1; j++)
			{
				tacke.push_back(Tacka(x-i + j, y + 1 + i, "-"));
			}
		}

		tacke.push_back(Tacka(x - 1 - b, y + 1 + b + i, "|"));
		tacke.push_back(Tacka(x + a + 2 + b, y + 1 + b + i, "|"));
		if (pun)
		{
			for (int j = 0; j <= a + 2 * b + 1; j++)
			{
				tacke.push_back(Tacka(x - b + j, y + 1 + b + i, "-"));
			}
		}


		tacke.push_back(Tacka(x-b+i,y+1+2*b+i,"\\"));
		tacke.push_back(Tacka(x+a+1+b-i,y+1+2*b+i,"/"));
		if (pun)
		{
			for (int j =0;j<a+2*b-2*i ; j++)
			{
				tacke.push_back(Tacka(x+i+j-b+1, y + 1 + i+2*b, "-"));
			}
		
		}
	}

	return tacke;
}

void Krug::unosOblika()
{
	cout << "Krenite da unosite podatke, obavezni atributi imaju zvezdicu (*)" << endl;
	cout << "Ukoliko ne zelite da unosite vrednost za neki atribut, unesite /" << endl;

	int a;
	cout << "Unesite precnik kruga(mora da bude deljiv sa 3)*" << endl;

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
		cout << "Precnik mora biti veca od 0" << endl;
		return;
	}
	if (a % 3 != 0)
	{
		cout << "Precnik mora biti deljiv sa 3" << endl;
		return;
	}

	bool pun = false;
	cout << "Da li zelite da krug bude pun, da ili ne" << endl;
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
	cout << "Unesite nivo kruga" << endl;
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
	x *= 2;
	x += 1;

	//namestanje pravog y zbog koordinatnog sistema
	y += 1;

	this->a = a;
	this->pun = pun;
	this->nivo = nivoInt;
	this->x = x;
	this->y = y;
}