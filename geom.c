#include "geom.h"

int getdir(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3){
    long long result = (y2-y1)*(x3-x2) - (x2-x1)*(y3-y2);
    if(result > 0) 
        return 1;
    if(result < 0) 
        return 2;
    return 0;
}

int dotheycut(int r1,int c1,int r2,int c2,int a1,int b1,int a2,int b2){
    long long x1=c1,y1=r1,x2=c2,y2=r2,x3=b1,y3=a1,x4=b2,y4=a2;
    int d1 = getdir(x1,y1,x2,y2,x3,y3);
    int d2 = getdir(x1,y1,x2,y2,x4,y4);
    int d3 = getdir(x3,y3,x4,y4,x1,y1);
    int d4 = getdir(x3,y3,x4,y4,x2,y2);
    
    if(d1 != d2 && d3 != d4)
        return 1;
    return 0;
}