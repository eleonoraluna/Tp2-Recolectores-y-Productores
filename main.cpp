#include <iostream>
#include "Game.h"

const int RESOURCES=4;

int main(int argc,char* argv[]){
	int exit;
	if(argc==3){
		Game game(RESOURCES,argv[1],argv[2]);
		exit=game.run();
	}else{
		std::cout<<"modo no soportado\n";
		return 1;
	}
	return exit;
}




