#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct zbior_pytania
{
    char pytanie[100];
    char odpowiedz1[100];
    char odpowiedz2[100];
    char popOdp[100];
};

struct zle_odpowiedzi
{
    char zlePytanie[100];
    char zlaOdpowiedz[100];
    char poprawnaOdpowiedz[100];
};

int main()
{
    struct zle_odpowiedzi zo[10];
    char zlePytanie[100], zlaOdpowiedz[100], poprawnaOdpowiedz[100];
    int licznikZlych=0;
    int wygrywajaca, przegrywajaca1, przegrywajaca2;
    int odpowiedzUzytkownika, wynik=0;
    int losowaOdpowiedz, zbiorLosowaOdpowiedz[3];
    int losowePytanie, zbiorLosowePytania[10];
    srand(time(NULL));
    char cos[100];
    struct zbior_pytania zp[20];
    int zestaw=0;
    int akapity=1;
    char c, bufor[2600];
    char zmienna[100];
    char pytanie[100], popOdp[100], odpowiedz1[100], odpowiedz2[100];
    int a=0,b=0, i;
    FILE *fp;
    fp = fopen("pytania.txt", "r");
    if(fp==NULL){
        printf("Eror");
        exit(1);
    }
        while((c=fgetc(fp))!=EOF){
            bufor[a]=c;
            a++;
        }
		bufor[a] = '\0'; 

        while(b<=a && bufor[b]!='\0'){
            i=0;
            while(bufor[b]!='\n' && bufor[b]!='\0'){
                zmienna[i] = bufor[b];
                i++;
                b++;
            }
            zmienna[i] = '\0';
            if(zmienna[0]=='1'){
                //printf("%s", zmienna);
                strcpy(zp[zestaw].pytanie,zmienna);
            }
            if(zmienna[0]=='2'){
                //printf("%s", zmienna);
                strcpy(zp[zestaw].popOdp,zmienna);
            }
            if(zmienna[0]=='3'){
               // printf("%s", zmienna);
               strcpy(zp[zestaw].odpowiedz1,zmienna);
            }
            if(zmienna[0]=='4'){
               // printf("%s", zmienna);
               strcpy(zp[zestaw].odpowiedz2,zmienna);
               zestaw++;
            }

            if(bufor[b]=='\n'){
                akapity++;
            }

            b++;
        }
    
    for(int n=0;n<10;n++){
        int unikat;
        do{
            losowePytanie = rand()%20;
            unikat=1;
            for(int k=0;k<n;k++){
                if(zbiorLosowePytania[k]==losowePytanie){
                    unikat = 0;
                }
            }
        }
        while(!unikat);
        zbiorLosowePytania[n]=losowePytanie;
    }
    printf("\n");

    for(int n=0;n<10;n++){
        printf("%s\n", zp[zbiorLosowePytania[n]].pytanie);
    }



       if(cos_losujacego==0){
                printf("%s\n", zp[zbiorLosowePytania[n]].popOdp);
            }
            if(cos_losujacego==1){
                printf("%s\n", zp[zbiorLosowePytania[n]].odpowiedz1);
            }
            if(cos_losujacego==2){
            printf("%s\n", zp[zbiorLosowePytania[n]].odpowiedz2);
            }

      for(i=0;i<3;i++){
            zbiorLosowaOdpowiedz[i]=i;
            }

            for(i=0;i<3;i++){
            int temp = zbiorLosowaOdpowiedz[i];
            int randomIndex = rand()%3;

            zbiorLosowaOdpowiedz[i]=zbiorLosowaOdpowiedz[randomIndex];
            zbiorLosowaOdpowiedz[randomIndex] = temp;


            }



     for(int k=0;k<3;k++){
            if(zbiorLosowaOdpowiedz[k]==0){
                printf("%s\n", zp[n].popOdp);
                wygrywajaca=k;
            }
            if(zbiorLosowaOdpowiedz[k]==1){
                printf("%s\n", zp[n].odpowiedz1);
                przegrywajaca1=k;
            }
            if(zbiorLosowaOdpowiedz[k]==2){
                printf("%s\n", zp[n].odpowiedz2);
                przegrywajaca2=k;
            }
        }
        
        printf("Podaj numer odpowiedzi (1-3)");
        scanf("%d", &odpowiedzUzytkownika);
       if(odpowiedzUzytkownika==wygrywajaca){
            wynik++;
        }else if(odpowiedzUzytkownika==przegrywajaca1){
            strcpy(zo[licznikZlych].zlePytanie,zp[n].pytanie);
            strcpy(zo[licznikZlych].zlaOdpowiedz,zp[n].odpowiedz1);
            strcpy(zo[licznikZlych].poprawnaOdpowiedz,zp[n].popOdp);
            licznikZlych++;
        }else if(odpowiedzUzytkownika==przegrywajaca2){
            strcpy(zo[licznikZlych].zlePytanie,zp[n].pytanie);
            strcpy(zo[licznikZlych].zlaOdpowiedz,zp[n].odpowiedz1);
            strcpy(zo[licznikZlych].poprawnaOdpowiedz,zp[n].popOdp);
            licznikZlych++;
        }
    }
   float procentowo = (wynik/10);
    printf("Osiagnales %d punktow! procentowo to %f", wynik, procentowo);
    printf("Pytania na ktore odpowiedziales zle, twoja odpowiedz oraz poprawna odpowiedz:");
    for(i=0;i<=licznikZlych;i++){//albo < albo <=
        printf("%s\n", zo[i].zlePytanie);
        printf("%s\n", zo[i].zlaOdpowiedz);
        printf("%s\n", zo[i].poprawnaOdpowiedz);
    }
    fclose(fp);
    return 0;
}