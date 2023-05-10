# include <iostream>
# include <stdlib.h>
# include <time.h>
using namespace std;

int gamewon(char A[][15])
{int gw=0;
if (A[14][0]=='Z'){cout << "Game Won! Congrats :-)"; gw=1;}
return gw;
}
void gameover()
{
	cout << "You failed! :-("<<endl;
}

void addenemy(char A[][15])
{
	int x,y;
	do{
	x = rand()%15;
	y = rand()%15;
	if (A[x+1][y]!= 'X'&&A[x+1][y]!='Z'&&A[x+1][y]!='H'&&A[x][y]!='E'){break;}
	else if (A[x+1][y+1]!= 'X'&&A[x+1][y+1]!='Z'&&A[x+1][y+1]!='H'&&A[x][y]!='E'){break;}
	else if (A[x+1][y-1]!= 'X'&&A[x+1][y-1]!='Z'&&A[x+1][y-1]!='H'&&A[x][y]!='E'){break;}
	else if (A[x][y-1]!= 'X'&&A[x][y-1]!='Z'&&A[x][y-1]!='H'&&A[x][y]!='E'){break;}
	else if (A[x][y]!= 'X'&&A[x][y]!='Z'&&A[x][y]!='H'&&A[x][y]!='E'){break;}
	else if (A[x][y+1]!= 'X'&&A[x][y+1]!='Z'&&A[x][y+1]!='H'&&A[x][y]!='E'){break;}
	else if (A[x-1][y-1]!= 'X'&&A[x-1][y-1]!='Z'&&A[x-1][y-1]!='H'&&A[x][y]!='E'){break;}
	else if (A[x-1][y]!= 'X'&&A[x-1][y]!='Z'&&A[x-1][y]!='H'&&A[x][y]!='E'){break;}
	else if (A[x-1][y+1]!= 'X'&&A[x-1][y+1]!='Z'&&A[x-1][y+1]!='H'&&A[x][y]!='E'){break;}
	}while(true);
	A[x][y]='E';
}
int moveenemy(int x, int y, char B[][15])
{
	int t,r=0;

	do{
	t= rand()%4;
	if (t==0&&x!=0&&B[x][y]=='E'){if(x==1&&y==14){continue;}else{if(B[x-1][y]=='E'){continue;}
	else {B[x][y]='0';if(B[x-1][y]=='Z'||B[x-1][y]=='X'){r = 1; cout<<" 1 " << x<< ' '<< y <<endl; B[x-1][y]='D'; break;}else B[x-1][y]='E'; break;}}}
	else if (t==1&&y!=0&&B[x][y]=='E'){if(B[x][y-1]=='E'){continue;} else {{B[x][y]='0';if(B[x][y-1]=='Z'||B[x][y-1]=='X'){r=1;cout<<" 1 " << x<< ' '<< y <<endl;B[x][y-1]='D'; break;}
	else {B[x][y-1]='E'; break;}}}}
	else if (t==2&&x!=14&&B[x][y]=='E'){if(B[x+1][y]=='E'){continue;}else{B[x][y]='0';if(B[x+1][y]=='Z'||B[x+1][y]=='X'){r=1;cout<<" 2 " << x<< ' '<< y <<endl;B[x+1][y]='D'; break;}
	else {B[x+1][y]='E'; break;}}}
	else if (t==3&&y!=14&&B[x][y]=='E'){if(x==0&&y==13){continue;}else{if(B[x][y+1]=='E'){continue;}else{B[x][y]='0';if(B[x][y+1]=='Z'||B[x][y+1]=='X'){r=1;cout<<" 3 " << x<< ' '<< y <<endl;B[x][y+1]='D'; break;}
	else {B[x][y+1]='E'; break;}}}}
	}while(true); return r;
}

