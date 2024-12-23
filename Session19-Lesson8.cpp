#include <stdio.h>
#include <string.h>

// Dinh nghia cau truc SinhVien
typedef struct {
    int id;             
    char name[50];      
    int age;            
    char phoneNumber[15]; 
} SinhVien;

// Ham in danh sach sinh vien
void inDanhSachSinhVien(SinhVien danhSach[], int soLuong) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < soLuong; i++) {
        printf("ID: %d, Ten: %s, Tuoi: %d, SDT: %s\n", 
               danhSach[i].id, danhSach[i].name, danhSach[i].age, danhSach[i].phoneNumber);
    }
}

// Ham sap xep sinh vien theo ten
void sapXepSinhVienTheoTen(SinhVien danhSach[], int soLuong) {
    SinhVien temp; // Bien tam de hoan doi
    for (int i = 0; i < soLuong - 1; i++) {
        for (int j = i + 1; j < soLuong; j++) {
            if (strcmp(danhSach[i].name, danhSach[j].name) > 0) {
                // Hoan doi neu ten o vi tri i lon hon ten o vi tri j
                temp = danhSach[i];
                danhSach[i] = danhSach[j];
                danhSach[j] = temp;
            }
        }
    }
}

int main() {
    int soLuong = 5; // So luong sinh vien
    SinhVien danhSach[] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Vu Thi B", 21, "0987654321"},
        {3, "Nguyen Van C", 22, "01234567891"},
        {4, "Pham Thi Thu", 23, "0765432190"},
        {5, "Hoang Van Vu", 24, "0934567890"}
    };

    printf("Danh sach ban dau:\n");
    inDanhSachSinhVien(danhSach, soLuong);

    // Sap xep sinh vien theo ten
    sapXepSinhVienTheoTen(danhSach, soLuong);

    // In danh sach sau khi sap xep
    printf("\nDanh sach sau khi sap xep theo ten:\n");
    inDanhSachSinhVien(danhSach, soLuong);

    return 0;
}

