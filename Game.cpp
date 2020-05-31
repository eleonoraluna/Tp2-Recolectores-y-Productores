#include <vector>
#include <string>
#include "Game.h"
#include "Collector.h"
#include "Producer.h"

//puntos que genera cada productor
const int pointschef=5;
const int pointscarpenter=2;
const int pointsarmourer=3;
//cant que necesita cada productor de cada recurso
const int chefwheat=2;
const int chefcoal=1;
const int carpenterwood=3;
const int carpenteriron=1;
const int armourercoal=2;
const int armoureriron=2;

Game::Game(int worker_types,const std::string &filename_workers,
		   const std::string &filename_map):workers(worker_types,0),
		   inventory(4),myprinter(this->inventory,this->mypoints),
		   reader(filename_workers,filename_map){}

void Game::hand_out_resources(){
	 char resource;
	 while (!this->reader.map_eof()){
		this->reader.readResource(resource);
			switch(resource){
			case 'T':
					this->agr_queue.add(resource);
					break;
			case 'M':
					this->l_queue.add(resource);
					break;
			case 'C':
					this->m_queue.add(resource);
					break;
			case 'H':
					this->m_queue.add(resource);
					break;
			}
	 }
}

void Game::close_queues(){
	 this->agr_queue.close();
	 this->l_queue.close();
	 this->m_queue.close();
}

int Game::count_workers(){
	int i=0,exit=0;
	while(!this->reader.workers_eof() && exit==0){
	exit=this->reader.readWorkers(this->workers,i);
	i++;
	}
	return exit;
}

void Game::create_collectors(std::vector<Thread*> &collectors,
		                      Blocking_queue &q,int cant){
	 collectors.reserve(cant);
	 for (int i=0; i<cant; i++){
		collectors.push_back(new Collector(q,this->inventory));
	 }
}

void Game::create_producers(std::vector<Thread*> &producers,int count,
							int res1,int res2,int count1, int count2
							,int points){
	 producers.reserve(count);
	 for (int i=0; i<count; i++){
		producers.push_back(new Producer(this->inventory,this->mypoints,
				            res1,res2,count1,count2,points));
	 }
}

void Game::start_workers(std::vector<Thread*> &workers){
	 for (unsigned int i=0; i<(workers.size()); i++){
		 workers[i]->start();
	 }
}

void Game::collect(){
	 create_collectors(this->agriculturists,this->agr_queue,
			          this->workers[agriculturist]);
	 create_collectors(this->lumberjacks,this->l_queue,
			          this->workers[lumberjack]);
	 create_collectors(this->miners,this->m_queue,this->workers[miner]);
	 start_workers(this->agriculturists);
	 start_workers(this->lumberjacks);
	 start_workers(this->miners);
}

void Game::produce(){
	 create_producers(this->chefs,this->workers[chef],wheat,coal,chefwheat,
			         chefcoal,pointschef);
	 create_producers(this->carpenters,this->workers[carpenter],wood,iron,
			         carpenterwood,carpenteriron,pointscarpenter);
	 create_producers(this->armourers,this->workers[armourer],coal,iron,
			         armourercoal,armoureriron,pointsarmourer);
	 start_workers(this->chefs);
	 start_workers(this->carpenters);
	 start_workers(this->armourers);
}

void Game::join_workers(std::vector<Thread*> &workers){
	 for (unsigned int i=0; i<(workers.size()); i++){
		  workers[i]->join();
	 }
}

void Game::join_collectors(){
	 join_workers(this->agriculturists);
	 join_workers(this->lumberjacks);
	 join_workers(this->miners);
}

void Game::join_producers(){
	 join_workers(this->chefs);
	 join_workers(this->carpenters);
	 join_workers(this->armourers);
}

void Game::clear_workers(std::vector<Thread*> &workers){
	 for (unsigned int i=0; i<(workers.size()); i++){
		  delete(workers[i]);
	 }
}

void Game::clear(){
	 clear_workers(this->agriculturists);
	 clear_workers(this->lumberjacks);
	 clear_workers(this->miners);
	 clear_workers(this->chefs);
	 clear_workers(this->carpenters);
	 clear_workers(this->armourers);
}

int Game::run(){
	if(this->reader.openFiles()==1 || count_workers()==1){
		return 1;
	}
	collect();//spawneo recolectores
	produce();//spawneo productores
	hand_out_resources();
	close_queues();
	join_collectors();
	this->inventory.close();
	join_producers();
	this->myprinter.print();
	return 0;
}

Game::~Game(){
	clear();
}
