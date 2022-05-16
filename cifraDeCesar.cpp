#include<bits/stdc++.h>

using namespace std;
#define total 26

char cifrar(string frase, int k){

    char alfabetoOriginal[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alfabetoModificado[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n = 0, i=0;

	strlwr(alfabetoModificado);
	strlwr(alfabetoOriginal);
	transform(frase.begin(), frase.end(), frase.begin(), ::tolower);

	while(alfabetoModificado[n] != 0){
		if((alfabetoModificado[n] + k) > 122){ //Z = 122
			alfabetoModificado[n] -= total;
		}

		if((alfabetoModificado[n] + k) < 97){ //A = 97
			alfabetoModificado[n] += total;
		}

		alfabetoModificado[n] = alfabetoModificado[n] + k;
		n++;
	}

	cout<<"\nFrase Criptografada: ";

	while(frase[i]!=0){
        for(int j=0;j<total;j++){
        	if (frase[i] == 32){
        		cout<<" ";
        		j = total;
			}
            else if(frase[i] == alfabetoOriginal[j]){
                cout<<alfabetoModificado[j];
                j = total;
            }

        }
        i++;
	}
}

int main(){
	string frase;
	int k, i;

	cout<<"Digite o valor de K: ";
	cin>>k;

	cout<<"Digite a frase a ser criptografada: ";

	cin.ignore();
	getline(cin,frase);

	cifrar(frase, k);

	return 0;
}
