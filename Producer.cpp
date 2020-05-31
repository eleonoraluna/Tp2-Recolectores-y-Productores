#include <iostream>
#include "Producer.h"


Producer::Producer(Inventory &inventory,Benefit_points &benefitpoints,int res1
		           ,int res2,int count1,int count2,int points):
myInventory(inventory),benefitpoints(benefitpoints),resource_1(res1),
resource_2(res2),count1(count1),count2(count2),points(points){}

void Producer::run(){
	 int exit=0;
	 while (exit!=1){
		exit=this->myInventory.remove_resources(resource_1,resource_2,count1,count2);
		std::chrono::milliseconds duration(60);
		std::this_thread::sleep_for(duration);
		if(exit!=1){
		this->benefitpoints.add_points(this->points);
		}
	 }
}

Producer::~Producer() {}

