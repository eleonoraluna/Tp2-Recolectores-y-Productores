#include "Collector.h"
#include <chrono>

Collector::Collector(Blocking_queue &queue,Inventory &inventory):
myqueue(queue),myInventory(inventory){}

void Collector::add_resource(char *resource){
	 enum resources {wheat,wood,coal,iron};
	 switch (*resource){
			 case 'T':
					this->myInventory.add_resource(wheat);
					break;
			 case 'M':
					this->myInventory.add_resource(wood);
					break;
			 case 'C':
					this->myInventory.add_resource(coal);
					break;
			 case 'H':
					this->myInventory.add_resource(iron);
					break;
	 }
}

void Collector::run(){
	 char* c;
	 c=this->myqueue.remove();
	 //mientras la cola no este cerrada y vacia
	 while (c!=NULL){
		//simulo trabajo
		std::chrono::milliseconds duration(50);
		std::this_thread::sleep_for(duration);
		//agrego recurso al inventario
		add_resource(c);
		//recibo otro recurso de la cola
		c=this->myqueue.remove();
	 }
}

Collector::~Collector() {}

