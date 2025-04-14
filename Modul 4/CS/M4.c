#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Peminjam
{
    char nama[32];
    char alamat[64];
    char telp[16];
    float pinjaman;
    float bunga;
    float tagihan;
} Peminjam;

void create(int jumlahPeminjam,Peminjam list[]) {
    for(int i=0;i<jumlahPeminjam;i++){
    Peminjam p;

    printf("\nNama Peminjam %d: ", i+1);
    fgets(p.nama, 32, stdin);
    p.nama[strcspn(p.nama, "\n")] = '\0';

    printf("Alamat Peminjam %d: ", i+1);
    fgets(p.alamat, 64, stdin);
    p.alamat[strcspn(p.alamat, "\n")] = '\0';
    
    printf("No Telp Peminjam %d: ", i+1);
    fgets(p.telp, 16, stdin);
    p.telp[strcspn(p.telp, "\n")] = '\0';

    printf("Pinjaman Peminjam %d: ", i+1);
    scanf("%g",&p.pinjaman);

    printf("Bunga Peminjam %d: ", i+1);
    scanf("%g",&p.bunga);

    p.tagihan = p.pinjaman+(p.pinjaman*p.bunga);

    list[i] = p;
    while ((getchar()) != '\n');

    
    }
    return ;
}

void display(Peminjam p) {
    printf("\nNama - Alamat : %s - %s\n", p.nama, p.alamat);
    printf("Telp: %s\n", p.telp);
    printf("Pinjaman - Rate Bunga : Rp %.2f - %.0f %% \n",p.pinjaman,p.bunga*100);
    printf("Tagihan Bulan Ini : %.2f\n", p.tagihan);
}

int main(){

    int numberOfBorrowers; 
    printf("Jumlah Peminjam: ");
    scanf("%d",&numberOfBorrowers);
    while ((getchar()) != '\n');

    Peminjam *list = (Peminjam*)malloc(numberOfBorrowers * sizeof(Peminjam));

    create(numberOfBorrowers,list);

    while(1){
        for(int i=0;i<numberOfBorrowers;i++){
            display(list[i]);
        }
        printf("\nDatabase Pinjol\n---------------\n");
        printf("a. Hitung total tagihan\nb. Tagihan semua orang +500 ribu\nc. Tagihan semua orang -500 ribu\nd. Exit Program\n\n");
        char option;
        scanf("%c", &option);
        while ((getchar()) != '\n');
        switch (option)
        {
        case 'a':
            printf("Total Tagihan %d Peminjam:\n",numberOfBorrowers);
            float total = 0;
            for (int i = 0; i < numberOfBorrowers; i++) {
                total += list[i].pinjaman + (list[i].pinjaman * list[i].bunga / 100);
            }
            printf("Rp %.1f\n",total);
            break;
        case 'b':
        for(int i=0;i<numberOfBorrowers;i++){
            list[i].pinjaman+=500000;
        }
            break;
        case 'c':
        for(int i=0;i<numberOfBorrowers;i++){
            list[i].pinjaman-=500000;
        }
            break;
        case 'd':
            printf("Program Selesai!");
            return 0;
        default:
            break;
        }
    }
    return 0;   
}