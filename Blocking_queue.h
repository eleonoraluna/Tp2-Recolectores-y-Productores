#ifndef BLOCKING_QUEUE_H_
#define BLOCKING_QUEUE_H_
#include <mutex>
#include <condition_variable>
#include <queue>

class Blocking_queue {
public:
	  Blocking_queue();
	  void add(char c);
	  //elimina un elemento de la cola
	  //si la cola esta vacia se queda esperando hasta que haya algo
	  //si la cola esta vacia y cerrada devuelve un *NULL
	  char* remove();
	  //marca la cola como cerrada cuando no se le van a agregar mas elementos
	  void close();
	  ~Blocking_queue();
private:
	  std::queue<char> myqueue;
	  std::mutex m;
	  std::condition_variable cond_var;
	  bool isclosed;
};

#endif /* BLOCKING_QUEUE_H_ */
