#include <iostream>
#include "Printer.h"

Printer::Printer(Inventory &inventory,Benefit_points &points):
myinventory(inventory),mypoints(points){}

void Printer::print(){
	 enum resources{wheat,wood,coal,iron};
	 std::cout<<"Recursos restantes:"<<std::endl;
	 std::cout<<"  - Trigo: "<<this->myinventory.get_resource(wheat)<<std::endl;
	 std::cout<<"  - Madera: "<<this->myinventory.get_resource(wood)<<std::endl;
	 std::cout<<"  - Carbon: "<<this->myinventory.get_resource(coal)<<std::endl;
	 std::cout<<"  - Hierro: "<<this->myinventory.get_resource(iron)<<std::endl;
	 std::cout<<std::endl;
	 std::cout<<"Puntos de Beneficio acumulados: "<<this->mypoints.get_points()
			  <<std::endl;
}

Printer::~Printer(){}

