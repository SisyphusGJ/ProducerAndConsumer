#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "MutexLock.h"

#include <pthread.h>


class Condition
{
public:
  Condition(MutexLock & mutex);
  ~Condition();

  void wait();
  void notify();
  void broadcast();

private:
  MutexLock & _mutex;
  pthread_cond_t _cond;
};

#endif
