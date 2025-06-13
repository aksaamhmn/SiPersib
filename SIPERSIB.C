#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

struct registrasi {
    char username[30];
    char password[35];
};

struct login {
    char usernametrdftr[30];
    char passwordtrdftr[35];
};

struct Data {    
    char nama[50];
    int tgl, bln, thn;
    int id;
    int statusPembayaran;
    char kelas[50];
};

void registrasi();
void loginAdmin();
void loginUser();
int usernameAdmin(char *username);
int user(char *user);
void halamanAdmin();
void dataPendaftar();
void infoKelas();
void halamanUser();
void tambahData();
int idTerakhir();
void pembayaran();
void bagiKelas(struct Data *dt);
void informasi();

int main() {
    int pilihan;
    do {
        system("cls");
        printf("SELAMAT DATANG DIPORTAL PENERIMAAN SISWA BARU\n");
        printf("1. Registrasi\n");
        printf("2. Login Admin\n");
        printf("3. Login User\n");
        printf("4. Exit\n");
        printf("Pilih (1-4) : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                registrasi();
                break;
            case 2:
                loginAdmin();
                break;
            case 3:
                loginUser();
                break;
            case 4:
            printf("Terimakasih. Semoga Harimu Menyenangkan :)");
                return 0;
            default:
                printf("Mohon Masukkan Pilihan Yang Valid\n");
                getch();
                break;
        }
    } while (pilihan != 4);

    return 0;
}

int usernameAdmin( char *username) {
    FILE *regis = fopen("regisAdmin.txt", "r");
    struct registrasi data;
    
    while (fscanf(regis, "%s %s", data.username, data.password) != EOF) {
        if (strcmp(username, data.username) == 0) {
            fclose(regis);
            return 1;
        }
    }

    fclose(regis);
    return 0;
}

int usernameUser(char *user) {
    FILE *regis = fopen("regisUser.txt", "r");
    struct registrasi data;

    while (fscanf(regis, "%s %s", data.username, data.password) != EOF) {
        if (strcmp(user, data.username) == 0) {
            fclose(regis);
            return 1;
        }
    }

    fclose(regis);
    return 0;
}

void registrasi() {
    system("cls");
    int pilihan;
    struct registrasi data;
    int ditemukan;
    FILE *regis;

    printf("------------------\n");
    printf("Halaman Registrasi\n");
    printf("------------------\n");
    printf("1. Registrasi Admin\n");
    printf("2. Registrasi User\n");
    printf("3. Kembali\n");
    printf("Pilih (1-3) : ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
        system("cls");
        regis = fopen("regisAdmin.txt ", "a+");
        printf("----------------\n");
        printf("Registrasi Admin\n");
        printf("----------------\n");

        do {
            printf("Masukkan Username: ");
            scanf("%s", data.username);
            ditemukan = usernameAdmin(data.username);
            if (ditemukan == 1) {
                printf("Username sudah digunakan. Masukkan Username lain...\n");
            }
        } while (ditemukan == 1);

        printf("Masukkan Password: ");
        scanf("%s", data.password);

        fprintf(regis, "%s %s\n", data.username, data.password);
        fclose(regis);

        printf("Registrasi Berhasil\n");
        printf("Welcome %s!\n", data.username);

        getch();
        break;
        
        case 2 :
        system("cls");
        regis = fopen("regisUser.txt ", "a+");
        printf("---------------\n");
        printf("Registrasi User\n");
        printf("---------------\n");
        
        do {
            printf("Masukkan Username: ");
            scanf("%s", data.username);
            ditemukan = usernameUser(data.username);
            if (ditemukan == 1) {
                printf("Username sudah digunakan. Masukkan Username lain...\n");
            } 
        } while (ditemukan == 1);

        printf("Masukkan Password: ");
        scanf("%s", data.password);

        fprintf(regis, "%s %s\n", data.username, data.password);
        fclose(regis);

        printf("Registrasi Berhasil\n");
        printf("Welcome %s!\n", data.username);

        getch(); 
        break;

        case 3:
        main();
        break;

        default:
        printf("Pilihan Tidak Tersedia");
        break;
    }
}

