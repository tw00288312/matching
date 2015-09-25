#include<match.h>
#include<cstdlib>
using namespace std;
int main(){
	int temp,max=10; // MAX DIFFERENCE
	srand(time(NULL));
	int size=0,num=0,ele;
	cout<<"size:";
	cin>>size;
	cout<<"number";
	cin>>num;
	match M(size);
	for(int i=0;i<num;i++){
		cout<<"number: "<<i<<endl;
		for(int j=1;j<=size;j++){   //sample a random matching
			ele=(rand()%size)+1;
			for(int k=1;k<j;k++){
				if(ele==M.entry(k)){
					ele=(rand()%size)+1;
					k=0;
				}
		
			}
			M.edit(j,ele);
		}
	if(!M.isContinuous(temp)){  M.printSign();
				cout<<"CL :"<<temp<<endl;
				if (max>temp)max = temp;}
/*		if(!M.rotation_balance()){
			temp = M.test();
			cout<<"D:"<<temp<<endl;
			if(max<temp) max = temp;
*/		}
	


cout<<"\n the maximal diffrence is :"<<max<<endl;
return 0;
}
