#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int i;
int getcust_id();
int getsupp_id();
void main_screen();
void bill_printing();
void medicine_menu();
void medicine_sale();
void medicine_stock();
void update_medicine_stock();
void medicine_purchase();
void medicine_search();
void supplier_menu();
void supplier_entry();
void supplier_list();
void search_supplier();
void customer_menu();
void customer_search();
void customer_entry();
void customer_list();
void profit_rpt();
//===================================structures =========================
struct medical
{
	char id[6];
	char medi_name[20];
	int rack;
	char cabnit[2];
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	char pur_date[15];
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	char comp_name[20];
	char supp_name[30];
 };

struct medical temp;
struct medical x[20];
FILE *ptr;

char a[10];
struct supplier
{
	int supp_id;
	char supp_name[25];
	char city[20];
	char mob_no[11];
	char email[30];

};
struct supplier temp1;

struct customer
{
	int cust_id;
	char cust_name[30];
	char city[20];
	char mob_no[11];
	char email[50];

};
struct customer temp_c;
FILE *ptr1;

struct bill
{
	char billno[6];
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
};
struct bill bil;
FILE *ptrbill;

struct profit_report
{
	char medi_id[6];
	char medir_name[20];
	int qty;
	float rate;
	float unit;
	float profit;
};
struct profit_report pr_r;
FILE *ptrpr_r;
//=========================== validation =========================
void ventry(char t[],int code)
{
  int i=0;
	if(code==0)
	{
		while((t[i]=getch())!='\r' && i<30)
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;
		}
	}
	else if(code==1)
	{
		while((t[i]=getch())!='\r' && i<10 )
		if((t[i]>=48 && t[i]<=57) || t[i]==46 ||  t[i]=='-')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{  printf("%c%c%c",8,32,8);
			i--;}
	}
	else if(code==2)
	{
		while((t[i]=getch())!='\r' && i<30 )
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;}
	}
