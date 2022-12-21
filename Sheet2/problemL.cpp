#include<stdio.h>
#include<string.h>
#define MOD 100000000
int DP[101][101][2]; // DP[i][j][0] use i horse and j footman ,last place horse
int main(){
	int n, m, k1, k2;
	while (scanf("%d%d%d%d", &n, &m, &k1, &k2) == 4){
		memset(DP, 0, sizeof(DP));
		DP[0][0][0] = DP[0][0][1] = 1;
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= m; j++){
				for (int k = 1; k <= k1&&k <= i; k++){
					DP[i][j][0] += DP[i - k][j][1]; // 
					DP[i][j][0] %= MOD;
				}
				for (int k = 1; k <= k2&&k <= j; k++){
					DP[i][j][1] += DP[i][j - k][0];
					DP[i][j][0] %= MOD;
				}
			}
		}
		printf("%d\n", (DP[n][m][0] + DP[n][m][1]) % MOD);
	}
	return 0;
}
