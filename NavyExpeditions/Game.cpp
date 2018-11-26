#include "stdafx.h"
#include "Game.h"
#include "Navio.h"
#include "Veleiro.h"
#include "Escuna.h"
#include "Fragata.h"
#include "Galeao.h"
#include "Porto.h"
#include "Jogador.h"
#include <vector>
#include <ctime>

Game::Game(Configuration config) {
	this->config = config;
}

void Game::run() {
	string comando;
	bool val = false;

	do {
		system("cls");
		displayMap();
		displayMenuTwo();	
		resolveCommand(comando);
		moveNavios();
		setShipsMap();

		cout << endl;
		system("pause");
	} while (val != true);
}

void Game::displayMap() {
	for (auto i = config.map.begin(); i != config.map.end(); ++i) {
		cout << *i << endl;
	}
	cout << endl;
	cin.get();
}

void Game::setShipsMap() {
	int x, y;
	char c;
	auto i = jog.getVectorNavios();
	for (auto j = 0; j < jog.getVectorNavios().size(); j++){
		x = i[j].getX();
		y = i[j].getY();
		c = i[j].getIcon();

		config.map[x][y] = i[j].getIcon();
	}
}

void Game::moveNavios() {
	int a, b, x=0, z=0;
	auto i = jog.getVectorNavios();

	for (auto k = 0; k < i.size(); k++) {
		srand((unsigned int)time(NULL));
		int r = rand() % 100;
		cout << "r" << r << endl;
		if (r >= 0 && r < 25) {
			x = 1;
			z = 0;
		}
		else if (25 <= r && r < 50) {
			x = -1;
			z = 0;
		}
		else if (50 <= r && r < 75) {
			x = 0;
			z = 1;
		}
		else if (75 <= r && r < 100) {
			x = 0;
			z = -1;
		}

		cout << "xz" << x << z << endl;
		cin.get();
		a = i[k].getX() + x;
		b = i[k].getY() + z;
		if (config.map[a][b] == '+')
			break;
		else {
			jog.getVectorNavios()[k].setX(a);
			jog.getVectorNavios()[k].setY(b);
			cout << "2" << a << b << endl;
			cin.get();
		}
	}
}

void Game::displayMenuTwo() {
	string comando;
	system("cls");
	cout << "--- Lista de Comandos Fase 2 --- \n" << endl;
	cout << endl;
	cout << "exec <nomeFicheiro>" << endl;
	cout << "prox" << endl;
	cout << "compranav <T>" << endl;
	cout << "vendenav <T>" << endl;
	cout << "lista" << endl;
	cout << "compra <N><M>" << endl;
	cout << "vende <N>" << endl;
	cout << "move <N><X>" << endl;
	cout << "auto <N>" << endl;
	cout << "stop <N>" << endl;
	cout << "pirata <X><Y><T>" << endl;
	cout << "evpos <E><X><Y>" << endl;
	cout << "evnav <E><N>" << endl;
	cout << "moedas <N>" << endl;
	cout << "vaipara <N><X><Y>" << endl;
	cout << "comprasold <N><S>" << endl;
	cout << "saveg <nome>" << endl;
	cout << "loadg <nome>" << endl;
	cout << "delg <nome>" << endl;
	cout << "sair" << endl;
	cout << endl;
	cout << "Comando: " << endl;
	getline(cin, comando);
	resolveCommand(comando);
}

void Game::resolveCommand(string comando) {
	string cmd;
	istringstream iss(comando);
	iss >> cmd;

	// Ver qual � o comando
	if (cmd == "exec") {
		iss >> cmd; //fica com o nome do ficheiro guardado
		getFileCommands(cmd);
	}
	else {
		if (cmd == "compranav") {
			iss >> cmd; // fica com o tipo de navio a ser comprado
			if (cmd == "v") {
				Veleiro v; 
				v.setX(2); //criar navio no porto principal
				v.setY(2);
				jog.setVeleiro(v);
				cout << "Comprou um navio do tipo Veleiro" << endl;
			}
			else if (cmd == "e") {
				Escuna e;
				e.setX(2);
				e.setY(10);
				jog.setEscuna(e);
				cout << "Comprou um navio do tipo Escuna" << endl;
			}
			else if (cmd == "g") {
				Galeao g;
				g.setX(2);
				g.setY(10);
				jog.setGaleao(g);
				cout << "Comprou um navio do tipo Galeao" << endl;
			}
			else if (cmd == "f") {
				Fragata f;
				f.setX(2);
				f.setY(10);
				jog.setFragata(f);
				cout << "Comprou um navio do tipo Fragata" << endl;
			}
			else {
				cout << "Tipo de navio inexistente!" << endl;
				return;
			}

			//Jogador::moedas = Jogador::moedas - 100;
		}
	}
}

void Game::getFileCommands(string fich) {
	string cmd;
	string line;
	fstream file;
	file.open(fich);

	if (file.fail()) {
		cerr << "Erro ao abrir ficheiro!" << endl;
		cout << "Press enter to continue..." << endl;
		cin.get();
	}
	else {
		while (!file.eof()) {
			getline(file, line);
			// interpreta o comando e executa
		}
	}
}

Game::~Game()
{
}
