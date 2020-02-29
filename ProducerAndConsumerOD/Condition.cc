#include "Condition.h"

Condition::Condition(MutexLock & mutex)
:_mutex(mutex)
{
  pthread_cond_init(&_cond,NULL);
}

Condition::~Condition()
{
  pthread_cond_destroy(&_cond);
}

void Condition::wait()
{
  pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());
}

void Condition::notify()
{
  pthread_cond_signal(&_cond);
}

void Condition::broadcast()
{
  pthread_cond_broadcast(&_cond);
}
