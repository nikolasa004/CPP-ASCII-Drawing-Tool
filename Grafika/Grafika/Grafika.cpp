#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include "Kvadrat.h"
#include "Pravougaonik.h"
#include "Linija.h"
#include "Tekst.h"
#include "Trougao.h"
#include "Krug.h"
#include "Srce.h"
#include "Krst.h"
#include "Sanduk.h"
using namespace std;

void ispis(vector<vector<string>> ekran)
{
    for (int i = 0; i < 41; ++i)
    {
        for (int j = 0; j < 80; ++j)
        {
            cout << ekran[i][j];
        }
        cout << endl;
    }
}

void ucrtavanjeTacaka(vector<Tacka> tacke, vector<vector<string>>& ekran,unordered_map<int,unordered_map<int,int>> &nivoi,int noviNivo,vector<vector<vector<string>>> &istorijaNazad,vector<vector<vector<string>>> &istorijaNapred)
{
    if (istorijaNazad.size() == 10)
    {
        istorijaNazad.erase(istorijaNazad.begin());
    }
    istorijaNazad.push_back(ekran);
    istorijaNapred.clear();

    for (Tacka tacka : tacke)
    {
        if (tacka.getX() >= 1 && tacka.getY() >= 1 && tacka.getX()<80 && tacka.getY()<=40)
        {
            if (ekran[tacka.getY()][tacka.getX()] == " ")
            {
                ekran[tacka.getY()][tacka.getX()] = tacka.getZnak();
                nivoi[tacka.getY()][tacka.getX()] = noviNivo;
            }
            else
            {
                bool napravljenPlus = false;
                if (ekran[tacka.getY()][tacka.getX()] == "-" && tacka.getZnak() == "|")
                {
                    ekran[tacka.getY()][tacka.getX()] = "+";
                    napravljenPlus = true;
                }
                else if (ekran[tacka.getY()][tacka.getX()] == "|" && tacka.getZnak() == "-")
                {
					ekran[tacka.getY()][tacka.getX()] = "+";
                    napravljenPlus = true;
				}
                else if (ekran[tacka.getY()][tacka.getX()] == "+" && tacka.getZnak() == "-")
                {
					ekran[tacka.getY()][tacka.getX()] = "+";
                    napravljenPlus = true;
				}
                else if (ekran[tacka.getY()][tacka.getX()] == "+" && tacka.getZnak() == "|")
                {
					ekran[tacka.getY()][tacka.getX()] = "+";
                    napravljenPlus = true;
				}
                else
                {
                    int stariNivo = nivoi[tacka.getY()][tacka.getX()];
                    if (stariNivo <= noviNivo)
                    {
                        ekran[tacka.getY()][tacka.getX()] = tacka.getZnak();
                        nivoi[tacka.getY()][tacka.getX()] = noviNivo;
                    }
				}

                if (napravljenPlus)
                {
                    int stariNivo = nivoi[tacka.getY()][tacka.getX()];
                    if (stariNivo < noviNivo)
                    {
                        nivoi[tacka.getY()][tacka.getX()] = noviNivo;
                    }
                }
            }
        }

    }
}

