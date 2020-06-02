#ifndef INVENTORY_H_
#define INVENTORY_H_
#include <vector>
#include <mutex>
#include <condition_variable>

class Inventory{
public:
	explicit Inventory(int resources_types);
	void add_resource(int resource_type);

	//elimina los recursos pasados por parametros en las cantidades indicadas
	//si no se encuentran los recursos en esas cantidades disponibles
	//espera hasta que las haya
	//o en su defecto hasta que cierren el inventario
	int remove_resources(int res1,int res2,int count1,int count2);

	//marca el inventario como cerrado
	void close();
	int get_resource(int resource_type);
	~Inventory();
private:
	std::mutex m;
	std::vector<int> resources;
	std::condition_variable cond_var;
	int points;
	bool isclosed;
	bool available_resources(int res1,int res2,int count1,int count2);
};



#endif /* INVENTORY_H_ */
