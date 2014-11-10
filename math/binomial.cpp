#include <iostream>

using namespace std;


unsigned long long calc_binom(unsigned long long N, unsigned long long K)
{
   unsigned long long r = 1;
   unsigned long long d;
   if (K > N) return 0;
   for (d = 1; d <= K; d++)
   {
      r *= N--;
      r /= d;
   }
   return r;
}


}

