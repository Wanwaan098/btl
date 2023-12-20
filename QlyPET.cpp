#include <bits/stdc++.h>
using namespace std;

class khach {
    int MK;
    string hoten, diachi, sdt;
    static int dem;

public:
    khach();
    void nhapk();
    void ink() const;
    int getMK() const;
    string gethoten() const;
    void setMK(int newMK);
};

int khach::dem = 0;

khach::khach() {
    MK = 0;
    hoten = diachi = sdt = "";
}

void khach::nhapk() {
    MK = dem++;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap dia chi: ";
    getline(cin, diachi);
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
}

void khach::ink() const {
    cout << setw(4) << setfill('0') << MK << "\t\t";
    cout <<hoten << "\t\t";
    cout << diachi << "\t\t";
    cout << sdt << "\n";
}

int khach::getMK() const {
    return MK;
}

string khach::gethoten() const {
    return hoten;
}

void khach::setMK(int newMK) {
    MK = newMK;
}

class thucung {
    int MTC;
    string tenthucung, loaithucung;
    int slton;
    static int dt;

public:
    thucung();
    void nhaptc();
    void intc() const;
    int getMTC() const;
    int getSlton() const;
    string getloaithucung() const;
    string gettenthucung() const;
    void setMTC(int newMTC);
};

int thucung::dt = 0;

thucung::thucung() {
    MTC = slton = 0;
    tenthucung = loaithucung = "";
}

void thucung::nhaptc() {
    MTC = dt++;
    cin.ignore();
    cout << "Nhap loai thu cung: ";
    getline(cin, loaithucung);
    cout << "Nhap ten thu cung: ";
    getline(cin, tenthucung);
    cout << "Nhap so luong ton: ";
    cin >> slton;
    cin.ignore();
}

void thucung::setMTC(int newMTC) {
    MTC = newMTC;
}

void thucung::intc() const {
    cout << setw(4) << setfill('0') << MTC << "\t\t";
    cout << loaithucung << "\t\t";
    cout << tenthucung << "\t\t";
    cout << slton << "\n";
}

int thucung::getMTC() const {
    return MTC;
}

string thucung::getloaithucung() const {
    return loaithucung;
}

string thucung::gettenthucung() const {
    return tenthucung;
}

int thucung::getSlton() const {
    return slton;
}


class hoadon;

void updateThucung(thucung m[], int x);

class hoadon {
    khach k;
    thucung tc;
    int slb;
    float dongia;
    string ngayhd;

public:
    void nhaphd(khach a, thucung b);
    void nhapdlhd();
    void getdl() const;
    khach getk() const;
    int getslb() const;
    float getdongia() const;
    string getngayhd() const;
    thucung getthucung() const;
    friend void updateHoaDon(hoadon hdArr[], int hdCount, khach arr[], int n, thucung m[], int x);
};

void hoadon::nhaphd(khach a, thucung b) {
    k = a;
    tc = b;
}

thucung hoadon::getthucung() const {
    return tc;
}

void hoadon::nhapdlhd() {
    cout << "So luong ban: ";
    cin >> slb;
    cout << "Don gia: ";
    cin >> dongia;
    cin.ignore();
    cout << "Ngay mua hang: ";
    getline(cin, ngayhd);
}

void hoadon::getdl() const {
    cout << setw(4) << setfill('0') << k.getMK() << "\t\t";
    cout << k.gethoten() << "\t\t";
    cout << tc.gettenthucung() << "\t\t";
    cout << slb << "\t\t";
    cout << dongia << "\t\t";
    cout << ngayhd << "\n";
}

khach hoadon::getk() const {
    return k;
}

int hoadon::getslb() const {
    return slb;
}

string hoadon::getngayhd() const {
    return ngayhd;
}

float hoadon::getdongia() const {
    return dongia;
}


void updateThucung(thucung m[], int x) {
    int uptc;
    cout << "Nhap so thu tu thu cung can sua (1-" << x << "): ";
    cin >> uptc;

    if (uptc >= 1 && uptc <= x) {
        int oMTC = m[uptc - 1].getMTC();
        m[uptc - 1].nhaptc();
        m[uptc - 1].setMTC(oMTC);
        cout << "Thong tin thu cung da duoc cap nhat.\n";
    } else {
        cout << "Thu tu nhap khong hop le.\n";
    }
}


void updateKhach(khach arr[], int n) {
    int upk;
    cout << "Nhap so thu tu khach hang can sua (1-" << n << "): ";
    cin >> upk;

    if (upk >= 1 && upk <= n) {
        int originalMK = arr[upk - 1].getMK();
        arr[upk - 1].nhapk(); 
        arr[upk - 1].setMK(originalMK);  
        cout << "Thong tin khach hang da duoc cap nhap.\n";
    } else {
        cout << "Thu tu nhap khong hop le.\n";
    }
}


