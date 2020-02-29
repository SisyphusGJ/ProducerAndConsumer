#ifndef __MUTEXLOCK_H__
#define __MUTEXLOCK_H__

#include <pthread.h>

class MutexLock
{
public:
  MutexLock();
  ~MutexLock();

  void lock();
  void unlock();

  pthread_mutex_t * getMutexLockPtr();
  bool isLocked()const;
private:
  pthread_mutex_t _mutex;
  bool _isLocked;
};

class MutexLockGuard
{
public:
  MutexLockGuard(MutexLock & mutex);
  ~MutexLockGuard();
private:
  MutexLock & _mutex;
};
#endif
