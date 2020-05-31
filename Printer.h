#ifndef PRINTER_H_
#define PRINTER_H_
#include "Inventory.h"
#include "Benefitpoints.h"

class Printer{
public:
	Printer(Inventory &inventory,Benefit_points &points);
	void print();
	~Printer();
private:
	Inventory &myinventory;
	Benefit_points &mypoints;
};



#endif /* PRINTER_H_ */
