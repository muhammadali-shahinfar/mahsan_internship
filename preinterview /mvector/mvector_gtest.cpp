#include <gtest/gtest.h>

#include "mvector.hpp"




TEST(mvector,push_pop_test){
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
  EXPECT_EQ(v1[1],1);
  v1.resize(2);
  EXPECT_EQ(v1[0],1);
}

TEST(mvector,copy_assignment){
  mvector<int> v1,v2;
  v1.push_back(1);
  v1.push_back(2);
  v2 = v1;
  v2.push_back(2);
  ASSERT_NE(v1.size(),3);
}

TEST(mvector,move_constructure){
  mvector<int> v2;
  v2.push_back(1);
  std::vector<mvector<int>> v1{std::move(v2)};
  EXPECT_EQ(v1[0][0],1);
  ASSERT_NE(v2.size(),1);

}

TEST(mvector,move_assignment){ 
  mvector<int> v1;
  v1.push_back(1);
  v1.push_back(1);
  mvector<int> v2;
  v2 = std::move(v1);
  EXPECT_EQ(v2[1],1);
  ASSERT_NE(v1.size(),2);
}

TEST(mvector,copy_constructor){
  mvector<int> v1;
  v1.push_back(1);
  v1.push_back(1);
  mvector<int> v2 = v1;
  v1.pop_back();
  EXPECT_EQ(v2[1],1);
}
int main(int argc,char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
