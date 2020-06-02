#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include <string>
#include "Inventory.h"
#include "Reader.h"
#include "Benefitpoints.h"
#include "Blocking_queue.h"
#include "Printer.h"
#include "Thread.h"
#include <map>

class Game{
public:
	explicit Game(int resources,const std::string &filename_workers,
			      const std::string &filename_map);

	//retorna 1 si en caso de algun error al abrir,leer o parsear alguno
	//de los parametros o archivos
	int run();
	~Game();

private:
	enum resources{wheat,wood,coal,iron};
	std::map<std::string,int> workers;
	std::vector<Thread*> agriculturists;
	std::vector<Thread*> lumberjacks;
	std::vector<Thread*> miners;
	std::vector<Thread*> chefs;
	std::vector<Thread*> carpenters;
	std::vector<Thread*> armourers;
	Blocking_queue agr_queue;
	Blocking_queue l_queue;
	Blocking_queue m_queue;
	Benefit_points mypoints;
	Inventory inventory;
	Printer myprinter;
	Reader reader;

	int count_workers();//cantidad de trabajadores que necesitamos de cada tipo
	void hand_out_resources();//distribuye recursos en las colas bloqueantes
	void start_workers(std::vector<Thread*> &workers);
	void join_workers(std::vector<Thread*> &workers);
	void clear_workers(std::vector<Thread*> &workers);
	void collect();//spawnea los recolectores
	void create_collectors(std::vector<Thread*> &collectors,
			               Blocking_queue &q,int cant);
	void join_collectors();
	void close_queues();
	void produce();//spawnea los productores
	void create_producers(std::vector<Thread*> &producers,int count,int res1,
			              int res2,int count1, int count2,int points);
	void join_producers();
	void clear();//liberamos recursos
};


#endif /* GAME_H_ */