int main()
{
    vector<vector<string>> ekran;
    unordered_map<int,unordered_map<int,int>> nivoi;
    char abeceda[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<vector<vector<string>>> istorijaNazad;
    vector<vector<vector<string>>> istorijaNapred;

    int brojacRedova = 0;
    int brojacKolona = 0;
    int brojacDesetice = 0;
    for (int i = 0; i < 41; ++i)
    {
        vector<string> red;
        for (int j = 0; j < 80; ++j)
        {
            if (j == 0 && i == 0)
            {
                red.push_back(" *");
            }
            else if (j == 0)
            {
                if (brojacRedova < 10)
                    red.push_back(" " + to_string(brojacRedova++));
                else
                    red.push_back(to_string(brojacRedova++));
            }
            else if (j == 1 && i != 0)
                red.push_back("|");
            else if (j == 1 && i == 0)
                red.push_back(to_string(brojacKolona++));
            else if (i == 0)
            {
                if (brojacKolona <=9 && j % 2 != 0)
                {
                    red.push_back(to_string(brojacKolona++));
                }
                else if (brojacKolona == 10 && j%2==0)
                {
                    red.push_back(string(1,abeceda[brojacDesetice++]));
                    brojacKolona=0;
                }
                else
                {
                    red.push_back(" ");
                }
            }
            else if (i == 1)
                red.push_back("-");
            else
                red.push_back(" ");
        }
        ekran.push_back(red);
    }

    ispis(ekran);

    /*while (true)
        cin.get();*///za testiranje crtanja

    bool prviPut= true;
    while (true)
    {
        if (prviPut)
        {
            cout<<"Dobro dosli u program za crtanje oblika"<<endl;
            prviPut = false;
        }

        cout << "Izaberite radnju"<<endl;
        cout<<"Moguce radje su: unos, brisanje, nazad, napred, kraj"<<endl;
        string tipUnosa;
        cin >> tipUnosa;

        if (tipUnosa == "unos")
        {
            while (true)
            {
                cout << "Unesite sta zelite da nacrtate" << endl;
                cout << "Moguci su unosi: kvadrat, pravougaonik, linija, tekst, trougao, krug, srce, sztr_Savic, nazad" << endl;

                string izbor;
                cin >> izbor;

                if (izbor == "kvadrat")
                {
                    Kvadrat kvadrat;
                    kvadrat.unosOblika();
                    vector<Tacka> tacke = kvadrat.vratiTacke();

                    ucrtavanjeTacaka(tacke, ekran, nivoi, kvadrat.getNivo(),istorijaNazad,istorijaNapred);

                    ispis(ekran);
                }
                else if (izbor == "pravougaonik")
                {
                    Pravougaonik pravougaonik;
                    pravougaonik.unosOblika();
                    vector<Tacka> tacke = pravougaonik.vratiTacke();

                    ucrtavanjeTacaka(tacke, ekran, nivoi, pravougaonik.getNivo(),istorijaNazad,istorijaNapred);

                    ispis(ekran);
                }
                else if (izbor == "linija")
                {
                    Linija linija;
                    linija.unosOblika();
                    vector<Tacka> tacke = linija.vratiTacke();

                    ucrtavanjeTacaka(tacke, ekran, nivoi, linija.getNivo(),istorijaNazad,istorijaNapred);

                    ispis(ekran);
                }
                else if (izbor == "tekst")
                {
					Tekst tekst;
					tekst.unosOblika();
					vector<Tacka> tacke = tekst.vratiTacke();

					ucrtavanjeTacaka(tacke, ekran, nivoi, tekst.getNivo(),istorijaNazad,istorijaNapred);

					ispis(ekran);
				}
                else if (izbor == "trougao")
                {
                    Trougao trougao;
                    trougao.unosOblika();
                    vector<Tacka> tacke = trougao.vratiTacke();

                    ucrtavanjeTacaka(tacke, ekran, nivoi, trougao.getNivo(),istorijaNazad,istorijaNapred);

                    ispis(ekran);
                }
                else if (izbor == "krug")
                {
					Krug krug;
					krug.unosOblika();
					vector<Tacka> tacke = krug.vratiTacke();

					ucrtavanjeTacaka(tacke, ekran, nivoi, krug.getNivo(),istorijaNazad,istorijaNapred);

					ispis(ekran);

                }
                else if (izbor == "srce" || izbor=="beba" || izbor=="adriana")
                {
                    Srce srce;
                    srce.unosOblika();
                    vector<Tacka> tacke = srce.vratiTacke();

                    ucrtavanjeTacaka(tacke, ekran, nivoi, srce.getNivo(),istorijaNazad,istorijaNapred);

                    ispis(ekran);
                }
                else if (izbor == "sztr_Savic")
                {
					cout<<"Dobar izbor, sta vam treba"<<endl;
                    cout<<"Moguci unosi su krst ili sanduk"<<endl;

                    string izbor;
                    cin >> izbor;

                    if (izbor == "krst")
                    {
                        Krst krst;
                        krst.unosOblika();
                        vector<Tacka> tacke = krst.vratiTacke();

                        ucrtavanjeTacaka(tacke, ekran, nivoi, krst.getNivo(), istorijaNazad, istorijaNapred);

                        ispis(ekran);
                    }
                    else if (izbor == "sanduk")
                    {
                        Sanduk sanduk;
                        sanduk.unosOblika();
                        vector<Tacka> tacke = sanduk.vratiTacke();

                        ucrtavanjeTacaka(tacke, ekran, nivoi, sanduk.getNivo(), istorijaNazad, istorijaNapred);

                        ispis(ekran);
					}
                    else
                    {
						cout << "Nepostojeci unos" << endl;
					}
				}
                else if (izbor == "nazad")
                {
					break;
				}
                else
                {
                    cout << "Nepostojeci unos" << endl;
                }
            }
        }
        else if (tipUnosa == "brisanje")
        {
            while (true)
            {
                cout<<"Izaberite nacin brisanja"<<endl;
                cout<<"Moguci unosi su: pravougaonik, linija, nazad"<<endl;

                string izbor;
                cin >> izbor;

                if (izbor == "pravougaonik")
                {
                    Pravougaonik pravougaonik(true);
                    pravougaonik.unosOblika();
                    vector<Tacka> tacke = pravougaonik.vratiTacke();

                    ucrtavanjeTacaka(tacke, ekran, nivoi, pravougaonik.getNivo(), istorijaNazad, istorijaNapred);

                    ispis(ekran);
                }
                else if (izbor == "linija")
                {
                    Linija linija(true);
                    linija.unosOblika();
                    vector<Tacka> tacke = linija.vratiTacke();

                    ucrtavanjeTacaka(tacke, ekran, nivoi, linija.getNivo(), istorijaNazad, istorijaNapred);

                    ispis(ekran);
				}
                else if (izbor == "nazad")
                {
                    break;
                }
                else
                {
					cout << "Nepostojeci unos" << endl;
				}
            }
        }
        else if (tipUnosa == "nazad")
        {
            if (istorijaNazad.size() == 0)
            {
                cout<<"Nema prethodnih koraka"<<endl;
            }
            else 
            {
                if (istorijaNapred.size() == 10)
                {
					istorijaNapred.erase(istorijaNapred.begin());
				}
                istorijaNapred.push_back(ekran);
                ekran = istorijaNazad[istorijaNazad.size() - 1];
                istorijaNazad.pop_back();

                ispis(ekran);
            }
		}
        else if (tipUnosa == "napred")
        {
            if (istorijaNapred.size() == 0)
            {
				cout<<"Nema sledecih koraka"<<endl;
			}
            else
            {
                if (istorijaNazad.size() == 10)
                {
					istorijaNazad.erase(istorijaNazad.begin());
				}
				istorijaNazad.push_back(ekran);
				ekran = istorijaNapred[istorijaNapred.size() - 1];
                istorijaNapred.pop_back();

				ispis(ekran);
			}
		}
        else if (tipUnosa == "kraj")
        {
            cout<<"Kraj programa, dovidjenja"<<endl;
			break;
		}
        else
        {
			cout << "Nepostojeci unos" << endl;
		}
    }
}