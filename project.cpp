// This is my first project .
// ALGORİTMA 2 PROJE ÖDEVİ - GİYİM MAGAZASI OTOMASYONU **

#include <iostream> // giriş çıkış fonk.
#include <fstream> //dosyalama işlemleri
#include <cstring> //string işlemler
#include <iomanip> // setw() komutları
using namespace std;

void menu();
void cleanscreen();
void duraksama();

void personelsil();
void beforepersonelupdate();
void personelara();
void personelistele();

void urunsil();
void beforeurunupdate();
void urunara();
void urunlistele();

class personel
{
	public:
		long long tcno;
		string ad;
		string soyad;
		int dogumyil;
		long long telno;
		
		void personelekle()
		{
			cout<<"Personelin tc kimlik no'su: \n>";
			cin>>tcno;
			cout<<"Personelin adi: \n>";
			cin>>ad;
			cout<<"Personelin soyadi: \n>";
			cin>>soyad;
			cout<<"Personelin dogum yili: \n>";
			cin>>dogumyil;
			cout<<"Personelin telefon numarasi: \n>";
			cin>>telno;
			
			ofstream personelEkle;
			personelEkle.open("personel.txt",ios::app);
			personelEkle<<tcno<<" "<<ad<<" "<<soyad<<" "<<dogumyil<<" "<<telno<<endl;
			personelEkle.close();		
		}
	
	
	
}p[20];

class urun
{
	public:
		int serino;
		string tur;
		string renk;
		string beden;
		int fiyat;//tl cinsinden 
		
		void urunekle()
		{
			cout<<"Urunun seri no'su (7 hane) : \n>";
			cin>>serino;
			cout<<"Urunun turu (ornek -> kazak,pantolon,tshirt) : \n>";
			cin>>tur;
			cout<<"Urunun rengi: \n>";
			cin>>renk;
			cout<<"Urunun bedeni (ornek -> small,medium,large) : \n>";
			cin>>beden;
			cout<<"Urunun fiyati (TL cinsinden) : \n>";
			cin>>fiyat;
			
			ofstream urunEkle;
			urunEkle.open("urun.txt",ios::app);
			
			urunEkle<<serino<<" "<<tur<<" "<<renk<<" "<<beden<<" "<<fiyat<<endl;
			
			urunEkle.close();
		}
	
}k[25];

bool isTCExist=false;
bool isSeriExist=false;
int choose;

int main() {
	
	int sayac=0;
	int sayac2=0;
	
	for(;;)
	{
		isTCExist=false;
		cleanscreen();
		cout<<"** Giyim Magazasi Otomasyonu **"<<endl<<endl;
	
		menu();
		
		switch(choose)
		{
			case 1:
			{
				cleanscreen();
				p[sayac].personelekle();
				sayac++;
				duraksama();
				break;
			}
			
			case 2:
			{
				cleanscreen();
				personelsil();
				duraksama();
				break;
			}
			
			case 3:
			{
				cleanscreen();
				beforepersonelupdate();
				if(isTCExist==true)
				{
					p[sayac].personelekle();
					sayac++;
				}
				duraksama();
				break;
			}
			
			case 4:
			{
				cleanscreen();
				personelara();
				duraksama();
				break;
			}
			
			case 5:
			{
				cleanscreen();
				personelistele();
				duraksama();
				break;
			}
			
			case 6:
			{
				cleanscreen();
				k[sayac2].urunekle();
				sayac2++;
				duraksama();
				break;
			}
			
			case 7:
			{
				cleanscreen();
				urunsil();
				duraksama();
				break;
			}
			
			case 8:
			{
				cleanscreen();
				beforeurunupdate();
				if(isSeriExist==true)
				{
					k[sayac2].urunekle();
					sayac2++;
				}
				duraksama();
				break;
			}
			
			case 9:
			{
				cleanscreen();
				urunara();
				duraksama();
				break;
			}
			
			case 10:
			{
				cleanscreen();
				urunlistele();
				duraksama();
				break;
			}
			
			case 11:
			{
				cleanscreen();
				cout<<"Programdan basariyla cikis yapiliyor..!";
				return 0;
				break;
			}
			
			default:
			{
				cleanscreen();
				cout<<"Yanlis secim yaptiniz.";	
				duraksama();
			}	
			
		}
	}
}


