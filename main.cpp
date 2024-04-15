#include "queue.h"
#include "functions.h"


int main() {
  Queue<int> integers;

  for (int i = 1; i <= 10; i++){
    integers.push(i*10);
  }
 
  integers.print();
  cout << endl;
  
  cout << "Size: " << integers.size() << endl;
  cout << "Front: " << integers.front() << endl;
  
  
  integers.move_to_rear();
  cout << endl;
  integers.print();
  cout << endl << "New Front: " << integers.front() << endl;
   //cout << "Empty? " << (integers.empty() ? "Yeah!" : "Nah!") << endl;
  


  vector<string> names = {"Jaylen", "Sydney", "Jayden", "Kai", "Sydney", "Charla", "Sydney"};
  cout << "Names List: ";
  for (auto i : names) {
    cout << i << " ";
  }
  
  string targeted = "Sydney";
  int a = linear_search(names, targeted, names.size());
  
  cout << endl << "The name: " << targeted << " was found at index: " << a << endl;
  
   /*
  vector<int> nums = {8,5,4,6,2,9,3};
  insertion_sort(nums);
  
  for (int i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
  }
 
  Queue<int> ordered;
  ordered.push(5);
  ordered.push(3);
  ordered.push(1);
  ordered.push(8);
  ordered.push(4);
  ordered.print();
  ordered.insertion_sort();
  cout << endl;
  ordered.print();*/
  return 0;
  
}