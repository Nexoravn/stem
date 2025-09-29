#include <bits/stdc++.h>
using namespace std;

// Cấu trúc lưu 1 giao dịch
struct GiaoDich {
    string ngay;       // Ngày (YYYY-MM-DD)
    string danhMuc;    // Danh mục (Ăn uống, Học tập, ...)
    int soTien;        // Số tiền
    string ghiChu;     // Ghi chú
};

// Danh sách giao dịch (giống như bảng trong HTML)
vector<GiaoDich> danhSach;

// Hàm thêm một giao dịch mới
void themGiaoDich() {
    GiaoDich gd;
    cout << "Nhập ngày (YYYY-MM-DD): ";
    getline(cin, gd.ngay);
    cout << "Danh mục: ";
    getline(cin, gd.danhMuc);
    cout << "Số tiền: ";
    cin >> gd.soTien;
    cin.ignore(); // bỏ ký tự xuống dòng còn sót
    cout << "Ghi chú: ";
    getline(cin, gd.ghiChu);

    danhSach.push_back(gd);
    cout << "✅ Đã thêm giao dịch!\n";
}

// Hàm xem danh sách giao dịch
void xemDanhSach() {
    if (danhSach.empty()) {
        cout << "📭 Danh sách trống.\n";
        return;
    }

    cout << "\n===== DANH SÁCH GIAO DỊCH =====\n";
    for (int i = 0; i < (int)danhSach.size(); i++) {
        cout << i+1 << ". "
             << danhSach[i].ngay << " | "
             << danhSach[i].danhMuc << " | "
             << danhSach[i].soTien << " VND | "
             << danhSach[i].ghiChu << "\n";
    }
    cout << "================================\n";
}

// Hàm tính tổng chi tiêu
void tongChiTieu() {
    int tong = 0;
    for (auto &gd : danhSach) {
        tong += gd.soTien;
    }
    cout << "💰 Tổng chi tiêu = " << tong << " VND\n";
}

// Menu chính (giống như thanh menu trong HTML)
void menu() {
    while (true) {
        cout << "\n===== QUẢN LÝ CHI TIÊU DEMO =====\n";
        cout << "1. Thêm giao dịch\n";
        cout << "2. Xem danh sách giao dịch\n";
        cout << "3. Xem tổng chi tiêu\n";
        cout << "0. Thoát\n";
        cout << "Chọn: ";

        int chon;
        cin >> chon;
        cin.ignore(); // bỏ ký tự xuống dòng

        if (chon == 1) themGiaoDich();
        else if (chon == 2) xemDanhSach();
        else if (chon == 3) tongChiTieu();
        else if (chon == 0) {
            cout << "👋 Tạm biệt!\n";
            break;
        } else {
            cout << "❌ Lựa chọn không hợp lệ.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
