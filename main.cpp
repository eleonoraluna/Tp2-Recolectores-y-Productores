#include <iostream>
#include "Game.h"

const int WORKER_TYPES=6;

int main(int argc,char* argv[]){
	int exit;
	if(argc==3){
		Game game(WORKER_TYPES,argv[1],argv[2]);
		exit=game.run();
	}else{
		std::cout<<"modo no soportado\n";
		return 1;
	}
	return exit;
}




