#include <iostream>
#include <fstream>

int main() {
    using namespace std;
    long int value;
    size_t size = sizeof(value);
    ifstream random("/dev/random", ios::in|ios::binary);
    ifstream urandom("/dev/urandom", ios::in|ios::binary);
    int counter = 128;

    //Read from random
    if(!random) {
        cerr << "Failed to open /dev/urandom" << endl;
    }

    while (random && counter >= 0) 
    {
        random.read(reinterpret_cast<char*>(&value), size); 
        if(random)
        {
           cout <<  hex << value << endl;
        }
        else
        {
            cerr << "Failed to read from /dev/urandom" << endl;
        }
        counter--;
    }
    random.close();

    cout << "finish reading random" << endl;


    //Read from urandom
    counter = 128;
    if(!urandom) {
        cerr << "Failed to open /dev/urandom" << endl;
    }

    while (urandom && counter >= 0) 
    {
        urandom.read(reinterpret_cast<char*>(&value), size); 
        if(urandom)
        {
           cout <<  hex << value << endl;
        }
        else
        {
            cerr << "Failed to read from /dev/urandom" << endl;
        }
        counter--;
    }
    urandom.close();

    cout << "finish reading urandom" << endl;
    
    
    return 0;
}