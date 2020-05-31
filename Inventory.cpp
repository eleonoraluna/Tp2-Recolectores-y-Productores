#include "Inventory.h"

Inventory::Inventory(int resources_types): resources(resources_types,0),
points(0),isclosed(false){}

void Inventory::add_resource(int resource_type){
	std::unique_lock<std::mutex> lock(this->m);
	this->resources[resource_type]=this->resources[resource_type]+1;
	cond_var.notify_all();
}

int Inventory::remove_resources(int res1,int res2,int count1,int count2){
	std::unique_lock<std::mutex> lock(this->m);
	while(!this->available_resources(res1,res2,count1,count2)){
		if(this->isclosed){
			return 1;
		}
		this->cond_var.wait(lock);
	}
	this->resources[res1]=this->resources[res1]-count1;
	this->resources[res2]=this->resources[res2]-count2;
	return 0;
}

void Inventory::close(){
	 std::unique_lock<std::mutex> lock(this->m);
	 this->isclosed=true;
	 cond_var.notify_all();
}

bool Inventory::available_resources(int res1,int res2,int count1,int count2){
	 bool available=false;
	 if ((this->resources[res1]>=count1)&&(this->resources[res2]>=count2)){
		available=true;
	 }
	 return available;
}

int Inventory::get_resource(int resource_type){
	return(this->resources[resource_type]);
}

Inventory::~Inventory(){}


