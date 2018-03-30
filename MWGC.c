#include<stdio.h>
#define MWGC(x,i)  (( (x) >> (i) ) & 1)  //CHECKING i BIT OF THE STATE
#define XOR(x,y,i) ( MWGC(x,i) ^ MWGC(y,i) ) //CHECKING THAT ITEM IS MOVED OR NOT




//******FUNCTION DECLARATION******//
int edge(int,int);
void Display(int);
int *returnarray1();
int *returnarray2();

//*********MAIN FUNCTION BEGINS*******//
int main()
{

int x,y;
int *p=returnarray1();
printf("SOLUTION 1 :\n\n");
for(x=0;x<8;x++)
   {
     int k=*(p+x);
     printf("STEP %d : ", x+1);
     Display(k);
   }

int *q=returnarray2();
printf("\n\nSOLUTION 2 :\n\n");
  for (y=0;y<8;y++)
  {
    int l=*(q+y);
    printf("STEP %d : ",y+1);
    Display(l);
  }

return 0;

}


//******THIS FUNCTION RETURNS SOLUTION 1 OF THE PROBLEM****//
int *returnarray1()
{

 int i,j,l,temp=0;
 static int y[8];


 for (i=0;i<=15;i=j)
 {
  for (j=0;j<=15;j++)
  {
   if(!(i==13&&j==4))
   {
    if (edge(i,j))
    {
     for(l=0;l<8;l++)
     {
      if(j==y[l])
        break;
     }

      if(j==y[l])
        continue;

      if (temp==0)
      {
       y[temp]=i;
       temp++;
       y[temp]=j;
        break;
      }

      else
      {
       temp++;
       y[temp]=j;
       break;
      }
     }
    }
   }
 }
  return y;
}



//******THIS FUNCTION RETURNS SOLUTION 2 OF THE PROBLEM****//
int *returnarray2()
{

    int i2,j2,l2,temp2=0,c1,c2;
    static int z[8];
   c1=XOR(i2,j2,3)&&(!AND(i2,j2,2))&&AND(i2,j2,1)&&XOR(i2,j2,0);
   c2=XOR(i2,j2,3)&&XOR(i2,j2,2)&&(!AND(i2,j2,1))&&AND(i2,j2,0);

  for(i2=0;i2<=15;i2=j2)
  {
   for(j2=0;j2<=15;j2++)
   {
    if(edge(i2,j2))
    {
     if(c1||c2)
        continue;
     for(l2=0;l2<8;l2++)
     {
      if(j2==z[l2])
        break;
     }
     if(j2==z[l2])
        continue;
     if(temp2==0)
     {
       z[temp2]=i2;
       temp2++;
       z[temp2]=j2;
        break;
     }
     else
     {
       temp2++;
       z[temp2]=j2;
       break;
     }
    }
   }
  }
   return z;
 }


/****THIS FUNCTION CHECKS WHETHER THERE IS EDGE BETWEEN i AND j OR NOT***
 *****IF THERE IS NO EDGE THEN RETURN 0 OTHERWISE 1*******/
int edge(int i,int j)
{

 int Mmoves,WEG,GEC,x,y;
 int Invalid,moveswithman,check;
 int k,movingatatime;

//*****INVALID STATES WHEN WOLF EATS GOAT ****//
WEG =MWGC(j,3)^MWGC(j,2) && MWGC(j,3)^MWGC(j,1);
//*****INVALID STATES WHEN GOAT EATS CABBAGE ***//
GEC= MWGC(j,3)^MWGC(j,1) && MWGC(j,3)^MWGC(j,0);
Invalid = WEG||GEC;

if(Invalid)
{
 return 0;
}

Mmoves = XOR(i,j,3);

moveswithman = 1;
  for (k=0;k<4;k++)
    if ( MWGC(i,k)^MWGC(j,k) && MWGC(j,3)^MWGC(j,k) )
      {
      moveswithman = 0;
      break;
      }
movingatatime = XOR(i,j,0) + XOR(i,j,1) + XOR(i,j,2) + XOR(i,j,3);
if (movingatatime<3)
{
  x=1;
}
check = Mmoves && !Invalid && x && moveswithman;

return check;
}



//*******THIS FUNCTION DISPLAYS THE SOLUTION*******
void Display(int i)
{
   if (MWGC(i,3) == 0) printf("MAN");
   if (MWGC(i,2) == 0) printf(" WOLF ");
   if (MWGC(i,1) == 0) printf(" GOAT");
   if (MWGC(i,0) == 0) printf(" CABBAGE ");
   printf(" ~~~~~~~~~~~~~~~~~~~~~~~~ ");
   if (MWGC(i,3) == 1) printf("MAN");
   if (MWGC(i,2) == 1) printf(" WOLF ");
   if (MWGC(i,1) == 1) printf(" GOAT");
   if (MWGC(i,0) == 1) printf(" CABBAGE");
   printf("\n");
}
