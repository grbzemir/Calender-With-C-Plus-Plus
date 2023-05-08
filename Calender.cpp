#include<iostream>
#include<conio.h>
#include<iomanip>
#include<time.h>

using namespace std;

void AylariYazdir(int yil)

{

    int time[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
    int mGunler[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
    string AyListesi[] = { "Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran", "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik" }; 

    cout<<"  --------------------------------"<<endl;
    cout<<"           Tarihler - "<<yil<<endl;
    cout<<"  --------------------------------"<<endl<<endl;
    
    int gunler;
    int zaman; 

    int y = yil -1;  

    zaman = (y +y/4 - y/100 + y/400 + time[0]+1) % 7; // Ocak ayi icin 

    for(int i=0;i<12;i++) // 12 ay icin

    {

        if(i==1) // Subat ayi icin

        {

            if(yil%400==0 || (yil%4==0 && yil%100!=0)) // Artik yil kontrolu

            {

                gunler = 29; // Artik yil icin

            }

            else

            {

                gunler = 28; // Normal yil icin

        }

        }

        else

        {

            gunler = mGunler[i]; // Normal ay icin



    }

    cout<<"  "<<AyListesi[i]<<endl;
    cout<<"  ----------------"<<endl;
    cout<<"  Paz  Pzt  Sal  Csr  Per  Cum  Cmt"<<endl;

    int k;

    for(k=0;k<zaman;k++) // Ayin baslangic gunu icin bosluklar

    {

        cout<<"     ";

    }

    for(int j=1;j<=gunler;j++) // Ayin gunleri

    {
         
        k++;
        cout<<setw(5)<<j;

        if(k>6) // Haftanin son gunu icin

        {

            k=0;

            cout<<endl;

        }

    
}

    if(k) // Haftanin son gunu degilse

    

        cout<<endl;

        zaman = k;

    }

    return ;
    

}

 int main()

 {

    system("color 0A");
    system("cls");

    time_t ttime = time(0);
	tm *local_time = localtime(&ttime);
	
	int yil = 1900 + local_time->tm_year; 
	char secim;
	
	do

    {
		system("cls");
		AylariYazdir(yil);
		
		cout<<endl<<endl;
		cout<<"Basss "<<endl;
		cout<<"- n Bir Sonraki Yil"<<endl;
		cout<<"- p Onceki Yil Icin"<<endl;
		cout<<"- C Cikis"<<endl;
		secim = getche();

		switch(secim)
        
        {
			case 'n':
				yil++;
				break;

			case 'p':
				yil--;
				break;

		}
			
	}
    
    while(secim!='c' && secim!='C');	 	
 	
    return 0;

}


