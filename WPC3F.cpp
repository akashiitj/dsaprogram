// map::lower_bound/upper_bound
#include <iostream>
#include <map>

int main ()
{
  std::map<int,int> mymap;
  std::map<int,int>::iterator itlow,itup;

  mymap[1]=20;
  mymap[2]=40;
  mymap[3]=60;
  mymap[4]=80;
  mymap[6]=100;

  itlow=mymap.lower_bound (5);  // itlow points to b
  itlow--;
//   itup=mymap.upper_bound ('d');   // itup points to e (not d!)
std::cout<<itlow->first<<" "<<mymap[itlow->first]<<std::endl;
// cout<<itlow->first<<" "<<itlow->second<<endl;
  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
//   for (std::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    // std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