void deleteHoaDon(hoadon hdArr[], int& hdCount) {
    int delt;
    cout << "Nhap so thu tu hoa don can xoa (1-" << hdCount << "): ";
    cin >> delt;

    if (delt >= 1 && delt <= hdCount) {
    
        for (int i = delt - 1; i < hdCount - 1; i++) {
            hdArr[i] = hdArr[i + 1];
        }

    
        hdCount--;

        cout << "Hoa don da duoc xoa.\n";
    } else {
        cout << "Thu tu nhap khong hop le.\n";
    }
}


void updateHoaDon(hoadon hdArr[], int hdCount, khach arr[], int n, thucung m[], int x) {
    int uphd;
    cout << "Nhap so thu tu hoa don can sua (1-" << hdCount << "): ";
    cin >> uphd;

    if (uphd >= 1 && uphd <= hdCount) {
        int khachupd, tcupd;

    
        cout << "\nCap nhat thong tin khach hang:\n";
        cout << "Chon khach hang thu (1-" << n << "): ";
        cin >> khachupd;
        if (khachupd >= 1 && khachupd <= n) {
            khach updated = arr[khachupd - 1];
            hdArr[uphd - 1].nhaphd(updated, hdArr[uphd - 1].getthucung());
        }

        cout << "\nCap nhat thong tin thu cung:\n";
        cout << "Chon thu cung thu (1-" << x << "): ";
        cin >> tcupd;
        if (tcupd >= 1 && tcupd <= x) {
            thucung updatedPet = m[tcupd - 1];
            hdArr[uphd - 1].nhaphd(hdArr[uphd - 1].getk(), updatedPet);
        }


        hdArr[uphd - 1].nhapdlhd();

        cout << "\nThong tin hoa don da duoc cap nhat.\n";
    } else {
        cout << "Thu tu nhap khong hop le.\n";
    }
}


