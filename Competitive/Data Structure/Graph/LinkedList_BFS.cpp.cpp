#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
using namespace std;
struct Edge;

struct Vertex
{
	char info;
	struct Vertex *nextVertex;
	struct Edge *firstEdge;
	string state="initial";
}*start = NULL;

struct Edge
{
	struct Vertex *destVertex;
	struct Edge *nextEdge;
};
void insertVertex(int u)
{
	struct Vertex *tmp,*ptr;
	tmp = new Vertex;
	tmp->info = u;
	tmp->nextVertex = NULL;
	tmp->firstEdge = NULL;

	if(start == NULL)
	{
		start = tmp;
		return;
	}
	ptr = start;
	while(ptr->nextVertex!=NULL)
		ptr = ptr->nextVertex;
	ptr->nextVertex = tmp;
}

struct Vertex *findVertex(int u)
{
	struct Vertex *ptr;
	ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->info == u )
            return ptr;

		else
			ptr = ptr->nextVertex;
	}
	return NULL;
}

void insertEdge(int u,int v)
{
	struct Vertex *locu,*locv;
	struct Edge *ptr,*tmp;

	locu = findVertex(u);
	locv = findVertex(v);

	tmp = new Edge;
	tmp->destVertex = locv;
	tmp->nextEdge = NULL;

	if(locu->firstEdge == NULL)
	{
		 locu->firstEdge = tmp;
         goto label;
	}
	ptr = locu->firstEdge;
	while(ptr->nextEdge!=NULL)
		ptr = ptr->nextEdge;
	ptr->nextEdge = tmp;

    label:
	tmp = new Edge;
	tmp->destVertex = locu;
	tmp->nextEdge = NULL;

	if(locv->firstEdge == NULL)
	{
		 locv->firstEdge = tmp;
         return;
	}
	ptr = locv->firstEdge;
	while(ptr->nextEdge!=NULL)
		ptr = ptr->nextEdge;
	ptr->nextEdge = tmp;
}

struct queu{
    struct Vertex *vv[MAX];
    int first=-1,last=-1;
};
void push(int x,struct queu &q){
    if(q.first==-1)
        q.first=0;
    ++q.last;
    struct Vertex *v;
    v=findVertex(x);
    q.vv[q.last]=v;
}
struct Vertex *pop(struct queu &q){
    struct Vertex *v;
    v=q.vv[q.first++];
    return v;
}
bool isempty(struct queu &q){
    if(q.first==-1||q.first>q.last)
        return 1;
    return 0;
}
void breadth_search(int x,struct queu &q){
    struct Vertex *v,*u;
    struct Edge *temp;
    push(x,q);
    while(!isempty(q)){
        u=pop(q);
        u->state="waiting";
        temp=u->firstEdge;
        cout<<u->info<<" ";
        while(temp!=nullptr){
           v=findVertex(temp->destVertex->info);
           if(v->state=="initial")
            push(v->info,q);
           v->state="waiting";
           temp=temp->nextEdge;
        }
        u->state="visited";
    }
}
int main()
{
    queu q;
	int i,n,e,t,choice;
	char vrt,a,b,x;
    cout<<"Enter total Vertex to be inserted"<<endl;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>vrt;
        insertVertex(vrt);
    }
    cout<<"Enter total Edge to be connected"<<endl;
    cin>>e;
    for(i=0;i<e;++i){
        cin>>a>>b;
        insertEdge(a,b);
    }
	cout<<"Enter a Vertex to start BFS"<<endl;
        cin>>x;
	breadth_search(x,q);
}