void menu()
{
	cout<<"1-  Personel Ekle"<<endl;
	cout<<"2-  Personel Sil"<<endl;
	cout<<"3-  Personel Guncelle"<<endl;
	cout<<"4-  Personel Ara"<<endl;
	cout<<"5-  Personel Listele"<<endl<<endl;
	cout<<"6-  Urun Ekle"<<endl;
	cout<<"7-  Urun Sil"<<endl;
	cout<<"8-  Urun Guncelle"<<endl;
	cout<<"9-  Urun Ara"<<endl;
	cout<<"10- Urun Listele"<<endl<<endl;
	cout<<"11- Programdan Cik!"<<endl<<endl;
	cout<<"Lutfen bir islem seciniz: ";
	cin>>choose;
	cout<<endl<<endl;
}

void cleanscreen()
	{
		system("cls");
	}
	
void duraksama()
{
	cout<<endl<<endl;
	cout<<"Devam etmek icin herhangi bir tusa basiniz !.."<<endl;
	system("pause");
}

void personelsil()
{
	ifstream personelSil;
	ofstream temp;
	
	string okunan1;
	char okunan2[11];
	char deLtc[11];
	char deneme[5];
	gets(deneme);
	
	cout<<"Silmek istediginiz personelin tc no'sunu giriniz: \n>";
	gets(deLtc);
	
	personelSil.open("personel.txt",ios::app);
	temp.open("temp.txt",ios::app);
	
	while(!personelSil.eof())
	{
		getline(personelSil,okunan1);
		
		for(int i=0;i<11;i++)
		{
			okunan2[i]=okunan1[i];
		}
		
		if(strcmp(okunan2,deLtc)==0)
		{
			isTCExist=true;
			continue;
		}
		else
		{
			temp<<okunan1<<endl;
		}
	}
	
	temp.close();
	personelSil.close();
	if(isTCExist==false)
	{
		cout<<"Boyle bir tc kimlik no bulunamadi !";
		remove("temp.txt");
	}
	else
	{
		remove("personel.txt");//txt silme işlemi
		rename("temp.txt","personel.txt");//txt isim değiştirme işlemi
	
		cout<<"Sectiginiz personel basariyla silindi !..";	
	}
}

void beforepersonelupdate()
{
	cout<<"NOT: Degistirmek istemediginiz bilgileri aynen giriniz !.."<<endl<<endl;
	ifstream personelSil;
	ofstream temp;
	
	string okunan1;
	char okunan2[11];
	char deLtc[11];
		
	char deneme[5];
	gets(deneme);
	
	cout<<"Bilgilerini guncellemek istediğiniz personelin tc no'sunu giriniz: \n>";
	gets(deLtc);
		
	personelSil.open("personel.txt",ios::app);
	temp.open("temp.txt",ios::app);
	
	while(!personelSil.eof())
	{
		getline(personelSil,okunan1);
			
		for(int i=0;i<11;i++)
		{
			okunan2[i]=okunan1[i];
		}
		
		if(strcmp(okunan2,deLtc)==0)
		{
			isTCExist=true;
			continue;
		}
		else
		{
			temp<<okunan1<<endl;
		}
	}
	temp.close();
	personelSil.close();
	
	if(isTCExist==false)
	{
		cout<<"Boyle bir tc kimlik no bulunamadi !";
		remove("temp.txt");
	}
	else
	{
		remove("personel.txt");//txt silme işlemi
		rename("temp.txt","personel.txt");//txt isim değiştirme işlemi
	}
}

void personelara()
{
	isTCExist=false;
	string searchtc;
	string okunan;
	ifstream personelAra;
	personelAra.open("personel.txt",ios::app);
	cout<<"Goruntulemek istediginiz personelin tc no'sunu giriniz: \n>";
	cin>>searchtc;
	cout<<endl;
	while(!personelAra.eof())
	{
		personelAra>>okunan;
		if(okunan==searchtc)
		{
			getline(personelAra,okunan);
			cout<<"AD  "<<"SOYAD  "<<"DOGUM YILI  "<<"TEL NO"<<endl<<endl;
			cout<<okunan;
			break;
		}
	}
	personelAra.close();
	if(isTCExist==false)
	{
		cout<<"Boyle bir tc kimlik no bulunamadi.";	
	}	
}

