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

TEST(EntropyTest, jointEntropyIndependent)
{
   std::vector<int> rv1;
   std::vector<int> rv2;
   rv1.push_back(0); rv2.push_back(1);
   rv1.push_back(0); rv2.push_back(2);
   rv1.push_back(1); rv2.push_back(1);
   rv1.push_back(1); rv2.push_back(2);

   ASSERT_EQ(joint_entropy(rv1, rv2), entropy(rv1)+entropy(rv2))
      << "H(X,Y) = H(X) + H(Y) if X and Y are independent";
}

TEST(EntropyTest, jointEntropyDependent)
{
   std::vector<int> rv1;
   std::vector<int> rv2;
   // if rv1 = 0 -> rv2 = 1
   rv1.push_back(0); rv2.push_back(1);
   rv1.push_back(0); rv2.push_back(1);
   rv1.push_back(1); rv2.push_back(2);
   rv1.push_back(1); rv2.push_back(1);

   ASSERT_LT(joint_entropy(rv1, rv2), entropy(rv1)+entropy(rv2))
      << "joint entropy of dependent r.v.s should be less than the sum of their entropies.";
}

TEST(EntropyTest, jointEntropyWithSelf)
{
   std::vector<int> rv = {1,2,3,4,3,2,1};

   ASSERT_EQ(joint_entropy(rv, rv), entropy(rv))
      << "joint entropy of dependent r.v.s should be less than the sum of their entropies.";
}

TEST(EntropyTest, jointEntropyMismatchedSize)
{
   std::vector<int> rv1 = {1,34,1,56,1,5,6,3,5};
   std::vector<int> rv2 = {1,4,12,54,2,1,1,1};
   ASSERT_THROW(joint_entropy(rv1, rv2), std::invalid_argument);
   ASSERT_THROW(joint_entropy(rv2, rv1), std::invalid_argument);
}
