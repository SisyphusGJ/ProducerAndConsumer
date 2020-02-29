#include "TaskQueue.h"
#include "Thread.h"

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <iostream>
#include <functional>

void Producer(TaskQueue * que)
{
  int cnt=20;
  srand(time(NULL));
  while(cnt--)
  {
    int num=rand()%100;
    que->push(num);
    std::cout << "生产者生产数据:" << num << std::endl;
    sleep(rand()%5);
  }
}

void Consumer(TaskQueue * que)
{
  int cnt=20;
  srand(time(NULL));
  while(cnt--)
  {
    int num=que->pop();
    std::cout << ">>>消费者消费数据:" << num << std::endl;
    sleep(rand()%5);
  }
}

int main(void)
{
  TaskQueue que(20);
  Thread ProducerThread(std::bind(Producer,&que));
  Thread ConsumerThread(std::bind(Consumer,&que));
  ProducerThread.start();
  ConsumerThread.start();
  ProducerThread.join();
  ConsumerThread.join();
  return 0;
}
