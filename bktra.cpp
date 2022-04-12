#include<iostream.h>
#include<iomanip.h>
#include<string.h>
using namespace std;
class PTGT
{
	protected:
	char Hang[20];
	char Ma[20];
	int ngay;
	float Gia;
	 public:
	     PTGT(char *a="", char *b=" ", int c=0, int d=0, int e=0,float g=0)
	     {
     		strcpy(Hang,a);
     		strcpy(Ma,b);
     		ngay=c;
     		
     		Gia=g;
     	}
     	~PTGT(){};
     	void nhap()
     	{
	     	cin.ignore();
	     	cout<<"\t\t\tNhap hang san xuat: "; cin.getline(this->Hang,20);
	     	cout<<"\t\t\tNhap ma phuong tien: "; cin.getline(this->Ma,10);
	     	cout<<"\t\t\tNhap ngay san xuat: "; cin>>this->ngay;
	     	cout<<"\t\t\tNhap gia chua thue: ";cin>>this->Gia;
	     }
	     void xuat()
	     {
     		cout<<setw(20)<<this->Hang<<setw(10)<<this->Ma<<setw(10)<<this->ngay;
     		cout<<setw(10)<<this->Gia;
     	}
};
class MAYBAY: public PTGT
{
	private:
	char DBay[10];
	int SCN;
	char NoiDK[20];
 	public:
          MAYBAY(char *a="", char *b=" ", int c=0,float g=0, char *db=" ",
		  int cn=0, char *dk=" "):PTGT()
		  {
  			strcpy(DBay,db);
  			SCN=cn;
  			strcpy(NoiDK,dk);	
  		  }
  		  ~MAYBAY()
  		  {};
  		  friend istream& operator >>(istream &is,MAYBAY &m)
  		  {
  		  	m.nhap();
  		  	is.ignore();
  		  	cout<<"Nhap duong bay: "; is.getline(m.DBay,10);
  		  	cout<<"Nhap so cho ngoi: "; is>>m.SCN;
  		  	is.ignore();
  		  	cout<<"Nhap noi dang ki kinh doanh: "; is.getline(m.NoiDK,10);
  		  	return is;
  		  }
  		  float GiaThue()
  		  {
  		  	return Gia+ (Gia * 0.08);
  		  }
  		  friend bool operator<(MAYBAY &m, int a)
  		  {
  		  	 return (m.SCN < a);
  		  }
  		  friend ostream& operator <<(ostream &os,MAYBAY &m)
  		  {
  		  	m.xuat();
  		  	os<<setw(10)<<m.DBay<<setw(10)<<m.SCN<<setw(10)<<m.NoiDK<<setw(10)<<m.GiaThue()<<endl;
	      }
	      char *GetDK()
	      {
      		return NoiDK;
      	}
      	char *GetHangSX()
      	{
	      	return Hang;
      	}
      	int getSCN()
      	{
      		return SCN;
      	} 
};
void table()
{
	cout<<setw(20)<<"HANG SAN XUAT"<<setw(10)<<"MA PHUONG TIEN"<<setw(10)<<"NGAY SAN XUAT"<<setw(15)<<"GIA CHUA THUE";
	cout<<setw(10)<<"DUONG BAY"<<setw(10)<<"SO CHO NGOI"<<setw(10)<<"NOI DKKD"<<setw(15)<<"GIA SAU THUE"<<endl;
}
void InDS(MAYBAY m[], int &n)
{
     table();
	for (int i=0; i<n; i++) cout<<m[i];
}
void sapxeptangdan(MAYBAY m[], int &n)
{
   for (int i=0; i<n; i++)
    	{for (int j=i+1; j<n; j++)
         {
         	if (m[i].GiaThue()>m[j].GiaThue())
         	    {
    	         	MAYBAY temp=m[i];
    	         	m[i]=m[j];
    	         	m[j]=temp;
    	         }
         }
    }
    cout<<"\nCHON 1 DE XEM DANH SACH"<<endl;
}
void VietNam(MAYBAY m[], int &n)
{
	for (int i=0; i<n; i++)
	  {
  		if (strcmp(m[i].GetDK(),"Viet Nam")==0)
  		     {
    		  	cout<<"\n\nTHONG TIN MAY BAY DK KINH DOANH TAI VIET NAM"<<endl;
    		  	table();
    		  	cout<<m[i];
    		  }
  	 }
}
void demcho(MAYBAY m[], int &n)
{
	
	int dem=0;
 	for (int i=0;i<5;i++)
	{
		if (m[i].getSCN()>200)
		{
			dem++;
		}
	}
	cout<<"\nSo may bay co cho ngoi >200 la :"<<dem<<endl;
}
int main()
{
   int n;
  cout<<"\nNhap so luong may bay: "; cin>>n;
   MAYBAY m[100];
  for (int i=0; i<n; i++) cin>>m[i];
  int x;
  do
   {
   	 cout<<"\n\t\t\t\t\tMENU"<<endl;
   	 cout<<"\t\t\t\t0. Thoat!"<<endl;
   	 cout<<"\t\t\t\t1. In danh sach may bay!"<<endl;
   	 cout<<"\t\t\t\t2. In danh sach may bay dang ki kinh doanh tai Viet Nam!"<<endl;
   	 cout<<"\t\t\t\t3. In danh sach may bay tang dan theo gia sau thue"<<endl;
   	 cout<<"\t\t\t\t3. In danh sach may bay co so cho ngoi >200"<<endl;
   	 
   	 cout<<"\t\t\t\tNHAP LUA CHON: "; cin>>x;
   	 system("cls");
		 switch(x)
		    {
    			case 1:InDS(m,n);break;
    			case 2:VietNam(m,n);break;
    			case 3:sapxeptangdan(m,n);break;
    			case 4:demcho(m,n);break;
    		
					 }
 		}
  while (x!=0); 	
}
