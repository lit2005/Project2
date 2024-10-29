#include <iostream>
#include <initializer_list>
#include <cstring>
using namespace std;
class MyString {
private:
    char* data;
    size_t size;

public:
    
    MyString() : data(nullptr), size(0) {}

   
    MyString(initializer_list<char> initList) : size(initList.size()) {
        data = new char[size + 1];
        size_t i = 0;
        for (const char& ch : initList) {
            data[i++] = ch;
        }
        data[size] = '\0';
    }

   
    MyString(MyString&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

   
    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) { 
            delete[] data; 

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    
    ~MyString() {
        delete[] data;
    }

   
    void print() const {
        if (data) {
            cout << data << endl;
        }
        else {
            cout << "(empty)" << endl;
        }
    }
};

int main() {
    MyString obj{ 'H', 'e', 'l', 'l', 'o' };
    obj.print(); 

    MyString obj2 = move(obj);
    obj2.print(); 
    obj.print();  

    return 0;
}
