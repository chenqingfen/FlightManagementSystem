#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
void hbpx();//航班排序
void qbhb();//全部的航班
void hbhpx();//按航班号排序
void sjpx();//按起飞时间排序
void pspx();//按票数排序
void hao();//按航班号查询
void cfd();//按出发地查询
void mdd();//按目的地查询
void gsmc();//按航空公司查询
void bj();//北京票子
void jiemian();//管理界面
void cxhb();//航班查询
void glhb();//管理航班
void tjhb();//添加航班 
void schb();//删除航班
void xghb();//修改航班
void wjdr();//文件读入
void wjbc();//文件保存
void chonglai();
struct hangban
{
	char hbh[40];//航班号
	char cfd[40];//出发地
	char mdd[40];//目的地
	char cfsj[40];//出发时间
	char ddsj[40];//到达时间
	char hkgs[40];//航空公司
	char jpsl[40];//机票数量
};


int i,q=0;//q为航班的数量


int main()//初始界面
{
	printf("			-----------------------------------------------\n");
	printf("			=                                             =\n");
	printf("			= 欢迎使用厦门航班管理系统                    =\n");
	printf("			=                                             =\n");
	printf("			-----------------------------------------------\n");
	printf("			按任意键继续\n");
	getch();
	jiemian();
	return 0;
}




void jiemian()//主功能界面
{


	system("CLS");//清屏
	printf("			1、查询航班\n			2、管理航班\n			3、文件读入\n			4、文件保存\n			5、航班排序\n			请输入您需要的功能的序号:");
	int a; 
	scanf("%d",&a);
	switch(a)
	{
		case 1:system("CLS");cxhb();break;
		case 2:system("CLS");glhb();break;
		case 3:system("CLS");wjdr();break;
		case 4:system("CLS");wjbc();break;
		case 5:system("CLS");hbpx();break;
		default :printf(" \n\n\n			输入有误，按任意键新输入");
		getch();
		jiemian();
	}


}


void qbhb()//全部的航班
{ 
	system("CLS");
	FILE *py = NULL;
	char buf[300];
	py=fopen("D:/py/ppy.txt","a+");//打开文件
	int i;
	char b[80];
	for(i=0;i<99;i++)//一一写出
	{fgets(buf,299,py);


	if(strcmp(buf,b)==0)//结束判断
		break;
	else
		strcpy(b,buf);
	printf("%s\n",buf);}
	fclose(py);
	printf("输入1返回上一级,输入2返回主页面：");
	int a;
	scanf("%d",&a);
	switch(a)
	{
	    case 1:cxhb();break;
		case 2:system("CLS");jiemian();break;
		default :system("CLS");printf("			输入有误，按任意键重新输入");
		getch();
		qbhb();
	}
}






struct hangban hb[99],*p=hb;//定义主要结构体和指针
void glhb()//管理航班
{
	system("CLS");
	printf("			1、修改航班(请在保存前修改完毕)\n			2、添加航班\n			3、删除航班\n			4、返回上一级\n			输入您想要的功能序号:");
	int a;
	scanf("%d",&a);
	switch(a)
	{
		case 1:xghb();break;
		case 2:tjhb();break;
		case 3:schb();break;
		case 4:jiemian();break;
		default:printf("			输入有误，按任意键重新输入");
		getch();
		glhb();
	}
}




void tjhb()//添加航班
{ 
	system("CLS");
	


	printf("			输入你想要添加的航班\n		航班号:");
	scanf("%s",p[q].hbh);
	printf("\n		出发地:");
	scanf("%s",p[q].cfd);
	printf("\n		目的地:");
	scanf("%s",p[q].mdd);
	printf("\n		出发时间:");
	scanf("%s",p[q].cfsj);
	printf("\n		到达时间:");
	scanf("%s",p[q].ddsj);
	printf("\n		航空公司:");
	scanf("%s",p[q].hkgs);
	printf("\n		机票数量:");
	scanf("%s",p[q].jpsl);
	system("CLS");


	q++;


	printf("添加完成，是否继续添加（1是2否）");
	
	chonglai();
}


	void chonglai()
	{
		int j;
		scanf("%d",&j);
        switch(j)
		{
		case 1:tjhb();break;
		case 2:glhb();break;
		default:printf("输入有误，按任意键重新输入");
		getch();chonglai();break;
		}
	}
	








void wjdr()//文件读入


{ 
	system("CLS");
	FILE *py = NULL;
	q=0;
	py=fopen("D:/py/ppy.txt","a+");
	while(!feof(py))//找到结尾标志
	{
		fscanf(py,"%s%s%s%s%s%s%s",p[q].hbh,p[q].cfd,p[q].mdd,p[q].cfsj,p[q].ddsj,p[q].hkgs,p[q].jpsl);
				q++;
		


			}
	fclose(py);
	printf("			读入成功");
	getch();
	jiemian();
}




void schb()//文件删除航班


