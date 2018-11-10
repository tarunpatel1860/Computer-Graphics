#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void ffill(int x,int y,int ocol,int fcol)
{
 int ccol=getpixel(x,y);
 if(ccol==ocol)
 {
   putpixel(x,y,fcol);
   ffill(x+1,y,ocol,fcol);
   ffill(x-1,y,ocol,fcol);
   ffill(x,y+1,ocol,fcol);
   ffill(x,y-1,ocol,fcol);
 }
}

void drawtri()
{
int gd=DETECT,gm,x1,x2,x3,y1,y2,y3;
char *col1,*col2,*col3;

cout<<"\n Enter coordinates of triangle\n (X1,Y1): ";
cin>>x1>>y1;
cout<<"\n (X2,Y2): ";
cin>>x2>>y2;
cout<<"\n (X3,Y3): ";
cin>>x3>>y3;


  setcolor(YELLOW);
  line(x1,y1,x2,y2);
  setcolor(RED);
  line(x3,y3,x2,y2);
  setcolor(GREEN);
  line(x3,y3,x1,y1);

}

void main()
{
clrscr();
int gd=DETECT,gm,x,y;
cout<<"\n\t\tFlood Fill Algorithm\n";


drawtri();

cout<<"\n Enter Any Interior point coordinates of triangle (X,Y): ";
cin>>x>>y;

initgraph(&gd,&gm,"C://TURBOC3//BGI");
cout<<"\nThe required output is : \n";
int ocol=getpixel(x,y);
ffill(x,y,ocol,YELLOW);
getch();

}