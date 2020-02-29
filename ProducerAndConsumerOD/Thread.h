#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

class Thread
{
public:
  Thread();
  virtual ~Thread();

  void start();
  void join();
private:
  static void * threadFunc(void * p);
protected:
  virtual void run()=0; 
private:
  pthread_t _pthID;
  bool _isRunning;
};
#endif