{
	system("CLS");
	struct hangban sc[80];
	printf("		输入你想要删除的航班号：");
	scanf("%s",sc[0].hbh);




	int i,f=0;
	for(i=0;i<q;i++)
	{
		if(strcmp(sc[0].hbh,p[i].hbh)==0)
		{f++;continue;}
		else
		{ 
			FILE *lspy=NULL;
			lspy=fopen("D:/py/pppy.txt","a+"); 
			fputs(p[i].hbh,lspy);
			fputs(" ",lspy);
			fputs(p[i].cfd,lspy);
			fputs(" ",lspy);
			fputs(p[i].mdd,lspy);
			fputs(" ",lspy);
			fputs(p[i].cfsj,lspy);
			fputs(" ",lspy);
			fputs(p[i].ddsj,lspy);
			fputs(" ",lspy);
			fputs(p[i].hkgs,lspy);
			fputs(" ",lspy);
			fputs(p[i].jpsl,lspy);
			fputs("\n",lspy);
			fclose(lspy);
		}
	}




	remove("D:/py/ppy.txt");
	rename("D:/py/pppy.txt","D:/py/ppy.txt");//文件覆盖
	if(f==0)
	{printf("			没有这个航班请重新输入");
	q--;
	getch();
	schb();
}
printf("			删除完成并保存，按任意键回到上一级");
getch();
glhb();


}












void wjbc()//文件保存
{
	int i;
	for(i=0;i<q;i++)
	{
		FILE *py = NULL;
		py=fopen("D:/py/pppy.txt","a+");
		fputs(p[i].hbh,py);
		fputs("   ",py);
		fputs(p[i].cfd,py);
		fputs("   ",py);
		fputs(p[i].mdd,py);
		fputs("   ",py);
		fputs(p[i].cfsj,py);
		fputs("   ",py);
		fputs(p[i].ddsj,py);
		fputs("   ",py);
		fputs(p[i].hkgs,py);
		fputs("   ",py);
		fputs(p[i].jpsl,py);
		fputs("\n",py);
		fclose(py);
	   
	} 
	remove("D:/py/ppy.txt");
	    rename("D:/py/pppy.txt","D:/py/ppy.txt");
	printf("			保存完成按任意键继续");
	getch();
	jiemian();
}






void xghb()//修改航班
{
	int i,b=0;struct hangban xg[40];


	system("CLS");
	printf("		输入你想要修改的航班号:");
	scanf("%s",xg[0].hbh);
	for(i=0;i<q;i++)
	{ 
		if(strcmp(p[i].hbh,xg[0].hbh)==0)


		{ 
			printf("\n		新的航班号:");
			scanf("%s",xg[0].hbh);
			printf("\n		出发地:");
			scanf("%s",xg[0].cfd);
			printf("\n		目的地:");
			scanf("%s",xg[0].mdd);
			printf("\n		出发时间:");
			scanf("%s",xg[0].cfsj);
			printf("\n		到达时间:");
			scanf("%s",xg[0].ddsj);
			printf("\n		航空公司:");
			scanf("%s",xg[0].hkgs);
			printf("\n		机票数量:");
			scanf("%s",xg[0].jpsl);
			p[i]=xg[0];
			printf("			修改成功,按任意键返回");b++;
			getch();glhb();break;
			}
	}
	if(b==0)
	{ printf("			没有此航班，按1重新输入按2返回上一级");
	int c=0;
	scanf("%d",&c);
	switch(c)


	{
	case 1:system("CLS");xghb();break;
	case 2:system("CLS");glhb();break;
	default :printf("			输入有误，返回上一级");getch();glhb();
	}
	}
}
void hbpx()//航班排序
{ 
	system("CLS");
	printf("			1、按航班号排序\n			2、按起飞时间排序\n			3、按票数排序\n			4、返回上一级\n			输入您想要的功能序号:");
	int i;
	scanf("%d",&i);
	switch(i)
		{
			case 1:hbhpx();break;
			case 2:sjpx();break;
			case 3:pspx();break;
			case 4:jiemian();break;
			default:printf("			输入有误，请重新输入");
			getch();
			hbpx();
		}
}
 
 
 
void hbhpx()//按航班号排序
{ 
	int i,j,k;
	struct hangban temp;
		system("CLS");
	printf("			按航班号排序\n");
	for(i=0;i<q-1;i++)
	{
		k=i;
	for(j=i+1;j<q;j++)
		if(strcmp(p[j].hbh,p[k].hbh)<0)//从小到大排序
		k=j;
		temp=p[k];
	  	p[k]=p[i];
		p[i]=temp;
	}
	for(i=0;i<q;i++)
	{
		printf("%s %s %s %s %s %s %s\n",p[i].hbh,p[i].cfd,p[i].mdd,p[i].cfsj,p[i].ddsj,p[i].hkgs,p[i].jpsl);
	}
		printf("			按任意键返回");
		getch();
		hbpx();
}
 
