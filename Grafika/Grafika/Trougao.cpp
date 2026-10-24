#include "Trougao.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

std::vector<Tacka> Trougao::vratiTacke() const
{
	std::vector<Tacka>tacke;

	int visina= (a  - 1) / 2;
	if(rotacija=="gore" || rotacija=="dole")
		visina=(a*2-1)/2;
	tacke.push_back(Tacka(x, y, "*"));

	if (rotacija == "gore")
	{
		for (int i = 1; i <= visina; i++)
		{
			tacke.push_back(Tacka(x - i, y + i, "/"));
			tacke.push_back(Tacka(x + i, y + i, "\\"));
			if (pun)
			{
				for (int j = 0; j < i; j++)
				{
					tacke.push_back(Tacka(x - j, y + i, "-"));
					tacke.push_back(Tacka(x + j, y + i, "-"));
				}
			}
		}

		for (int i = -1; i < a*2; i++)
		{
			tacke.push_back(Tacka(x - visina+i, y + visina+1, "-"));
		}
	}
	else if (rotacija == "dole")
	{
		for (int i = 1; i <= visina; i++)
		{
			tacke.push_back(Tacka(x - i, y - i, "\\"));
			tacke.push_back(Tacka(x + i, y - i, "/"));
			if (pun)
			{
				for (int j = 0; j < i; j++)
				{
					tacke.push_back(Tacka(x - j, y - i, "-"));
					tacke.push_back(Tacka(x + j, y - i, "-"));
				}
			}
		}

		for (int i = -1; i < a*2; i++)
		{
			tacke.push_back(Tacka(x - visina + i, y - visina - 1, "-"));
		}
	}
	else if (rotacija == "levo")
	{
		for (int i = 1; i <=visina; i++)
		{
			tacke.push_back(Tacka(x + i, y - i, "/"));
			tacke.push_back(Tacka(x + i, y + i, "\\"));
			if (pun)
			{
				for (int j = 0; j < i; j++)
				{
					tacke.push_back(Tacka(x + i, y - j, "|"));
					tacke.push_back(Tacka(x + i, y + j, "|"));
				}
			}

			for (int i = -1; i < a; i++)
			{
				tacke.push_back(Tacka(x + visina + 1, y - visina + i, "|"));
			}
		}
	}
	else
	{
		for (int i = 1; i <= visina; i++)
		{
			tacke.push_back(Tacka(x - i, y - i, "\\"));
			tacke.push_back(Tacka(x - i, y + i, "/"));
			if (pun)
			{
				for (int j = 0; j < i; j++)
				{
					tacke.push_back(Tacka(x - i, y - j, "|"));
					tacke.push_back(Tacka(x - i, y + j, "|"));
				}
			}

			for (int i = -1; i < a; i++)
			{
				tacke.push_back(Tacka(x - visina - 1, y - visina + i, "|"));
			}
		}
	}

	return tacke;
}

void Trougao::unosOblika()
{
	cout << "Krenite da unosite podatke, obavezni atributi imaju zvezdicu (*)" << endl;
	cout << "Ukoliko ne zelite da unosite vrednost za neki atribut, unesite /" << endl;

	int a;
	cout << "Unesite osnovicu trougla(mora biti paran broj)*" << endl;

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
		cout << "Osnovica trougla mora biti veca od 0" << endl;
		return;
	}
	if (a % 2 != 0)
	{
		cout << "Osnovica trougla mora biti paran broj" << endl;
		return;
	}

	string rotacija="gore";
	cout<<"Unesite rotaciju trougla (levo, desno, gore, dole)"<<endl;
	cin>>rotacija;

	if (rotacija != "levo" && rotacija != "desno" && rotacija != "gore" && rotacija != "dole" && rotacija!="/")
	{
		cout << "Rotacija nije validna" << endl;
		return;
	}

	bool pun = false;
	cout << "Da li zelite da trougao bude pun, da ili ne" << endl;
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
	cout << "Unesite nivo trougla" << endl;
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
	this->rotacija = rotacija;
	this->pun = pun;
	this->nivo = nivoInt;
	this->x = x;
	this->y = y;
}