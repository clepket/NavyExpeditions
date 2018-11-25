// NavyExpeditions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Configuration.h"
#include "Game.h"

using namespace std;

int main(){
	//Primeira Fase, Configuração
	Configuration config;
	config.run();
	//Configuration *config = new Configuration;
	//config->run();

	//Segunda Fase, Jogo
	//Game *game = new Game;
	//game(config);
	//ou
	Game game(config);
	game.run();
    return 0;
}

