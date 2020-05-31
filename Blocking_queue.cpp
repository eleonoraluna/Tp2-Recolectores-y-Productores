#include "Blocking_queue.h"

Blocking_queue::Blocking_queue():isclosed(false) {}

void Blocking_queue::close(){
	 std::unique_lock<std::mutex> lock(this->m);
	 this->isclosed=true;
	 cond_var.notify_all();
}

void Blocking_queue::add(char c){
	 std::unique_lock<std::mutex> lock(this->m);
	 this->myqueue.push(c);
	 this->cond_var.notify_all();
}

char* Blocking_queue::remove(){
	  std::unique_lock<std::mutex> lock(this->m);
	  while (this->myqueue.empty()){
		  if (this->isclosed){
			return NULL;
		  }
	  this->cond_var.wait(lock);
	  }
	  char* c=&this->myqueue.front();
	  this->myqueue.pop();
	  return(c);
}

Blocking_queue::~Blocking_queue() {}