void loginAdmin() {
    system("cls");
    FILE *login;
    char nama[30];
    char pw[35];
    struct registrasi data;
    int found = 0;
    
    login = fopen("regisAdmin.txt", "r");

    printf("-----------\n");
    printf("Login Admin\n");
    printf("-----------\n");

    printf("Masukkan Username: ");
    scanf("%s", nama);

    while (fscanf(login, "%s %s", data.username, data.password) != EOF) {
        if (strcmp(nama, data.username) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("username yang Anda masukkan salah\n");
        getch();
        loginAdmin();
        return;

    }

    printf("Masukkan Password: ");
    scanf("%s", pw);

    if (strcmp(pw, data.password) == 0) {
        printf("Login Berhasil! Selamat datang, %s\n", data.username);
    } else {
        printf("Password yang Anda masukkan salah\n");
        getch();
        loginAdmin();
    }

    fclose(login);

    halamanAdmin();

    getch(); 
}

void loginUser() {
    system("cls");
    FILE *login;
    char nama[30];
    char pw[35];
    struct registrasi data;
    int found = 0;
    
    login = fopen("regisUser.txt", "r");

    printf("--------------------------\n");
    printf("Login user\n");
    printf("--------------------------\n\n");

    printf("Masukkan Username: ");
    scanf("%s", nama);

    while (fscanf(login, "%s %s", data.username, data.password) != EOF) {
        if (strcmp(nama, data.username) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Username yang Anda masukkan salah\n");
        getch(); 
        loginUser();    
        return;
    }

    printf("Masukkan Password: ");
    scanf("%s", pw);

    if (strcmp(pw, data.password) == 0) {
        printf("Login Berhasil! Selamat datang, %s\n", data.username);
    } else {
        printf("Password yang Anda masukkan salah\n");
        getch();
        loginUser();
    }

    fclose(login);

    halamanUser();

    getch(); 
}

void halamanAdmin() {
    int pilihan;

    do {
        system("cls");
        printf("HALAMAN ADMIN:\n");
        printf("=========== MENU UTAMA ===========\n");
        printf("1. Data Pendaftaran\n");
        printf("2. Pembagian Kelas\n");
        printf("3. Kembali\n");
        printf("===================================\n");
        printf("Pilih Menu (1-3) : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                dataPendaftar();
                break;
            case 2:
                infoKelas();
                break;
            case 3:
                main();
                break;
            default:
                printf("Pilihan tidak valid. Silahkan coba lagi.\n");
        }
        printf("\n");
    } while (pilihan != 3);
}

void dataPendaftar(){
    system("cls");
    FILE *filePointer;
    struct Data dt;

    filePointer = fopen("pendaftaran.txt", "r");

    printf("======================= Data Pendaftaran =========================\n");
    printf("------------------------------------------------------------------\n");
    printf("ID\tNAMA\tTANGGAL LAHIR\tSTATUS PEMBAYARAN\tKELAS\n");
    printf("------------------------------------------------------------------\n");
    while (fscanf(filePointer, "%d %s %d %d %d %d %s", &dt.id, dt.nama, &dt.tgl, &dt.bln, &dt.thn, &dt.statusPembayaran, dt.kelas) != EOF) {
        printf ("%d\t%s\t%d-%d-%d\t%d\t\t\t%s\n", dt.id, dt.nama, dt.tgl, dt.bln, dt.thn, dt.statusPembayaran, dt.kelas);
    }
    printf("------------------------------------------------------------------\n");

    fclose(filePointer);

    getch();
}

void infoKelas() {
    system("cls");
    FILE *filePointer;
    struct Data dt;
    struct Data data[200]; 
    int reguler = 0, lanjutan = 0; 

    filePointer = fopen("pendaftaran.txt", "r");

    while (fscanf(filePointer, "%d %s %d %d %d %d %s", &dt.id, dt.nama, &dt.tgl, &dt.bln, &dt.thn, &dt.statusPembayaran, dt.kelas) != EOF) {
        if (strcmp(dt.kelas, "Reguler") == 0) {
            data[reguler++] = dt;
        } else if (strcmp(dt.kelas, "Lanjutan") == 0) {
            data[100 + lanjutan++] = dt;
        }
    }

    printf("======================= Informasi Kelas ==========================\n");
    printf("------------------------------------------------------------------\n");
    printf("ID\tNAMA\t\tKELAS\n");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < reguler; i++) {
        printf("%d\t%s\t\t%s\n", data[i].id, data[i].nama, data[i].kelas);
    }
    for (int i = 0; i < lanjutan; i++) {
        printf("%d\t%s\t\t%s\n", data[100 + i].id, data[100 + i].nama, data[100 + i].kelas);
    }
    printf("------------------------------------------------------------------\n");

    fclose(filePointer);

    getch();
}

void halamanUser() {
    int pilihan;

    do {
        system("cls");
        printf("HALAMAN USER:\n");
        printf("=========== MENU UTAMA ===========\n");
        printf("1. Pendaftaran\n");
        printf("2. Pembayaran\n");
        printf("3. Informasi Kelulusan\n");
        printf("4. Kembali\n");
        printf("===================================\n");
        printf("Pilih Menu (1-4) : ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                pembayaran();
                break;
            case 3:
                informasi();
                break;
            case 4:
                main ();
                break;
            default:
                printf("Pilihan tidak valid. Silahkan coba lagi.\n");
        }
        printf("\n");
    } while (pilihan != 4);
}

void tambahData() {
    system("cls");
    FILE *filePointer;
    struct Data dt;

    filePointer = fopen("pendaftaran.txt", "a");

    int lastID = idTerakhir();
    dt.id = lastID + 1;

    printf("Data Pendaftaran:\n");
    printf("Masukkan Nama: ");
    scanf("%s", dt.nama);
    printf("Masukkan Tanggal Lahir (DD MM YYYY): ");
    scanf("%d %d %d", &dt.tgl, &dt.bln, &dt.thn);

    int tahunTerakhir = 2024;
    int bulanTerakhir = 5;
    int usiaTahun = tahunTerakhir - dt.thn;
    int usiaBulan = bulanTerakhir - dt.bln;

    if (usiaBulan < 0) {
        usiaTahun--;
        usiaBulan += 12;
    }

    printf("Rincian Usia: %d tahun dan %d bulan\n", usiaTahun, usiaBulan);

    dt.statusPembayaran = 0;

    strcpy(dt.kelas, "-");

    if ((dt.thn == 2016 && dt.bln >= 6) || (dt.thn > 2016 && dt.thn < 2020) || (dt.thn == 2020 && dt.bln <= 5)) {
        fprintf(filePointer, "%d %s %d %d %d %d %s\n", dt.id, dt.nama, dt.tgl, dt.bln, dt.thn, dt.statusPembayaran, dt.kelas);
        printf("Syarat usia memenuhi. Data berhasil ditambahkan\n");
        printf("ID Daftar Anda: %d\n", dt.id);  
        printf("Status pembayaran anda: %d (0 = Belum bayar, 1 = Sudah bayar)\n", dt.statusPembayaran);
    } else {
        printf("Syarat usia tidak memenuhi. Data tidak ditambahkan\n");
    }

    fclose(filePointer);

    getch();
}

int idTerakhir() {
    FILE *filePointer;
    struct Data dt;
    int lastID = 0;

    filePointer = fopen("pendaftaran.txt", "r");

    while (fscanf(filePointer, "%d %s %d %d %d %d %s", &dt.id, dt.nama, &dt.tgl, &dt.bln, &dt.thn, &dt.statusPembayaran, dt.kelas) != EOF) {
        lastID = dt.id;
    }

    fclose(filePointer);

    return lastID;
}

void pembayaran() {
    system("cls");
    FILE *filePointer, *tempFile;
    struct Data dt;
    int idCari, found = 0;
    int pilihan;

    printf("Masukkan ID pendaftaran yang ingin dibayar: ");
    scanf("%d", &idCari);

    filePointer = fopen("pendaftaran.txt", "r");
    tempFile = fopen("temp.txt", "w");

    while (fscanf(filePointer, "%d %s %d %d %d %d %s", &dt.id, dt.nama, &dt.tgl, &dt.bln, &dt.thn, &dt.statusPembayaran, dt.kelas) != EOF) {
        if (dt.id == idCari) {
            found = 1;
            printf("------------------\n");
            printf("Halaman Pembayaran\n");
            printf("------------------\n");
            printf("Status pembayaran anda: %d (0 = Belum bayar, 1 = Sudah bayar)\n", dt.statusPembayaran);
            printf("1. Bayar\n");
            printf("2. Exit\n");
            printf("Pilih (1-2): ");
            scanf("%d", &pilihan);

            if (pilihan == 1) {
                if (dt.statusPembayaran == 1) {
                    printf("Anda sudah bayar.\n");
                    printf("Silahkan Meilhat Status Kelulusan Anda.\n");
                } else {
                    dt.statusPembayaran = 1;
                    printf("Pembayaran berhasil. Status pembayaran telah diperbarui.\n");
                    printf("Silahkan Meilhat Status Kelulusan Anda.\n");
                    bagiKelas(&dt);
                }
            } else {
                printf("Pembayaran dibatalkan.\n");
            }
        }
        fprintf(tempFile, "%d %s %d %d %d %d %s\n", dt.id, dt.nama, dt.tgl, dt.bln, dt.thn, dt.statusPembayaran, dt.kelas);
    }

    fclose(filePointer);
    fclose(tempFile);

    remove("pendaftaran.txt");
    rename("temp.txt", "pendaftaran.txt");

    if (!found) {
        printf("ID pendaftaran tidak ditemukan.\n");
    }

    getch();
}

void bagiKelas(struct Data *dt){
    int tahunTerakhir = 2024;
    int bulanTerakhir = 5;
    int usiaTahun = tahunTerakhir - (*dt).thn;
    int usiaBulan = bulanTerakhir - (*dt).bln;

    if (usiaBulan < 0) {
        usiaTahun--;
        usiaBulan += 12;
    }

    if ((usiaTahun == 4 && usiaBulan >= 0) || (usiaTahun == 5 && usiaBulan <= 12)) {
        strcpy((*dt).kelas, "Reguler");
    } else {
        strcpy((*dt).kelas, "Lanjutan");
    }
}

void informasi() {
    system("cls");
    FILE *filePointer;
    struct Data dt;
    int idCari, found = 0;

    printf("Masukkan ID pendaftaran yang ingin ditampilkan: ");
    scanf("%d", &idCari);

    filePointer = fopen("pendaftaran.txt", "r");

    while (fscanf(filePointer, "%d %s %d %d %d %d %s", &dt.id, dt.nama, &dt.tgl, &dt.bln, &dt.thn, &dt.statusPembayaran, dt.kelas) != EOF) {
        if (dt.id == idCari) {
            found = 1;

            int tahunTerakhir = 2024;
            int bulanTerakhir = 5;
            int usiaTahun = tahunTerakhir - dt.thn;
            int usiaBulan = bulanTerakhir - dt.bln;

            if (usiaBulan < 0) {
                usiaTahun--;
                usiaBulan += 12;
            }

            if (dt.statusPembayaran == 1){
                printf("Data pendaftaran:\n");
                printf("Selamat! Anda Lulus Masuk Seleksi Rumah Belajar\n");
                printf("ID: %d\n", dt.id);
                printf("Nama: %s\n", dt.nama);
                printf("Tgl Lahir: %d-%d-%d\n", dt.tgl, dt.bln, dt.thn);
                printf("Usia: %d tahun %d bulan\n", usiaTahun, usiaBulan);
                printf("Kelas: %s\n", dt.kelas);
            } else if (dt.statusPembayaran == 0){
                printf("Maaf anda tidak lulus\n");
            }
        }
    }

    fclose(filePointer);

    if (!found) {
        printf("ID pendaftaran tidak ditemukan.\n");
    }

    getch();
}