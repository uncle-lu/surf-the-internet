#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	int val;
	node *front, *behind;
};

class myList{
public:
	node* head;
	node* end;
	int cnt;
	myList(){
		head = NULL;
		cnt = 0;
	}
	
	void push_back(int x) {
		node *now = new node();
		now->val = x; now->behind = NULL;
		cnt++;
		if(head == NULL) {
			head = now;
			now->front = NULL;
			end = now;
			return ;
		}
		end->behind = now;
		now->front = end;
		end = now;
		return ;
	}

	int size(){
		return cnt;
	}

	bool remove(node* x)
	{
		if(x == NULL)
			return false;
		if(x == head)
			head = x->behind;
		else 
			x->front->behind = x->behind;
		if(x->behind != NULL)
			x->behind->front = x->front;
		else
			end = x->front;
		delete x;
		cnt--;
		return true;
	}
	
	node* sit(const int x){
		if(x <= 0 || x > cnt)
			return NULL;
		int now = 1;
		for(node* curr = head; curr != NULL; curr = curr->behind, now++) {
			if(now == x)
				return curr;
		}
		return NULL;

	}

};
const int M = 1e4+10;
int tong[M];

bool _solv() {
	myList line;
	int m, n, k, temp, m_top = 1;
	scanf("%d %d %d", &m, &n, &k);
	memset(tong, 0, sizeof(tong));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &temp);
		tong[temp]++;
		line.push_back(temp);
	}
	node* t = line.head;
	int top = 1;
	while(m_top <= m && line.size() > 0) {
		while(m_top <= m && tong[m_top] == 0)m_top++;
		while(line.size() > 0 && line.size() - top + 1 < k && top != 1){
			top --;
			t = t->front;
		}
		int remove = 0;
		while(t != NULL && t->val < m_top + k) {
			tong[t->val]--;
			node* _t = (t->behind == NULL) ? t->front : t->behind;
			line.remove(t);
			t = _t;
			remove++;
		}
		if(line.size() <= 0)
			return true;
		if(line.size() < top) top = line.size();
		if(t == NULL && top > 0) {
			t = line.sit(top);
		}
		node *curr = t;
		for(int i=1; i<=k && curr != NULL; i++){
			while(curr != NULL && curr->val < m_top + k)
			{
				tong[curr->val]--;
				node* _temp = curr->behind;
				line.remove(curr);
				curr = _temp;
				remove++;
			}
			if(curr != NULL)
				curr = curr->behind;
			else
				break;
		}
		if(remove == 0 && line.size() - top + 1 <= k)
			return false;
		if(remove == 0) {
			top ++;
			t = t->behind;
		}
	}
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		if(_solv())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
