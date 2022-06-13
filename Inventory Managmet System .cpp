#include <iostream>
#include <fstream>
#include <string>            // Programi kullanmak icin gerekli k�t�phaneler
#include <Windows.h>
using namespace std;
void anaMenu()//ana menu secim ekrani
{

	cout << "<-------------- ANA MENU ------------------>" << endl;
	cout << endl;
	cout << endl;
	cout << "Lutfen Yapmak Istediginiz Islemi Seciniz!" << endl;
	cout << endl;
	cout << endl;
	cout << "1-Urun Islemleri" << endl;
	cout << "2-Musteri Islemleri" << endl;
	cout << "3-Siparis Islemleri" << endl;
	cout << "4-Cikis" << endl;
}
void urunMenu()//urun menusu secim ekrani
{
	cout << "<----------------- Urun Islemleri Menusu ------------------->" << endl;
	cout << endl;
	cout << endl;
	cout << "Lutfen Yapmak Istediginiz Islemi Seciniz!" << endl;
	cout << endl;
	cout << endl;
	cout << "1-Urun Ekleme" << endl;
	cout << "2-Urun Arama" << endl;
	cout << "3-Urun Listeleme" << endl;
	cout << "4-Urun Duzeltme" << endl;
	cout << "5-Urun Silme" << endl;
}
void musteriMenu()//musteri menusu secim ekrani
{
	cout << "<----------- Musteri Islemleri Menusu -------->" << endl;
	cout << endl;
	cout << endl;
	cout << "Lutfen Yapmak Istediginiz Islemi Seciniz!" << endl;
	cout << endl;
	cout << endl;
	cout << "1-Musteri Ekle" << endl;
	cout << "2-Musteri Arama" << endl;
	cout << "3-Musteri Duzeltme" << endl;
	cout << "4-Musteri Silme" << endl;
}
void siparisMenu()//siparis menusu secim ekrani
{
	cout << "<----------- Siparis Islemleri Menusu --------->" << endl;
	cout << endl;
	cout << endl;
	cout << "Lutfen Yapmak Istediginiz Islemi Seciniz!" << endl;
	cout << endl;
	cout << endl;
	cout << "1-Siparis Olustur" << endl;
	cout << "2-Siparis Arama" << endl;
	cout << "3-Siparis Silme" << endl;
	cout << "4-Siparis Duzeltme" << endl;
	cout << "5-Siparis Raporlama" << endl;
}
void siparisMenualt()//siparis raporlama menusu
{
	cout << "<---------------- Siparis Raporlama Menusu---------------->" << endl;
	cout << endl;
	cout << endl;
	cout << "Lutfen Raporlamak Istediginiz Turu Seciniz" << endl;
	cout << "1-Urun Koduna Gore Raporlama" << endl;
	cout << "2-Firma No'ya Gore Raporlama" << endl;
}
int main()
{

	//Urun.txt icerisinde kullanilan degiskenler
	string urunKodu;
	string urunAdi;
	string urunUreticisi;
	string urunTeminsuresi;
	double urunFiyatgenel;
	double urunFiyatozel;
	string urunKdvorani;
	int urunStokadedi;


	//Cari.txt icerisinde kullanilan degiskenler
	string firma_No;
	string firma_Adi;
	string firma_Tel;
	string firma_Sorumlusu;
	string firma_Musterikatagorisi;
	string firma_Adres;


	//siparis.txt icerisnde kullanilan degiskenler
	string firmaNo;
	string siparis_Tarihi;
	double siparis_Tutari;
	string siparisi_Alan;
	string urun_Adedi;
	string urun_Kodu;
	
	// program kullanimi icin gerekli degiskenlerin tanimlanmasi
	ofstream dosyaYaz;
	ifstream dosyaOku;
	int secim_anaMenu;
	int secim_urunMenu;
	int secim_musteriMenu;
	int secim_siparisMenu;
	int secim_siparisMenualt;
	char secim_musteri;
	char secim_urun = 'e';
	char secim_siparis;
	do
	{
		system("cls");
		anaMenu();
		cin >> secim_anaMenu;


		if (secim_anaMenu == 1)
		{
			system("cls");
			urunMenu();
			cin >> secim_urunMenu;

			if (secim_urunMenu == 1)// urun eklemek icin kullanilan kod satiri
			{


				system("cls");
				string urun_Kontrol; // kontrol amaciyla eklenen degiskenler
				int counter = 0;
				ofstream dosyaYaz("urun.txt", ios::app); // urun.txt dosyasinin ekleme modunda yaritlmasi 
				ifstream dosyaOku("urun.txt");//urun.txt dosyasinin okunmasi
				cout << "Lutfen Urun Kontrolu Icin Eklemek Istediginiz Urunun Kodunu Giriniz" << endl;
				cin >> urun_Kontrol;
				while (!dosyaOku.eof())//urun.txt dosaysinin iceriginin okunmasi
				{
					dosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminsuresi >> urunFiyatgenel >> urunFiyatozel >> urunKdvorani >> urunStokadedi;
					if (urun_Kontrol == urunKodu)// urun.txt dosyasinin icerisndeki verilerle eklenmek istenen verilerin kontrolu
					{
						cout << "Boyle Bir Urun Zaten Ekli!" << endl;
						counter++;

					}
				}
				if (counter == 0)//urun ekleme
				{
					

					system("cls");
					cout << "Lutfen Klavyeden Deger Girerken Bosluk Ve Nokta Kullanmayiniz!!" << endl;
					cout << "\nUrun Kodu: "; cin >> urunKodu;
					cout << "\nUrun Adi: "; cin >> urunAdi;
					cout << "\nUrun Ureticisi: "; cin >> urunUreticisi;
					cout << "\nUrun Temin Suresi: "; cin >> urunTeminsuresi;
					cout << "\nUrun Fiyati(Genel Musteri): "; cin >> urunFiyatgenel;
					cout << "\nUrun Fiyati(Ozel Musteri: "; cin >> urunFiyatozel;
					cout << "\nUrun KDV Orani: "; cin >> urunKdvorani;
					cout << "\nUrun Stok Adedi: "; cin >> urunStokadedi;
					dosyaYaz << urunKodu << " " << urunAdi << ' ' << urunUreticisi << ' ' << urunTeminsuresi << ' ' << urunFiyatgenel << ' ' << urunFiyatozel << ' ' << urunKdvorani << ' ' << urunStokadedi << "\n";
					cout << endl;
					cout << "Urun Basariyla Eklenmistir!" << endl;
					cout << endl;
					

				}
				dosyaYaz.close();
				dosyaOku.close();

				break;

			}
			if (secim_urunMenu == 2)//urun sorgulama kod blogu
			{
				system("cls");
				string urun_Sorgu;
				ofstream dosyaYaz("urun.txt", ios::app);
				ifstream dosyaOku("urun.txt");
				int counter = 0;
				cout << "Lutfen Sorgulamak Istediginiz Urun Kodunu Giriniz" << endl;
				cin >> urun_Sorgu;
				while (!dosyaOku.eof())//urun.txt dosyasinin verilerinin okunup istenilen koda g�re  ekrana yazdirilmasi
				{
					dosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminsuresi >> urunFiyatgenel >> urunFiyatozel >> urunKdvorani >> urunStokadedi;
					if (urun_Sorgu == urunKodu)
					{
						system("cls");
						cout << "\nUrun Kodu: " << urunKodu << endl;
						cout << "\nUrun Adi: " << urunAdi << endl;
						cout << "\nUrun Ureticisi: " << urunUreticisi << endl;
						cout << "\nUrun Temin Suresi: " << urunTeminsuresi << endl;
						cout << "\nUrun Fiyati(Genel Musteri): " << urunFiyatgenel << endl;
						cout << "\nUrun Fiyati(Ozel Musteri: " << urunFiyatozel << endl;
						cout << "\nUrun KDV Orani: " << urunKdvorani << endl;
						cout << "\nUrun Stok Adedi: " << urunStokadedi << endl;
						counter++;
						
					}
					
					

				}
				if (counter == 0) { cout << "Boyle Bir Urun Bulunamadi!!" << endl; break; }

			}
			if (secim_urunMenu == 3)//urun listeleme kod blogu
			{
				system("cls");
				ifstream dosyaOku("urun.txt");
				while (!dosyaOku.eof())//urun.txt dosaysinin verilerinin okunup ekrana yazdirilmasi
				{
					dosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminsuresi >> urunFiyatgenel >> urunFiyatozel >> urunKdvorani >> urunStokadedi;

					cout << "\nUrun Kodu: " << urunKodu << endl;
					cout << "\nUrun Adi: " << urunAdi << endl;
					cout << "\nUrun Ureticisi: " << urunUreticisi << endl;
					cout << "\nUrun Temin Suresi: " << urunTeminsuresi << endl;
					cout << "\nUrun Fiyati(Genel Musteri): " << urunFiyatgenel << endl;
					cout << "\nUrun Fiyati(Ozel Musteri: " << urunFiyatozel << endl;
					cout << "\nUrun KDV Orani: " << urunKdvorani << endl;
					cout << "\nUrun Stok Adedi: " << urunStokadedi << endl;
					cout << "=====================================================" << endl;
					cout << "=====================================================" << endl;

				}
				
				
				



			}
			if (secim_urunMenu == 4)// urun duzeltme 
			{

				system("cls");
				string duzeltilicek_Urun;
				ifstream dosyaOku("urun.txt");//urun.txt dosyasinin okuma modunda acilmasi
				ofstream dosyaYaz("urun.tmp");// urun.tmp adinda gecici dosyanin olusturulmasi
				cout << "Lutfen Duzeltmek Istediginiz Urunun Kodunu Giriniz" << endl;
				cin >> duzeltilicek_Urun;
				while (!dosyaOku.eof())
				{
					dosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminsuresi >> urunFiyatgenel >> urunFiyatozel >> urunKdvorani >> urunStokadedi;
					if (duzeltilicek_Urun == urunKodu)
					{
						cout << "\nUrun Kodu: " << urunKodu << endl;
						cout << "\nUrun Adi: " << urunAdi << endl;
						cout << "\nUrun Ureticisi: " << urunUreticisi << endl;
						cout << "\nUrun Temin Suresi: " << urunTeminsuresi << endl;
						cout << "\nUrun Fiyati(Genel Musteri): " << urunFiyatgenel << endl;
						cout << "\nUrun Fiyati(Ozel Musteri: " << urunFiyatozel << endl;
						cout << "\nUrun KDV Orani: " << urunKdvorani << endl;
						cout << "\nUrun Stok Adedi: " << urunStokadedi << endl;
						cout << endl;
						cout << endl;
						cout << "<------------------Yeni Urun Bilgileri------------------>" << endl;//duzeltilecek urunun yeni bilgilerinin alinmasi
						cout << endl;
						cout << endl;
						cout << "Lutfen Klavyeden Deger Girerken Bosluk Ve Nokta Kullanmayiniz!!" << endl;
						cout << endl;
						cout << endl;
						cout << "\nYeni Urun Kodu: "; cin >> urunKodu;
						cout << "\nYeni Urun Adi: "; cin >> urunAdi;
						cout << "\nYeni Urun Ureticisi: "; cin >> urunUreticisi;
						cout << "\nYeni Urun Temin Suresi: "; cin >> urunTeminsuresi;
						cout << "\nYeni Urun Fiyati(Genel Musteri): "; cin >> urunFiyatgenel;
						cout << "\nYeni Urun Fiyati(Ozel Musteri): "; cin >> urunFiyatozel;
						cout << "\nYeni Urun KDV Orani: "; cin >> urunKdvorani;
						cout << "\nYeni Urun Stok Adedi: "; cin >> urunStokadedi;
						dosyaYaz << urunKodu << " " << urunAdi << ' ' << urunUreticisi << ' ' << urunTeminsuresi << ' ' << urunFiyatgenel << ' ' << urunFiyatozel << ' ' << urunKdvorani << ' ' << urunStokadedi << "\n";
						cout << endl;
						cout << "Urun Basariyla Duzeltilmistir" << endl;
						cout << endl;
						break;
					}
					else
					{


						dosyaYaz << urunKodu << " " << urunAdi << ' ' << urunUreticisi << ' ' << urunTeminsuresi << ' ' << urunFiyatgenel << ' ' << urunFiyatozel << ' ' << urunKdvorani << ' ' << urunStokadedi << "\n";
						
					}

				}
				dosyaYaz.close();
				dosyaOku.close();
				remove("urun.txt");//urun.txt dosaysinin kaldirilmasi 
				rename("urun.tmp", "urun.txt");//urun.tmp dosyasinin isminin urun.txt olarak degistirlmesi 

				break;

			}
			if (secim_urunMenu == 5)// urun silme kod blogu
			{
				system("cls");
				string silinecek_Urun;
				ifstream dosyaOku("urun.txt");
				ofstream dosyaYaz("urun.tmp");
				cout << "Lutfen Silmek Istediginiz Urunun Kodunu Giriniz" << endl;
				cin >> silinecek_Urun;
				while (!dosyaOku.eof())
				{
					dosyaOku >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminsuresi >> urunFiyatgenel >> urunFiyatozel >> urunKdvorani >> urunStokadedi;
					if (silinecek_Urun == urunKodu)
					{
						cout << "\nUrun Kodu: " << urunKodu << endl;
						cout << "\nUrun Adi: " << urunAdi << endl;
						cout << "\nUrun Ureticisi: " << urunUreticisi << endl;
						cout << "\nUrun Temin Suresi: " << urunTeminsuresi << endl;
						cout << "\nUrun Fiyati(Genel Musteri): " << urunFiyatgenel << endl;
						cout << "\nUrun Fiyati(Ozel Musteri: " << urunFiyatozel << endl;
						cout << "\nUrun KDV Orani: " << urunKdvorani << endl;
						cout << "\nUrun Stok Adedi: " << urunStokadedi << endl;
						cout << endl;
						cout << endl;
						cout << "Urun Basariyla Silinmistir!" << endl;
					}
					else
					{
						dosyaYaz << urunKodu << " " << urunAdi << ' ' << urunUreticisi << ' ' << urunTeminsuresi << ' ' << urunFiyatgenel << ' ' << urunFiyatozel << ' ' << urunKdvorani << ' ' << urunStokadedi << "\n";
					}
				}
				dosyaYaz.close();
				dosyaOku.close();
				remove("urun.txt");
				rename("urun.tmp", "urun.txt");
				break;

			}

		}
	
		if (secim_anaMenu == 2)
		{
			system("cls");
			musteriMenu();
			cin >> secim_musteriMenu;
			if (secim_musteriMenu == 1)//musteri ekleme kod blogu
			{


				system("cls");
				string musteri_Kontrol;
				int counter = 0;
				ofstream dosyaYaz("cari.txt", ios::app);
				ifstream dosyaOku("cari.txt");
				cout << "Lutfen Musteri Kontrolu Icin Eklemek Istediginiz Firma No'yu Giriniz" << endl;
				cin >> musteri_Kontrol;
				while (!dosyaOku.eof())
				{
					dosyaOku >> firma_No >> firma_Adi >> firma_Tel >> firma_Sorumlusu >> firma_Musterikatagorisi >> firma_Adres;
					if (musteri_Kontrol == firma_No)
					{
						cout << "Boyle Bir Musteri Zaten Ekli!" << endl;
						counter++;
						break;
					}
				}
				if (counter == 0)
				{

					system("cls");
					
					cout << "Lutfen Klavyeden Deger Girerken Bosluk Ve Nokta Kullanmayiniz!!" << endl;
					cout << endl;
					cout << "\nFirma No: "; cin >> firma_No;
					cout << "\nFirma Adi: "; cin >> firma_Adi;
					cout << "\nFirma Telefonu: "; cin >> firma_Tel;
					cout << "\nFirma Sorumlusu: "; cin >> firma_Sorumlusu;
					cout << "\nFirma Katagorisi(Ozel/Genel): "; cin >> firma_Musterikatagorisi;
					cout << "\nFirma Adresi: "; cin >> firma_Adres;
					dosyaYaz << firma_No << " " << firma_Adi << ' ' << firma_Tel << ' ' << firma_Sorumlusu << ' ' << firma_Musterikatagorisi << ' ' << firma_Adres << "\n";
					cout << endl;
					cout << "Musteri Basariyla Eklenmistir!" << endl;
					cout << endl;

				}
				dosyaYaz.close();
				dosyaOku.close();
			}

			if (secim_musteriMenu == 2)//musteri sorgulama kod blogu
			{
				system("cls");
				string musteri_Sorgu;
				ofstream dosyaYaz("cari.txt", ios::app);
				ifstream dosyaOku("cari.txt");
				int counter = 0;
				cout << "Lutfen Sorgulamak Istediginiz Firma'nin Kodunu Giriniz" << endl;
				cin >> musteri_Sorgu;
				while (!dosyaOku.eof())
				{
					dosyaOku >> firma_No >> firma_Adi >> firma_Tel >> firma_Sorumlusu >> firma_Musterikatagorisi >> firma_Adres;
					if (musteri_Sorgu == firma_No)
					{
						cout << "\nFirma No: " << firma_No << endl;
						cout << "\nFirma Adi: " << firma_Adi << endl;
						cout << "\nFirma Telefonu: " << firma_Tel << endl;
						cout << "\nFirma Sorumlusu: " << firma_Sorumlusu << endl;
						cout << "\nFirma Katagorisi(Ozel/Genel): " << firma_Musterikatagorisi << endl;
						cout << "\nFirma Adresi: " << firma_Adres << endl;
						counter++;
						break;

					}

				}
				if (counter == 0) { cout << "Boyle Bir Musteri Bulunamadi!!" << endl; break; }

			}
			if (secim_musteriMenu == 3)// musteri duzeltme kod blogu
			{

				system("cls");
				string duzeltilicek_Musteri;
				ifstream dosyaOku("cari.txt");
				ofstream dosyaYaz("cari.tmp");
				cout << "Lutfen Duzeltmek Istediginiz Firmanin No'sunu  Giriniz" << endl;
				cin >> duzeltilicek_Musteri;
				while (!dosyaOku.eof())
				{
					dosyaOku >> firma_No >> firma_Adi >> firma_Tel >> firma_Sorumlusu >> firma_Musterikatagorisi >> firma_Adres;
					if (duzeltilicek_Musteri == firma_No)
					{

						cout << "\nFirma No: " << firma_No << endl;
						cout << "\nFirma Adi: " << firma_Adi << endl;
						cout << "\nFirma Telefonu: " << firma_Tel << endl;
						cout << "\nFirma Sorumlusu: " << firma_Sorumlusu << endl;
						cout << "\nFirma Katagorisi(Ozel/Genel): " << firma_Musterikatagorisi << endl;
						cout << "\nFirma Adresi: " << firma_Adres << endl;
						cout << endl;
						cout << endl;
						cout << "<------------------Yeni Urun Bilgileri------------------>" << endl;
						cout << endl;
						cout << "Lutfen Klavyeden Deger Girerken Bosluk Ve Nokta Kullanmayiniz!!" << endl;
						cout << endl;
						cout << "\nYeni Firma No: "; cin >> firma_No;
						cout << "\nYeni Firma Adi: "; cin >> firma_Adi;
						cout << "\nYeni Firma Telefonu: "; cin >> firma_Tel;
						cout << "\nYeni Firma Sorumlusu: "; cin >> firma_Sorumlusu;
						cout << "\nYeni Firma Katagorisi(Ozel/Genel) : "; cin >> firma_Musterikatagorisi;
						cout << "\nYeni Firma Adresi: "; cin >> firma_Adres;

						dosyaYaz << firma_No << " " << firma_Adi << ' ' << firma_Tel << ' ' << firma_Sorumlusu << ' ' << firma_Musterikatagorisi << ' ' << firma_Adres << "\n";
						cout << endl;
						cout << "Musteri Basariyla Duzeltilmistir" << endl;
						cout << endl;
						break;
					}
					else
					{


						dosyaYaz << firma_No << " " << firma_Adi << ' ' << firma_Tel << ' ' << firma_Sorumlusu << ' ' << firma_Musterikatagorisi << ' ' << firma_Adres << "\n";

					}

				}
				dosyaYaz.close();
				dosyaOku.close();
				remove("cari.txt");
				rename("cari.tmp", "cari.txt");
			}
			if (secim_musteriMenu == 4)//musteri silme kod blogu
			{
				system("cls");
				string silinecek_Musteri;
				ifstream dosyaOku("cari.txt");
				ofstream dosyaYaz("cari.tmp");
				cout << "Lutfen Silmek Istediginiz Musterinin Firma No'sunu  Giriniz" << endl;
				cin >> silinecek_Musteri;
				while (!dosyaOku.eof())
				{
					dosyaOku >> firma_No >> firma_Adi >> firma_Tel >> firma_Sorumlusu >> firma_Musterikatagorisi >> firma_Adres;
					if (silinecek_Musteri == firma_No)
					{
						cout << "\nFirma No: " << firma_No << endl;
						cout << "\nFirma Adi: " << firma_Adi << endl;
						cout << "\nFirma Telefonu: " << firma_Tel << endl;
						cout << "\nFirma Sorumlusu: " << firma_Sorumlusu << endl;
						cout << "\nFirma Katagorisi(Ozel/Genel): " << firma_Musterikatagorisi << endl;
						cout << "\nFirma Adresi: " << firma_Adres << endl;
						cout << endl;
						cout << endl;
						cout << "Musteri Basariyla Silinmistir!" << endl;
						break;
					}
					else 
					{
						dosyaYaz << firma_No << " " << firma_Adi << ' ' << firma_Tel << ' ' << firma_Sorumlusu << ' ' << firma_Musterikatagorisi << ' ' << firma_Adres << "\n";
					}
				}
				dosyaYaz.close();
				dosyaOku.close();
				remove("cari.txt");
				rename("cari.tmp", "cari.txt");
			}



		}

			if (secim_anaMenu == 3)
			{
				system("cls");
				siparisMenu();
				cin >> secim_siparisMenu;
				if(secim_siparisMenu==1)// siparis ekleme kod blogu
				{
					string siparis_Kontrol;
					string siparis_Kontrol2;
					int counter = 0;
					cout << "Lutfen Olusturmak Istediginiz Siparis Icin Kontrol Amaciyla Firma No'yu Ve Urun Kodunu Giriniz" << endl;
					cin >> siparis_Kontrol;
					cin >> siparis_Kontrol2;
					ofstream dosyaYaz("siparis.txt", ios::app);
					ifstream dosyaOku("siparis.txt");
					while (!dosyaOku.eof())//siparis kontrol
					{
						dosyaOku >> firmaNo >> siparis_Tarihi >> siparis_Tutari >> urun_Kodu >> urun_Adedi;
						if (siparis_Kontrol == firmaNo && siparis_Kontrol2 == urun_Kodu)
						{
							cout << "Bu Siparis Zaten Alinmis!" << endl;
							counter++;
							break;
						}
					}
					
					if (counter == 0)// siparis edilmek urunun kontrolu
					{
						system("cls");
						ifstream dosyaOku1("urun.txt");
						int gcc1 = 0;
						while (!dosyaOku1.eof())
						{
							dosyaOku1 >> urunKodu >> urunAdi >> urunUreticisi >> urunTeminsuresi >> urunFiyatgenel >> urunFiyatozel >> urunKdvorani >> urunStokadedi;
							if (siparis_Kontrol2 == urunKodu)
							{
								cout << "\nUrun Kodu: " << urunKodu << endl;
								cout << "\nUrun Adi: " << urunAdi << endl;
								cout << "\nUrun Ureticisi: " << urunUreticisi << endl;
								cout << "\nUrun Temin Suresi: " << urunTeminsuresi << endl;
								cout << "\nUrun Fiyati(Genel Musteri): " << urunFiyatgenel << endl;
								cout << "\nUrun Fiyati(Ozel Musteri: " << urunFiyatozel << endl;
								cout << "\nUrun KDV Orani: " << urunKdvorani << endl;
								cout << "\nUrun Stok Adedi: " << urunStokadedi << endl;
								gcc1++;
								break;



							}
						}
						if(gcc1==0)
						{
							cout << "Stoklarda Boyle Bir Urun Bulunmadigindan Siparis Olusturamazsiniz!" << endl;
						}
						dosyaOku1.close();
						cout << "===============================================================" << endl;
						ifstream dosyaoku2("cari.txt");
						int gcc = 0;
						while (!dosyaoku2.eof())//siparis veren firmanin kontrolu
						{
							dosyaoku2 >> firma_No >> firma_Adi >> firma_Tel >> firma_Sorumlusu >> firma_Musterikatagorisi >> firma_Adres;
							if (siparis_Kontrol == firma_No)
							{
								cout << "\nFirma No: " << firma_No << endl;
								cout << "\nFirma Adi: " << firma_Adi << endl;
								cout << "\nFirma Telefonu: " << firma_Tel << endl;
								cout << "\nFirma Sorumlusu: " << firma_Sorumlusu << endl;
								cout << "\nFirma Katagorisi(Ozel/Genel): " << firma_Musterikatagorisi << endl;
								cout << "\nFirma Adresi: " << firma_Adres << endl;
								cout << endl;
								cout << endl;
								gcc++;
								break;
							}

						}
						if (gcc == 0)
						{
							cout << "Boyle Bir Firma Bulunmamaktadir Ilk Once Musteri Islemlerinden Firmayi Eklemelisiniz!" << endl;
							break;
						}
						else if (gcc == 1)//siparis alinmasi
						{
							cout << "Lutfen Siparis Olusturmak Icin Gerekli Bilgileri Giriniz" << endl;
							cout << endl;
							cout << "Lutfen Klavyeden Deger Girerken Bosluk Ve Nokta Kullanmayiniz!!" << endl;
							cout << endl;
							cout << "\nFirma No: "; cin >> firmaNo;
							cout << "\nSiparis Tarihi: "; cin >> siparis_Tarihi;
							cout << "\nSiparis Tutari: "; cin >> siparis_Tutari;
							cout << "\nUrun Kodu: "; cin >> urun_Kodu;
							cout << "\nUrun Adedi: "; cin >> urun_Adedi;
							dosyaYaz << firmaNo << " " << siparis_Tarihi << ' ' << siparis_Tutari << ' ' << urun_Kodu << ' ' << urun_Adedi << "\n";
							cout << endl;
							cout << "Siparis Basariyla Olusturulmustur!" << endl;
							cout << endl;
							break;
						}
								
							
						
					dosyaoku2.close();
					}
					dosyaOku.close();
					dosyaYaz.close();
				}

				if (secim_siparisMenu == 2)// siparis sorgu kod blogu
				{
					system("cls");
					int kontrol = 0;
					string siparis_Kontrol;
					string siparis_Kontrol2;
					ifstream dosyaOku("siparis.txt");
					cout << "Lutfen Sorgulamak Istediginiz Siparisin Firma No'sunu ve Siparis Verilen Urun Kodunu Giriniz" << endl;
					cin >> siparis_Kontrol;
					cin >> siparis_Kontrol2;
					while (!dosyaOku.eof())
					{
						dosyaOku >> firmaNo >> siparis_Tarihi >> siparis_Tutari >> urun_Kodu >> urun_Adedi;
						if (siparis_Kontrol == firmaNo && siparis_Kontrol2 == urun_Kodu)
						{
							system("cls");
							cout << "\nFirma No: " << firmaNo << endl;
							cout << "\nSiparis Tarihi: " << siparis_Tarihi << endl;
							cout << "\nSiparis Tutari: " << siparis_Tutari << endl;
							cout << "\nUrun Kodu: " << urun_Kodu << endl;
							cout << "\nUrun Adedi: " << urun_Adedi << endl;
							cout << endl;
							kontrol++;
							break;
						}
						

					}
					if (kontrol == 0)
					{
						cout << "Aradiginiz Siparis Bulunmamaktadir!" << endl;
					}

				}
				if (secim_siparisMenu == 3)//siparis silme kod blogu
				{
					system("cls");
					string silinecek_Siparis;
					string silinecek_Siparis2;
					ifstream dosyaOku("siparis.txt");
					ofstream dosyaYaz("siparis.tmp");
					cout << "Lutfen Silmek Istediginiz Siparisin Firma No'sunu ve Siparis Verilen Urun Kodunu Giriniz" << endl;
					cin >> silinecek_Siparis;
					cin >> silinecek_Siparis2;
					while (!dosyaOku.eof())
					{
						dosyaOku >> firmaNo >> siparis_Tarihi >> siparis_Tutari >> urun_Kodu >> urun_Adedi;
						if (silinecek_Siparis == firma_No && silinecek_Siparis2==urun_Kodu)
						{
							cout << "\nFirma No: " << firmaNo << endl;
							cout << "\nSiparis Tarihi: " << siparis_Tarihi << endl;
							cout << "\nSiparis Tutari: " << siparis_Tutari << endl;
							cout << "\nUrun Kodu: " << urun_Kodu << endl;
							cout << "\nUrun Adedi: " << urun_Adedi << endl;
							cout << endl;
							cout << endl;
							cout << "Siparis Basariyla Silinmistir!" << endl;
							break;
						}
						else
						{
							dosyaYaz << firmaNo << " " << siparis_Tarihi << ' ' << siparis_Tutari << ' ' << urun_Kodu << ' ' << urun_Adedi << "\n";
						}
					}
					dosyaYaz.close();
					dosyaOku.close();
					remove("siparis.txt");
					rename("siparis.tmp", "siparis.txt");
				}
				if (secim_siparisMenu == 4)// siparis duzeltme kod blogu
				{
					system("cls");
					string duzeltilicek_siparis;
					string duzeltilicek_siparis2;
					ifstream dosyaOku("siparis.txt");
					ofstream dosyaYaz("siparis.tmp");
					cout << "Lutfen Duzeltmek Istediginiz Urunun Kodunu Giriniz" << endl;
					cin >> duzeltilicek_siparis;
					cin >> duzeltilicek_siparis2;
					while (!dosyaOku.eof())
					{
						dosyaOku >> firmaNo >> siparis_Tarihi >> siparis_Tutari >> urun_Kodu >> urun_Adedi;

						if (duzeltilicek_siparis == firma_No&&duzeltilicek_siparis2==urun_Kodu)
						{

							cout << "\nFirma No: " << firmaNo << endl;
							cout << "\nSiparis Tarihi: " << siparis_Tarihi << endl;
							cout << "\nSiparis Tutari: " << siparis_Tutari << endl;
							cout << "\nUrun Kodu: " << urun_Kodu << endl;
							cout << "\nUrun Adedi: " << urun_Adedi << endl;
							cout << endl;
							cout << endl;
							cout << "<------------------Yeni Urun Bilgileri------------------>" << endl;
							cout << endl;
							cout << "Lutfen Klavyeden Deger Girerken Bosluk Ve Nokta Kullanmayiniz!!" << endl;
							cout << endl;
							cout << "\nYeni Firma No: "; cin >> firmaNo;
							cout << "\nYeni Siparis Tarihi: "; cin>> siparis_Tarihi;
							cout << "\nYeni Siparis Tutari: "; cin >> siparis_Tutari;
							cout << "\nYeni Urun Kodu: "; cin >> urun_Kodu;
							cout << "\nYeni Urun Adedi: "; cin >> urun_Adedi;

							dosyaYaz << firmaNo << " " << siparis_Tarihi << ' ' << siparis_Tutari << ' ' << urun_Kodu << ' ' << urun_Adedi << "\n";
							cout << endl;
							cout << "Siparis Basariyla Duzeltilmistir" << endl;
							cout << endl;
						}
						else
						{


							dosyaYaz << firmaNo << " " << siparis_Tarihi << ' ' << siparis_Tutari << ' ' << urun_Kodu << ' ' << urun_Adedi << "\n";

						}
					}
					dosyaYaz.close();
					dosyaOku.close();
					remove("siparis.txt");
					rename("siparis.tmp", "siparis.txt");
				}
				if (secim_siparisMenu == 5)// siparis raporlama kod blogu
				{
					system("cls");
					siparisMenualt();
					cin >> secim_siparisMenualt;
					if (secim_siparisMenualt==1)// siparis raporlama firma no ya g�re 
					{
						int kontrol = 0;
						system("cls");
						string secim_urunkodu;
						ifstream dosyaOku("siparis.txt");
						cout << "Lutfen Raporlamak Istediginiz Siparisin Urun Kodunu Giriniz" << endl;
						cin >> secim_urunkodu;
						while (!dosyaOku.eof())
						{
							dosyaOku >> firmaNo >> siparis_Tarihi >> siparis_Tutari >> urun_Kodu >> urun_Adedi;
							if (secim_urunkodu == urun_Kodu)
							{
								cout << "\nFirma No: " << firmaNo << endl;
								cout << "\nSiparis Tarihi: " << siparis_Tarihi << endl;
								cout << "\nSiparis Tutari: " << siparis_Tutari << endl;
								cout << "\nUrun Kodu: " << urun_Kodu << endl;
								cout << "\nUrun Adedi: " << urun_Adedi << endl;
								cout << "===================================================" << endl;
								kontrol++;
								break;
							}
							
						}
						if (kontrol == 0)
						{
							cout << "Bu Urun Koduyla Eslesen Siparis Bulunmamaktadir!!" << endl;
						}

					}
					if (secim_siparisMenualt == 2)// siparis raporlama urun koduna g�re 
					{
						int kontrol = 0;
						system("cls");
						string secim_firmaNo;
						ifstream dosyaOku("siparis.txt");
						cout << "Lutfen Raporlamak Istediginiz Siparisin Firma No'sunu  Giriniz" << endl;
						cin >> secim_firmaNo;
						while (!dosyaOku.eof())
						{
							dosyaOku >> firmaNo >> siparis_Tarihi >> siparis_Tutari >> urun_Kodu >> urun_Adedi;
							if (secim_firmaNo == firmaNo)
							{
								cout << "\nFirma No: " << firmaNo << endl;
								cout << "\nSiparis Tarihi: " << siparis_Tarihi << endl;
								cout << "\nSiparis Tutari: " << siparis_Tutari << endl;
								cout << "\nUrun Kodu: " << urun_Kodu << endl;
								cout << "\nUrun Adedi: " << urun_Adedi << endl;
								cout << "=======================================================" << endl;
								kontrol++;
								break;
							}
							
						}
						if (kontrol == 0)
						{
							cout << "Bu Firma No'suyla Eslesen Siparis Bulunmamaktadir!" << endl;
							break;
						}

					}
				}







			}

	}while (secim_anaMenu != 1 && secim_anaMenu != 2 && secim_anaMenu != 3 && secim_anaMenu != 4);
		cout<< endl;
}


















