#include <cstdio>
#include <cstring>

const int N = 1e6+10;
char str[N];
int sand[N], sor[N], cand[N], cor[N], cnt;
int andcnt, orcnt;

bool f(int l, int r) {
	if(sor[r] > l) { // r前面的或是否是同一层的 
		if(f(l, sor[r] - 1)) {
			orcnt++;
			return true;
		}
		return f(sor[r] + 1, r);
	}
	if(sand[r] > l) {// r前面的与是否是同一层的 
		if(f(l, sand[r] - 1)) {
			andcnt++;
			return false;
		}
		return f(sand[r] + 1, r);
	}
	if(str[l] == '(' && str[r] == ')') 
		return f(l + 1, r - 1);
	if(l == r)
		return str[l] - '0';
    return false;
}

int main() {
	scanf("%s", str);
	int len = strlen(str);
	for(int i = 0; i < len ; i++) {
		if(str[i] == '(')
			cnt++;
		else if(str[i] == '&')
			cand[cnt] = i;
		else if(str[i] == '|')
			cor[cnt] = i;
		else if(str[i] == ')') {
			cand[cnt] = cor[cnt] = 0;
			cnt--;
		}
		sand[i] = cand[cnt];
		sor[i] = cor[cnt];
	}
	printf("%d\n", f(0, len - 1));
	printf("%d %d", andcnt, orcnt);
	return 0;
}