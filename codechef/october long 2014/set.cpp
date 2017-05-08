/*#include<bits/stdc++.h>

typedef  std::pair<int, int> PairInt;
typedef bool Compare(const PairInt &,const PairInt &);

bool compare(const PairInt &l,const PairInt &r)
{
  if ( l.first != r.first )
        return l.first < r.first;
   else
        return l.second < r.second;
}

int main()
{
  typedef std::set<PairInt,Compare*> IntSet;
  IntSet intSet(compare);
  intSet.insert(PairInt(4,2));
  intSet.insert(PairInt(1,3));
  intSet.insert(PairInt(1,-4));

  intSet.insert(PairInt(4,2));
  for (IntSet::const_iterator i=intSet.begin(); i!=intSet.end(); ++i) {
    std::cerr << i->first << "," << i->second << "\n";
  }

}
*/
#include <iostream>
#include <set>

int main ()
{
  int myints[] = {75,23,65,42,13};
  std::set<int> myset (myints,myints+5);
  std::set<int>::iterator it=myset.end();
  std::cout << "myset contains:";

    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
