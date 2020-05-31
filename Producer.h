#ifndef PRODUCER_H_
#define PRODUCER_H_
#include "Inventory.h"
#include "Thread.h"
#include "Benefitpoints.h"

class Producer: public Thread {
public:
	Producer(Inventory &inventory,Benefit_points &benefitpoints,int res1,
			 int res2,int count1,int count2,int points);
	//si los recursos que necesita estan disponibles en el inventario
	//suma sus puntos a los puntos de beneficio
	void run();
	virtual ~Producer();
private:
	Inventory &myInventory;
	Benefit_points &benefitpoints;
	int resource_1;
	int resource_2;
	int count1;
	int count2;
	int points;
};

#endif /* PRODUCER_H_ */
