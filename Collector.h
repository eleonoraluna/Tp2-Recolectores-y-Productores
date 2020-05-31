#ifndef COLLECTOR_H_
#define COLLECTOR_H_
#include "Thread.h"
#include "Blocking_queue.h"
#include "Inventory.h"

class Collector :public Thread{
public:
	  Collector(Blocking_queue &queue,Inventory &inventory);
	  //obtiene recursos de su cola y los coloca en el inventario
	  void run();
	  virtual ~Collector();
private:
	  Blocking_queue &myqueue;
	  Inventory &myInventory;
	  void add_resource(char *resource);
};

#endif /* COLLECTOR_H_ */
