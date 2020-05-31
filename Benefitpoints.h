#ifndef BENEFITPOINTS_H_
#define BENEFITPOINTS_H_
#include <mutex>

class Benefit_points {
public:
	  Benefit_points();
	  void add_points(int points);
	  int get_points();
	  virtual ~Benefit_points();
private:
	  int points_accumulator;
	  std::mutex m;
};

#endif /* BENEFITPOINTS_H_ */
