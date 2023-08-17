#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

struct AREA{
	int x1,y1,x2,y2;
	int area(){
		return (x2-x1)*(y2-y1);
	}
};

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	AREA P, Q;
	int tarp;
	cin>>P.x1>>P.y1>>P.x2>>P.y2;
	cin>>Q.x1>>Q.y1>>Q.x2>>Q.y2;
	int xOverLap = max(0,min(P.x2,Q.x2)-max(P.x1,Q.x1));
	int yOverLap = max(0,min(P.y2,Q.y2)-max(P.y1,Q.y1));
	if(xOverLap == P.x2 - P.x1 && yOverLap == P.y2 - P.y1)
		tarp = 0;
	else if(xOverLap == P.x2 - P.x1 || yOverLap == P.y2 - P.y1)
		tarp = P.area() - xOverLap*yOverLap;
	else
		tarp = P.area();
	cout<<tarp;
}