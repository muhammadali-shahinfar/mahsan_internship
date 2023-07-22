#include <gtest/gtest.h>

#include "vector.cpp"



TEST(mvector,assign_test){
  mvector<int> v1;
  v1.push_back(1);
  v1.push_back(1);
  int n1;
  n1 = v1.pop_back();
  std::cout << n1;
  EXPECT_EQ(n1,1);
}

TEST(mvector,size_test){
  mvector<int> v1;
  v1.push_back(1);
  v1.resize(10);
  EXPECT_EQ(v1.size(),10);
}

TEST(mvector,resize_test){
  mvector<int> v1;
  v1.push_back(1);
  v1.resize(5);
  ASSERT_NE(v1[1],2);
  v1.resize(2);
  EXPECT_EQ(v1[0],1);
}

int main(int argc,char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}