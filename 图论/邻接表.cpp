struct node {
	int v, next;
}edge[N];
int heads[N],cnt;
void add(int x, int y)
{
	edge[++cnt].next = heads[x];
	edge[cnt].v = y;
	heads[x] = cnt;
	return;
}