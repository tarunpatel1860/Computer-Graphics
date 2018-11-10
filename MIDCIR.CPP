#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void drawsym(int x,int y,int xc,int yc)
{
 putpixel(y+xc,x+yc,YELLOW);
 putpixel(x+xc,-y+yc,YELLOW);
 putpixel(y+xc,-x+yc,YELLOW);
 putpixel(-y+xc,-x+yc,YELLOW);
 putpixel(-x+xc,-y+yc,YELLOW);
 putpixel(-x+xc,y+yc,YELLOW);
 putpixel(-y+xc,x+yc,YELLOW);
}
void drawcir(int r,int xc,int yc)
{
 int p=(1-r),x=0,y=r;
 putpixel(x+xc,y+yc,YELLOW);
 outtextxy(xc,yc,"x,y");
 while(x<=y)
 {
 if(p<0)
 {
   x=x+1;
   p=p+(2*x)+1;
   putpixel(x+xc,y+yc,YELLOW);
 }

 else
 {
   x=x+1;
   y=y-1;
   p=p+(2*x)-(2*y)+1;
   putpixel(x+xc,y+yc,YELLOW);
 }

 drawsym(x,y,xc,yc);
 }
}


void main()
{
int r,xc,yc,gd=DETECT,gm;
cout<<"\n\t\t\tMid Point Circle Drawing \n";
cout<<"\nEnter the radius : ";
cin>>r;
cout<<"\nEnter the coordinates of center : ";
cin>>xc>>yc;
initgraph(&gd,&gm,"C://TURBOC3//BGI");
cout<<"\n The required circle is :\n";
drawcir(r,xc,yc);
getch();
}