int main() {
    int choice;
    int n = 0; 
    int x = 0; 
    int hdCount = 0; 
    khach arr[100]; 
    thucung m[100]; 
    hoadon hdArr[100 * 100]; 

    do {
        cout << "\n===============  MENU  ===============\n";
        cout << "1. Them thong tin khach hang \n";
        cout << "2. Them Thu Cung\n";
        cout << "3. Xuat Danh Sach khach hang\n";
        cout << "4. Xuat Danh Sach Thu Cung\n";
        cout << "5. Them Hoa Don\n";
        cout << "6. Xuat Danh Sach hoa don\n";
        cout << "7. Sua Thong Tin Thu Cung\n";
        cout << "8. Sua Thong Tin Khach\n";
        cout << "9. Sua Thong Tin Hoa Don\n";
        cout << "10. Xoa hoa don\n";
        cout << "11. Thong tin cua khach hang mua nhieu lan nhat\n";
        cout << "12. Hoa don co tong tien cao nhat\n";
        cout << "13. Tim kiem thong tin hoa don theo ma khach\n";
        cout << "14. Tim thong tin thu cung theo loai thu cung\n";
        cout << "0. Thoat\n";
        cout << "=======================================\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: // Them thong tin khach hang
                if (n < 100) {
                    cout << "Khach thu " << n + 1 << ": " << endl;
                    arr[n].nhapk();
                    n++;
                } else {
                    cout << "Danh sach khach da day. Khong the them moi.\n";
                }
                break;

            case 2: // Them Thu Cung
                if (x < 100) {
                    cout << "Thu cung thu " << x + 1 << ": " << endl;
                    m[x].nhaptc();
                    x++;
                } else {
                    cout << "Danh sach thu cung da day. Khong the them moi.\n";
                }
                break;

            case 3: // Xuat Danh Sach khach hang
            cout<<"\n\t\tDANH SACH KHACH HANG\n";
            cout << "\nMa khach\tHo ten\t\tDia chi\t\tSo dien thoai\n";
                for (int i = 0; i < n; i++) {
                    arr[i].ink();
                }
                break;

            case 4: // Xuat Danh Sach Thu Cung
            cout<<"\n\t\tDANH SACH THU CUNG\n";
            cout << "\nMa thu cung\tLoai thu cung\tTen thu cung\tSo luong ton\n";
                for (int i = 0; i < x; i++) {
                    m[i].intc();
                }
                break;

            case 5: // Them Hoa Don
                if (hdCount < 100 * 100) { // Assuming a maximum of 100 customers * 100 pets
                    cout << "Hoa don thu " << hdCount + 1 << ": " << endl;
                    int customer, pet;
                    cout << "Chon khach hang thu (1-" << n << "): ";
                    cin >> customer;
                    cout << "Chon thu cung thu (1-" << x << "): ";
                    cin >> pet;

                    if (customer >= 1 && customer <= n && pet >= 1 && pet <= x) {
                        hdArr[hdCount].nhaphd(arr[customer - 1], m[pet - 1]);
                        hdArr[hdCount].nhapdlhd();
                        hdCount++;
                    } else {
                        cout << "Khach hang hoac thu cung khong hop le.\n";
                    }
                } else {
                    cout << "Danh sach hoa don da day. Khong the them moi.\n";
                }
                break;

            case 6: // Xuat Danh Sach hoa don
               
                cout << "\n\t\t\t\tDANH SACH CAC HOA DON\n";
                cout<<"\nMa khach\tHo ten khach\tTen thu cung\tSo luong ban\tdongia\t\tNgay mua hang\n";
                for (int i = 0; i < hdCount; i++) {
                    khach k = hdArr[i].getk();
                    thucung tc = hdArr[i].getthucung();
                    hdArr[i].getdl();
                }
                break;

            case 7: // Sua Thong Tin Thu Cung
                updateThucung(m, x);
                break;

            case 8: // Sua Thong Tin Khach
                updateKhach(arr, n);
                break;

            case 9: // Sua Thong Tin Hoa Don
                updateHoaDon(hdArr, hdCount, arr, n, m, x);
                break;

            case 10: // Xoa hoa don
                deleteHoaDon(hdArr, hdCount);
                break;



            case 11:
                {
                    if (n > 0) {
                        int max= -1; // Initialize with a negative value
                        int maxkhach = -1;

                        for (int i = 0; i < n; i++) {
                            int Count = 0;

                            for (int j = 0; j < hdCount; j++) {
                                if (hdArr[j].getk().getMK() == arr[i].getMK()) {
                                    Count++;
                                }
                            }

                            if (Count > max) {
                                max= Count;
                                maxkhach= i;
                            }
                        }

                        if (maxkhach != -1) {
                            cout << "\nKhach hang co nhieu hoa don nhat:\n";
                            cout << "\nMa khach\tHo ten\t\tDia chi\t\tSo dien thoai\n";
                            arr[maxkhach].ink();
                            cout << "So luong hoa don: " << max<< endl;
                        } else {
                            cout << "Danh sach khach hang rong. Khong co khach hang nao.\n";
                        }
                    } else {
                        cout << "Danh sach khach hang rong. Khong co khach hang nao.\n";
                    }
                }
                break;

            case 12:
                {
                    if (hdCount > 0) {
                        float max = -1.0; 
                        int maxhd = -1;

                        for (int i = 0; i < hdCount; i++) {
                            float x = hdArr[i].getslb() * hdArr[i].getdongia();

                            
                            if (x > max) {
                                max = x;
                                maxhd = i;
                            }
                        }

                        if (maxhd != -1) {
                            cout << "\nHoa don co tong tien nhieu nhat:\n";
                            cout<<"\nMa khach\tHo ten khach\tTen thu cung\tSo luong ban\tdon gia\t\tNgay mua hang\n";
                            hdArr[maxhd].getdl();
                            cout << fixed << setprecision(0);
                            cout << "Tong tien nhieu nhat: " << max << endl;
                        } else {
                            cout << "Danh sach hoa don rong. Khong co hoa don nao.\n";
                        }
                    } else {
                        cout << "Danh sach hoa don rong. Khong co hoa don nao.\n";
                    }
                }
                break;

            case 13: 
                {
                    int searchMK;
                    cout << "Nhap ma khach can tim: ";
                    cin >> searchMK;

                    bool found = false;
                    cout << "\nThong tin hoa don co ma khach " << setw(4) << setfill('0') << searchMK << ":\n";
                    cout<<"\nMa khach\tHo ten khach\tTen thu cung\tSo luong ban\tdon gia\t\tNgay mua hang\n";

                    for (int i = 0; i < hdCount; i++) {
                        if (hdArr[i].getk().getMK() == searchMK) {
                           
                            hdArr[i].getdl();
                            found = true;
                        }
                    }

                    if (!found) {
                        cout << "Khong tim thay hoa don voi ma khach " << setw(4) << setfill('0') << searchMK << ".\n";
                    }
                }
                break;
                


            case 14: // Tim thong tin thu cung theo loai thu cung
                {
                    string searchLoaiThuCung;
                    cout << "Nhap loai thu cung can tim: ";
                    cin.ignore();
                    getline(cin, searchLoaiThuCung);

                    bool found = false;

                      cout << "\nCac thu cung co loai " << searchLoaiThuCung << ":\n";

                    regex searchPattern(searchLoaiThuCung, regex_constants::icase);
                    cout << "Ma thu cung\tLoai thu cung\tTen thu cung\tSo luong ton\n";
                    
                    for (int i = 0; i < x; i++) {
                    if (regex_search(m[i].getloaithucung(), searchPattern)) {
                      m[i].intc();
                       found = true;
                    }
                    }

                    if (!found) {
                      cout << "Khong tim thay thu cung voi loai " << searchLoaiThuCung << ".\n";
                    }
                }
                break;

            case 0: // Thoat
                cout << "Tam biet!\n";
                break;

            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }

    } while (choice != 0);

    return 0;
}
