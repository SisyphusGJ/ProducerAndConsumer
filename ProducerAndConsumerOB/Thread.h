#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>
#include <functional>

class Thread
{
public:
  typedef std::function<void()> ThreadCallback;
  Thread(ThreadCallback cb);
  ~Thread();

  void start();
  void join();
private:
  static void * threadFunc(void * p);
private:
  ThreadCallback _cb;
  pthread_t _pthID;
  bool _isRunning;
};
#endif
