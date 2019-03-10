#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char sign[1024]={0},pfx[256]={0},exe[256]={0},pas[256]={0};
char s1[]="signtool.exe sign /v /f ";
char s2[]=" /p ";
char s3[]=" /tr http://timestamp.wosign.com/rfc3161 ";
char s4[]="  >  signlogs.log   2>&1     & ";
char ss[]=" ";
int  time=-1;
void sm_pfxfile()
{
	system( "cls && title 选择PFX文件-皮卡丘代码签名向导 && mode con cols=60 lines=25 && color 1f && echo. && echo. && echo." );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇      ********皮卡丘数字签名向导********    ▇" );
	system( "echo      ▇--------------------------------------------▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇              第一步：选择PFX文件           ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇         请将包含私钥的PFX文件拖拽到此      ▇" );
	system( "echo      ▇        (注意：文件路径中不能包含空格）     ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	printf("\n \n     ****请将包含私钥的PFX文件拖拽到此，按回车继续***\n\n     ");
	//scanf("%s",pfx);
	getchar();
	gets(pfx); 
	 
} 
void sm_exefile()
{
	system( "cls && title 选择可执行文件-皮卡丘代码签名向导 && mode con cols=60 lines=25 && color 8f && echo. && echo. && echo." );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇      ********皮卡丘数字签名向导********    ▇" );
	system( "echo      ▇--------------------------------------------▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇             第二步：选择签名文件           ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇         请将要签名的程序文件拖拽到此       ▇" );
	system( "echo      ▇        (注意：文件路径中不能包含空格）     ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	printf("\n \n      *****请将要签名的程序拖拽到此，按回车继续*****\n\n     ");
	//scanf("%s",exe);
	gets(exe); 
} 
void sm_pfxpass()
{
	system( "cls && title 输入密码-皮卡丘代码签名向导 && mode con cols=60 lines=25 && color Cf && echo. && echo. && echo." );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇      ********皮卡丘数字签名向导********    ▇" );
	system( "echo      ▇--------------------------------------------▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇             第三步：输入私钥密码           ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	printf("\n \n      *****请输入私钥密码：");
	//scanf("%s",pas);
	gets(pas); 
} 
void sm_asksign()
{
	char kkk=0;
	system( "cls && title 是否添加时间-皮卡丘代码签名向导 && mode con cols=60 lines=25 && color 3f && echo. && echo. && echo." );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇      ********是否添加时间戳？********      ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	printf(     "\n\n      是否添加时间戳（Y=是,N=否，默认为是）：");
	//getchar();
	scanf("%c",&kkk);
	if(kkk=='N') time=0;
	else time=1;
	system( "cls && title 签名确认-皮卡丘代码签名向导 && mode con cols=60 lines=25 && color df && echo. && echo. && echo." );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇       ********确认执行签名？********       ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	printf(     "\n      私钥文件：%s\n",pfx);
	printf(     "\n      待签文件：%s\n",exe);
	printf(     "\n      私钥密码：%s\n",pas);
	if(time==0) 
	printf(     "\n      标记时间：否\n"); 
	else 
	printf(     "\n      标记时间：是\n"); 
	printf(     "\n      如果确认无误，");system("pause") ;
	
} 
void sm_exesign()
{
	system( "cls && title 正在签名-皮卡丘代码签名向导 && mode con cols=60 lines=25 && color 4f && echo. && echo. && echo." );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇      ********皮卡丘数字签名向导********    ▇" );
	system( "echo      ▇--------------------------------------------▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇               第四步：执行签名             ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	strcat(sign,s1); 
	strcat(sign,pfx); 
	strcat(sign,s2); 
	strcat(sign,pas); 
	if(time==1) strcat(sign,s3); 
	else strcat(sign,ss); 
	strcat(sign,exe); 
	strcat(sign,s4);
	system("choice /t 3 /d y /n >nul");
	system(sign) ;
} 
void sm_exesucc()
{
	system( "cls && title 签名完成-皮卡丘代码签名向导 && mode con cols=60 lines=30 && color 2f && echo. && echo. && echo." );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇      ********皮卡丘数字签名向导********    ▇" );
	system( "echo      ▇--------------------------------------------▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇                   签名完成                 ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	system("echo." );
	system("choice /t 1 /d y /n >nul");
	system("echo **************************签名日志**************************" );
	system("type signlogs.log");
	system("echo ************************************************************" );
	system("pause");
} 
void signauto()
{
	system("call \"./data/signcode.exe\" ");
}
void signmanl()
{
	sm_pfxfile();
	sm_exefile();
	sm_pfxpass();
	sm_asksign();
	sm_exesign();
	sm_exesucc();
}
void signlogs()
{
	system( "cls && mode con cols=60 lines=25 && color af && echo. && echo. && echo." );
	system("echo **************************签名日志**************************" );
	system("type signlogs.log");
	system("echo ************************************************************" );
	system("pause");
}
void certmang()
{
	system("call \"./data/certmgr.exe\"");
}
void certmake()
{
	system("start ./data/certsys.exe");
}
void certssys()
{
	system("start ./data/certlm.msc");
}
void menu()
{
	system( "cls && title 皮卡丘代码签名工具 && mode con cols=60 lines=25 && color 3f && echo. && echo. && echo." );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇      ********皮卡丘代码签名工具********    ▇" );
	system( "echo      ▇--------------------------------------------▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇         1.签名向导(Signature Wizard)       ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇         2.手动签名(Manual signature)       ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇         3.查看日志(View Error Logs )       ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇         4.证书管理(Certificate Manage)     ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇         5.自建证书(Create certificate)     ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇         6.系统证书(System certificate)     ▇" );
	system( "echo      ▇                                            ▇" );
	system( "echo      ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇" );
	printf( "\n     请输入选项前面对应的数字，按回车确认：" );
}

int main(int argc, char *argv[]) {
	int key; menu(); scanf( "%d", &key );
		while ( 1 )
			switch ( key )
			{
			case 0: menu(); scanf( "%d", &key ); break;
			case 1: key	= 0; signauto(); menu(); scanf( "%d", &key ); break;
			case 2: key	= 0; signmanl(); menu(); scanf( "%d", &key ); break;
			case 3: key	= 0; signlogs(); menu(); scanf( "%d", &key ); break;
			case 4: key	= 0; certmang(); menu(); scanf( "%d", &key ); break;
			case 5: key	= 0; certmake(); menu(); scanf( "%d", &key ); break;
			case 6: key	= 0; certssys(); menu(); scanf( "%d", &key ); break;
			default: key= 0; printf( "你的输入有误，请重新输入:" ); scanf( "%d", &key ); break;
			} 
	return 0;
}
