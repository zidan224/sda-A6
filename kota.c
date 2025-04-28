#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

Kota* buatKota(const char* nama) {
    Kota* baru = (Kota*)malloc(sizeof(Kota));
    if (!baru) {
        printf("Gagal alokasi kota.\n");
        exit(1);
    }
    strcpy(baru->namaKota, nama);
    CreateList(&(baru->daftarWarga));
    baru->prevKota = NULL;
    return baru;
}

void tambahWargaKota(Kota* kota, const char* namaWarga) {
    infotype warga;
    strcpy(warga.nama, namaWarga);
    InsVLast(&(kota->daftarWarga), warga);
}

void hapusWargaKota(Kota* kota, const char* namaWarga) {
    address p = First(kota->daftarWarga);
    while (p != Nil) {
        if (strcmp(Info(p).nama, namaWarga) == 0) {
            DelP(&(kota->daftarWarga), Info(p));
            break;
        }
        p = Next(p);
    }
}

void cetakKota(Kota* kota) {
    printf("[%s]\n", kota->namaKota);
    printf("    Next menunjuk ke warga: ");
    address p = First(kota->daftarWarga);
    if (p == Nil) {
        printf("List Kosong\n");
    } else {
        while (p != Nil) {
            printf("%s", Info(p).nama);
            if (Next(p) != Nil) {
                printf(" -> ");
            }
            p = Next(p);
        }
        printf("\n");
    }
    printf("    Prev menunjuk ke kota: ");
    if (kota->prevKota != NULL) {
        printf("%s\n", kota->prevKota->namaKota);
    } else {
        printf("NULL\n");
    }
}

void freeKota(Kota* kota) {
    DelAll(&(kota->daftarWarga));
    free(kota);
}

void tambahKota(Kota** head, Kota* kotaBaru) {
    if (*head == NULL) {
        *head = kotaBaru;
    } else {
        Kota* temp = *head;
        while (temp->prevKota != NULL) {
            temp = temp->prevKota;
        }
        temp->prevKota = kotaBaru;
    }
}

Kota* cariKota(Kota* head, const char* namaKota) {
    Kota* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->namaKota, namaKota) == 0) {
            return temp;
        }
        temp = temp->prevKota;
    }
    return NULL;
}

void hapusKota(Kota** head, const char* namaKota) {
    Kota* temp = *head;
    Kota* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->namaKota, namaKota) == 0) {
            if (prev == NULL) {
                *head = temp->prevKota;
            } else {
                prev->prevKota = temp->prevKota;
            }
            freeKota(temp);
            printf("Kota %s dihapus.\n", namaKota);
            return;
        }
        prev = temp;
        temp = temp->prevKota;
    }
    printf("Kota %s tidak ditemukan.\n", namaKota);
}

void cetakSemuaKota(Kota* head) {
    Kota* temp = head;
    if (temp == NULL) {
        printf("Belum ada kota.\n");
        return;
    }

    while (temp != NULL) {
        
        printf(" %s ", temp->namaKota);

        
        address p = First(temp->daftarWarga);
        if (p == Nil) {
            printf(" -> Null");
        } else {
            while (p != Nil) {
                printf(" ->  %s ", Info(p).nama);
                p = Next(p);
            }
        }

        printf("\n");
        printf("     |\n");
        printf("     v\n");

        temp = temp->prevKota;
    }

    printf("Null\n");
}

