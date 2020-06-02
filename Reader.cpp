#include <vector>
#include <string>
#include <map>
#include "Reader.h"

Reader::Reader(const std::string &filename_workers,
               const std::string &filename_map):file_workers(filename_workers),
               file_map(filename_map){}

bool Reader::workers_eof(){
	 return(this->file_workers.peek()==EOF);
}

bool Reader::map_eof(){
	 return(this->file_map.peek()==EOF);
}

int Reader::openFiles(){
	if (!this->file_workers || !this->file_map){
		return 1;
	}
	return 0;
}

int Reader::readResource(char &resource){
	resource=this->file_map.get();
	if(resource==EOF){
		return 1;
	}
	return 0;
}

int Reader::readWorkers(std::map<std::string,int> &workers){
	std::string line,aux,worker;
	int number,length;
	std::getline(this->file_workers,line);
	std::size_t pos=line.find("=");
	if (pos==std::string::npos){
		return 1;
	}
	length=line.size();
	worker=line.substr(0,length-2);
	aux=line[pos+1];
	number=std::stoi(aux);
	workers.emplace(worker,number);
	return 0;
}

Reader::~Reader(){}

