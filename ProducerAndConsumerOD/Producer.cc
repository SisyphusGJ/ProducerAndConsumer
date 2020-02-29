#include "Producer.h"
#include "TaskQueue.h"

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <iostream>

Producer::Producer(TaskQueue & que)
:_que(que)
{}

void Producer::run()
{
  int cnt=20;
  srand(time(NULL));
  while(cnt--)
  {
    int num=rand()%100;
    _que.push(num);
    std::cout << "生产者生产数据:" << num << std::endl;
    sleep(rand()%5);
  }
}
