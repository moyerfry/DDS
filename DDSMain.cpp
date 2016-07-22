#include "ASender.h"
#include "AReceiver.h"
#include "CircularBuffer.h"
#include <cstdio>
#include <cstdlib>

int main(int argc, char * argv[])
{
  CircularBuffer<int> test(3);
  test.push(4);
  printf("%i\n", test.pop());
}
