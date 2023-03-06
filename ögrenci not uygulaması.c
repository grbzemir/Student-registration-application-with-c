#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int hesapla(int ogrencisayisi , int dersgecmenotu)
{
    int dizi[100];
    int i;
    int ortalama;
    int kalanogrencisayisi;
    int toplam=0;

    for(i=0;i<ogrencisayisi;i++)
    {
        printf("%d. ogrencinin notunu giriniz: \n", i+1);
        scanf("%d", &dizi[i]);
        toplam=toplam+dizi[i];
    }
    
    ortalama=toplam/ogrencisayisi;
    printf("sinif ortlaması: %d \n",ortalama);

    for(i=0;i<ogrencisayisi;i++)
    {
        if(dizi[i]<dersgecmenotu)
        
            kalanogrencisayisi++;
        }


    return kalanogrencisayisi;
}

int main () {
    int ogrencisayisi;
    int dersgecmenotu;
    int kalanogrencisayisi;

    system("color 0a");
    printf("lutfen ogrenci sayisini giriniz: \n");
    scanf("%d", &ogrencisayisi);

    if("ogrencisayisi < 0 || ogrencisayisi > 100")
    {
     printf("lutfen 0 ile 100 arasinda bir sayi giriniz: \n");
    }
    else
    {
    printf("gecme notu: ");
    scanf("%d", &dersgecmenotu);
    kalanogrencisayisi=hesapla(ogrencisayisi,dersgecmenotu);
    printf("kalan ogrenci sayisi: %d \n", kalanogrencisayisi);
    }

    return 0;
}
