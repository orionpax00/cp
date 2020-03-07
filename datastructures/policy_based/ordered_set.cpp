#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree< int, \
                          null_type,\
                          less<int>, \
                          rb_tree_tag,\
                          tree_order_statistics_node_update>

int main(){
  ordered_set oset;
  oset.insert(0);
  oset.insert(1);
  oset.insert(5);
  oset.insert(10);

  cout<<*oset.find_by_order(2)<<endl; // location of second 3 largest element
  cout<<oset.order_of_key(5)<<endl; // no of element smaller than 5
}