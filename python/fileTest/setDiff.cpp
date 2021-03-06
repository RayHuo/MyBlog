// set_difference example
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
int main () {
  int first[] = {5,10,15,20,25};
  int second[] = {50,40,30,20,10};
  vector<int> v;                           // 0  0  0  0  0  0  0  0  0  0
  vector<int>::iterator it;
 
  sort (first,first+5);     //  5 10 15 20 25
  sort (second,second+5);   // 10 20 30 40 50
 
  it=set_difference (first, first+5, second, second+5, v.begin());
  // 5 15 25  0  0  0  0  0  0  0
 
  cout << "difference has " << int(it - v.begin()) << " elements.\n";
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}