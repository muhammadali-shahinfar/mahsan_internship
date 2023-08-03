#include "mvector.hpp"
#include <vector>
int main(){
  mvector<int> v1;
  int n1;
  v1.push_back(1);
  v1.push_back(1);
  n1 = v1.pop_back();

  mvector<int> v4=v1;
  v4.push_back(1);
  v1.resize(10);

  mvector<int> v5;
  v5 = std::move(v1);

  v5.push_back(1);
  mvector<int> v6;
  v6 = v5;

  v5.pop_back();
  

  std::vector<mvector<int>> v2{std::move(v1)};

}
