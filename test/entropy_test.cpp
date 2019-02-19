#include <gtest/gtest.h>
#include "entropy.hpp"

TEST(EntropyTest, singletonRandomVariable)
{
   std::vector<int> rv;
   for(int i = 0; i < 100; i++)
   {
      rv.push_back(0);
   }
   ASSERT_EQ(0.0, entropy(rv));
}

TEST(EntropyTest, binaryUniformRandomVariable)
{
   std::vector<int> rv;
   for(int i = 0; i < 100; i++)
   {
      rv.push_back(10);
      rv.push_back(20);
   }
   ASSERT_EQ(1.0, entropy(rv));
}

TEST(EntropyTest, fourValueUniformRandomVariable)
{
   std::vector<int> rv;
   for(int i = 0; i < 25; i++)
   {
      rv.push_back(10);
      rv.push_back(20);
      rv.push_back(200);
      rv.push_back(-10);
   }
   ASSERT_EQ(2.0, entropy(rv));
}

TEST(EntropyTest, fourValueNonUniformRandomVariable)
{
   std::vector<int> rv;
   for(int i = 0; i < 25; i++)
   {
      rv.push_back(10);
      rv.push_back(11);
      rv.push_back(12);
      rv.push_back(13);
   }
   rv.push_back(13);
   ASSERT_GT(2.0, entropy(rv));
}

TEST(EntropyTest, enumRandomVariable)
{
   enum RV { A, B, C, D };
   std::vector<RV> rv = {A, B, C, A, B, C, D, D};
   ASSERT_EQ(entropy(rv), 2.0);
}
