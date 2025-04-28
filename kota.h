#ifndef KOTA_H
#define KOTA_H
#define MIN_KOTA 5
#define MAX_KOTA 10

#include "Sll.h"

typedef struct Kota Kota;

struct Kota {
    char namaKota[100];
    List daftarWarga;
    Kota* nextKota;
    Kota* prevKota;
};

Kota* buatKota(const char* nama);
void tambahWargaKota(Kota* kota, const char* namaWarga);
void hapusWargaKota(Kota* kota, const char* namaWarga);
void cetakKota(Kota* kota);
void freeKota(Kota* kota);

void tambahKota(Kota** head, Kota* kotaBaru);
void hapusKota(Kota** head, const char* namaKota);
void cetakSemuaKota(Kota* head);
Kota* cariKota(Kota* head, const char* namaKota);

#endif




