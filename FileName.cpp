
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
using namespace std;
char char_set[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz&quot" };
char char_set2[] = { "0123456789" };
int Getid(int i) {
	return char_set[i];
}
int Getid1(int i) {
	return char_set2[i];
}
void RandomAmuont() {
	char arr[10];
	
	for (int i = 0; i <10 ; i++) {
		int temp = rand() % 2;
		int temp1 = rand() % sizeof(char_set);
		int temp2 = rand() % sizeof(char_set2);
		if (temp == 0) {
			arr[i] = Getid(temp1);

			

		}if (temp == 1) {
			arr[i] = Getid1(temp2);
		}
	}for (int i = 0; i < 10; i++) {
		cout << arr[i];
	}

}

int main() {
	srand(time(NULL));
	RandomAmuont();
	return 0;
}
