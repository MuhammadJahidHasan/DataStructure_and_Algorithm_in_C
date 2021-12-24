#include <bits/stdc++.h>

using namespace std;

vector<int> edg[100];
 int vis[100];
 int level[100];
 queue<int> q;

void bfs(int s, int n){

    level[s]=0;
    for(int i=0;i<n;i++) vis[i]=0;

     q.push(s);
     vis[s]=1;
     while(!q.empty()){

         int u=q.front();
         q.pop();

         for(int i=0;i<edg[u].size();i++){

            if(vis[edg[u][i]]==0){

              int temp=edg[u][i];
              vis[temp]=1;
              level[temp]=level[u]+1;
              q.push(temp);
            }
         }

     }

}

int main()
{
    int N,E;
    cin>>N>>E;
    for(int i=0;i<E;i++){
       int x,y;
       cin>>x>>y;
       edg[x].push_back(y);

    }
    int s;
    bfs(1,N);
    cout<<level[3]<<endl;


    return 0;
}
