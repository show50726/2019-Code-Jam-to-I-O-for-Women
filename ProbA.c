#include<stdio.h>
#include<string.h>

int m[10010];
int ok[10010];
int ok2[10010];
int main(){
    int t;
    int k;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        memset(ok, 0, sizeof(ok));
        memset(ok2, 0, sizeof(ok2));
    	scanf("%d", &k);
    	for(int j = 0; j <= k; j++){
    		scanf("%d", &m[j]);
    	}
    	int ans = 0;
        int ans2 = 0;
        int first = 1;
    	for(int j = 1; j < k; j++){
            int l = 1;
            while(m[j]==m[j+l]&&j+l<=k){
                l++;
            }
    		if(m[j-1]<m[j]&&m[j]>m[j+l]){
                if(first==1){
                    first = 0;
                }
    			ok[j] = 1;
    			j+=l;
    			ans++;
    		}
    		else if(m[j-1]>m[j]&&m[j]<m[j+l]){
                if(first==1){
                    first = 0;
                    continue;
                }
    			ok[j] = -1;
    			j+=l;
    			ans++;
    		}
    		//printf("l:%d\n", l);
    	}
        first = 1;
        for(int j = 1; j < k; j++){
            int l = 1;
            while(m[j]==m[j+l]&&j+l<=k){
                l++;
            }
            if(m[j-1]<m[j]&&m[j]>m[j+l]){
                if(first==1){
                    first = 0;
                    continue;
                }
                ok2[j] = 1;
                j+=l;
                ans2++;
            }
            else if(m[j-1]>m[j]&&m[j]<m[j+l]){
                if(first==1){
                    first = 0;
                }
                ok2[j] = -1;
                j+=l;
                ans2++;
            }
            //printf("l:%d\n", l);
        }
        //for(int ii = 0; ii <= k; ii++) printf("%d ", ok[ii]);
        if(ans-1<0&&ans2-1<0) printf("Case #%d: 0\n", i+1);
    	else printf("Case #%d: %d\n", i+1, ans>ans2?ans-1:ans2-1);
    }

    return 0;
}
