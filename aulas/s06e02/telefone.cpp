#include <iostream>
using namespace std;
char transforma(char c){
	string indices = "DGJMPTW";
	for(int i = 0; i < (int)indices.size(); i++)
		if(indices[i] > c){
			return (i + 2);
}
int main(){
	string palavra;
	cin >> palavra;	
	for(char c : palavra){
		if(c == '-')
			cout << '-';
		else if(c >= '0' && c <= '9')
			cout << c;
		else
			cout << transforma(c);
	}
	return 0;
}