t[i]='\0';
}
//=========================getsupp_id =======================
int getsupp_id()
{ FILE *fp;
	 fp=fopen("supplier.dat","r");
	 if(fp==NULL)
	 {  printf("\n\t\tData not Found.....");
		getch();
	 }
	 else
	 {
		temp1.supp_id=100;
		rewind(fp);
		while(fscanf(fp,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.city, temp1.mob_no,temp1.email)!=EOF)
		{
		}
	 }
	 fclose(fp);
	 return temp1.supp_id+1;
}
//=========================getcust_id =======================
int getcust_id()
{
 FILE *fp;
	 fp=fopen("customer.dat","r");
	 if(fp==NULL)
	 {
		printf("\n\t\tData not Found.....");
		getch();
	 }
	 else
	 {
		temp_c.cust_id=100;
		rewind(fp);
		while(fscanf(fp,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
		{
		}
	 }
	 fclose(fp);
	 return temp_c.cust_id+1;
}
//===========================main ===================
int main()
{
    system("cls");
    main_screen();
}
void main_screen()
{  int ch;
	do
	{system("cls");
	printf("\n\n\t\t\tWELCOME TO MEDICAL STORE");
		printf("\n1->Supplier menu\n");
		printf("2->Customer menu\n");
		printf("3->Medicine\n");
		printf("4->Bill\n");
		printf("5->Report\n");
		printf("6->Exit\n");
		printf("\nEnter your choice for further Menu\n");
		ch=toupper(getche());
		switch(ch)
		{
			case '1':supplier_menu();
				 break;
			case '2':customer_menu();
				 break;
			case '3':medicine_menu();
				 break;
			case '5':profit_rpt();
				 break;
			case '4':bill_printing();
				 break;
			case '6':printf("\n\n\n\t\tDo you want to exit now? Y/N :");
			ch=(getche());
			ch=toupper(ch);
			if(ch=='Y')
			{   system("cls");
				exit(0);}
			else
            main_screen();
			default:printf("Wrong Choice!!");
		}
	}while(ch!='6');
}
//=========================For supplier ===========================
void supplier_menu()
{  int ch;
	do
	{
	  system("cls");
	  printf("\n\n\t\t\tSUPPLIER MENU\n");
	  printf("\n1->Add New Supplier\n");
	  printf("2->Search Supplier\n");
	  printf("3->List of Existing Supplier\n");
	  printf("4->Main Menu\n");
	  printf("\nEnter your choice for further Menu\n");
	  ch=toupper(getche());
	  switch(ch)
	  {
		case '1':supplier_entry();
			 break;
		case '3':supplier_list();
			 break;
		case '2':search_supplier();
			 break;
		case '4':main_screen();
			 break;
		default:printf("\nWrong Choice!!");
	  }
	}while(ch!='4');
}
//=========================For customer ===========================
void customer_menu()
{  int ch;
	do
	{
	  system("cls");
	  printf("\n\n\t\t\tCUSTOMER MENU\n");
	  printf("\n1->Add New Customer\n");
	  printf("2->Search Customer\n");
	  printf("3->List of Existing Customer\n");
	  printf("4->Main Menu\n");
	  printf("\nEnter your choice for further Menu\n");
	  ch=toupper(getche());
	  switch(ch)
	  {
		case '1':customer_entry();
			 break;
		case '3':customer_list();
			 break;
		case '2':customer_search();
			 break;
		case '4':main_screen();
			 break;
		default:printf("\nWrong Choice!");
	  }
	}while(ch!='4');
}
//=========================For Medicine ===========================
void medicine_menu()
{	int ch;
	do
	{
	  system("cls");
	  printf("\n\n\t\t\tMEDICINE MENU.\n");
	  printf("\n1->Purchase New Medicine\n");
	  printf("2->Sale Medicine\n");
	  printf("3->Search Medicine\n");
	  printf("4->Stock\n");
	  printf("5->Update Medicine\n");
	  printf("6->Main Menu\n");
	  printf("\nEnter your choice for further Menu\n");
	  ch=toupper(getche());
	  switch(ch)
	  {
		case '1':medicine_purchase();
			 break;
		case '2':medicine_sale();
			 break;
		case '4':medicine_stock();
			 break;
		case '3':medicine_search();
			 break;
		case '6':main_screen();
			 break;
        case '5':update_medicine_stock();
            break;
		default:printf("\nWrong Choice!!");
	  }
	}while(ch!='5');
}
//========================for bill =============================
void bill_printing()
{	   FILE *ptrbill;
	   char id[6];
	   int j=1,k;
	   float netamt=0.0;
	   system("cls");
	   ptrbill=fopen("dbbill.dat","r");
	   printf("\n\nEnter bill no : ");
	   scanf("%s",&id);
	   system("cls");
	   printf("\n\n\n\nBill No: ");
	   printf("%s",id);
	   printf("\nCustomer Name: ");
	   do
	   {   while(fscanf(ptrbill,"%s %s %s %d %f %f",bil.billno,bil.cname,bil.mediname,&bil.medi_qty,&bil.medi_rate,&bil.total)!=EOF)
	       {if(strcmp(id,bil.billno)==0)
			{   printf("%s",bil.cname);
			break;}}
		}while(feof(ptrbill));
	   fclose(ptrbill);
	   ptrbill=fopen("dbbill.dat","r");
	   printf("\nSr.No\tMedicine Name\t\tQty\tRate\tTotal");
	   printf("\n---------------------------------------------------------------------\n");
	   while(fscanf(ptrbill,"%s %s %s %d %f %f",bil.billno,bil.cname,bil.mediname,&bil.medi_qty,&bil.medi_rate,&bil.total)!=EOF)
	   {
		       do
		       {
			if(strcmp(id,bil.billno)==0)
			{   printf("%d\t",j);j++;
				printf("%s\t\t",bil.mediname);
				printf("%d\t",bil.medi_qty);
				printf("%.2f\t",bil.medi_rate);
				printf("%.2f\n",bil.total);
				netamt=netamt+bil.total;
			}
		}while(feof(ptrbill));
	   }
	   printf("\n\n\n\n---------------------------------------------------------------------");
	   printf("\n\t\t\t\t\tNet Amount : ");
	   printf("%.2f",netamt);
	   printf("\n\nPress Any key to go to Menu");
	   fclose(ptrbill);
	   getch();
}
//========FOR SUPPLIERS ENTRY=================
void supplier_entry()
{ int id;
 char ch;
 FILE *fp;
 system("cls");
	   fp=fopen("supplier.dat","a");
	   if(fp==NULL)
	   {
		printf("\n Cannot open file!!");
		exit(0);
	   }
	   system("cls");
	   ch='y';
	   while(ch=='y')
	   {system("cls");
		printf("\n\n\t\t\tSUPPLIER ENTRY\n");
		temp1.supp_id=getsupp_id();
		printf("SUPPLIER ID : %d\n",temp1.supp_id);
		printf("SUPPLIER NAME : ");
		ventry(temp1.supp_name,0);
		printf("\nCITY        : ");
		ventry(temp1.city,0);
		printf("\nCONTACT NO.   : ");
		ventry(temp1.mob_no,1);
		printf("\nEMAIL ID    : ");
		gets(temp1.email);
		printf("\nSave");
		printf("\nCancel");
		printf("Press 's' to save and 'c' to cancel: ");
		ch=getch();
		if(ch=='s' || ch=='S')
		{
			fprintf(fp,"%d %s %s %s %s\n\n",temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email);
			fprintf(fp,"\n");
			system("cls");
			printf("\n\nSupplier Added successfully!!");
			printf("\nMore entries  [y/n]");
			ch=getche();  }
	   }
	   fclose(fp);
}
//=========FOR SUPPLIER DISPLAY LIST ==========
void supplier_list()
{char ch;
 int j;
 system("cls");
	   ptr1=fopen("supplier.dat","r");
	   if(ptr1==NULL)
	   {printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   printf("\n\n\t\t\tSUPPLIER LIST\n");
	   printf("\nID.\tSUPPLIER NAME.\tPH.NO.\t\t\tCITY.\t\tEMAIL");
	   printf("\n*****************************************************************************************\n");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email)!=EOF)
	   {printf(" %d\t",temp1.supp_id);
		printf(" %s\t\t",temp1.supp_name);
		printf(" %s\t\t",temp1.mob_no);
		printf(" %s\t\t",temp1.city);
		printf(" %s\n",temp1.email);
	   }
	   printf("Press Anykey to go to SUPPLIER MENU !!!");
	   getche();
}
//=============================== Search Supplier=============================
void search_supplier()
{ int id;
  FILE *fp;
	   fp=fopen("supplier.dat","r");
	   if(fp==NULL)
       {printf("file can't open!!!!");}
	   system("cls");
	   printf("\n\tEnter id to be searched:");
	   scanf("%d",&id);
	   printf("Press Any key to Return Back Menu ....");
	   printf("\nID.\t\tSUPPLIER NAME.\t\tCITY.\t\tPH.NO.\t\t\tEMAIL");
	   printf("\n***************************************************************************************************\n");
	   while(fscanf(fp,"%d %s %s %s %s",&temp1.supp_id,temp1.supp_name,temp1.mob_no,temp1.city,temp1.email)!=EOF)
	   {
		if(temp1.supp_id==id)
		{   printf("%d\t\t",temp1.supp_id);
			printf("%s\t\t\t",temp1.supp_name);
			printf("%s\t\t",temp1.city);
			printf("%s\t\t",temp1.mob_no);
			printf("%s\t",temp1.email);
			break;}
	   }
	   if(temp1.supp_id!=id)
	   {printf("\n\nRecord not found!");}
	   fclose(fp);
	   getche();
}
//========FOR CUSTOMER ENTRY=================
void customer_entry()
{char ch;
 int id;
 FILE *fp;
 system("cls");
	   fp=fopen("customer.dat","a");
	   if(fp==NULL)
	   {printf("\n Can not open file!!");
		exit(0);}
	   system("cls");
	   ch='y';
	   while(ch=='y')
	   {system("cls");
		printf("\n\n\t\t\tCUSTOMER ENTRY\n");
		temp_c.cust_id=getcust_id();
		printf("\nCUSTOMER ID :%d\n",temp_c.cust_id);
		printf("CUSTOMER NAME : ");
		ventry(temp_c.cust_name,0);
		printf("\nCITY        : ");
		ventry(temp_c.city,0);
		printf("\nCONTACT NO.   : ");
		ventry(temp_c.mob_no,1);
		printf("\nEMAIL ID    : ");
		gets(temp_c.email);
		printf("\nSave");
		printf("\nCancel");
		printf("Press 's' to save and 'c' to cancel");
		ch=getch();
		if(ch=='s' || ch=='S')
		{
			fprintf(fp,"%d %s %s %s %s\n",temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email);
			fprintf(fp,"\n");
			fflush(stdin);
			system("cls");
			printf("\n\nCustomer Added Successfully.");
			printf("More entries  [y/n] ");
			ch=getche();}
	   }
	   fclose(fp);
}
//=========FOR CUSTOMER DISPLAY LIST ==========
void customer_list()
{
 char ch;
 system("cls");
	   ptr1=fopen("customer.dat","r");
	   if(ptr1==NULL)
	   {printf("\n\t Can not open File! ");
		exit(0);}
	   system("cls");
	   printf("\n\n\t\t\tCUSTOMER LIST\n");
	   printf(" ID.\tCUSTOMER NAME.\t\tCITY.\t\tMOBILE.NO.\t\tEMAIL");
	   printf("\n*********************************************************************************************\n");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {
		printf("%d\t",temp_c.cust_id);
		printf("%s\t\t\t",temp_c.cust_name);
		printf("%s\t\t",temp_c.city);
		printf("%s\t\t",temp_c.mob_no);
		printf(" %s\n",temp_c.email);
	   }
	   printf("Press Anykey to go to CUSTOMER MENU.");
	   getche();
	   fclose(ptr1);
}
//======================search CUSTOMER==================
void customer_search()
{ int id;
  system("cls");
	   ptr1=fopen("customer.dat","rb");
	   printf("\n\n\t\tEnter id to be searched:");
	   scanf("%d",&id);
	   printf(" ID.\tCUSTOMER NAME.\t\t\tCITY.\t\tMOBILE.NO.\t\tEMAIL");
	   printf("\n**************************************************************************************\n");
	   while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
	   {
		if(temp_c.cust_id==id)
		{
        printf("%d\t",temp_c.cust_id);
		printf("%s\t\t\t",temp_c.cust_name);
		printf("%s\t\t",temp_c.city);
		printf("%s\t\t",temp_c.mob_no);
		printf(" %s\n",temp_c.email);
        printf("Press Any key to go to Customer Menu");
        break;
		}  }
	   if(temp_c.cust_id!=id)
	   {printf("\n\nRecord not found!");}
	   fclose(ptr1);
       getche();}
//============================ FOR MEDICINE PURCHASE ============================
void medicine_purchase()
{ char ch,id[6];
  int f;
  FILE *fp;
  system("cls");
	  ch='Y';
	  while(ch=='Y')
	  {
		system("cls");
		printf("\n\n\t\t\tMEDICINE PURSHASE\n");
		  printf("MEDICINE ID    : ");
			ventry(temp.id,1);
			strcpy(id,temp.id);
			fp=fopen("medical.dat","r");
			while((fread(&temp,sizeof(temp),1,fp))==1)
			{
			if(strcmp(id,temp.id)==0)
			{   f=1;
				break;}
			}
			fclose(fp);
			if(f==1)
			{   printf("ID Allready Exists");
				getche();
				system("cls");
				medicine_purchase();
			}
			else
			{
			ptr=fopen("medical.dat","a+b");
			strcpy(temp.id,id);
			printf("\nMEDICINE NAME  : ");
			ventry(temp.medi_name,0);
			printf("\nENTER RACK NO  : ");
			ventry(a,1);
			temp.rack= atoi(a);//atoi() used for convert str to int.
			printf("\nCABNIT NO      : ");
			ventry(temp.cabnit,2);
			printf("\nCOMPANY NAME   : ");
			ventry(temp.comp_name,0);
			printf("\nSUPPLIER NAME  : ");
			ventry(temp.supp_name,0);
			printf("\nUNIT COST   Rs.:  ");
			ventry(a,1);
			temp.unit= atof(a);
			printf("\nSALE COST   Rs.: ");
			ventry(a,1);
			temp.sale= atof(a);
			printf("\nQUANTITY       :  ");
			ventry(a,1);
			temp.quantity= atoi(a);
			printf("\nMFG.DATE(dd-mm-yyyy): ");
			ventry(temp.manu_date,1);
			printf("\nEXP.DATE(dd-mm-yyyy): ");
			ventry(temp.exp_date,1);
			printf("\n==================================================================\n");
			temp.total=temp.quantity*temp.sale;
			printf("\nTotal Sale Cost=Rs. %.2f",temp.total);
			temp.cost=(temp.unit*temp.quantity);
			printf("\nTotal unit cost=Rs. %.2f",temp.cost);
		 }
		printf("\nSave");
		printf("\nCancel");
		printf("\nPress 's' to save and 'c' to cancel : ");
		ch=toupper(getche());
		if(ch=='S')
		{   fwrite(&temp,sizeof(temp),1,ptr);
			fflush(stdin);
			printf("\n\nMedicine Added sucessfully!");
			printf("More entries? (y/n)");
			ch=toupper(getche());
		}
	   }
	   fclose(ptr);
}
//===========FOR MEDICINE SALE=========================
void medicine_sale()
{
  struct bill bil;
  int j,n,i,a,billno;
  float b,total,rate;
  char tar[30],ch,mediname[30],c_name[30],cname[30];
  FILE *fp,*fpc;
  int count=0;
	   ch='y';
	   while(ch=='y')
	   {
		fp = fopen("dbbill.dat","a");
		ptr1 = fopen("customer.dat","r");
		ptr = fopen("medical.dat","r");
		ptrpr_r=fopen("profitRpt.dat","a");
		system("cls");
		printf("\n\nCust_ID\t\tCust_Name\n");
		while(fscanf(ptr1,"%d %s %s %s %s",&temp_c.cust_id,temp_c.cust_name,temp_c.mob_no, temp_c.city,temp_c.email)!=EOF)
		{
			printf("%d\t\t",temp_c.cust_id);
			printf("%s\n",temp_c.cust_name);
		}
		printf("\nENTER MEDICINE ID TO BE SOLD  : ");
		ventry(tar,1);
		j=0;
		while((fread(&temp,sizeof(temp),1,ptr))==1)
		{
			if((strcmp(temp.id,tar)<0) || (strcmp(temp.id,tar)>0))
			{
				x[j] = temp;
				j++;
			}
			else if((strcmp(temp.id,tar)==0))
			{   printf("\nMedicine Name        : %s",temp.medi_name);
				printf("\nQuantity in stock    : %d",temp.quantity);
				printf("\nSales price          : %.2f",temp.sale);
				printf("\nEnter bill number     : ");
				ventry(bil.billno,1);
				printf("\nEnter customer Name   : ");
				ventry(c_name,0);
				printf("\nQuantity want to sale : ");
				scanf("%d",&a);
				pr_r.profit=(temp.sale-temp.unit)*a;
				x[j]=temp;
				x[j].quantity=(x[j].quantity-a);
				x[j].total=(x[j].quantity*temp.sale);
				x[j].cost=(x[j].quantity*temp.unit);
				x[j].bye=(x[j].sale*a);
				b=x[j].bye;
				x[j].qty=a;
				j++;
				count++;
				strcpy(bil.cname,c_name);
				strcpy(bil.mediname,temp.medi_name);
				bil.medi_qty=a;
				bil.medi_rate=temp.sale;
				bil.total=temp.sale*a;
				fprintf(fp,"%s %s %s %d %.2f %.2f\n",bil.billno,bil.cname,bil.mediname,bil.medi_qty,bil.medi_rate,bil.total);
				//fflush(stdin);
				fclose(fp);
				strcpy(pr_r.medi_id,tar);
				strcpy(pr_r.medir_name,temp.medi_name);
				pr_r.qty=a;
				pr_r.rate=temp.sale;
				pr_r.unit=temp.unit;
				fprintf(ptrpr_r,"%s %s %d %.2f %.2f  %.2f\n",pr_r.medi_id,pr_r.medir_name,pr_r.qty,pr_r.unit,pr_r.rate,pr_r.profit);
				//fflush(stdin);
				fclose(ptrpr_r);
			}
		}
		if (count==0)
		{
			system("cls");
			printf("\nNot in stock!!!!!");
			getch();
			return;
		}
		fclose(ptr1);
		fclose(ptr);
		n = j;
		system("cls");
		ptr=fopen("medical.dat","wb");
		for(i=0; i<n; i++)
		{fwrite(&x[i],sizeof(x[i]),1,ptr);}
		fclose(ptr);
		system("cls");
		printf("\nPrice paid by customer = %.2f",b);
		printf("\n    Quantity sold      = %d",a);
		getch();
		printf("\nMore entries? (y/n)");
		ch=getche();
	   }
}
//********************************stock***************************
void medicine_stock()
{
  char ch;
  int i,c;
		system("cls");
		ptr1=fopen("medical.dat","r");
		if(ptr1==NULL)
		{
			printf("\n\t Can not open File! ");
			exit(1);
		}
		system("cls");
		printf("\n\n\t\t\tSTOCK OF MEDICINE\n");
		printf("\t\tID.\tMEDICINE NAME.\t\tQTY\tSupplier Name\t\tExp.Date");
		printf("\n\t\t================================================================================\n");
		while((fread(&temp,sizeof(temp),1,ptr1))==1)
		{	printf("\n\t\t%s\t",temp.id);
			printf("%s\t\t ",temp.medi_name);
			printf("%d\t",temp.quantity);
			printf("%s\t\t",temp.supp_name);
			printf("%s\n",temp.exp_date);
		}
	   getche();
}
//=============================== FOR MEDICINE SEARCH ====================
void medicine_search()
{ char mid[6];
  int i,c;
  system("cls");
	   ptr1=fopen("medical.dat","r");
	   if(ptr1==NULL)
	   {printf("\n\t Can not open File! ");
		exit(0);}
	   system("cls");
	   printf("\n\n\t\tEnter Medicine Id to be searched : ");
	   scanf("%s",&mid);
	   system("cls");
	   printf("\n\n\t\t\tMEDICINE ");
	   printf("\nID\tMEDICINE NAME\t\tQTY\tSupplier Name\t\tExp.Date");
	   printf("\n====================================================================================\n");
	   while((fread(&temp,sizeof(temp),1,ptr1))==1)
	   { if(strcmp(mid,temp.id)==0)
		{
			printf("%s\t",temp.id);
			printf("%s\t\t",temp.medi_name);
			printf("%d\t",temp.quantity);
			printf("%s\t",temp.supp_name);
			printf("%s\n",temp.exp_date);
			break;}	   }
	   if(strcmp(mid,temp.id)!=0)
	   {printf("\n\n\t\t\tNot in Stock.");
	   }
	   getche();}
//============================ FOR MEDICINE UPDATE =====================
void update_medicine_stock()
{
  char mid[6];
  int j,a,count=0,n;
  system("cls");
	   ptr=fopen("medical.dat","rb");
	   if(ptr==NULL)
	   {printf("\n\t Can not open File! ");
		exit(0);}
	   system("cls");
	   printf("\n\n\t\t\tUPDATE MEDICINE QUANTITY\n");
	   printf("Enter medicine id to update qty: ");
	   scanf("%s",&mid);
	   j=0;
	   while((fread(&temp,sizeof(temp),1,ptr))==1)
	   {
		if((strcmp(temp.id,mid)<0) || (strcmp(temp.id,mid)>0))
		{
			x[j] = temp;
			j++;
		}
		else
		{   printf("\n\nMedicine Name     : %s",temp.medi_name);
			printf("\nQuantity in stock : %d",temp.quantity);
			printf("\nQuantity want to update : ");
			scanf("%d",&a);
			x[j]=temp;
			x[j].quantity=(x[j].quantity+a);
			x[j].total=(x[j].quantity*temp.sale);
			x[j].cost=(x[j].quantity*temp.unit);
			x[j].bye=(x[j].sale*a);
			x[j].qty=a;
			j++;
			count++;}
	   }
	   if (count==0)
	   {
		 system("cls");
		 printf("\n\nNot in stock!!!!!!");
		 getch();
		 return;
	   }
	   printf("Press Enter to go to MENU ...........");
	   fclose(ptr);
	   n = j;
	   system("cls");
	   ptr=fopen("medical.dat","wb");
	   for(i=0;i<n;i++)
	   fwrite(&x[i],sizeof(x[i]),1,ptr);
	   fclose(ptr);
}
//===================== view report =============================
void profit_rpt()
{
  char ch;
  int j;
  system("cls");
	   ptrpr_r=fopen("profitRpt.dat","r");
	   if(ptrpr_r==NULL)
	   {printf("\n\t Can not open File! ");}
	   printf("\n\n\t\t\tPROFIT REPORT\n");
	   printf("\nID.\tMedicine Name.\t\t\tQty.\tUnit\tPrice\tProfit");
	   printf("\n******************************************************************************************\n");
	   while(fscanf(ptrpr_r,"%s %s %d %f %f %f \n",pr_r.medi_id,pr_r.medir_name,&pr_r.qty,&pr_r.unit,&pr_r.rate,&pr_r.profit)!=EOF)
	   {printf("%s\t",pr_r.medi_id);
		printf("%s\t\t",pr_r.medir_name);
		printf("%d\t",pr_r.qty);
		printf("%.2f\t",pr_r.unit);
		printf("%.2f\t",pr_r.rate);
		printf("%.2f\t\n",pr_r.profit);
	   }
	   printf("Press any key to go to Main Menu");
	   getche();
}
