#include<bits/stdc++.h>
#include<fstream>
int main(){
	
	int n; 
	std::cin>>n;
	int a[101][3]={};
	std::map<std::string,int> m;
	m["Bessie"]=0; 	m["Mildred"]=1; m["Elsie"]=2;
	int x,y; 
	std::string s;
	for(int i=0;i<n;i++){
		std::cin>>x>>s>>y;
		a[x-1][m[s]]=y;
	}

	int d=0;
	int max1,max2;
	int b[200]={},c[200]={};
	c[0]=a[0][0]; c[1]=a[0][1]; c[2]=a[0][2];

	for(int i=0;i<100;i++){
			b[0]+=a[i][0]; b[1]+=a[i][1]; b[2]+=a[i][2];
			c[0]+=a[i+1][0]; c[1]+=a[i+1][1]; c[2]+=a[i+1][2];
			std::cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<"\n";
			std::cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<"\n";
		
		max1=*std::max_element(b,b+3);
		max2=*std::max_element(c,c+3);
		std::cout<<"max1 max2 "<<max1<<" "<<max2<<"\n";

		for(int j=0;j<3;j++)
			if (max1 != max2){
				d++;
				break;
			}
			else 
				if ((b[j] != c[j]) & ((b[j]==max1) || (c[j]==max2))){
					d++;
					std::cout<<b[j]<<" "<<c[j]<<"\n";
					break;
				}
		std::cout<<"d = "<<d<<"\n";
		std::cout<<"\n";
	}
	std::cout<<d;		
}