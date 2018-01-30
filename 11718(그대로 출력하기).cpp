#include <iostream>
#include <string>

using namespace std;

int main() {
	char c;
	do{
		//c = getchar();
		scanf("%c", &c);
		if (c != EOF)
			//putchar(c);
			printf("%c", c);
	} while (c != EOF);
}