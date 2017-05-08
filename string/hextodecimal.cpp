#include <sstream>
#include <iostream>

using namespace std;

int main() {
    long long  x;
    stringstream ss;
    ss << hex << "fffefffe";
    ss >> x;
    // output it as a signed type
    cout << x << endl;
}
