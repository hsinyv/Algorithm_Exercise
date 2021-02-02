#include <cstdio>
int main() {
	int n, m, dis_sum = 0;
	scanf("%d", &n);
	int *dis = new int[n+1];
	for(int i = 1; i < n+1; i++){
		int temp;
		scanf("%d", &temp);
		dis_sum += temp;
		dis[i] = temp;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int start = 1, end = 1, s_dis = 0;
		scanf("%d %d", &start, &end);
		if(start > end){
			int temp = end;
			end = start;
			start = temp;
		}
		for(int i = start; i < end; i++){
			s_dis += dis[i];
		}
		int com_dis = dis_sum - s_dis;
		if(com_dis < s_dis){
			s_dis = com_dis;
		}	
		printf("%d\n", s_dis);
	}
	delete []dis;
	return 0;
}


