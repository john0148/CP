#include<bits/stdc++.h>
#include <fstream>
int main(){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        int m,n;
        std::cin>>m>>n;
        int a1[m],b1[m],a2[n],b2[n];
        std::vector<int> v;
        for(int i=0;i<m;i++)
                std::cin>>a1[i]>>b1[i];
        for(int j=0;j<n;j++)
                std::cin>>a2[j]>>b2[j];
        int i=0,j=0;
        while (i<m || j<n){
                if (a1[i] == a2[j]){
                        if (b1[i]<b2[j])
                                v.push_back(b2[j]-b1[i]);
                        i++;
                        j++;
                }
                else if (a1[i] > a2[j]){
                        a1[i]-=a2[j];
                        if (b1[i]<b2[j])
                                v.push_back(b2[j]-b1[i]);
                        j++;
                }
                else{
                        a2[j]-=a1[i];
                        if (b1[i]<b2[j])
                                v.push_back(b2[j]-b1[i]);
                        i++;
                }                
        }
        std::cout<<*max_element(v.begin(),v.end());

}