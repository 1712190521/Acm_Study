#define N 505
using namespace std;
map<string, int> mp; map<string, int> mp2;
string sboy[N], sgirl[N];
int man[N][N], woman[N][N], p, had[N], arrive[N], have[N];
queue<int>que;
void input(int a)
{
	char name[100]; p = a;
	for (int i = 0; i < a; i++) {
		int m, n;
		scanf("%s", name);
		mp[name] = i;
		m = mp[name];
		sboy[i] = name;
		for (int j = 0; j < a; j++) {
			scanf("%s", name);
			if (!mp2[name]) {
				mp2[name] = p++;
				sgirl[p - 1] = name;

			}
			n = mp2[name];
			man[m][j] = n;
		}
	}
	for (int i = 0; i < a; i++) {
		int m, n;
		scanf("%s", name);
		m = mp2[name];
		for (int j = 0; j < a; j++) {
			scanf("%s", name);
			n = mp[name];
			woman[m][n] = j;
		}
	}
}
void marr(int n)
{
	for (int i = 0; i < n; i++)
		que.push(i);
	while (!que.empty()) {
		int x = que.front();
		int y = man[x][arrive[x]];
		que.pop();
		arrive[x]++;
		if (had[y] == -1) {
			had[y] = x;
			have[x] = y;
			continue;
		}
		else if (woman[y][had[y]] < woman[y][x])
			que.push(x);
		else {
			que.push(had[y]);
			had[y] = x;
			have[x] = y;
		}
	}
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(had, -1, sizeof(had));
		memset(arrive, 0, sizeof(arrive));
		mp.clear(); mp2.clear();
		input(n);
		marr(n);
		for (int i = 0; i < n; i++) {
			cout << sboy[i] << ' ' << sgirl[have[i]] << endl;
		}
		printf("\n");
	}
	return 0;
}