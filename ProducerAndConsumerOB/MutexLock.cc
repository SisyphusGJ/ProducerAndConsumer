#include "MutexLock.h"

MutexLock::MutexLock()
:_isLocked(false)
{
  pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock()
{
  pthread_mutex_destroy(&_mutex);
  _isLocked=false;
}

void MutexLock::lock()
{
  pthread_mutex_lock(&_mutex);
  _isLocked=true;
}

void MutexLock::unlock()
{
  pthread_mutex_unlock(&_mutex);
  _isLocked=false;
}

bool MutexLock::isLocked()const
{
  return _isLocked;
}

pthread_mutex_t * MutexLock::getMutexLockPtr()
{
  return & _mutex;
}

MutexLockGuard::MutexLockGuard(MutexLock & mutex)
:_mutex(mutex)
{
  _mutex.lock();
}

MutexLockGuard::~MutexLockGuard()
{
  _mutex.unlock();
}
