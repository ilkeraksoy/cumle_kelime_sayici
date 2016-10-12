#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void okuma();
void parcala();
bool Tekrarkontrolu(string x);
void yazma();

string yazi;
string *parcali;
string *kontrol;
int noktaSayisi = 0;
int cumleSayisi = 0;

int main(){

	okuma();
	parcala();
	yazma();	

	system("PAUSE");
}

void okuma(){

	fstream oku("oku.txt");
	while (!oku.eof())
	{
		getline(oku, yazi);
	}
}

void parcala(){

	for (int i = 0; i < yazi.length();i++){
		if (yazi[i] == '.'){
			noktaSayisi++;
		}
	}

	cumleSayisi = noktaSayisi;
	
	parcali = new string[noktaSayisi];
	int j = 0;
	
	for (int i = 0; i < yazi.length(); i++){
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

	kontrol = new string[cumleSayisi];
}

bool Tekrarkontrolu(string x){
	
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

	int adet = 0;
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