void sjpx()//按起飞时间排序
{ 
	int i,j,k;
	struct hangban temp;
    system("CLS");
	printf("			按起飞时间排序\n");
	for(i=0;i<q-1;i++)
	{
		k=i;
		for(j=i+1;j<q;j++)
		if(strcmp(p[j].cfsj,p[k].cfsj)>0)//从大到小排序
		k=j;
		temp=p[k];
		p[k]=p[i];
		p[i]=temp;
 }
	for(i=0;i<q;i++)
	{
		printf("%s %s %s %s %s %s %s\n",p[i].hbh,p[i].cfd,p[i].mdd,p[i].cfsj,p[i].ddsj,p[i].hkgs,p[i].jpsl);
	}
	printf("			按任意键返回");
	getch();
	hbpx();
}
 
void pspx()//按票数排序
{ 
	int i,j,k;
	struct hangban temp;
    system("CLS");
	printf("			按票数排序\n");
	for(i=0;i<q-1;i++)
	{
		k=i;
		for(j=i+1;j<q;j++)
		if(strcmp(p[j].jpsl,p[k].jpsl)<0)
		k=j;
		temp=p[k];
	p[k]=p[i];
     p[i]=temp;
	}
	for(i=0;i<q;i++)
	{	
		printf("%s %s %s %s %s %s %s\n",p[i].hbh,p[i].cfd,p[i].mdd,p[i].cfsj,p[i].ddsj,p[i].hkgs,p[i].jpsl);}
		printf("			按任意键返回");
		getch();
		hbpx();
	}




void cxhb()//航班查询
{  
	system("CLS");
	printf("			1、按航班号查询\n			2、按出发地\n			3、按目的地目的地\n			4、按航空公司\n			5、全部航班\n			6、返回上一级\n			输入您想要的功能序号:");
     int i;
     scanf("%d",&i);
	switch(i)
	{
		case 1:hao();break;
		case 2:cfd();break;
		case 3:mdd();break;
		case 4:gsmc();break;
		case 5:qbhb();break;
		case 6:jiemian();break;
		default:printf("			输入有误，请重新输入");
		  getch();
		cxhb();
	}
}






void hao()//按航班号查询
{  
	int i,b=0;struct hangban xg[40];
     
	system("CLS");
    printf("		输入你想要查询的航班号:");
    scanf("%s",xg[0].hbh);
    for(i=0;i<q;i++)
	{ 
		if(strcmp(p[i].hbh,xg[0].hbh)==0)
		{printf("%s %s %s %s %s %s %s\n",p[i].hbh,p[i].cfd,p[i].mdd,p[i].cfsj,p[i].ddsj,p[i].hkgs,p[i].jpsl);b++;}
	}
		if(b==0)
		{printf("			未找到该航班");}
		printf("			按任意键返回\n");
		getch();
		cxhb();
 
}
 


void cfd()//按出发地查询
{   
	int i,b=0;struct hangban xg[40];
     
	system("CLS");
    printf("		输入你想要查询的出发地的航班:");
    scanf("%s",xg[0].cfd);
    for(i=0;i<q;i++)
	{
		if(strcmp(p[i].cfd,xg[0].cfd)==0)
		{printf("%s %s %s %s %s %s %s\n",p[i].hbh,p[i].cfd,p[i].mdd,p[i].cfsj,p[i].ddsj,p[i].hkgs,p[i].jpsl);b++;}
	}
	if(b==0)
	  {printf("			未找到该航班");}
	printf("			按任意键返回\n");
	  getch();
	cxhb();
}


void mdd()//按目的地查询
{  
	int i,b=0;struct hangban xg[40];
     
	system("CLS");
    printf("		输入你想要查询的目的地的航班号:");
    scanf("%s",xg[0].mdd);
    for(i=0;i<q;i++)
	{ 
		if(strcmp(p[i].mdd,xg[0].mdd)==0)
		{printf("%s %s %s %s %s %s %s\n",p[i].hbh,p[i].cfd,p[i].mdd,p[i].cfsj,p[i].ddsj,p[i].hkgs,p[i].jpsl);b++;}}
		  if(b==0)
		  {printf("			未找到该航班");}
		printf("			按任意键返回\n");
		  getch();
		cxhb();
}


void gsmc()//按航空公司查询
{  
	int i,b=0;struct hangban xg[40];
     
	system("CLS");
    printf("		输入你想要查询的航空公司:");
    scanf("%s",xg[0].hkgs);
    for(i=0;i<q;i++)
	{ 
		if(strcmp(p[i].hkgs,xg[0].hkgs)==0)
		{printf("%s %s %s %s %s %s %s\n",p[i].hbh,p[i].cfd,p[i].mdd,p[i].cfsj,p[i].ddsj,p[i].hkgs,p[i].jpsl);b++;}
	}
		if(b==0)
		{printf("			未找到该航班");}
		printf("			按任意键返回\n");
		getch();
		cxhb();
 
}
