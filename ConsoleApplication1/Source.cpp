#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void okuma(); // dosya okuma fonksiyonu
void parcala(); // okunan string'i cümlelere parçalayan fonksiyon
bool Tekrarkontrolu(string x); // cümle tekrarını bulan fonksiyon
void yazma(); // dosyaya yazan fonksiyon

string yazi; // okunan string
string *parcali; // cümleleri tutan dinamik dizi
string *kontrol;
int noktaSayisi = 0;
int cumleSayisi = 0;

int main(){

	remove("yaz.txt"); // varsa yaz.txt'i sil
	
	okuma();
	parcala();
	yazma();	

	system("PAUSE");
}

void okuma(){

	fstream oku("oku.txt");
	while (!oku.eof())  // dosya sonuna ulaşılmadıysa eğer
	{
		getline(oku, yazi); // satır satır oku.
	}
}

void parcala(){

	for (int i = 0; i < yazi.length();i++){   // nokta sayısını bul (nokta kadar cümle var.)
		if (yazi[i] == '.'){                   
			noktaSayisi++;
		}
	}

	cumleSayisi = noktaSayisi;
	
	parcali = new string[noktaSayisi];            // dinamik dizi oluştur
	int j = 0;
	
	for (int i = 0; i < yazi.length(); i++){    // cümleler arası boşlukları alma(boşluk varsa)
		if (yazi[i] == ' '){
			if (yazi[i - 1] == '.'){			
				continue;
			}
			else{
				parcali[j] += yazi[i];           
				continue;
			}
		}

		parcali[j] += yazi[i];

		if (yazi[i] == '.'){
			j++;
		}
	}

	kontrol = new string[cumleSayisi];     // dinamik olarak kontrol dizisi oluştur
}

bool Tekrarkontrolu(string x){        // tekrar eden cümleleri tespit et
	
	int i;

	for (i = 0; i < cumleSayisi; i++){
		if (kontrol[i]==x){

			return true;
		}
		else if (kontrol[i] == ""){

			kontrol[i] = x;
			return false;
		}
		
		continue;
	}	
}

void yazma(){

	int adet = 0;   // tekrar eden cümle sayacı
	ofstream yaz;

	for (int i = 0; i < cumleSayisi; i++){
		if (Tekrarkontrolu(parcali[i])){
			continue;
		}

		for (int j = i; j < cumleSayisi; j++){
			if(parcali[i] == parcali[j]){

				adet++;
			}
		}

		yaz.open("yaz.txt", ios::app);
		yaz << parcali[i] + "^" + std::to_string(adet) << endl;
		yaz.close();
		adet = 0;
	}




	
}

