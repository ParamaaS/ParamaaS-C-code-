/*/
- Paramaa Sawanpanyalert -
Lang : c++
/*/
#include <bits/stdc++.h>
using namespace std;
int n,m,c,c2,x1,x2,rem;
char s[105][105];
vector<pair<int,int> > vec;
queue<pair<int,int> > q;
main()
{
	//freopen("test.txt","w",stdout);
	while(1)
	{
		rem=0;
		scanf("%d%d",&n,&m);
		if(n==0&&m==0)
		{
			return 1-1;
		}
		for(c=0;c<n;c++)
		{	
			scanf("%s",s[c]);
		}
		if(s[0][0]=='.')
		{
			s[0][0]='A';
		}
		else if(s[0][0]=='H')
		{
			s[0][0]='B';
		}
		q.push(make_pair(0,0));
		while(!q.empty())
		{
			x1=q.front().first;
			x2=q.front().second;
			q.pop();
			//printf("%d %d\n",x1,x2);
			if(x1>0)//left
			{
				if(s[x1-1][x2]!='A'||s[x1-1][x2]!='B')
				{
					if(s[x1-1][x2]=='.')
					{
						s[x1-1][x2]='A';
						q.push(make_pair(x1-1,x2));
					}
					if(s[x1-1][x2]=='H')
					{
						s[x1-1][x2]='B';
					}
				}
			}
			if(x2>0)//up
			{
				if(s[x1][x2-1]!='A'||s[x1][x2-1]!='B')
				{
					if(s[x1][x2-1]=='.')
					{
						s[x1][x2-1]='A';
						q.push(make_pair(x1,x2-1));
					}
					if(s[x1][x2-1]=='H')
					{
						s[x1][x2-1]='B';
					}	
				}	
			}
			if(x1<n-1)//right
			{
				if(s[x1+1][x2]!='A'||s[x1+1][x2]!='B')
				{
					if(s[x1+1][x2]=='.')
					{
						s[x1+1][x2]='A';
						q.push(make_pair(x1+1,x2));
					}
					if(s[x1+1][x2]=='H')
					{
						s[x1+1][x2]='B';
					}
				}	
			}
			if(x2<m-1)//down
			{
				if(s[x1][x2+1]!='A'||s[x1][x2+1]!='B')
				{
					if(s[x1][x2+1]=='.')
					{
						s[x1][x2+1]='A';
						q.push(make_pair(x1,x2+1));
					}
					if(s[x1][x2+1]=='H')
					{
						s[x1][x2+1]='B';
					}
				}
			}
		}
		for(c=0;c<n;c++)
		{
			for(c2=0;c2<m;c2++)
			{
				//printf("%c",s[c][c2]);
				//*/
				if(s[c][c2]=='B')
				{
					vec.push_back(make_pair(c,c2));
					continue;
				}
				else if(s[c][c2]=='.'&&s[c+1][c2]=='H'&&s[c][c2+1]=='H'&&s[c][c2-1]=='H'&&s[c-1][c2]=='H')
				{
					s[c][c2]='P';
				}//*/
			}//printf("\n");
		}
		while(!vec.empty())
		{
			x1=vec[vec.size()-1].first;
			x2=vec[vec.size()-1].second;
			vec.pop_back();
			if(x1>0)
			{
				if(s[x1-1][x2]=='A')
				{
					rem++;
				}
			}
			if(x2>0)
			{
				if(s[x1][x2-1]=='A')
				{
					rem++;
				}	
			}
			if(x1<n-1)
			{
				if(s[x1+1][x2]=='A')
				{
					rem++;
				}	
			}
			if(x2<m-1)
			{
				if(s[x1][x2+1]=='A')
				{
					rem++;
				}
			}
		}
		printf("%d\n",rem);
	}
}
