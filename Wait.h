#ifndef BIN_SLEEP_SLEEP_H
#define BIN_SLEEP_SLEEP_H

#include <POSIXApplication.h>
  
class Wait : public POSIXApplication
{
  public:

Wait(int argc, char **argv);

  virtual ~Wait();

virtual Result exec();
};

#endif /* __BIN_SLEEP_SLEEP_H */
