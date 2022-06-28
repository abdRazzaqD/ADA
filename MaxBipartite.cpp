#include <iostream>
#define MAX 10
using namespace std;
int graph[MAX][MAX], setA[MAX], setB[MAX];
int A,B;
bool bipartiteMatch(int u,bool *visited,int *check)
{
    for(int i=0;i<A;i++)
    {
        if (graph[u][i] && !visited[i])
        {
            visited[i] = true;
            if (check[i]<0 || bipartiteMatch(check[i],visited,check))
            {
                check[i]=u;
                return true;
            }
        }
    }
    return false;
}
int maxMatch()
{
    int check[A];
    bool visited[A];
    for(int i=0;i<A;i++)
        check[i]=-1;
    int result=0;
    for(int u=0;u<B;u++)
    {
        for(int i=0;i<A;i++)
            visited[i]=false;
        if(bipartiteMatch(u,visited,check))
            result++;
    }
    cout<<"Matched vertices set = {";
    for(int i=0;i<A;i++)
    {
        cout<<"("<<setA[i]<<", "<<setB[check[i]]<<")";
        if(i != A-1)
            cout<<", ";
    }
    cout<<"}";
    cout<<"\nMaximum number of matching: ";
    return result;
}
int main()
{
    cout<<"Enter number of vertices in set A and set B of bipartite graph: ";
    cin>>A>>B;
    cout<<"Enter vertices of set A: ";
    for(int i=0;i<A;i++)
        cin>>setA[i];
    cout<<"Enter vertices of set B: ";
    for(int i=0;i<B;i++)
        cin>>setB[i];
    cout<<"Enter "<<A<<" x "<<B<<" adjacency matrix representing relationship between set (A -> B):\n";
    for(int i=0;i<A;i++)
        for(int j=0;j<B;j++)
            cin>>graph[i][j];
    cout<<maxMatch();
    return 0;
}