void personelistele()
{
	string okunan;
	ifstream personeListele;
	personeListele.open("personel.txt",ios::app);
	cout<<"TC NO       "<<"AD  "<<"SOYAD  "<<"DOGUM YILI "<<"TEL NO"<<endl<<endl;
	while(!personeListele.eof())
	{
		getline(personeListele,okunan);
		cout<<okunan<<endl;
	}
	personeListele.close();
}
	
void urunsil()
{
	ifstream urunSil;
	ofstream temp;
		
	string okunan3;
	char okunan4[7];
	char deLserino[7];
	
	char deneme2[5];
	gets(deneme2);
	cout<<"Silmek istediginiz urunun seri no'sunu giriniz: \n>";
	gets(deLserino);
	cout<<endl;
	urunSil.open("urun.txt",ios::app);
	temp.open("temp.txt",ios::app);
		
	while(!urunSil.eof())
	{
		getline(urunSil,okunan3);
			
		for(int i=0;i<7;i++)
		{
			okunan4[i]=okunan3[i];
		}
			
		if(strcmp(okunan4,deLserino)==0)
		{
			isSeriExist=true;
			continue;
		}
		else
		{
			temp<<okunan3<<endl;
		}
	}
		
	temp.close();
	urunSil.close();
	
	if(isSeriExist==false)
	{
		cout<<"Boyle bir seri no bulunamadi !";
		remove("temp.txt");
	}
	else
	{
		remove("personel.txt");//txt silme işlemi
		rename("temp.txt","personel.txt");//txt isim değiştirme işlemi
	
		cout<<"Sectiginiz urun basariyla silindi !..";	
	}
}
	
void beforeurunupdate()
{
	cout<<"NOT: Degistirmek istemediginiz bilgileri aynen giriniz !.."<<endl<<endl;
	ifstream urunSil;
	ofstream temp;
		
	string okunan3;
	char okunan4[7];
	char deLserino[7];
	
	char deneme2[5];
	gets(deneme2);
	
	cout<<"Bilgilerini degistirmek istediginiz urunun seri no'sunu giriniz: \n>";
	gets(deLserino);
	cout<<endl;
	urunSil.open("urun.txt",ios::app);
	temp.open("temp.txt",ios::app);
		
	while(!urunSil.eof())
	{
		getline(urunSil,okunan3);
			
		for(int i=0;i<7;i++)
		{
			okunan4[i]=okunan3[i];
		}
			
		if(strcmp(okunan4,deLserino)==0)
		{
			isSeriExist=true;
			continue;
		}
		else
		{
			temp<<okunan3<<endl;
		}
	}
		
	temp.close();
	urunSil.close();
		
	if(isSeriExist==false)
	{
		cout<<"Boyle bir seri no bulunamadi !";
		remove("temp.txt");
	}
	else
	{
		remove("personel.txt");//txt silme işlemi
		rename("temp.txt","personel.txt");//txt isim değiştirme işlemi
	}
}
	
void urunara()
{
	string searchserino;
	string okunan;
	ifstream urunAra;
	urunAra.open("urun.txt",ios::app);
	cout<<"Goruntulemek istediginiz urunun seri no'sunu giriniz: \n>";
	cin>>searchserino;
	cout<<endl;
	while(!urunAra.eof())
	{
		urunAra>>okunan;
		if(okunan==searchserino)
		{
			isTCExist=true;
			getline(urunAra,okunan);
			cout<<"TUR "<<"RENK "<<"BEDEN "<<"FIYAT(TL)"<<endl;
			cout<<okunan;
			break;
		}
	}
	urunAra.close();
	if(isTCExist==false)
	{
		cout<<"Boyle bir seri no bulunamadi.";	
	}	
}
	
void urunlistele()
{
	string okunan;
	ifstream urunListele;
	urunListele.open("urun.txt",ios::app);
	cout<<"SERI NO "<<" TUR "<<"RENK "<<"BEDEN "<<"FIYAT(TL)"<<endl<<endl;
	while(!urunListele.eof())
	{
		getline(urunListele,okunan);
		cout<<okunan<<endl;
	}
	urunListele.close();	
}
	
	




