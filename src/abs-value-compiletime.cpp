#include "NanoLogCpp17.h"
#include "timer.h"

int to_abs(const int &value)
{
   return value < 0 ? -value : value;
}

int main()
{
   emumba::utils::timer timer;
   NanoLog::setLogFile("./performance-logs");
   NanoLog::preallocate();
   NanoLog::setLogLevel(NanoLog::NOTICE);

   for (uint itr = 0; itr < 1000000; ++itr)
   {
      timer.start();

      const int value_1     = -10;
      int       abs_value_1 = to_abs(value_1);

      const int value_2     = -10;
      int       abs_value_2 = to_abs(value_2);

      const int value_3     = 10;
      int       abs_value_3 = to_abs(value_3);

      const int value_4     = -150;
      int       abs_value_4 = to_abs(value_4);

      const int value_5     = -120;
      int       abs_value_5 = to_abs(value_5);

      const int value_6     = -1030;
      int       abs_value_6 = to_abs(value_6);

      const int value_7     = -260;
      int       abs_value_7 = to_abs(value_7);

      const int value_8     = -490;
      int       abs_value_8 = to_abs(value_8);

      const int value_9     = 580;
      int       abs_value_9 = to_abs(value_9);

      const int value_10     = 6710;
      int       abs_value_10 = to_abs(value_10);

      timer.stop();
      double latency = timer.get_elapsed_ns();
      NANO_LOG(NOTICE, "Duration: *%0.0f", latency);
   }
}
