#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stddef.h>


 /* 
 1) Bir sınıftaki öğrencilerin numarası,adı,vize notu ve final notu üzerinden çeşitli işlemelr yapabilecek bir program yazalım
 a) program ana menü ile acılcak. Menüde olacak secenekeler su şekildedir:
 1-Yeni Kayıt ekleme
 2-Kayıt listeleme
 3-Kayıt Güncelleme
 4-Sınıf ortalamasını hesapla
 5-ortalamaya göre en başarılı ögrenci bilgisin göster
 b) program hafızdana minimum miktarda alan tüketmelidir.bunun için dinamik hafizayı kullan
 c) kayıt güncelleme öğrenci numarasına göre olacak .
 */


struct Ogrenci {
    int numara;
    char ad[20];
    int vize;
    int final;
};


void yenikayit(struct Ogrenci *ptr , int n)
{
    int numara;
    char ad[20];
    int vize;
    int final;
    int i=0;
    printf("yeni kayit eklenecek ogrenci bilgilerini giriniz: \n");
    while(i<n)
    {
        printf("%d. ogrenci bilgilerini giriniz: \n",i+1);
        printf("numara: ");
        scanf("%d", &numara);
        printf("ad: ");
        scanf("%s", ad);
        printf("vize: ");
        scanf("%d", &vize);
        printf("final: ");
        scanf("%d", &final);

        ptr->numara = numara;
        strcpy( ptr->ad, ad);
        ptr->vize = vize;
        ptr->final = final;

        i++;
        ptr++;

    }

printf("kayit islemi tamamlandı \n");

}

void kayitlistele(struct Ogrenci *ptr , int n)
{

system("cls");
int i=0;
while( i<n )
{
    printf("%d. numarali ogrenci bilgileri: \n",ptr->numara);
    printf("ad:   %s \n",ptr->ad);
    printf("vize: %d \n",ptr->vize);
    printf("final:%d \n",ptr->final);
    printf("**************************************** \n");

    i++;
    ptr++;
}
    printf("listeleme islemi tamamlandı \n");

}


void kayitguncelle(struct Ogrenci *ptr , int n)
{
    int numara;
    char ad[20];
    int vize;
    int final;
    int i=0;
    printf("kaydi guncellenecek ogrencinin numarasini giriniz: ");
    scanf("%d", &numara);

    while( i<n )
    {
        int sonuc=0;
        if(numara==ptr->numara)
    {
        printf("%d. numaralı ogreni bilgilerini girinz: \n",numara);
        printf("ad: ");
        scanf("%s", ad);
        printf("vize: ");
        scanf("%d", &vize);
        printf("final: ");
        scanf("%d", &final);

        ptr->numara = numara;
        strcpy( ptr->ad, ad);
        ptr->vize = vize;
        ptr->final = final;
        sonuc=1;
        break;

    }
        if( sonuc == 0)
        printf("%d numarali ogrenci listede yokt ",numara);
        i++;
        ptr++;
    
    }
    printf("kayit islemi tamamlandı \n");
}
 void ortalamahesapla(struct Ogrenci *ptr , int n)
{
    system("cls");
    int i=0;
    float ortalama=0;
    int toplam=0;
    int sonortalama;
    while (i<n)
    {
        ortalama=ptr->vize*0.4+ptr->final*0.6;
        toplam=toplam+ortalama;
        i++;
        ptr++;
    }
    sonortalama=toplam/n;
    printf("sinif ortalamasi: %d \n",sonortalama);
}

void enbasariliogrenciyibul(struct Ogrenci *ptr , int n)
{
    system("cls");
    int numara;
    char ad[20];
    int vize;
    int final;
    int i=0;
    int buyuk=0;
    int ortalama;
    while(i<n)
    {
        ortalama=ptr->vize*0.4+ptr->final*0.6;
        if(ortalama>buyuk)
        {
            buyuk=ortalama;
            numara=ptr->numara;
            strcpy(ad,ptr->ad);   
            ortalama=buyuk;         
        }
        i++;
        ptr++;
    }

    printf("en basarili ogrenci bilgileri: \n");
    printf("numara: %d \n",numara);
    printf("ad:     %s \n",ad);
    printf("ortalama: %d \n",buyuk);
    printf("**************************************** \n");

}


int menu()
{


    
    int secim;

    printf("1-Yeni Kayit ekleme \n");
    printf("2-Kayit listeleme \n");
    printf("3-Kayit Güncelleme \n");
    printf("4-Sinif ortalamasını hesapla \n");
    printf("5-ortalamaya göre en başarılı ögrenci bilgisin göster \n");
    printf("6-cıkıs \n");
    printf("Seçiminiz: ");
    scanf("%d", &secim);
    
 
    return secim;
}



int main ()
{   
   
    int secim;
    int n;
    printf("kac ogrenci kaydi yapilacak: ");
    scanf("%d", &n);

    struct Ogrenci *ogrptr=(struct Ogrenci *) malloc(n* sizeof(struct Ogrenci));
    struct ogrenci *ptr=ogrptr;

  

    secim=menu();
     
    while(secim!=0)
    {
        if(secim==1)
        yenikayit(ptr,n);
        else if(secim==2)
        kayitlistele(ptr,n);
        else if(secim==3)
        kayitguncelle(ptr,n);
        else if(secim==4)
        ortalamahesapla(ptr,n);
        else if(secim==5)
        enbasariliogrenciyibul(ptr,n);
        else if(secim==6)
        exit(0);
        else
        printf("yanlis secim yaptiniz \n");  
        
        secim=menu();
    }



    return 0;
}


