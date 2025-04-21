#include <iostream>
#include <string>
#include <vector>
#include <format>
#include "Dosen.h"
#include "Mahasiswa.h"
#include "Kelas.h"

int main() {
    Dosen dosenAlprog("Mr. Budi", 10), dosenSisben("Mr. Thomas", 11), dosenMatdis("Ms. Puff", 12), dosenFislis("Ms. Sandy", 13);
    Kelas alprog("Algoritma Pemrograman", 3.8, 3, dosenAlprog), sisben("Sistem Benam", 3.5, 3, dosenSisben), matdis("Matematika Diskrit", 4, 3, dosenMatdis), fislis("Fisika Listrik", 3.6, 2, dosenFislis);
    Mahasiswa m("Seorang Mahasiswa", 69420, {alprog, sisben, matdis, fislis}, ELEKTRO);
    m.showDetail();
    return 0;
}
