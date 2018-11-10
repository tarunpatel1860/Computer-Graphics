#include<graphics.h>
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

void ddaline(int x1,int y1,int x2,int y2)
{
   int dx=(x2-x1);
   int dy=(y2-y1);
   int step;

   if(abs(dx)>abs(dy))
     step=abs(dx);

   else
      step=abs(dy);

   float xi=(dx/(float)step);
   float yi=(dy/(float)step);

   float x=x1,y=y1;

   for(int i=0;i<=step;i++)
   { putpixel(x,y,YELLOW);
     x=x+(xi);
     y=y+(yi);
     delay(100);

     }
 }
void main()
{
  clrscr();
  int x1,y1,x2,y2;
  cout<<"\n\t\t\t DDA Line Drawing Algorithm\n";
  cout<<"\t\t\tBY- Tarun Patel\n\n";
  cout<<"\n Enter the first coordinate: ";
  cin>>x1>>y1;
  cout<<"\n Enter the second coordinate: ";
  cin>>x2>>y2;

  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

 cout<<"\n The required line is :\n";
 ddaline(x1,y1,x2,y2);
  getch();
}


