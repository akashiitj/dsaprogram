#include <iostream>

#include <iomanip>

#include <map>



using namespace std;



void display (map <string,char> grades)

{

    cout << "\tTotal size: " << grades.size() << endl; /* Output the size */

    /* Create an iterator, much like vector iterators */

    map <string, char>::iterator it;

    for (it = grades.begin(); it != grades.end(); ++it)

        cout << setw(10) << it->first << setw(5) << it->second << endl;

    cout << endl; /* Print a new line */

}



int main ()

{

    cout << "Populating map..." << endl;

    map <string, char> grades; /* Create a map with string as a referencer and char as the storage */

    grades["Danny"] = 'A'; /* This is how we add values to a map */

    grades["Kayleigh"] = 'A'; /* Basically, it is like an array, but cooler */

    grades["Joe"] = 'F'; /* We get to use any data type we like as the access key */

    grades["Brad"] = 'C'; /* As opposed to using 'int' all the time wih an array */

    cout << "Before any modifications:" << endl;

    display (grades); /* Call my function to display the map */

    //grades.erase (grades.find("Joe"));
   map <string, char>::iterator it=grades.find("Joe");
    cout << it->second<< " gyhghg"<<endl;

    display (grades); /* Call my function to display the map */

    if (grades.count("Danny")) /* if "Danny" is in the map */

        cout << grades.count("Joe") << endl;

    else cout << "Danny is not a member of grades" << endl;

    if (grades.count("Joe")) /* remember we deleted him! */

        cout << "Joe is a member of grades" << endl;

    else cout << "Joe is not a member of grades" << endl;



    cout << endl; /* Add a bit of white space */
    /* clear() does exactly what it says on the tin. It completely clears all data from the map */

    grades.clear ();

    cout << "After clearing the map:" << endl;

    display (grades);



    cin.get ();

    return 0;

}

