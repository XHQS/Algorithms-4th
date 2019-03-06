class UF{
private:
	int count;
	int *id;
public:
	UF(int N){
		count = N;
		id = new int[N];
		for(int i = 0; i < N; i++)
			id[i] = i;
	}
	int count() { return count; }
	bool connected(int p, int q) { return quick_find(p) == quick_find(q); }
	int quick_find(int p) {
		while(p != id[p]) p = id[p];
		return p;
	}
	void quick_union(int p, int q) {
		int pRoot = quick_find(p);
		int qRoot = quick_find(q);
		if(pRoot == qRoot) return;
		id[pRoot] = qRoot;
		count--;
	}
};