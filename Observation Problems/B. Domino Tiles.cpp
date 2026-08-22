#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{ 
  ll n;
  cin>>n;
  string s;
  cin>>s;
 
  string a,b,c,d;
  a="0";
  b="1";
  c="00";
  d="11";
  // 0 1100 11 
  //1100
  // 1100
 
  while(a.size()<n)
  {
    if(a.size()+4<=n) a+="1100";
    else if(a.size()+3 <= n) a+="110";
    else if(a.size()+2 <= n) a+="11";
    else if(a.size()+1 <= n ) a+="1";
  }
  while(b.size()<n)
  {
    if(b.size()+4<=n) b+="0011";
    else if(b.size()+3 <= n) b+="001";
    else if(b.size()+2 <= n) b+="00";
    else if(b.size()+1 <= n ) b+="0";
  }
  while(c.size()<n)
  {
    if(c.size()+4<=n) c+="1100";
    else if(c.size()+3 <= n) c+="110";
    else if(c.size()+2 <= n) c+="11";
    else if(c.size()+1 <= n ) c+="1";
  }
  while(d.size()<n)
  {
    if(d.size()+4 <= n) d+="0011";
    else if(d.size()+3 <= n) d+="001";
    else if(d.size()+2 <= n) d+="00";
    else if(d.size()+1 <= n ) d+="0";
  }
 
  ll ans=4;
 
  for(ll i=0;i<n;i++)
  {
    if(a[i]!=s[i] && s[i]!='?')
    {
      ans--; 
      break;
    }
  }
  for(ll i=0;i<n;i++)
  {
    if(b[i]!=s[i] && s[i]!='?')
    {
      ans--; 
      break;
    }
  }
  for(ll i=0;i<n;i++)
  {
    if(c[i]!=s[i] && s[i]!='?')
    {
      ans--; 
      break;
    }
  }
  for(ll i=0;i<n;i++)
  {
    if(d[i]!=s[i] && s[i]!='?')
    {
      ans--; 
      break;
    }
  } 
  cout<<ans<<endl;
 
 
 
 
 
}
int main()
{
#ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("inputf.in", "r", stdin);
  // for writing output to output.txt
  freopen("outputf.in", "w", stdout);
#endif
  int T;
  T = 1;
  cin>>T;
 
  while (T--)
  {
    solve();
  }
 
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}