#include <iostream>
#include <vector>

class MayLoc {
public:
    virtual double TinhCongSuatLoc() const = 0;
    virtual double TinhChiPhi() const = 0;
};

class MayLyTam : public MayLoc {
private:
    const double donGia = 50000;  // Đơn giá thuê
    const double chiPhiNhienLieu = 20000;  // Chi phí nhiên liệu/vật liệu

public:
    double TinhCongSuatLoc() const override {
        return 0;  // Cần thay đổi để tính công suất thực tế
    }

    double TinhChiPhi() const override {
        return chiPhiNhienLieu * TinhCongSuatLoc();
    }
};

class MayXucTac : public MayLoc {
private:
    const double donGia = 80000;  // Đơn giá thuê
    const double chiPhiHoaChat = 10000;  // Chi phí hóa chất/vật liệu

    double thoiGianSuDungHoaChat;

public:
    double TinhCongSuatLoc() const override {
        return 0;  // Cần thay đổi để tính công suất thực tế
    }

    double TinhChiPhi() const override {
        return chiPhiHoaChat * thoiGianSuDungHoaChat;
    }

    void NhapThoiGianSuDungHoaChat() {
        std::cout << "Nhap thoi gian su dung hoa chat (gio): ";
        std::cin >> thoiGianSuDungHoaChat;
    }
};

int main() {
    int N;
    std::cout << "Nhap so luong may loc: ";
    std::cin >> N;

    std::vector<MayLoc*> danhSachMayLoc;
    for (int i = 0; i < N; ++i) {
        char loaiMay;
        std::cout << "Nhap loai may (L/X): ";
        std::cin >> loaiMay;

        MayLoc* mayLoc = nullptr;
        if (loaiMay == 'L') {
            mayLoc = new MayLyTam();
        } else if (loaiMay == 'X') {
            mayLoc = new MayXucTac();
            dynamic_cast<MayXucTac*>(mayLoc)->NhapThoiGianSuDungHoaChat();
        } else {
            std::cerr << "Loai may khong hop le.\n";
            return 1;
        }

        danhSachMayLoc.push_back(mayLoc);
    }

    double luongNuoc;
    std::cout << "Nhap luong nuoc trong ao (m3): ";
    std::cin >> luongNuoc;

    double tongCongSuatLoc = 0;
    double tongChiPhi = 0;

    for (const auto& mayLoc : danhSachMayLoc) {
        tongCongSuatLoc += mayLoc->TinhCongSuatLoc();
        tongChiPhi += mayLoc->TinhChiPhi();
    }

    std::cout << "Tong cong suat loc: " << tongCongSuatLoc << " (thuoc don vi chua thay doi)\n";
    std::cout << "Tong chi phi su dung may loc: " << tongChiPhi << " dong\n";

    // Giải phóng bộ nhớ
    for (const auto& mayLoc : danhSachMayLoc) {
        delete mayLoc;
    }

    return 0;
}
