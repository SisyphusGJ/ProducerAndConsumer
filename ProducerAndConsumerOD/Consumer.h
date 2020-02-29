#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include "Thread.h"

class TaskQueue;

class Consumer
:public Thread
{
public:
  Consumer(TaskQueue & que);
private:
  void run();
private:
  TaskQueue & _que;
};
#endif
