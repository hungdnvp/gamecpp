#include<iostream>
#include<time.h>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;
int matran[21][21];
int fake[21][21];

void setup_matran(int& m,int& n)
{
	for(int i=1;i<=m;i++)
    {
        for(int j =1;j<=n;j++)
        {
            matran[i][j] = (rand()%3)/2; // tỉ lệ ra 0= 2/3 ;tỉ lệ ra 1 = 1/3;............................................            
        }
    }
}
void setup_fake(int& m,int& n)
{
	for(int i=1;i<=m;i++)
    {
        for(int j =1;j<=n;j++)
        {
            fake[i][j] = 0;   
        }
    }
}
void output(int a[21][21],int m,int n)
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
            cout<<"\n";
    }
    cout<<"\n";
}
fstream f;
void xuat(int m,int n)
{
    f<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(fake[i][j] !=0)
                f<<" ("<<i<<";"<<j<<")";
        }
    }
}
void Try(int i,int j,int m,int n)
{
    if(matran[i][j] ==0 && fake[i][j] !=1)
    {
        fake[i][j] =1;
        if(i==1||j==1||i==m||j==n)
        {
            xuat(m,n);
        	fake[i][j] =0;
//        	  setup_fake(m,n);
		}
        else{
            Try(i+1,j,m,n);
            Try(i-1,j,m,n);
            Try(i,j+1,m,n);
            Try(i,j-1,m,n);
            fake[i][j] =0;
        }
    }
}
int main()
{
    int m,n;
    f.open("output.txt",ios::out|ios::in|ios::trunc);
    cout<<"nhap vao ma tran mxn:\n";
    cout<<"m:= ";cin>>m;
    cout<<"n:= ";cin>>n;

	setup_matran(m,n); // matran=random
	setup_fake(m,n);  // fake[][] ={0};
    output(matran,m,n);

    int row,col;
    cout<<"nhap vao vi tri bat dau:\n";
    cout<<"row:=";cin>>row;
    cout<<"col:=";cin>>col;
    if(matran[row][col] == 1)
    {
        cout<<"vi tri bat dau ko hop le";
        return 0;
    }
    Try(row,col,m,n);
    // ghi file xong _> doc file
    f.seekg(1,ios::beg);
    string line="";
    string data ="";
    getline(f,line);
    getline(f,line);
    data = line;
    // f.seekg(2,ios::cur);
    while(!f.eof())
    {
        getline(f,line);
        if(data.length() > line.length())
        {
            data = line;
        }
    }
    // data luu chuoi con duong ngan nhat
    cout<<"con duong ngan nhat la: \n";
    cout<<data;
    cout<<"\ncac cach di khac duoc luu trong file output.txt";
    f.close();
    return 0;

}
