#ifndef _LIT_ENTROPY_HPP
#define _LIT_ENTROPY_HPP

#include <vector>
#include <map>
#include <numeric>
#include <cmath>

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
   return 0;
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
