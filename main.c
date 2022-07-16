#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "mahasiswa.c"

//  UAS - 2501973722 - Kenneth William Noverianto

#define MxN 255
#define cls system("cls");
#define symbl printf("--> ");
#define enter printf("Tekan enter untuk melanjutkan...");

// Prototype function
void clear_buff();
void asciiArt();
void defaultInput();
void menu();
void tambahMahasiswa();
void displayMahasiswa();
void cariMahasiswa();
void keluar();

// Declare variable
BSTMahasiswa presensi = NULL;

int main () {
  int option;

  do {
    cls
    asciiArt();
    menu();
    printf("Pilih fitur!\n");
    symbl scanf("%d", &option); 
    clear_buff();

    switch (option) {
      case 1:
        tambahMahasiswa();
        break;

      case 2:
        displayMahasiswa();
        break;

      case 3: 
        cariMahasiswa();
        break;

      case 0:
        keluar();
        break;
      
      default:
        defaultInput();
        break;
    }

  } while (option != 0);

  return 0;
}

// Main function
void clear_buff() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
  };
}

void asciiArt() {
  printf("  _____                              _\n");
  printf(" |  __ \\                            (_)\n");
  printf(" | |__) | __ ___  ___  ___ _ __  ___ _ \n");
  printf(" |  ___/ '__/ _ \\/ __|/ _ \\ '_ \\/ __| |\n");
  printf(" | |   | | |  __/\\__ \\  __/ | | \\__ \\ |\n");
  printf(" |_|   |_|  \\___||___/\\___|_| |_|___/_|\n");
  printf("========================================\n");
}

void defaultInput() {
  cls
  asciiArt();
  printf("|             Invalid Input            |\n");
  printf("========================================\n\n");
  enter getchar();
}

void menu() {
  printf("| 1. Tambah Mahasiswa                  |\n");
  printf("| 2. Tampilkan Mahasiswa               |\n");
  printf("| 3. Cari Mahasiswa                    |\n");
  printf("| 0. EXIT                              |\n");
  printf("========================================\n");
}

void tambahMahasiswa() {
  cls
  asciiArt();

  char nama[MxN];
  char NIM[MxN];

  printf("Nama\t\t: "); scanf("%[^\n]", nama); clear_buff();
  printf("NIM\t\t: "); scanf("%s", NIM); clear_buff();
  BSTMahasiswa_Insert(&presensi, newDataMahasiswa(nama, NIM));

  printf("\nSelamat datang, %s\n", nama);
  enter getchar();
}

void displayMahasiswa() {
  cls
  asciiArt();

  if (&presensi->data != NULL) {
    BSTMahasiswa_Display(presensi);
    printf("----------------------------------------\n");
    printf("| Date : %s\t\t       |\n", __DATE__);
    printf("========================================\n\n");
  }
  else {
    printf("|                                      |\n");
    printf("|                 NULL                 |\n");
    printf("|                                      |\n");
    printf("========================================\n\n");
  }

  enter getchar();
}

void cariMahasiswa() {
  cls
  asciiArt();

  char NIM[MxN];

  if (&presensi->data != NULL) {
    printf("Input NIM yang ingin dicari!\n");
    symbl scanf("%s", NIM); clear_buff();
    BSTMahasiswa searching = BSTMahasiswa_Search(presensi, NIM);

    if (searching) {
      cls
      asciiArt();
      printf("Nama\t\t: %s\n", searching->data.name);
      printf("NIM\t\t: %s\n", searching->data.NIM);
      printf(
            "Waktu Hadir\t: %02d:%02d:%02d\n", 
            searching->data.time.hour, 
            searching->data.time.min, 
            searching->data.time.sec
      );
      printf("========================================\n\n"); 
      printf("Data mahasiswa berhasil ditemukan!\n");
    }
    else {
      cls
      asciiArt();
      printf("Maaf, mahasiswa dengan NIM : %s tidak ditemukan!\n", NIM);
    }
  }
  else {
    printf("|                                      |\n");
    printf("|                 NULL                 |\n");
    printf("|                                      |\n");
    printf("========================================\n\n");
  }

  enter getchar();
}

void keluar() {
  cls
  asciiArt();
  printf("|             Terima Kasih             |\n");
  printf("========================================\n\n");
}