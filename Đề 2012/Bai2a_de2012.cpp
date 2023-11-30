#include <iostream>
using namespace std;

// Đa hình động
class PTIT {
public:
    virtual void show() {
        cout << "I love PTIT." << endl;
    }
};

class UTE : public PTIT {
public:
    void show() {
        cout << "I love UTE." << endl;
    }
};

class VLU : public PTIT {
public:
    void show()  {
        cout << "I love VLU." << endl;
    }
};

int main() {
    PTIT* ptit1 = new UTE();
    PTIT* ptit2 = new VLU();

    ptit1->show(); // I love UTE.
    ptit2->show(); // I love VLU

    delete ptit1;
    delete ptit2;
    return 0;
}