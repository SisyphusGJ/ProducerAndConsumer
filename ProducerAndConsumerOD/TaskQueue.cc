#include "TaskQueue.h"

TaskQueue::TaskQueue(size_t size)
:_size(size)
,_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex)
{}

void TaskQueue::push(const ElemType & elem)
{
  MutexLockGuard mlg(_mutex);
  while(full())
  {
    _notFull.wait();
  }
  _que.push(elem);
  _notEmpty.notify();
}

TaskQueue::ElemType & TaskQueue::pop()
{
  MutexLockGuard mlg(_mutex);
  while(empty())
  {
    _notEmpty.wait();
  }
  ElemType & elem=_que.front();
  _que.pop();
  _notFull.notify();
  return elem;
}

bool TaskQueue::full()const
{
  return _que.size()==_size;
}

bool TaskQueue::empty()const
{
  return _que.empty();
}
