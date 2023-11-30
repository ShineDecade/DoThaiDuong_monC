#include <iostream>

using namespace std;

class MayLoc {
public:
    virtual void nhap() = 0;
    virtual float tinhLuongNuoc() = 0;
    virtual long tinhChiPhi() = 0;
    virtual ~MayLoc() {}
};

class MayLyTam : public MayLoc {
public:
    void nhap() override {
        // Implement nhap() for MayLyTam
    }

    float tinhLuongNuoc() override {
        // Implement tinhLuongNuoc() for MayLyTam
        return 0.0;
    }

    long tinhChiPhi() override {
        // Implement tinhChiPhi() for MayLyTam
        return 0;
    }
};

class MayXucTac : public MayLoc {
public:
    void nhap() override {
        // Implement nhap() for MayXucTac
    }

    float tinhLuongNuoc() override {
        // Implement tinhLuongNuoc() for MayXucTac
        return 0.0;
    }

    long tinhChiPhi() override {
        // Implement tinhChiPhi() for MayXucTac
        return 0;
    }
};

class DanhSachMayLoc {
private:
    MayLoc** _danhSach;
    int _N;
public:
    DanhSachMayLoc() {
        this->_N = 0;
        this->_danhSach = NULL;
    }

    ~DanhSachMayLoc() {
        for (int i = 0; i < _N; i++) {
            delete _danhSach[i];
        }
        delete[] _danhSach;
    }

    void nhap() {
        cout << "Nhap luong may:";
        cin >> this->_N;
        _danhSach = new MayLoc * [_N];
        for (int i = 0; i < _N; i++) {
            int choice = 0;
            cout << "Nhap loai may: 1 = may ly tam, 2 = may xuc tac:\n";
            cin >> choice;
            if (choice == 1) {
                this->_danhSach[i] = new MayLyTam();
            }
            else {
                this->_danhSach[i] = new MayXucTac();
            }
            this->_danhSach[i]->nhap();
        }
    }

    float tinhLuongNuoc() {
        float sum = 0.0;
        for (int i = 0; i < this->_N; i++) {
            sum += this->_danhSach[i]->tinhLuongNuoc();
        }
        return sum;
    }

    long tinhChiPhi() {
        long sum = 0;
        for (int i = 0; i < this->_N; i++) {
            sum += this->_danhSach[i]->tinhChiPhi();
        }
        return sum;
    }
};

class Ao {
private:
    int _M;
    DanhSachMayLoc _ds;
public:
    Ao() {
        this->_M = 0;
    }

    ~Ao() {
        this->_M = 0;
    }

    void nhap() {
        cout << "Nhap luong nuoc: ";
        cin >> this->_M;
        cout << "Nhap danh sach:\n";
        this->_ds.nhap();
    }

    bool AoDuocLocHetKhong() {
        if (this->_M > this->_ds.tinhLuongNuoc()) {
            return false;
        }
        else {
            return true;
        }
    }

    long tongChiPhi() {
        return this->_ds.tinhChiPhi();
    }
};

int main() {
    Ao ao;
    ao.nhap();

    if (ao.AoDuocLocHetKhong()) {
        cout << "Ao co the duoc loc het va tong chi phi la: " << ao.tongChiPhi() << endl;
    }
    else {
        cout << "Ao khong the duoc loc het." << endl;
    }

    return 0;
}
