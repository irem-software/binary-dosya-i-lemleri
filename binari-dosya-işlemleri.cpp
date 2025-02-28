#include <iostream>
#include <fstream>

struct ogrenci
{
    char isim[20];
    int yas;
    float notu;
};

int main()
{
    ogrenci ogr1 = {"ahmet", 21, 85.5};

    // binary dosyayı yazma
    std::ofstream dosya("ogrenci.dat", std::ios::binary);
    dosya.write(reinterpret_cast<char *>(&ogr1), sizeof(ogrenci));
    dosya.close();

    // binary dosyadan okuma

    ogrenci ogr2;
    std::ifstream dosyaoku("ogrenci.dat", std::ios::binary);
    dosyaoku.read(reinterpret_cast<char *>(&ogr2), sizeof(ogrenci));
    dosyaoku.close();

    std::cout << "isim: " << ogr2.isim << ", yaş: " << ogr2.yas << ", not: " << ogr2.notu << std::endl;
    return 0;
}
