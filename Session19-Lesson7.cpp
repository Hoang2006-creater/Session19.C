#include <stdio.h>
#include <string.h>

// Dinh nghia cau truc SinhVien
typedef struct {
    int maSo;           
    char hoTen[50];     
    int tuoi;           
    char soDienThoai[15]; 
} SinhVien;

// Ham in danh sach sinh vien
void inDanhSachSinhVien(SinhVien danhSach[], int soLuong) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < soLuong; i++) {
        printf("Ma so: %d, Ho ten: %s, Tuoi: %d, SDT: %s\n", 
               danhSach[i].maSo, danhSach[i].hoTen, danhSach[i].tuoi, danhSach[i].soDienThoai);
    }
}

// Ham xoa sinh vien theo ma so
void xoaSinhVienTheoMaSo(int maSo, SinhVien danhSach[], int *soLuong) {
    int viTriXoa = -1;

    // Tim vi tri sinh vien can xoa
    for (int i = 0; i < *soLuong; i++) {
        if (danhSach[i].maSo == maSo) {
            viTriXoa = i;
            break;
        }
    }

    // Neu khong tim thay sinh vien
    if (viTriXoa == -1) {
        printf("Khong tim thay sinh vien voi ma so: %d\n", maSo);
        return;
    }

    // Xoa sinh vien bang cach don cac phan tu sau len truoc
    for (int i = viTriXoa; i < *soLuong - 1; i++) {
        danhSach[i] = danhSach[i + 1];
    }

    // Giam so luong sinh vien
    (*soLuong)--;
    printf("Da xoa sinh vien voi ma so: %d\n", maSo);
}

int main() {
    int soLuong = 5; // So luong sinh vien hien tai
    SinhVien danhSach[] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Vu Thi B", 21, "0987654321"},
        {3, "Nguyen Van C", 22, "01234567891"},
        {4, "Pham Thi Thu", 23, "0765432190"},
        {5, "Hoang Van Vu", 24, "0934567890"}
    };

    printf("Danh sach ban dau:\n");
    inDanhSachSinhVien(danhSach, soLuong);

    // Xoa sinh vien co ma so = 3
    xoaSinhVienTheoMaSo(3, danhSach, &soLuong);

    // In danh sach sau khi xoa
    printf("\nDanh sach sau khi xoa:\n");
    inDanhSachSinhVien(danhSach, soLuong);

    return 0;
}

