#include<bits/stdc++.h>
#include<vector>
#include<iterator>
using namespace std;
class tropicalfruit //Class tropicalfruit
{
    public:
    string name;
    double price;
};
bool sortByName(tropicalfruit &A, tropicalfruit &B) //function to sort fruits by names
{
    return (A.name < B.name);
}
bool sortByPrice(tropicalfruit &A, tropicalfruit &B) //function to sort fruits by price
{
    return (A.price < B.price);
}
int main()
{
    int sortchoice;
    /*sample fruit names and prices*/
    string fruitname[] = {"avocado", "Watermelon", "Mango", "Pineapple", "Apple", "Orange", "Honeydew", "Pear", "Banana", "Durian"};
    double fruitprice[] = {0.8, 4.8, 0.6, 2.4, 0.4, 0.3, 3.1, 0.7, 3.5, 3.8};
    vector<tropicalfruit> fruitlist; //vector used to store tropicalfruit class objects
    tropicalfruit fruit; //tropicalfruit class object
    for(int i=0; i<10; i++) /*puts 10 objects with name and price into vector*/
    {
        fruit.name = fruitname[i];
        fruit.price = fruitprice[i];
        fruitlist.push_back(fruit);
    }
    for(int i=0; i<10; i++) /*displays all fruits' names and prices*/
    {
        cout << fruitlist[i].name << " " << fruitlist[i].price << endl;
    }
    cout << endl;
    cout<<"Arrange fruits by 1)Name or 2)Price : "; //asks user whether to sort by name or price
    cin>>sortchoice;
    if(sortchoice == 1)
    {
        sort(fruitlist.begin(), fruitlist.end(), sortByName); //sort fruits by name
    }
    else if(sortchoice == 2)
    {   sort(fruitlist.begin(), fruitlist.end(), sortByPrice);

    }
    for(int i=0; i<10; i++) /*displays sorted fruits*/
    {
        cout << fruitlist[i].name << " " << fruitlist[i].price << endl;
    }
    cout << endl;
}
