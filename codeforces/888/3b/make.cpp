#include<cstdio>
#include<cstdlib>

char f[100];
int main() {
	int n = 10;
	for(int i=1; i<=n; i++) {
		sprintf(f, "./data.run > a%d.in", i);
		system(f);
		sprintf(f, "./3b.run < a%d.in > a%d.out", i, i);
		system(f);
		system("sleep 1");
	}
	return 0;
}
