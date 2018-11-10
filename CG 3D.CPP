#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

int gd=DETECT,gm,midx,midy;

void drawaxis()
{  int maxx = getmaxx();
   int maxy = getmaxy();
  line(0,(maxy/2),maxx,(maxy/2));
  line(maxx/2,0,maxx/2,maxy);
}

void scale3d()
{
  cout<<"\n Enter the Scaling factors:\n";
  float sx,sy;

  cout<<"Sx: ";
  cin>>sx;

  cout<<"\nSy: ";
  cin>>sy;
  initgraph(&gd, &gm,"C://TURBOC3//BGI");
  drawaxis();
  bar3d(midx+(100*sx),midy-(20*sy), midx+(90*sx),midy-(60*sy), 20, 1);
}

void rot3d()
{ clrscr();
  cout<<"\nEnter the angle:";
  float ang,arad;
  cin>>ang;

  arad=(3.14/180.0)*ang;

  initgraph(&gd, &gm,"C://TURBOC3//BGI");
  drawaxis();
  bar3d(midx+((100*cos(arad))-(20*sin(arad))),midy-((100*sin(arad))+(20*cos(arad))), midx+((90*cos(arad))-(60*sin(arad))),midy-((90*sin(arad))+(60*cos(arad))), 20, 1);
}


void trans3d()
{
  cout<<"\n Enter the translation factors:\n";
  int tx,ty;

  cout<<"tx: ";
  cin>>tx;

  cout<<"\nty: ";
  cin>>ty;
  initgraph(&gd, &gm,"C://TURBOC3//BGI");
  drawaxis();
  bar3d(midx+100+tx,midy-20-ty, midx+90+tx,midy-60-ty, 20, 1);
}



int main()
{   clrscr();


   int i,ch;
   char ch2;

   initgraph(&gd, &gm,"C://TURBOC3//BGI");

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;

   drawaxis();
   bar3d(midx+100, midy-20, midx+90,midy-60, 20, 1);
   getch();
   do{
   clrscr();
   cout<<"\n1.Translation\n2.Scaling\n3.Rotation\n";
   cout<<"Your choice: ";
   cin>>ch;
   switch(ch)
   {
     case 1:
	trans3d();
	break;
     case 2:
	scale3d();
	break;
     case 3:
	rot3d();
	break;
     default:
	break;
   }
   cout<<"\nDo u want to continue: ";
   cin>>ch2;
   }while(ch2=='y' || ch2=='Y');

   getch();

}