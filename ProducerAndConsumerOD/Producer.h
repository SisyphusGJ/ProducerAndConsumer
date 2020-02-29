#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include "Thread.h"

class TaskQueue;

class Producer
:public Thread
{
public:
  Producer(TaskQueue & que);
private:
  void run();
private:
  TaskQueue & _que;
};
#endif
