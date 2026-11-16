#include <iostream>
#include <utility>
using namespace std;

class Number {
private:
    int* value;

public:
    
    Number() {
        value = new int(0);
        cout << "Default Constructor" << endl;
    }

    
    Number(int x) {
        value = new int(x);
        cout << "Parameterized Constructor" << endl;
    }

    
    Number(const Number& n) {
        value = new int(*n.value);
        cout << "Copy Constructor" << endl;
    }

    
    Number(Number&& n) noexcept {
        value = n.value;
        n.value = nullptr;
        cout << "Move Constructor" << endl;
    }

    
    Number& operator=(const Number& n) {
        if (this != &n) {
            if (value == nullptr) {
                value = new int(*n.value);
            } else {
                *value = *n.value;
            }
        }
        cout << "Copy Assignment" << endl;
        return *this;
    }

        Number& operator=(Number&& n) noexcept {
        if (this != &n) {
            delete value;
            value = n.value;
            n.value = nullptr;
        }
        cout << "Move Assignment" << endl;
        return *this;
    }

    void display() const {
        if (value != nullptr) {
            cout << "Value: " << *value << endl;
        } else {
            cout << "Value: empty" << endl;
        }
    }

        ~Number() {
        delete value;
        cout << "Destructor" << endl;
    }
};

int main() {
    Number n1;
    Number n2(10);
    Number n3 = n2; 
    Number n4 = Number(20);

    n3 = n2;                
    n4 = Number(30);        

    cout << "\nDisplaying values:" << endl;
    n1.display();
    n2.display();
    n3.display();
    n4.display();

    return 0;
}
