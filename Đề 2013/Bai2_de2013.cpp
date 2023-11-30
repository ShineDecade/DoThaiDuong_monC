#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Constructor of Base\n";
    }

    // Không làm hủy ảo
    ~Base() {
        std::cout << "Destructor of Base\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Constructor of Derived\n";
    }

    // Không làm hủy ảo
    ~Derived() {
        std::cout << "Destructor of Derived\n";
    }
};

int main() {
    Base* basePtr = new Derived(); // Slicing có thể xảy ra ở đây
    delete basePtr; // Chỉ gọi hàm hủy của lớp cơ sở

    return 0;
}
