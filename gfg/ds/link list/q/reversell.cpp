#include<bits/stdc++.h>
#include<vector>
#include<iterator>
using namespace std;

class Car{
   public:
    string color;
    int price, horsepower;


    static bool ColorCmp (const Car& a, const Car& b) {
      return a.color < b.color;
    }
    static bool HorsePowerCmp(const Car& a, const Car &b) {
    	return a.horsepower<b.horsepower;
    }
    static bool PriceCmp(const Car &a, const Car &b) {
    	return a.price < b.price;
    }
};


int main(){
  vector < Car> cars;
  Car alto;
  alto.color = "black";
  alto.horsepower = 1000;
  alto.price = 200000;
  Car scorpio;
  scorpio.color = "white";
  scorpio.price = 800000;
  scorpio.horsepower= 2000;
  string parameter;
  cin>>parameter;
  sort(cars.begin(), cars.end(), Car::ColorCmp);

  vector<Car>:: iterator it ;
  for(it= cars.begin();it!=cars.end();it++) {
      cout<<it->color;
  }

  return 0;
}
