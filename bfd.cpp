#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<windows.h>
#include<conio.h>
#include<ctime>
using namespace std;
clock_t t1,t2;
int ti;
POINT pt;
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
HWND hConsole=FindWindow("ConsoleWindowClass",NULL);
void colset(int a){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void Goto(int Y,int X){
    COORD C; C.X=X; C.Y=Y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),C);   
}
void Hide(){ 
    CONSOLE_CURSOR_INFO cursor_info={1,0}; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
bool got(){
    GetCursorPos(&pt);
    ScreenToClient(hConsole,&pt);
    fflush(stdin);
    return true;
}
int pan(int x,int y){
    if(x<0||x>64)   return 0;
    y/=8;
    ++y;
    if(y>=3&&y<=10) return 1;
    if(y>=13&&y<=20)    return 2;
    if(y>=23&&y<=28)    return 3;
    if(y>=31&&y<=42)    return 4;
    if(y>=45&&y<=50)    return 5;
    if(y>=53&&y<=57)    return 6;
    if(y>=60&&y<=71)    return 7;
    if(y>=74&&y<=80)    return 8;
    return 0;
}
int by[10000002];
char lo[10000002],sc[10000002];
bool bp[10000002];
int now=1,ma,s=-1,nnnn=0,cs,mn;
bool ok=false,xr;
int q=0,lk;
bool aaa;
bool co(int be,int en){
    if(be>en){
        printf("Runtime Error: There's no anything in it\n");
        for(int i=1;i<en;i++)   printf("%c",lo[i]);
        colset(12);
        for(int i=en;i<=be;i++) printf("%c",lo[i]);
        colset(15);
        for(int i=be+1;i<=q;i++)    printf("%c",lo[i]);
        printf("\n");
        aaa=false;
        lk=lk+3+(q-1)/175;
        printf("-----------------------------------\n");
    }
    int nn=be;
    while(nn<=en){
        if(lo[nn]=='<'){
            --now;
            if(now==0){
                printf("Memory Limit Exceed: No variable position there\n");
                for(int i=1;i<nn;i++)   printf("%c",lo[i]);
                colset(12);
                printf("%c",lo[nn]);
                colset(15);
                for(int i=nn+1;i<=q;i++)    printf("%c",lo[i]);
                printf("\n");
                aaa=false;
                lk=lk+3+(q-1)/175;
                printf("-----------------------------------\n");
            }
        }
        else if(lo[nn]=='>'){
            ++now;
            if(now>10000000){
                printf("Memory Limit Exceed: I don\'t know why you want so big memories or... more than 1000,0000 bytes!\n");
                aaa=false;
                printf("-----------------------------------\n");
                lk=lk+3+(q-1)/175;
            }
        }
        else if(lo[nn]=='+'){
            ;
        }
        else if(lo[nn]=='-'){
            ;
        }
        else if(lo[nn]=='.'){
            ;
        }
        else if(lo[nn]==','){
            ;
        }
        else if(lo[nn]=='['){
            int nnn=nn+1,no=1;
            while(no!=0 && nnn<=en){
                if(lo[nnn]=='[')    ++no;
                if(lo[nnn]==']')    --no;
                ++nnn;
            }
            if(nnn!=en+1||no==0){
                aaa=co(nn+1,nnn-2);
            }
            else{
                printf("Compile Error: I can\'t find the last part there\n");
                for(int i=1;i<nn;i++)   printf("%c",lo[i]);
                colset(12);
                printf("%c",lo[nn]);
                colset(15);
                for(int i=nn+1;i<=q;i++)    printf("%c",lo[i]);
                printf("\n");
                aaa=false;
                printf("-----------------------------------\n");
                lk=lk+3+(q-1)/175;
            }
            nn=nnn-1;
        }
        else if(lo[nn]==' '){;}
        else if(lo[nn]==']'){
            printf("Comlple Error: I can\'t the first part there\n");
            for(int i=1;i<nn;i++)   printf("%c",lo[i]);
            colset(12);
            printf("%c",lo[nn]);
            colset(15);
            for(int i=nn+1;i<=q;i++)    printf("%c",lo[i]);
            printf("\n");
            aaa=false;
            printf("-----------------------------------\n");
            lk=lk+3+(q-1)/175;
        }
        else{
            printf("Compile Error: I don\'t know what \'%c\' is\n",lo[nn]);
            for(int i=1;i<nn;i++)   printf("%c",lo[i]);
            colset(12);
            printf("%c",lo[nn]);
            colset(15);
            for(int i=nn+1;i<=q;i++)    printf("%c",lo[i]);
            printf("\n");
            aaa=false;
            printf("-----------------------------------\n");
            lk=lk+3+(q-1)/175;
        }
        ++nn;
    }
    return aaa;
}
int ssc,sg=0,sg2,sg3=0,sg4;
void sou1(int be,int en){
    int nn=be;
    while(nn<=en){
        if(bp[nn]){
            t2=clock();
            ti=ti+(t2-t1);
            Goto(7+sg3,0);
            printf("Breakpoint there!\n");
            for(int i=1;i<nn;i++)   printf("%c",lo[i]);
            colset(10);
            printf("%c",lo[nn]);
            colset(15);
            for(int i=nn+1;i<=q;i++)    printf("%c",lo[i]);
            printf("\n");
            printf("You can look at the data\n");
            printf("+----++----+\n");
            printf("|Look||Quit|\n");
            printf("|   L||   Q|\n");
            printf("+----++----+\n");
            while(1){
                if(kbhit()){
                    char haha=getch();
                    if(haha=='L'||haha=='l'){
                        int h=(mn+9)/10;
                        for(int i=0;i<h;i++){
                            for(int j=0;j<10;j++){
                                if(i*10+j+1==now)   colset(12);
                                printf(" %3d |",by[i*10+j+1]);
                                colset(15);
                            }
                            printf("\n");
                            if((now+9)/10==i+1){
                                for(int j=1;j<(now%10);j++) printf("      ");
                                printf(" ^^^\n");
                            }
                        }
                        printf("Continue...\n");
                        Sleep(3000);
                        Goto(7+sg3,0);
                        printf("                    \n");
                        for(int i=1;i<=q;i++)   printf(" ");
                        printf("\n");
                        printf("                                              \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("                  \n");
                        for(int i=0;i<h;i++){   
                            for(int j=0;j<10;j++){
                                printf("      ");
                            }
                            printf("\n");
                            if((now+9)/10==i+1){
                                for(int j=1;j<(now%10);j++) printf("      ");
                                printf("     \n");
                            }
                        }
                        printf("              \n");
                        break;
                    }
                    if(haha=='Q'||haha=='q'){
                        printf("Continuing\n");
                        Sleep(3000);
                        Goto(7+sg3,0);
                        printf("                    \n");
                        for(int i=1;i<=q;i++)   printf(" ");
                        printf("\n");
                        printf("                                              \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("              \n");
                        break;
                    } 
                }
                if(KEY_DOWN(MOUSE_MOVED)){
                    got();
                    if(pt.y>(10+sg3+(q-1)/175)*16&&pt.y<(14+sg3+(q-1)/175)*16&&pt.x>0&&pt.x<48){
                        int h=(mn+9)/10;
                        for(int i=0;i<h;i++){
                            for(int j=0;j<10;j++){
                                if(i*10+j+1==now)   colset(12);
                                printf(" %3d |",by[i*10+j+1]);
                                colset(15);
                            }
                            printf("\n");
                            if((now+9)/10==i+1){
                                for(int j=1;j<(now%10);j++) printf("      ");
                                printf(" ^^^\n");
                            }
                        }
                        printf("Continue...\n");
                        Sleep(3000);
                        Goto(7+sg3,0);
                        printf("                    \n");
                        for(int i=1;i<=q;i++)   printf(" ");
                        printf("\n");
                        printf("                                              \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("                  \n");
                        for(int i=0;i<h;i++){   
                            for(int j=0;j<10;j++){
                                printf("      ");
                            }
                            printf("\n");
                            if((now+9)/10==i+1){
                                for(int j=1;j<(now%10);j++) printf("      ");
                                printf("     \n");
                            }
                        }
                        printf("              \n");
                        break;
                    }
                    if(pt.y>(10+sg3+(q-1)/175)*16&&pt.y<(14+sg3+(q-1)/175)*16&&pt.x>48&&pt.x<96){
                        printf("Continue...\n");
                        Sleep(3000);
                        Goto(7+sg3,0);
                        printf("                    \n");
                        for(int i=1;i<=q;i++)   printf(" ");
                        printf("\n");
                        printf("                                              \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("                  \n");
                        printf("              \n");
                        break;
                    }
                }
            }           
            t1=clock();
        }
        if(lo[nn]=='<') --now;
        else if(lo[nn]=='>'){
            ++now;
            if(mn<now)  mn=now;
        }
        else if(lo[nn]=='+'){
            ++by[now];
            while(by[now]<0)    by[now]+=128;
            while(by[now]>127)  by[now]-=128;
        }
        else if(lo[nn]=='-'){
            --by[now];
            while(by[now]<0)    by[now]+=128;
            while(by[now]>127)  by[now]-=128;
        }
        else if(lo[nn]=='.'){
            while(by[now]<0)    by[now]+=128;
            while(by[now]>127)  by[now]-=128;
            if(by[now]=='\n'){
                ++sg3;
                Goto(5+sg3,9);
                printf("|");
                for(int i=0;i<sg4;i++)  printf(" ");
                printf("|");
                Goto(6+sg3,9);
                printf("+");
                for(int i=0;i<sg4;i++)  printf("-");
                printf("+");
                sg=0;
            }
            else{
                ++sg;
                if(sg>sg4){
                    for(int i=0;i<=sg3;i++){
                        Goto(5+i,9+sg);
                        printf(" |");
                    }
                    Goto(4,9+sg4+1);
                    for(int i=0;i<sg-sg4;i++)   printf("-");
                    printf("+");
                    Goto(6+sg3,9+sg4+1);
                    for(int i=0;i<sg-sg4;i++)   printf("-");
                    printf("+");
                    sg4=sg;
                }
                Goto(5+sg3,9+sg);
                printf("%c",by[now]);
            }
        }
        else if(lo[nn]==','){
            Goto(7+sg3,0);
            t2=clock();
            ti=ti+t2-t1;
            printf("Waiting for read in No. %d\n",nn);
            for(int i=1;i<nn;i++)   printf("%c",lo[i]);
            colset(12);
            printf("%c",lo[nn]);
            colset(15);
            for(int i=nn+1;i<=q;i++)    printf("%c",lo[i]);
            printf("\n");
            char haha;
            haha=getch();
            by[now]=(int)haha;
            if(by[now]==13){
                Goto(1,10+sg2);
                printf("--+");
                Goto(2,10+sg2);
                printf("\\n|");
                Goto(3,10+sg2);
                printf("--+");
                sg2+=2;
                by[now]=10;
            }
            else{
                Goto(1,10+sg2);
                printf("-+");
                Goto(2,10+sg2);
                printf("%c|",haha);
                Goto(3,10+sg2);
                printf("-+");
                ++sg2;
            }
            Goto(7+sg3,0);
            printf("                                 \n");
            for(int i=1;i<=q;i++)   printf(" ");
            t1=clock();
        }
        else if(lo[nn]=='['){
            int nnn=nn+1,no=1;
            while(no!=0){
                if(lo[nnn]=='[')    ++no;
                if(lo[nnn]==']')    --no;
                ++nnn;
            }
            while(by[now]!=0){
                sou1(nn+1,nnn-2);
                ++cs;
                if(cs>1000000){
                    Goto(7,0);
                    printf("\nRuntime Error: soo many loops or... more than 100,0000 times!\n");
                    ++ssc;
                    return;
                }
            }
            nn=nnn-1;
        }
        ++nn;
    }
}
int K=0;
bool com(){
    now=1;
    s=-1;
    nnnn=0;
    aaa=true;
    return co(1,q);
}
void run(){
    memset(by,0,sizeof(by));
    system("cls");
    Goto(0,0);
    mn=1;
    s=-1;
    ssc=0;
    printf("\n+-----+  ++\n");
    printf("|Input|  ||\n");
    printf("+-----+  ++\n");
    printf("+-----+  ++\n");
    printf("|Ouput|  ||\n");
    printf("+-----+  ++");
    sg=0;
    sg2=0;
    sg3=0;
    sg4=0;
    cs=0;
    ti=0;
    t1=clock();
    sou1(1,q);
    t2=clock();
    ti=ti+t2-t1;
    Goto(0,0); 
    printf("Use %d ms to run...",ti);
    Sleep(1000);
}
void bpt(){
    int qw=1;
    colset(15);system("cls");
    printf("\n---------------------\n");
    int qwe=(q-1)/175+1;
    Goto(3,0);
    for(int i=0;i<qwe;i++){
        for(int j=1;j<=(i==qwe-1?(q-1)%175+1:175);j++){
            if(bp[i*175+j]) colset(10);
            if(i*175+j==1)  colset(12);
            printf("%c",lo[i*175+j]);
            colset(15);
        }
    }
    printf("\n");
    printf("      +----+\n");
    printf("      | Up |\n");
    printf("      |   W|\n");
    printf("      +----+\n");
    printf("+----++----++-----+\n");
    printf("|Left||Done||Right|\n");
    printf("|   A||  \\n||    D|\n");
    printf("+----++----++-----+\n");
    printf("+----++----+\n");
    printf("|Quit||Down|\n");
    printf("|   Q||   S|\n");
    printf("+----++----+\n");
    printf("\n---------------------\n");
    while(1){
        if(kbhit()){
            char hhhh=getch();
            if(hhhh=='A'||hhhh=='a'||hhhh=='D'||hhhh=='d'
                ||hhhh=='S'||hhhh=='s'||hhhh=='W'||hhhh=='w'){
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(15);
                if(bp[qw])  colset(10);
                printf("%c",lo[qw]);
            }
            if(hhhh=='A'||hhhh=='a'){
                --qw;
                if(qw<1)    qw+=q;
                while(lo[qw]=='['||lo[qw]==']'){
                    --qw;
                    if(qw<0)    qw+=q;
                }
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(12);
                printf("%c",lo[qw]);
            }
            else if(hhhh=='D'||hhhh=='d'){
                ++qw;
                if(qw>q)    qw-=q;
                while(lo[qw]=='['||lo[qw]==']'){
                    ++qw;
                    if(qw>q)    qw-=q;
                }
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(12);
                printf("%c",lo[qw]);
            }
            else if(hhhh=='w'||hhhh=='W'){
                qw-=175;
                if(qw<1){
                    while(qw<1) qw+=175;
                }
                while(lo[qw]=='['||lo[qw]==']'){
                    ++qw;
                    if(qw>q)    qw-=q;
                }
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(12);
                printf("%c",lo[qw]);
            }       
            else if(hhhh=='s'||hhhh=='S'){
                qw+=175;
                if(qw>q){
                    while(qw>q) qw-=175;
                }
                while(lo[qw]=='['||lo[qw]==']'){
                    ++qw;
                    if(qw>q)    qw-=q;
                }
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(12);
                printf("%c",lo[qw]);
            }       
            else if(hhhh==13){
                bp[qw]=!bp[qw];
                Goto(0,0);
                colset(12);
                if(bp[qw])  printf("Now there is a breakpoint.");
                else    printf("Now there is not a breakpoint.");
                printf("Press or click to continue...");
                while(1){
                    if(kbhit()||KEY_DOWN(MOUSE_MOVED))  return;
                }
                break;
            }
            if(hhhh=='Q'||hhhh=='q')    break;
        }
        if(KEY_DOWN(MOUSE_MOVED)){
            Sleep(100);
            got();
            if((pt.y>0+(4+(q-1)/175)*16&&pt.y<64+(4+(q-1)/175)*16&&pt.x>48&&pt.x<96)
               ||(pt.y>64+(4+(q-1)/175)*16&&pt.y<128+(4+(q-1)/175)*16&&pt.x>0&&pt.x<48)
               ||(pt.y>64+(4+(q-1)/175)*16&&pt.y<128+(4+(q-1)/175)*16&&pt.x>96&&pt.x<136)
               ||(pt.y>128+(4+(q-1)/175)*16&&pt.y<192+(4+(q-1)/175)*16&&pt.x>48&&pt.x<96)){
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(15);
                if(bp[qw])  colset(10);
                printf("%c",lo[qw]);
            }
            if(pt.y>0+(4+(q-1)/175)*16&&pt.y<64+(4+(q-1)/175)*16&&pt.x>48&&pt.x<96){
                qw-=175;
                if(qw<1){
                    while(qw<1) qw+=175;
                }
                while(lo[qw]=='['||lo[qw]==']'){
                    ++qw;
                    if(qw>q)    qw-=q;
                }
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(12);
                printf("%c",lo[qw]);
            }
            if(pt.y>64+(4+(q-1)/175)*16&&pt.y<128+(4+(q-1)/175)*16&&pt.x>0&&pt.x<48){
                --qw;
                if(qw<1)    qw+=q;
                while(lo[qw]=='['||lo[qw]==']'){
                    --qw;
                    if(qw<0)    qw+=q;
                }
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(12);
                printf("%c",lo[qw]);
            }   
            if(pt.y>64+(4+(q-1)/175)*16&&pt.y<128+(4+(q-1)/175)*16&&pt.x>48&&pt.x<96){
                bp[qw]=!bp[qw];
                Goto(0,0);
                colset(12);
                if(bp[qw])  printf("Now there is a breakpoint.");
                else    printf("Now there is not a breakpoint.");
                printf("Press or click to continue...");
                if(kbhit()||KEY_DOWN(MOUSE_MOVED))  return;
                break;
            }
            if(pt.y>64+(4+(q-1)/175)*16&&pt.y<128+(4+(q-1)/175)*16&&pt.x>96&&pt.x<136){
                ++qw;
                if(qw>q)    qw-=q;
                while(lo[qw]=='['||lo[qw]==']'){
                    ++qw;
                    if(qw>q)    qw-=q;
                }
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(12);
                printf("%c",lo[qw]);
            }   
            if(pt.y>128+(4+(q-1)/175)*16&&pt.y<192+(4+(q-1)/175)*16&&pt.x>48&&pt.x<96){
                qw+=175;
                if(qw>q){
                    while(qw>q) qw-=175;
                }
                while(lo[qw]=='['||lo[qw]==']'){
                    ++qw;
                    if(qw>q)    qw-=q;
                }
                Goto((qw-1)/175+3,(qw-1)%175);
                colset(12);
                printf("%c",lo[qw]);
            }   
            if(pt.y>128+(4+(q-1)/175)*16&&pt.y<192+(4+(q-1)/175)*16&&pt.x>0&&pt.x<48)   return;
        }
    }
    colset(15);system("cls");
}
bool r;
char haha;
void mdf(){
    colset(15);system("cls");
    colset(15);
    printf("+----+\n");
    printf("|Done|\n");
    printf("|   D|\n");
    printf("+----+\n");
    printf("Put the code there...\n");
    printf("Input D/d or press to select\n");
    printf("Because of some reason , we will change it to 1 line...\n");
    memset(lo,0,sizeof(lo));
    q=0;
    while(1){
        if(kbhit()){
            haha=getch();
            if(haha=='D'||haha=='d')    return;
            if(haha==13)    haha=10;
            if(haha==8){
                if(q!=0)    --q;
                Goto(7+q/175,q%175);
                printf(" ");
            }
            else if(haha==10||haha==32||haha==9){;}
            else{
                lo[++q]=haha;
                Goto(7+(q-1)/175,(q-1)%175);
                printf("%c",haha);
            }
        }
        if(KEY_DOWN(MOUSE_MOVED)){
            got();
            if(pt.y>0&&pt.y<64&&pt.x>0&&pt.x<48)    return;
        }
    }
}
int mnn,zz,zz2,uu;
bool aaaa;
void im(int be,int en){
    int nn=be;
    int su=(q-1)/175+1;
    while(nn<=en&&aaaa){
        got();
        if(KEY_DOWN(MOUSE_MOVED)){
            if(pt.y>32&&pt.y<48){ 
                colset(15);
                Goto(1,2);
                printf("Pause...");
                while(KEY_DOWN(MOUSE_MOVED)){
                    Sleep(50);
                    got();
                    if(pt.x<0)  pt.x=0;
                    if(pt.x>790)    pt.x=790;
                    Goto(2,uu/5-2);
                    printf("---");
                    Goto(2,99);
                    printf("  ");
                    Goto(2,pt.x/8);
                    printf("¡ö");
                    uu=pt.x/16*10+10;
                    Goto(0,8);
                    printf("%3d",uu);
                }
                Goto(1,2);
                printf("        ");
            }
            if(pt.y>0&&pt.y<64&&pt.x>808&&pt.x<856) return;
        }
        if(kbhit()){
            char haha=getch();
            if(haha==9){
                aaaa=false;
                return;
            }
            if(haha==-32){
                haha=getch();
                colset(15);
                Goto(2,uu/5-2);
                printf("---");
                Goto(2,99);
                printf("  ");
                if(haha==75)    uu=uu-10;
                if(haha==77)    uu=uu+10;
                if(uu<10)   uu=10;
                if(uu>500)  uu=500;
                Goto(2,uu/5-2);
                printf("¡ö");
                Goto(0,8);
                printf("%3d",uu);
                colset(12);
            }
        }
        if(zz!=now){
            colset(11);
            Goto(4*(zz/34)+9+su,5*(zz%34)+1);
            printf("   ");
            zz=now;
            Goto(4*(now/34)+9+su,5*(now%34)+1);
            printf("^^^");
            colset(15);
        }
        Goto((nn-1)/175+6,(nn-1)%175);
        colset(12);
        printf("%c",lo[nn]);
        colset(11);
        if(zz2!=nn){
            Goto((zz2-1)/175+6,(zz2-1)%175);
            colset(11);
            printf("%c",lo[zz2]);
        }
        zz2=nn;
        if(lo[nn]=='<'){
            colset(11);
            Goto(4*(now/34)+9+su,5*(now%34)+1);
            printf("   ");
            --now;
            Goto(4*(now/34)+9+su,5*(now%34)+1);
            printf("^^^");
            zz=now;
            colset(15);
        }
        else if(lo[nn]=='>'){
            colset(11);
            Goto(4*(now/34)+9+su,5*(now%34)+1);
            printf("   ");
            ++now;
            Goto(4*(now/34)+9+su,5*(now%34)+1);
            printf("^^^");
            colset(15);
            if(mnn<now){
                mnn=now;
                colset(15-now%8);
                Goto(4*(now/34)+6+su,5*(now%34));
                printf("+---+");
                Goto(4*(now/34)+7+su,5*(now%34));
                printf("|  0|");
                Goto(4*(now/34)+8+su,5*(now%34));
                printf("+---+");
            }
            zz=now;
        }
        else if(lo[nn]=='+'){
            ++by[now];
            while(by[now]<0)    by[now]+=128;
            while(by[now]>127)  by[now]-=128;
            Goto(4*(now/34)+7+su,5*(now%34)+1);
            colset(15-now%8);
            printf("%3d",by[now]);
        }
        else if(lo[nn]=='-'){
            --by[now];
            while(by[now]<0)    by[now]+=128;
            while(by[now]>127)  by[now]-=128;
            Goto(4*(now/34)+7+su,5*(now%34)+1);
            colset(15-now%8);
            printf("%3d",by[now]);
        }
        else if(lo[nn]=='.'){
            while(by[now]<0)    by[now]+=128;
            while(by[now]>127)  by[now]-=128;
            Goto(5,++s);
            if(by[now]!=10) printf("%c",by[now]);
            else{
                printf("\\n");
                ++s;
            }
        }
        else if(lo[nn]==','){
            Goto(4,0);
            colset(12);
            printf("Waiting for read");
            char haha;
            while(1){
                got();
                if(KEY_DOWN(MOUSE_MOVED)){
                    if(pt.y>32&&pt.y<48){ 
                        colset(15);
                        Goto(1,2);
                        printf("Pause...");
                        while(KEY_DOWN(MOUSE_MOVED)){
                            Sleep(50);
                            got();
                            if(pt.x<0)  pt.x=0;
                            if(pt.x>790)    pt.x=790;
                            Goto(2,uu/5-2);
                            printf("---");
                            Goto(2,99);
                            printf("  ");
                            Goto(2,pt.x/8);
                            printf("¡ö");
                            uu=pt.x/16*10+10;
                            Goto(0,8);
                            printf("%3d",uu);
                        }
                        Goto(1,2);
                        printf("        ");
                        colset(12);
                    }
                    if(pt.y>0&&pt.y<64&&pt.x>808&&pt.x<856) return;
                }
                if(kbhit()){        
                    haha=getch();
                    if(haha==9){
                        aaaa=false;
                        return;
                    }
                    else if(haha==-32){
                        haha=getch();
                        colset(15);
                        Goto(2,uu/5-2);
                        printf("---");
                        Goto(2,99);
                        printf("  ");
                        if(haha==75)    uu=uu-10;
                        if(haha==77)    uu=uu+10;
                        if(uu<10)   uu=10;
                        if(uu>500)  uu=500;
                        Goto(2,uu/5-2);
                        printf("¡ö");
                        Goto(0,8);
                        printf("%3d",uu);
                        colset(12);
                    }
                    else{
                        by[now]=(int)haha;
                        break;
                    }
                }
            }
            if(by[now]==13) by[now]=10;
            Goto(4,0);
            printf("                ");
            Goto(4*(now/34)+7+su,5*(now%34)+1);
            colset(15-now%8);
            printf("%3d",by[now]);
        }
        else if(lo[nn]=='['){
            int nnn=nn+1,no=1;
            while(no!=0){
                if(lo[nnn]=='[')    ++no;
                if(lo[nnn]==']')    --no;
                ++nnn;
            }
            while(by[now]!=0)   im(nn+1,nnn-2);
            nn=nnn-1;
        }
        ++nn;
        Sleep(uu);
    }
}
void imt(){
    memset(by,0,sizeof(by));
    colset(15);system("cls");
    printf("You will use this when you use less memorys , ouput , code and time.\n");
    printf("Are you ");
    colset(12);
    printf("SURE");
    colset(15);
    printf("?\n");
    printf("+---++--+\n");
    printf("|Yes||No|\n");
    printf("|  Y|| N|\n");
    printf("+---++--+\n");
    char qwer;
    do{
        if(kbhit()) qwer=getch();
        got();
    }while((qwer!='Y'&&qwer!='y'&&qwer!='N'&&qwer!='n') && !(KEY_DOWN(MOUSE_MOVED)&&pt.y>32&&pt.y<96&&pt.x>0&&pt.x<72));
    if(KEY_DOWN(MOUSE_MOVED)){
        if(pt.x>40&&pt.x<72)  return;
    }
    if(qwer=='N'||qwer=='n')    return;
    uu=100;
    colset(15);system("cls");
    Goto(0,0);
    printf("Speed : 100 ms                                                                                       +----+\n"); 
    printf("¡û                                                                                               ¡ú  |Exit|\n");
    printf("------------------¡ö-------------------------------------------------------------------------------  | Tab|\n");
    printf("                                                                                                     +----+\n");
    mnn=0;
    s=6;
    now=0;
    zz2=1;
    int sua=(q-1)/175+1;
    Goto(6+sua,0);
    colset(15-now%8);
    printf("+---+\n|  0|\n+---+\n ^^^ ");
    zz=1;
    Goto(5,0);
    printf("Ouput:)");
    Goto(6,0);
    uu=100;
    for(int i=0;i<sua;i++){
        for(int j=0;j<(i==sua-1?(q-1)%175+1:175);j++){
            colset(11);
            printf("%c",lo[i*175+j+1]);
        }
    }
    colset(15);
    aaaa=true;
    im(1,q);
    if(haha==9) return;
    Goto(4,0);
    printf("Press to continue...");
    getch();
    colset(15);system("cls");
}
void hlp(){
    system("cls");
    printf("Brainfuck is a minimal computer language created by Urban Muller in 1993 \n");
    printf("> pointer plus one \n< pointer minus one \n+ pointer to byte plus one \n- pointer to byte minus one \n");
    printf(". Output pointer pointing unit content (ASCII code) \n, input content to pointer pointing unit (ASCII code) \n");
    printf("[ jumps back to the next instruction of the corresponding ] instruction if the cell value the pointer points to is zero \n");
    printf("] jumps forward to the corresponding [ next instruction of instruction if the cell value that the pointer points to is not zero.\n");
    printf("+-----+\n|Close|\n|    C|\n+-----+");
    while(1){
        Sleep(50); got();
        if(kbhit()){
            char haha=getch();
            if(haha=='C'||haha=='c')    return;
        }
        if(KEY_DOWN(MOUSE_MOVED) && pt.y>=144 && pt.y<=208)
            if(pt.x>=4 && pt.x<=56) return;
    }
}
void imf(){
    colset(15);system("cls");
    printf("This is a Brainfuck Compile System\n");
    printf("Creater Imformatiom          |Modifier Imformation\n");
    printf("Name:\n");  
    printf("++++++++[->++++++++<]>+++    |+++++++++[->+++++++++<]>+\n");
    printf("++<]>+++.<.<++++++[->++++    |++++++++.++++++++.<++++[-\n");
    printf("+++[->+++<]>+.<              |>++++<]>+++++.< \n");
    printf("Nickname:\n");
    printf("++++++++++[->++++++++++<]    |++++++++[->++++++++<]>++.\n");
    printf(">++++++++++++++++.<+++[->    |<++++++[->++++++<]>++++++\n");
    printf("---<]>--.--.--.<+++[->+++    |+++.++++++++.<++++[->----\n");
    printf("<]>++++.<++++++++[->-----    |<]>--.+++++++++.<+++++++[\n");
    printf("---<]>.--..+++++.<           |->-------<]>------------.\n");
    printf("                             |+.+.<\n");
    printf("-------------------------------------------------------\n");
    printf("+-----+\n");
    printf("|Close|\n");
    printf("|    C|\n");
    printf("+-----+\n");
    while(1){
        Sleep(50);got();
        if(kbhit()){
            char haha=getch();
            if(haha=='C'||haha=='c')    break;
        }
        if(KEY_DOWN(MOUSE_MOVED) && pt.y>=224 && pt.y<=288)
            if(pt.x>=4 && pt.x<=56) return;
    }
    getch();
    colset(15);system("cls");
}
int main(){
    colset(15);
    system("mode con cols=175 lines=50");
    Hide(); 
    r=false;
    xr=false;
    memset(sc,0,sizeof(sc));
    memset(by,0,sizeof(by));
    memset(lo,0,sizeof(lo));
    memset(bp,0,sizeof(bp));
    while(1){
        system("cls");
//        fstream out("testlib.txt",ios::app);
        colset(15);
        printf("|+-------+  +-----+  +----+|");
        printf("|+----------+  +----+|");
        if(!r)  colset(8);
        printf("|+---+  +----------+  +-----+|\n");
        colset(15);
        printf("||Compile|  |Write|  |Edit||");
        printf("||Imfomation|  |Help||");
        if(!r)  colset(8);
        printf("||Run|  |Breakpoint|  |Debug||\n");
        colset(15);
        printf("||     F9|  |    W|  |   E||");
        printf("||         I|  |   H||");
        if(!r)  colset(8);
        printf("||F10|  |         B|  |   F5||\n");
        colset(15);
        printf("|+-------+  +-----+  +----+|");
        printf("|+----------+  +----+|");
        if(!r)  colset(8);
        printf("|+---+  +----------+  +-----+|\n");
        colset(15);
        printf("+----------Coding----------+");
        printf("+-------About--------+");
        if(!r)  colset(8); 
        printf("+-----------Running----------+\n");
        colset(15);
        while(kbhit())  haha=getch();
        while(1){
            Sleep(50); got();
            if(kbhit()){
                char haha=getch();
                if(haha==0){
                    char haha2=getch();
                    if(haha2==63){
                        if(r){
                            imt();
                            break;
                        }
                        else{
                            Goto(5,0);
                            colset(12);
                            printf("Warning : Compile First");
                            colset(15);
                        }
                    }
                    if(haha2==67){
                        system("cls");
                        lk=1;
                        printf("-----------------------------------\n");
                        r=com();
                        if(r){
                            printf("Compile success!\n");
                            printf("-----------------------------------\n");
                            lk+=2;
                        }
                        printf("+-----+\n");
                        printf("|Close|\n");
                        printf("|    C|\n");
                        printf("+-----+\n");
                        if(lk>45)   lk=45;
                        while(1){
                            Sleep(50);got();
                            if(kbhit()){
                                char haha=getch();
                                if(haha=='C'||haha=='c')    break;
                            }
                            if(KEY_DOWN(MOUSE_MOVED)){
                                if(pt.y>lk*16&&pt.y<lk*16+64&&pt.x>0&&pt.x<112) break;
                            }
                        }
                        break;
                    }
                    if(haha2==68){
                        if(r){
                            run();
                            break;
                        }
                        else{
                            Goto(5,0);
                            colset(12);
                            printf("Warning : Compile First");
                            colset(15);
                        }
                    }
                }
                if(haha=='W'||haha=='w'){
                    mdf();
                    r=false;
                    memset(bp,0,sizeof(bp));
                    break;
                }
                if(haha=='E'||haha=='e')    return 0;
                if(haha=='I'||haha=='i'){
                    imf();
                    break;
                }
                if(haha=='H'||haha=='h'){
                    hlp();
                    break; 
                }
                if(haha=='B'||haha=='b'){
                    if(r){
                        bpt();
                        break;
                    }
                    else{
                        Goto(5,0);
                        colset(12);
                        printf("Warning : Compile First");
                        colset(15);
                    }
                }
            }
            if(KEY_DOWN(MOUSE_MOVED)&&pan(pt.y,pt.x)){
                if(pan(pt.y,pt.x)==1){
                    system("cls");
                    lk=1;
                    printf("-----------------------------------\n");
                    r=com();
                    if(r){
                        printf("Compile succeed!\n");
                        printf("-----------------------------------\n");
                        lk+=2;
                    }
                    printf("+-----+\n");
                    printf("|Close|\n");
                    printf("|    C|\n");
                    printf("+-----+\n");                       
                    if(lk>45)   lk=45;
                    while(1){
                        Sleep(50);got();
                        if(kbhit()){
                            char haha=getch();
                            if(haha=='C'||haha=='c')    break;
                        }
                        if(KEY_DOWN(MOUSE_MOVED)){
                            if(pt.y>lk*16&&pt.y<lk*16+64&&pt.x>0&&pt.x<56) break;
                        }
                    }
                    break;
                }
                if(pan(pt.y,pt.x)==2){
                    mdf();
                    r=false;
                    break;
                }
                if(pan(pt.y,pt.x)==3)   return 0;
                if(pan(pt.y,pt.x)==4){
                    imf();
                    break;
                }
                if(pan(pt.y,pt.x)==5){
                    hlp();
                    break;
                }
                if(pan(pt.y,pt.x)==6){
                    if(!r){
                        Goto(5,0);
                        colset(12);
                        printf("Warning : Compile First");
                        colset(15);
                    }
                    else{
                        run();
                        break;
                    }

                }
                if(pan(pt.y,pt.x)==7){
                    if(!r){
                        Goto(5,0);
                        colset(12);
                        printf("Warning : Compile First");
                        colset(15);
                    }
                    else{
                        bpt();
                        break;
                    }
                }
                if(pan(pt.y,pt.x)==8){
                    if(!r){
                        Goto(5,0);
                        colset(12);
                        printf("Warning : Compile First");
                        colset(15);
                    }
                    else{
                        imt();
                        break;
                    }
                }
            }
        }
    }
}
