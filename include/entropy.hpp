#ifndef _LIT_ENTROPY_HPP
#define _LIT_ENTROPY_HPP

#include <vector>
#include <map>
#include <numeric>
#include <cmath>
#include <stdexcept>

/**
 * Entropy in a single signal.
 */
template <typename T>
double entropy(const std::vector<T>& signal)
{
   int n = signal.size();
   std::map<T, double> histogram;
   for(T x : signal) {
      ++histogram[x];
   }
   return -std::accumulate(histogram.begin(), histogram.end(), 0.0,
                           [n](double acc, std::pair<const T, double>& p)
                              { return ((p.second/n) * log2(p.second/n)) + acc; });
}

/**
 * Joint entropy between two signals. The signals must be the same
 * length.
 */
template <typename T1, typename T2>
double joint_entropy(const std::vector<T1>& signal1, const std::vector<T2>& signal2)
{
   if(signal1.size() != signal2.size())
   {
      throw std::invalid_argument("samples must be the same length");
   }
   int n = signal1.size();

   // build joint histogram
   std::map<std::pair<T1,T2>, double> joint_hist;

   auto s1 = signal1.begin();
   auto s2 = signal2.begin();
   while(s1 < signal1.end())
   {
      ++joint_hist[std::make_pair(*s1++, *s2++)];
   }

   return -std::accumulate(joint_hist.begin(), joint_hist.end(), 0.0,
                           [n](double acc,
                               std::pair<const std::pair<T1,T2>, double>& joint_count) {
                              return acc + ((joint_count.second/n) * log2(joint_count.second/n));
                           });
}

/**
 * Calculate the conditional entropy of signal1 given signal2
 */
template <typename T1, typename T2>
double conditional_entropy(const std::vector<T1>& signal1,
                           const std::vector<T2>& signal2)
{
   return 0;
}

#endif // _LIT_ENTROPY_HPP
