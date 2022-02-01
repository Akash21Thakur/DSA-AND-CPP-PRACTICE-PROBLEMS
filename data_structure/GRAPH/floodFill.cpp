#include<iostream>
using namespace std;


int R=20,C=20;

void print(char mat[10][10])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
           cout<<mat[i][j]<<"";
        cout<<endl;   
    }
}

int dy[]={0,-1,0,1};
int dx[]={-1,0,1,0};

void floodFill(char mat[][10],int i,int j,char ch,char color)
{
    //BASE CASE => BOUNDARY
    if(i<0 or j<0 or i>=R or j>=C)
       return;

    //FIGURE BOUNDARY
    if(mat[i][j]!=ch)
      return;

    //REC CASE
    mat[i][j]=color;

    for(int k=0;k<4;k++)
      floodFill(mat,i+dx[k],j+dy[k],ch,color);     


}

int main()
{
    cin>>R>>C;

    char mat[10][10];

    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        cin>>mat[i][j];

    print(mat);  

cout<<"Enter values\n";
    char ch,color;
    int i,j;
    cin>>i>>j>>ch>>color;

      

    floodFill(mat,i,j,ch,color);
    cout<<endl;
    print(mat);

}