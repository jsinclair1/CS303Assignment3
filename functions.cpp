#include "functions.h"

int linear_search(vector<string>& items, string target, int pos_last) {

if (pos_last == 0)
    return -1; 

if (target == items[pos_last])
  return pos_last; 

else
  return linear_search(items, target, pos_last - 1);

}




