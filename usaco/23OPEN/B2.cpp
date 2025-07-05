#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 1e3+10;
char nline[N][15], tline[N][15], iline[N][15], cline[N][15];
int ncnt, tcnt, icnt, ccnt;

void init() {
	ncnt = tcnt = icnt = ccnt = 0;
	memset(nline, 0, sizeof(nline));
	memset(tline, 0, sizeof(tline));
	memset(iline, 0, sizeof(iline));
	memset(cline, 0, sizeof(cline));
	return ;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, c, p;
		char temp[15], mod[20];
		init();
		scanf("%d %d %d\n", &n, &c, &p);
		for (int i = 1; i <= n; ++i) {
			scanf("%s %s", temp, mod);
			if(mod[0] == 'n')
				strcpy(nline[++ncnt], temp);
			else if(mod[0] == 't')
				strcpy(tline[++tcnt], temp);
			else if(mod[0] == 'i')
				strcpy(iline[++icnt], temp);
			else
				strcpy(cline[++ccnt], temp);
		}
		int ans = 0, type_t, type_i, conj, cc;
		int max_verb = 2 * min(ccnt, p) + max(0, p - ccnt);
		for (int t1 = 0; t1 <= icnt && t1 <= ncnt && t1 <= max_verb; ++t1) {
			int ans_temp = t1 * 2;
			int noun_now = ncnt - t1;

			int t2 = min({ tcnt, noun_now / 2, max_verb - t1 });
			ans_temp += t2 * 3;
			noun_now -= t2 * 2;
			int all_sentence = t1 + t2;
			int use_conj = min(all_sentence / 2, ccnt);
			ans_temp += use_conj;
			all_sentence -= use_conj;
			if(all_sentence > p) continue;
			int use_cc = 0;
			if(t2 > 0) {
				use_cc = min(noun_now, c);
				ans_temp += use_cc;
			}
			if(ans_temp > ans) {
				ans = ans_temp;
				type_i = t1;
				type_t = t2;
				conj = use_conj;
				cc = use_cc;
			}
		}
		printf("%d\n", ans);
		if(ans == 0) { printf("\n"); continue; }
		bool flag = false;
		for (int i = 1; i <= type_i; ++i) {
			printf("%s %s", nline[ncnt--], iline[icnt--]);
			
			if(conj && !flag) {
				printf(" %s", cline[ccnt--]);
				conj--; flag = !flag;
			}
			else {
				printf(".");
				flag = !flag;
			}

			if(i != type_i || type_t != 0)
				printf(" ");
		}

		for (int i = 1; i <= type_t; ++i) {
			printf("%s %s ", nline[ncnt--], tline[tcnt--]);
			printf("%s", nline[ncnt--]);
			while(cc > 0) {
				printf(", %s", nline[ncnt--]);
				cc--;
			}
			if(conj && !flag) {
				printf(" %s", cline[ccnt--]);
				conj--; flag = !flag;
			}
			else {
				printf(".");
				flag = !flag;
			}
			
			if(i != type_t)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
