#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

int main() {
    Kota* headKota = NULL;
    int pilihan;
    
    do {
        printf("\n=== Menu ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Warga ke Kota\n");
        printf("3. Hapus Warga dari Kota\n");
        printf("4. Hapus Kota\n");
        printf("5. Tampilkan Data\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar();

        if (pilihan == 1) {
            char namaKota[100];
            printf("Nama kota: ");
            fgets(namaKota, sizeof(namaKota), stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;

            Kota* baru = buatKota(namaKota);
            tambahKota(&headKota, baru);
            printf("Kota %s ditambahkan.\n", namaKota);

        } else if (pilihan == 2) {
            char namaKota[100], namaWarga[100];
            printf("Nama kota: ");
            fgets(namaKota, sizeof(namaKota), stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;

            Kota* kota = cariKota(headKota, namaKota);
            if (!kota) {
                printf("Kota tidak ditemukan.\n");
                continue;
            }

            printf("Nama warga: ");
            fgets(namaWarga, sizeof(namaWarga), stdin);
            namaWarga[strcspn(namaWarga, "\n")] = 0;

            tambahWargaKota(kota, namaWarga);

        } else if (pilihan == 3) {
            char namaKota[100], namaWarga[100];
            printf("Nama kota: ");
            fgets(namaKota, sizeof(namaKota), stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;

            Kota* kota = cariKota(headKota, namaKota);
            if (!kota) {
                printf("Kota tidak ditemukan.\n");
                continue;
            }

            printf("Nama warga yang dihapus: ");
            fgets(namaWarga, sizeof(namaWarga), stdin);
            namaWarga[strcspn(namaWarga, "\n")] = 0;

            hapusWargaKota(kota, namaWarga);

        } else if (pilihan == 4) {
            char namaKota[100];
            printf("Nama kota yang akan dihapus: ");
            fgets(namaKota, sizeof(namaKota), stdin);
            namaKota[strcspn(namaKota, "\n")] = 0;

            hapusKota(&headKota, namaKota);

        } else if (pilihan == 5) {
            cetakSemuaKota(headKota);
        }

    } while (pilihan != 0);

    Kota* temp = headKota;
    while (temp != NULL) {
        Kota* next = temp->prevKota;
        freeKota(temp);
        temp = next;
    }

    printf("Program selesai.\n");
    return 0;
}
