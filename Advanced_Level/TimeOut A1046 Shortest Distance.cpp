#include <cstdio>
#include <algorithm>

int min_dis(int e1, int e2, int dis[], int dis_sum, int n){
	if(e1 > e2) std::swap(e1,e2);
	if((e2 - e1) > (dis_sum / 2)) std::swap(e1,e2);
	//minimize the number of accumulations
	int min_dis = 0;
	for(int i = e1; i != e2; i++){
		min_dis += dis[i-1];
		if(i == n) i = 0;
	}

	if(dis_sum - min_dis < min_dis) return (dis_sum - min_dis);
	return min_dis;
}

int main(void){
	int n;	scanf("%d", &n);	int t;
	int *dis = new int[n]; int dis_sum = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		dis_sum += t;
		dis[i] = t;
	}
	int m;
	scanf("%d", &m); int e1, e2;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &e1, &e2);
		printf("%d\n",min_dis(e1, e2, dis, dis_sum, n));
	} 
	return 0;
} 
