#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<stack>
#include<vector>
using namespace std;
char *pro,*p; int len;
char **nxt,**pre;
int file_size(char* filename)
{
    FILE *fp=fopen(filename,"r");
    if(!fp) return -1;
    fseek(fp,0,SEEK_END);
    int size=ftell(fp);
    fclose(fp);
    return size;
}
void compile()
{
	nxt=new char*[len+5]; pre=new char*[len+5];
	stack<int> stk;
	for(int i=0;i<len;i++)
	{
		switch(pro[i])
		{
			case '[': stk.push(i); break;
			case ']':
				assert(stk.size());
				nxt[stk.top()]=pro+i;
				pre[i]=pro+stk.top();
				stk.pop();
				break;
			case '{':
				int pos=i++;
				while(i<len&&!(pro[i]=='}'&&pro[i-1]!='\\')) i++;
				assert(i<len);
				nxt[pos]=pro+i;
				break;
		}
	}
}
void run()
{
	compile();
	vector<unsigned char> mem; mem.push_back(0);
	auto it=mem.begin(); p=pro;
	while(p<pro+len)
	{
		switch(*p)
		{
			case '+': (*it)++; break;
			case '-': (*it)--; break;
			case '>':
				it++;
				if(it==mem.end()) { mem.push_back(0); it=mem.end()-1; }
				break;
			case '<':
				assert(it!=mem.begin());
				it--;
				break;
			case '.': putchar(*it); break;
			case ',': *it=getchar(); break;
			case '[':
				if(!(*it)) p=nxt[p-pro];
				break;
			case ']':
				if(*it) p=pre[p-pro];
				break;
			case '{': p=nxt[p-pro]; break;
		}
		p++;
	}
	delete[] nxt; delete[] pre;
}
int main(int argc,char** argv)
{
	if(argc==2)
	{
		char* fname=argv[1];
		len=file_size(fname);
		pro=new char[len+5]; memset(pro,0,len+5);
		FILE *fin=fopen(fname,"rb");
		fread(pro,len,1,fin);
		run();
	}
	else
	{
		const int maxn=10000000;
		pro=new char[maxn];
		while(fgets(pro,maxn,stdin))
		{
			len=strlen(pro);
			run();
		}
	}
	return 0;
}
