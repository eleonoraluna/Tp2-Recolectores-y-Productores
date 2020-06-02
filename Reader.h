#ifndef READER_H_
#define READER_H_
#include <fstream>
#include <vector>
#include <string>
#include <map>

class Reader{
public:
	Reader(const std::string &filename_workers,
		   const std::string &filename_map);
	//retorna 1 si los archivos no pudieron abrirse
	int openFiles();
	bool workers_eof();
	bool map_eof();
	//lee de a 1 caracter el archivo del mapa
	int readResource(char &resource);
	//retorna 1 si hubo algun error de parseo
	int readWorkers(std::map<std::string,int> &workers);
	~Reader();
private:
	std::ifstream file_workers;
	std::ifstream file_map;
};




#endif /* READER_H_ */
