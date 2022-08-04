#include "NanoLogCpp17.h"
#include "timer.h"

#include <iostream>
constexpr int gcd(const uint &input_1, const uint &input_2)
{
   int return_value = 0;

   if (input_2 == 0)  // Special Case
   {
      assert(input_1 != 0);  // gcd(0,0) is undefined
      return_value = input_1;
   }
   else
   {
      return_value = gcd(input_2, input_1 % input_2);
   }

   return return_value;
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

      const int value_1_1 = 3;
      const int value_2_1 = 2;
      int       gcd_1     = gcd(value_1_1, value_2_1);

      const int value_1_2 = 2;
      const int value_2_2 = 3;
      int       gcd_2     = gcd(value_1_2, value_2_2);

      const int value_1_3 = 15;
      const int value_2_3 = 150;
      int       gcd_3     = gcd(value_1_3, value_2_3);

      const int value_1_4 = 150;
      const int value_2_4 = 15;
      int       gcd_4     = gcd(value_1_4, value_2_4);

      const int value_1_5 = 78;
      const int value_2_5 = 36;
      int       gcd_5     = gcd(value_1_5, value_2_5);

      const int value_1_6 = 36;
      const int value_2_6 = 78;
      int       gcd_6     = gcd(value_1_6, value_2_6);

      //   const int value_1_7 = 0;
      //   const int value_2_7 = 0;
      //   int       gcd_7     = gcd(value_1_7, value_2_7);

      timer.stop();
      double latency = timer.get_elapsed_ns();
      NANO_LOG(NOTICE, "Duration: *%0.0f", latency);
   }
}
