 #include<stdio.h>

char a[1010][1010];
int main(){
	int t;
	int k, r, c;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		scanf("%d%d%d",&r,&c,&k);


		for(int ii = 0; ii < r; ii++){
            if(ii%2==0){
                for(int j = 0; j < c; j++){
                    if(j==c-1){
                        a[ii][j] = 'S';
                    }
                    else{
                        a[ii][j] = 'E';
                    }
                }
            }
            else{
                for(int j = c-1; j >= 0; j--){
                    if(j==0){
                        a[ii][j] = 'S';
                    }
                    else{
                        a[ii][j] = 'W';
                    }
                }

            }

		}
		int total = r*c;
		if(k==(r*c-1)){
			printf("Case #%d: IMPOSSIBLE\n", i);
		}
		else{
            k = total-k-1;
			printf("Case #%d: POSSIBLE\n", i);
            int nowr = 0;
            int nowc = 0;

            for(int j = 1; j <= k; j++){
                if(a[nowr][nowc]=='E'){
                    nowc++;
                }
                else if(a[nowr][nowc]=='W'){
                    nowc--;
                }
                else if(a[nowr][nowc]=='S'){
                    nowr++;
                }
            }
            if(nowc-1>=0&&a[nowr][nowc-1]=='E'){
                a[nowr][nowc] = 'W';
            }
            else if(nowc+1<c&&a[nowr][nowc+1]=='W'){
                a[nowr][nowc] = 'E';
            }
            else if(nowr-1>=0&&a[nowr-1][nowc]=='S'){
                a[nowr][nowc] = 'N';
            }

            for(int j = 0; j < r; j++){
                for(int l = 0; l < c; l++){
                    printf("%c", a[j][l]);
                }
                printf("\n");
            }

		}
	}

	return 0;
}
