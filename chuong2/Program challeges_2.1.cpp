#include <iostream>
#include <vector>
#include <limits>

class DATE {
private:
    int day, month, year;

public:
    DATE() : day(0), month(0), year(0) {}

    void inputDate() {
        std::cout << "Nhap ngay: ";
        std::cin >> day;
        std::cout << "Nhap thang: ";
        std::cin >> month;
        std::cout << "Nhap nam: ";
        std::cin >> year;
    }

    void displayDate() const {
        std::cout << "Ngay: " << day << ", Thang: " << month << ", Nam: " << year << std::endl;
    }
};

class MUONTRA : public DATE {
private:
    int readerCode, bookCode, quantity;
    static double loanFee;

public:
    MUONTRA() : readerCode(0), bookCode(0), quantity(0) {}

    static void setLoanFee(double fee) {
        loanFee = fee;
    }

    void inputInfo() {
        std::cout << "Nhap ma doc gia: ";
        std::cin >> readerCode;
        std::cout << "Nhap ma sach: ";
        std::cin >> bookCode;

        // Gọi hàm nhập của lớp DATE để nhập thông tin ngày mượn sách
        inputDate();

        std::cout << "Nhap so luong: ";
        std::cin >> quantity;
    }

    void displayInfo() const {
        std::cout << "Ma doc gia: " << readerCode << ", Ma sach: " << bookCode << ", So luong: " << quantity << ", Ngay muon: ";
        displayDate();
    }

    double calculateLoanAmount() const {
        return quantity * loanFee;
    }

    // Getter for reader code
    int getReaderCode() const {
        return readerCode;
    }
};

// Khởi tạo giá trị mặc định cho phí cược mượn trả
double MUONTRA::loanFee = 1.5;

int main() {
    int n;
    std::cout << "Nhap so luong MUONTRA: ";
    std::cin >> n;

    // Nhập thông tin cho n đối tượng MUONTRA
    std::vector<MUONTRA> muontraList(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "\nNhap thong tin MUONTRA thu " << i + 1 << std::endl;
        muontraList[i].inputInfo();
    }

    // In thông tin của n đối tượng MUONTRA
    std::cout << "\nThong tin MUONTRA:\n";
    for (const auto &muontra : muontraList) {
        muontra.displayInfo();
        std::cout << "So tien muon tra: " << muontra.calculateLoanAmount() << "\n\n";
    }

    // Hiển thị độc giả mượn trước ngày 1/1/2020
    std::cout << "\nDoc gia muon truoc ngay 1/1/2020:\n";
    for (const auto &muontra : muontraList) {
        if (muontra.year < 2020 || (muontra.year == 2020 && muontra.month < 1) ||
            (muontra.year == 2020 && muontra.month == 1 && muontra.day == 1)) {
            muontra.displayInfo();
            std::cout << "So tien muon tra: " << muontra.calculateLoanAmount() << "\n\n";
        }
    }

    // Tìm mã độc giả có số tiền cược mượn trả nhiều nhất
    double maxLoanAmount = -std::numeric_limits<double>::infinity();
    int maxLoanReaderCode = -1;
    for (const auto &muontra : muontraList) {
        double loanAmount = muontra.calculateLoanAmount();
        if (loanAmount > maxLoanAmount) {
            maxLoanAmount = loanAmount;
            maxLoanReaderCode = muontra.getReaderCode();
        }
    }

    std::cout << "\nDoc gia co so tien muon tra nhieu nhat (ma doc gia): " << maxLoanReaderCode << "\n";

    return 0;
}
