#include "Thread.h"

Thread::Thread(ThreadCallback cb)
:_cb(cb)
,_pthID(-1)
,_isRunning(false)
{}

Thread::~Thread()
{
  if(_isRunning)
  {
    pthread_detach(_pthID);
    _isRunning=false;
  }
}

void Thread::start()
{
  pthread_create(&_pthID,NULL,threadFunc,this);
  _isRunning=true;
}

void Thread::join()
{
  if(_isRunning)
  {
    pthread_join(_pthID,NULL);
    _isRunning=false;
  }
}

void * Thread::threadFunc(void * p)
{
  Thread * pThread=static_cast<Thread *>(p);
  if(pThread)
  {
    pThread->_cb();
  }
  return NULL;
}
