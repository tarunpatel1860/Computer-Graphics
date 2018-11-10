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

void xyaxis()
{
	initgraph(&gd,&gm,"C://TURBOC3//BGI");
	xmax=getmaxx();
	ymax=getmaxy();
	xmid=(xmax)/2;
	midy=(ymax)/2;

	for(int i=0;i<=xmax;i++)
	{ putpixel(i,(ymax/2),YELLOW);
	}
	for(i=0;i<=ymax;i++)
	{
	  //delay(10);
	  putpixel((xmax/2),i,GREEN);
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

void trans()
{ clrscr();
 int tx,ty;
 cout<<"\n Enter the translation factor in following directions :\n";
 cout<<" x- direction (tx): ";
 cin>>tx;
 cout<<"\n y- direction (ty): ";
 cin>>ty;

 x1+=tx; x2+=tx; x3+=tx;
 y1+=ty; y2+=ty; y3+=ty;

 drawtri(YELLOW);
}

void scale()
{
 clrscr();
 float Sx,Sy;
 cout<<"\n Enter the Scaling factors in following directions :\n";
 cout<<" x- direction (Sx): ";
 cin>>Sx;
 cout<<"\n y- direction (Sy): ";
 cin>>Sy;

 x1*=Sx; x2*=Sx; x3*=Sx;
 y1*=Sy; y2*=Sy; y3*=Sy;
 drawtri(GREEN);
}

void rotation()
{ clrscr();
  int ang;
  float rad;
  cout<<"\nEnter the angle: ";
  cin>>ang;
  rad=(3.14/180.0)*(float)ang;

  int xi=(x1*cos(rad))+(y1*-sin(rad));
  int yi=(x1*sin(rad))+(y1*cos(rad));
  int xii=(x2*cos(rad))+(y2*-sin(rad));
  int yii=(x2*sin(rad))+(y2*cos(rad));
  int xiii=(x3*cos(rad))+(y3*-sin(rad));
  int yiii=(x3*sin(rad))+(y3*cos(rad));
  x1=xi;
  y1=yi;
  x2=xii;
  y2=yii;
  x3=xiii;
  y3=yiii;

   drawtri(YELLOW);

}

void main()
{
clrscr();

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
cout<<"\n1. Translation\n2. Scaling\n3. Rotation\n4. Exit\n";
cout<<"\n Enter your choice : ";
cin>>ch;

switch(ch)
{
 case 1:
     trans();
     break;
 case 2:
      scale();
      break;
 case 3:
       rotation();
       break;
 case 4:
       exit(0);
       break;
 }

 cout<<"\nDo you want to continue(y/n): ";
 cin>>con;
}while((con=='y') || (con=='Y'));

getch();
}
