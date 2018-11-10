#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void bfill(int x,int y,int fcol,int bcol)
{
 int ccol=getpixel(x,y);
 if(ccol!=fcol && ccol!=bcol)
 {
   putpixel(x,y,fcol);
   bfill(x+1,y,fcol,bcol);
   bfill(x-1,y,fcol,bcol);
   bfill(x,y+1,fcol,bcol);
   bfill(x,y-1,fcol,bcol);
 }
}
void main()
{
clrscr();
int gd=DETECT,gm,x1,x2,y1,y2,x,y;
cout<<"\n\t\tBoundary Fill Algorithm\n";
cout<<"\n Enter starting point coordinates of rectangle (X1,Y1): ";
cin>>x1>>y1;
cout<<"\n Enter end point coordinates of rectangle (X2,Y2): ";
cin>>x2>>y2;
cout<<"\n Enter Any Interior point coordinates of rectangle (X,Y): ";
cin>>x>>y;

initgraph(&gd,&gm,"C://TURBOC3//BGI");
cout<<"\nThe Required Output is: \n";
rectangle(x1,y1,x2,y2);
bfill(x,y,YELLOW,WHITE);
getch();
}