#include<stdio.h>

int main(){
	int n,i=1;
	scanf("%d",&n);
	while(i<=n){
		int id;
		scanf("%d",&id);
		if (id/100000000000000000!=0){
			int check[18];
			temp = id;
			for (i=0;i<18;i++){
				check[i] = temp%10;
				temp /= 10;
			}
			sum = check[16]*7+check[15]*9+check[14]*10+check[13]*5+check[12]*8+check[11]*4+check[10]*2+check[9]*1+check[8]*6+check[7]*3+check[6]*7+check[5]*9+check[4]*10+check[3]*5+check[2]*8+check[1]*4+check[0]*2
			if (check[17]==sum%(17*10)) printf("Valid\n");
			else printf("Invalid\n");
		}
		else if(id/100000000000000000==0){
			num_shun = id/(9*10);
			num_bir = id%(9*10) / 1000
			num_sz = id %1000/10;
			num_gender = id%10;
		}
		
	}
	
}




//校验身份
int check[18];
temp = id;
for (i=0;i<18;i++){
	check[i] = temp%10;
	temp /= 10;
}
sum = check[16]*7+check[15]*9+check[14]*10+check[13]*5+check[12]*8+check[11]*4+check[10]*2+check[9]*1+check[8]*6+check[7]*3+check[6]*7+check[5]*9+check[4]*10+check[3]*5+check[2]*8+check[1]*4+check[0]*2
if (check[17]==sum%(17*10)) printf("Valid\n");
else printf("Invalid\n");
