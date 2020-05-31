#include "Benefitpoints.h"

Benefit_points::Benefit_points() {
	 this->points_accumulator=0;
}

void Benefit_points::add_points(int points){
	 std::unique_lock<std::mutex> lock(this->m);
	 this->points_accumulator=this->points_accumulator+points;
}

int Benefit_points::get_points(){
	return(this->points_accumulator);
}

Benefit_points::~Benefit_points() {}

