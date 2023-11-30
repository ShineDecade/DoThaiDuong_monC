#include <iostream>
#include <vector>
#include <limits>  // Sử dụng để loại bỏ kí tự newline từ buffer

class BenhNhan {
protected:
    int MSBN;

public:
    virtual void nhap(std::istream& is) {
        is >> this->MSBN;
    }

    virtual void capNhatNgayXuatVien(int ngay) {}

    virtual bool getTrangThai() {
        return true;
    }

    virtual long tinhTien() {
        return 0;
    }

    virtual void capNhatVienPhi() {}
};

class BenhNhanNgoaiTru : public BenhNhan {
private:
    long _vienPhi;

public:
    BenhNhanNgoaiTru(int id) {
        this->MSBN = id;
    }

    void nhap(std::istream& is) override {
        is >> this->_vienPhi;
    }

    long tinhTien() override {
        return this->_vienPhi;
    }

    void capNhatVienPhi(long Tien) {
        this->_vienPhi += Tien;
    }
};

class BenhNhanNoiTru : public BenhNhan {
private:
    int _loaiPhong;  // a=1, b=2, c=3
    int _ngayBatDauNamVien;
    int _soNgayNamVien;
    bool _daXuatVien;  // true: da, false: chua
    long _phiKhamBenhMoiNgay;

public:
    static long A;
    static long B;
    static long C;

    BenhNhanNoiTru(int MaSo, int ngay, long tien, char c) {
        this->MSBN = MaSo;
        this->_ngayBatDauNamVien = ngay;
        this->_phiKhamBenhMoiNgay = tien;
        this->_loaiPhong = c - 'A' + 1;
        this->_daXuatVien = false;
    }

    void nhap(std::istream& is) override {
        is >> this->_phiKhamBenhMoiNgay;
        char c;
        is >> c;
        this->_loaiPhong = c - 'A' + 1;
    }

    void capNhatNgayXuatVien(int ngay) override {
        this->_soNgayNamVien = ngay - this->_ngayBatDauNamVien;
        this->_daXuatVien = true;
    }

    long tinhTien() override {
        if (this->_daXuatVien) {
            if (this->_loaiPhong == 1) {
                return this->A * (this->_soNgayNamVien + this->_phiKhamBenhMoiNgay);
            } else if (this->_loaiPhong == 2) {
                return this->B * (this->_soNgayNamVien + this->_phiKhamBenhMoiNgay);
            } else if (this->_loaiPhong == 3) {
                return this->C * (this->_soNgayNamVien + this->_phiKhamBenhMoiNgay);
            }
        }
        return 0;
    }
};

long BenhNhanNoiTru::A = 1400000;
long BenhNhanNoiTru::B = 900000;
long BenhNhanNoiTru::C = 600000;

class DanhSachBenhNhan {
    std::vector<BenhNhan*> _ds;

public:
    void nhap() {
        freopen("input.log", "rt", stdin);
        int ngay = 0;
        while (!std::cin.eof()) {
            std::cin >> ngay;
            int MaSo = 0;
            std::cin >> MaSo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string s = "";
            std::cin >> s;
            BenhNhan* p = nullptr;
            if (s == "KB") {
                long Tien = 0;
                std::cin >> Tien;
                if (MaSo <= this->_ds.size()) {
                    this->_ds[MaSo - 1]->capNhatVienPhi(Tien);
                } else {
                    p = new BenhNhanNgoaiTru(MaSo);
                    p->nhap(std::cin);
                    this->_ds.push_back(p);
                }
            } else if (s == "NV") {
                long Tien = 0;
                std::cin >> Tien;
                char c;
                std::cin >> c;
                p = new BenhNhanNoiTru(MaSo, ngay, Tien, c);
                p->nhap(std::cin);
                this->_ds.push_back(p);
            } else if (s == "XV") {
                this->_ds[MaSo - 1]->capNhatNgayXuatVien(ngay);
            } else if (s == "TKVP") {
                for (int i = 0; i < this->_ds.size(); i++) {
                    if (dynamic_cast<BenhNhanNgoaiTru*>(this->_ds[i]) == nullptr) {
                        if (!this->_ds[i]->getTrangThai()) {
                            this->_ds[i]->capNhatNgayXuatVien(ngay);
                        }
                    }
                }
            }
        }
        freopen("CON", "rt", stdin);
    }

    long tinhTongTienVienPhi() {
        long sum = 0;
        for (int i = 0; i < this->_ds.size(); i++) {
            sum += this->_ds[i]->tinhTien();
        }
        return sum;
    }
};

int main() {
    DanhSachBenhNhan ds;
    ds.nhap();
    std::cout << "Tong vien phi: " << ds.tinhTongTienVienPhi() << std::endl;

    return 0;
}
