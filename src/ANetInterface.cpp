#include "ANetInterface.h"

#define CIRCULAR_BUFFER_SIZE 1024

ANetInterface::ANetInterface() : buf(CIRCULAR_BUFFER_SIZE)
{
  Init();
}

ANetInterface::~ANetInterface()
{

}

void ANetInterface::Init()
{

}
