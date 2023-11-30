#include <iostream>
using namespace std;

// Lớp trừu tượng
class PTIT {
public:
    void displayInfo() {
        cout << "I love PTIT" << endl;
    }
};

// Lớp con kế thừa từ lớp trừu tượng
class UTE : public PTIT {
public:
    void show(){
        cout << "I love UTE" << endl;
    }

    void display(){
        cout << "I love HNU" << endl;
    }
};

int main() {
    // Không thể tạo đối tượng từ lớp trừu tượng
    // PTIT* ptit = new PTIT(); // Lỗi!

    UTE ute;
    ute.show();
    ute.display();
    ute.displayInfo();

    return 0;
}
