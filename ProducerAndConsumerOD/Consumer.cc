#include "Consumer.h"
#include "TaskQueue.h"

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <iostream>

Consumer::Consumer(TaskQueue & que)
:_que(que)
{}

void Consumer::run()
{
  int cnt=20;
  srand(time(NULL));
  while(cnt--)
  {
    int num=_que.pop();
    std::cout << ">>>消费者消费数据:" << num << std::endl;
    sleep(rand()%5);
  }
}
