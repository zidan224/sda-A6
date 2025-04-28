#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sll.h"



boolean ListEmpty (List L) {
    return (First(L) == Nil);
}


void CreateList (List *L) {
    First(*L) = Nil;
}

address Alokasi (infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void DeAlokasi (address P) {
    if (P != Nil) {
        free(P);
    }
}

address Search (List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (strcmp(Info(P).nama, X.nama) == 0) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

boolean FSearch (List L, address P) {
    address PSearch = First(L);
    while (PSearch != Nil) {
        if (PSearch == P) {
            return true;
        }
        PSearch = Next(PSearch);
    }
    return false;
}

address SearchPrec (List L, infotype X) {
    address Prec = Nil;
    address P = First(L);
    while (P != Nil) {
        if (strcmp(Info(P).nama, X.nama) == 0) {   
            return Prev(P);
        }
        Prec = P;
        P = Next(P);
    }
    return Nil;
}

void InsVFirst (List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}

void InsVLast (List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertLast(L, P);
    }
}


void DelVFirst (List *L, infotype *X) {
    address P;
    DelFirst(L, &P);
    *X = Info(P);
    DeAlokasi(P);
}

void DelVLast (List *L, infotype *X) {
    address P;
    DelLast(L, &P);
    if (P != Nil) {
        *X = Info(P);
        DeAlokasi(P);
    }
}

void InsertFirst (List *L, address P) {
    if (ListEmpty(*L)) {
        First(*L) = P;
    } else {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec) {
    if (Next(Prec) != Nil) {
        Prev(Next(Prec)) = P;
    }
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Next(Prec) = P;
}

void InsertLast (List *L, address P) {
    if (ListEmpty(*L)) {
        InsertFirst(L, P);
    } else {
        address Last = First(*L);
        while (Next(Last) != Nil) {
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

void DelFirst (List *L, address *P) {
    *P = First(*L);
    if (*P != Nil) {
        First(*L) = Next(*P);
        if (First(*L) != Nil) {
            Prev(First(*L)) = Nil;
        }
        Next(*P) = Nil;
        Prev(*P) = Nil;
    }
}

void DelP (List *L, infotype X) {
    address P = Search(*L, X);
    if (P != Nil) {
        if (P == First(*L)) {
            address temp;
            DelFirst(L, &temp);
            DeAlokasi(temp);
        } else if (Next(P) == Nil) {
            address temp;
            DelLast(L, &temp);
            DeAlokasi(temp);
        } else {
            Prev(Next(P)) = Prev(P);
            Next(Prev(P)) = Next(P);
            DeAlokasi(P);
        }
    }
}

void DelLast (List *L, address *P) {
    *P = First(*L);
    if (*P == Nil) return;
    while (Next(*P) != Nil) {
        *P = Next(*P);
    }
    if (Prev(*P) != Nil) {
        Next(Prev(*P)) = Nil;
    } else {
        First(*L) = Nil;
    }
    Prev(*P) = Nil;
}

void DelAfter (List *L, address *Pdel, address Prec) {
     *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        if (Next(*Pdel) != Nil) {
            Prev(Next(*Pdel)) = Prec;
        }
        Next(*Pdel) = Nil;
        Prev(*Pdel) = Nil;
    }
}

void PrintInfo (List L) {
    address P = First(L);
    if (ListEmpty(L)) {
        printf("List Kosong\n");
    } else {
        while (P != Nil) {
            printf("%s", Info(P).nama);
            if (Next(P) != Nil) {
                printf(" <-> ");
            }
            P = Next(P);
        }
        printf(" ->\n");
    }
}

void DelAll (List *L) {
     address PDel;
    while (!ListEmpty(*L)) {
        DelFirst(L, &PDel);
        DeAlokasi(PDel);
    }
}


