#include "TaskQueue.h"
#include "Consumer.h"
#include "Producer.h"

#include <memory>

using std::unique_ptr;

int main(void)
{
  TaskQueue que(20);
  unique_ptr<Thread> pProducer(new Producer(que));
  unique_ptr<Thread> pConsumer(new Consumer(que));
  pProducer->start();
  pConsumer->start();
  pProducer->join();
  pConsumer->join();
  return 0;
}
