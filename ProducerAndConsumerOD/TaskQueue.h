#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include "Condition.h"
#include "MutexLock.h"

#include <queue>

using std::queue;

class TaskQueue
{
public:
  typedef int ElemType;
  TaskQueue(size_t size);

  void push(const ElemType & elem);
  ElemType & pop();

  bool full()const;
  bool empty()const;
private:
  size_t _size;
  queue<ElemType> _que;
  MutexLock _mutex;
  Condition _notFull;
  Condition _notEmpty;
};

#endif
