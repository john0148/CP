#include<iostream>
#include<cmath>

using namespace std;

struct AREA{
	int x1,y1,x2,y2;
	int area(){
		return (x2-x1)*(y2-y1);
	}
};

int intersect_two_area(AREA p, AREA q){
	int xOverLap = max(0,min(p.x2,q.x2)-max(p.x1,q.x1));
	int yOverLap = max(0,min(p.y2,q.y2)-max(p.y1,q.y1));
	return xOverLap*yOverLap;
}

int intersect_three_area(AREA p, AREA q, AREA r){
	int xOverLap = max(0,min(p.x2,min(q.x2,r.x2))-max(p.x1,max(q.x1,r.x1)));
	int yOverLap = max(0,min(p.y2,min(q.y2,r.y2))-max(p.y1,max(q.y1,r.y1)));
	return xOverLap*yOverLap;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	AREA P,Q,R;
	cin>>R.x1>>R.y1>>R.x2>>R.y2;
	cin>>P.x1>>P.y1>>P.x2>>P.y2;
	cin>>Q.x1>>Q.y1>>Q.x2>>Q.y2;
	int res = intersect_two_area(P,R) + intersect_two_area(Q,R) - intersect_three_area(P,Q,R);
	if(R.area() > res)
		printf("YES");
	else
		printf("NO");
}