int findenemy(char A[][15],int ne)
{
	int x=0,y=0,r=0, n=0;
	char B[15][15];
	char C[ne][15][15];
	for(x=0;x<15;x++)
	{
		for(y=0;y<15;y++)
		{
			B[x][y]=A[x][y];
		}
	}
for (int n=0; n<ne; n++)
	{for(x=0;x<15;x++)
	{
		for(y=0;y<15;y++)
		{
			C[n][x][y]='0';
		}
	}}
n=0;
for(x=0;x<15;x++)
{
	for(y=0;y<15;y++)
	{
		if(B[x][y]=='E'){C[n][x][y]='E';}
	}
}
for (n=0; n<ne;n++)
{for(x=0;x<15;x++)
	{
		for(y=0;y<15;y++)
		{
			if(C[n][x][y]=='E'){if(moveenemy(x,y,B)==1){r=1;}}
		}
	}}
	for(x=0;x<15;x++)
	{
		for(y=0;y<15;y++)
		{
			A[x][y]=B[x][y];
		}
	}return r;

}



char movex(char m, char p, char A[][15]){
	char z=p;
	int k=0,l=0;
	for (int k1=0;k1<15;k1++)
		{for (int l1=0;l1<15;l1++)
		{
			if (A[k1][l1]==p){k=k1;l=l1;break;}
		}
		}
	if(m=='W'||m=='w'){A[k][l]='0';if((k-1)==0&&l==14){z='Z';} A[k-1][l]=z;}
	else if(m=='A'||m=='a'){A[k][l]='0';if((k)==0&&(l-1)==14){z='Z';} A[k][l-1]=z;}
	else if(m=='S'||m=='s'){A[k][l]='0';if((k+1)==0&&l==14){z='Z';} A[k+1][l]=z;}
	else if(m=='D'||m=='d'){A[k][l]='0';if((k)==0&&(l+1)==14){z='Z';} A[k][l+1]=z;}
	else if(m=='Q'||m=='q'){A[k][l]='0';if((k-1)==0&&(l-1)==14){z='Z';} A[k-1][l-1]=z;}
	else if(m=='E'||m=='e'){A[k][l]='0';if((k-1)==0&&(l+1)==14){z='Z';} A[k-1][l+1]=z;}
	else if(m=='Z'||m=='z'){A[k][l]='0';if((k+1)==0&&(l-1)==14){z='Z';} A[k+1][l-1]=z;}
	else if(m=='C'||m=='c'){A[k][l]='0';if((k+1)==0&&(l+1)==14){z='Z';} A[k+1][l+1]=z;}
	return z;
}

int main(){
srand(time(NULL));
char m,p;
int r1=0, count=0, countenemy=0;
char A[15][15];
A[14][0]='X';
A[0][14]='H';
for(int i=0;i<15;i++)
	{
	for(int j=0;j<15;j++)
		{if ((i==14)&&(j==0)){}
		else if (i==0&&j==14){}
		else A[i][j]='0';
		}
	}

p='X';
do{
	for(int i=0;i<15;i++)
		{
		for(int j=0;j<15;j++)
			{
			 cout << A[i][j] << ' ' ;
			}
		cout << endl;
		} cout << endl;
cout << "Where do you want to move "<< p <<" (W,A,S,D,E,Z,Q,C)" <<endl;
cin >> m;
p=movex(m,p, A);
for(int i=0;i<15;i++)
	{
	for(int j=0;j<15;j++)
		{
		 cout << A[i][j] << ' ' ;
		}
	cout << endl;
	} cout << endl;
if (gamewon(A)==1){break;}
r1=findenemy(A, countenemy);
for(int i=0;i<15;i++)
	{
	for(int j=0;j<15;j++)
		{
		 cout << A[i][j] << ' ' ;
		}
	cout << endl;
	} cout << endl;
if (r1==1){gameover(); break;}
if(count%3==0)
{addenemy(A); countenemy=countenemy+1;}
count=count+1;
}while(true);

return 0;
}










