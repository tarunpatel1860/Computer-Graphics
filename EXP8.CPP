#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
int x1,y1,x2,y2,x3,y3;
int gd=DETECT,gm,ch;
char con;
int xmax,ymax,xmid,midy;
int x,y,xi,xii,xiii,yi,yii,yiii;
void calc()
{initgraph(&gd,&gm,"C://TURBOC3//BGI");
xmax=getmaxx();
ymax=getmaxy();
xmid=xmax/2;
midy=ymax/2;
}

void xyaxis()
{
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	int xmx=getmaxx();
	int ymx=getmaxy();

	for(int i=0;i<=xmx;i++)
	{ putpixel(i,(ymx/2),YELLOW);
	}
	for(i=0;i<=ymx;i++)
	{
	  //delay(10);
	  putpixel((xmx/2),i,GREEN);
	}
}



void drawtri(int color=WHITE)
{
 clrscr();
 xyaxis();

 setcolor(color);
 line(x1+xmid,midy-y1,xmid+x2,midy-y2);
 line(xmid+x1,midy-y1,xmid+x3,midy-y3);
 line(xmid+x2,midy-y2,xmid+x3,midy-y3);
 outtextxy(x1+xmid,midy-y1,"(x1,y1)");
 outtextxy(x2+xmid,midy-y2,"(x2,y2)");
 outtextxy(x3+xmid,midy-y3,"(x3,y3)");
}

void rotation()
{ clrscr();

  cout<<"\n Enter any arbiatary point : ";
  cin>>x>>y;

  int ang;
  float rad;
  cout<<"\nEnter the angle: ";
  cin>>ang;
  rad=(3.14/180.0)*(float)ang;

  xi=(x1*cos(rad))+(y1*-sin(rad));
  yi=(x1*sin(rad))+(y1*cos(rad));
  xii=(x2*cos(rad))+(y2*-sin(rad));
  yii=(x2*sin(rad))+(y2*cos(rad));
  xiii=(x3*cos(rad))+(y3*-sin(rad));
  yiii=(x3*sin(rad))+(y3*cos(rad));


  x1=xi+x;
  y1=yi-y;
  x2=xii+x;
  y2=yii-y;
  x3=xiii+x;
  y3=yiii-y;

  xmid+=x;
  midy-=y;
   drawtri(YELLOW);
    outtextxy(xmid,midy,".i am here");
   getch();
   calc();

}

void ref()
{ 	char ch;
	cout<<"\n you want to reflect line w.r.t (x/y) axis : ";
	cin>>ch;
	calc();
	if(ch=='x')
	{
		x1=x1-x;
		x2=x2-x;
		x3=x3-x;
		y1=-y1-y;
		y2=-y2-y;
		y3=-y3-y;
		drawtri();
	}

	else
	{
		 x1=-x1-x;
		 x2=-x2-x;
		 x3=-x3-x;
		 y1=y1-y;
		 y2=y2-y;
		 y3=y3-y;
		 drawtri();
	}
		getch();
}

void main()
{
clrscr();
calc();
cout<<"\n Enter the three coordinates of triangle:\n";
cout<<"x1 y1: ";
cin>>x1>>y1;
cout<<"\nx2 y2: ";
cin>>x2>>y2;
cout<<"\nx3 y3: ";
cin>>x3>>y3;

drawtri();
getch();
clrscr();
do{
cout<<"\n1. Rotation \n2. Reflection about line\n3. Exit\n";
cout<<"\n Enter your choice : ";
cin>>ch;

switch(ch)
{
 case 1:
     rotation();
     break;
 case 2:
       ref();
       break;
 case 3:
       exit(0);
       break;
 }

 cout<<"\nDo you want to continue(y/n): ";
 cin>>con;
}while((con=='y') || (con=='Y'));

getch();
}
