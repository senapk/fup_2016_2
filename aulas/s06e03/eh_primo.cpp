#include <iostream>
#include <cmath>

using namespace std;

bool eh_primo(int x){
	for(int i = 2; i <= sqrt(x); i++){
		if(x % i == 0)
			return false;
	}
	return true;
}

int main(){
	int x;
	cin >> x;
	if(eh_primo(x) && x != 0){
		cout<< "S" << "\n";
	}else{
		cout<< "N" << "\n";
	}
	return 0;
}

