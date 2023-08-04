#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    string t;
    node* parent = NULL;
    vector<node*> child;
    int desclocked =0;
    int uid =0;
    bool locked =0;
    node(string a)
    {
        t=a;
    }
    node(string a, node * p)
    {
        t=a;
        parent =p;
    }
};
unordered_map<string, node*> mp;



bool lock(string place, int uid)
{
    node* placeadd = mp[place];
    if(placeadd->locked==true) return false;
    if(placeadd->desclocked!=0) return false;
    node * curr = placeadd->parent;
    while(curr)
    {
        if(curr->locked==true)  return false;
        curr=curr->parent;
    }
    placeadd->locked=true;
    placeadd->uid=uid;
    //updating ancestor about locked node
    curr=placeadd->parent;
    while(curr)
    {
        curr->desclocked++;
        curr=curr->parent;
    }
    return true;

}

bool unlock(string place, int uid)
{
    node * placeadd = mp[place];
    if(placeadd->locked==false) return false;
    if(placeadd->uid!=uid)  return false;
    placeadd->locked=false;
    placeadd->uid=0;
    node *curr=placeadd->parent;
    while(curr)
    {
        curr->desclocked--;
        curr=curr->parent;
    }

    return true;






}


bool upgrade(string place, int uid)
{
    node * placeadd = mp[place];
    if(placeadd->locked==true)  return false;
    if(placeadd->desclocked==0) return false;
    node* curr=placeadd->parent;
    while(curr)
    {
        if(curr->locked==true)  return false;
        curr=curr->parent;

    }
    int n = placeadd->child.size();
    for(int i=0;i<n;i++)
    {
        if(!(placeadd->child[i]->locked==true&&placeadd->child[i]->uid==uid))
            return false;
        placeadd->child[i]->locked=false;
        placeadd->child[i]->uid=0;
    }
    placeadd->locked=true;
    placeadd->uid=uid;

    return true;




}

void addlink(node* n, vector<string> &s)
{
    for(auto it: s)
    {
        n->child.push_back(new node(it,n));
    }
}

node * buildTree( vector<string> &places, int m, node* root, int n)
{
    int st=1;

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node * r = q.front();
        q.pop();

        vector<string> temp;
        if(st>=n)
            continue;
        
        for(int i=0;i<m;i++)
        {
            if(st+i<n)
            temp.push_back(places[st+i]);
        }
        addlink(r,temp);
        st+=m;

        for(int i=0;i<r->child.size();i++)
        {
            q.push(r->child[i]);
        }

        
    }


    return root;

    
    

}

void fillmp(node *r){
			if(!r) return;
			mp[r->t] = r;
			for(auto k : r->child)
				fillmp(k);
		}




int main(void)
{
    int m;
    int n;
    int q;
    vector<pair<int,pair<string,int>>> query;
    vector<string> places;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
    {
        string s ;
        // cin>>s;
        places.push_back((cin>>s,s));
    }
    for(int i=0;i<q;i++)
    {
        int a;
        string s;
        int x;
        query.push_back({(cin >> a, a), {(cin >> s, s), (cin >> x, x)}});

    }

    

   
    node * root = new node(places[0],NULL);   
    root = buildTree( places, m,root,n);
    root->t = places[0];
    // mp[places[0]]=root;
    // build(root, places, m);
    fillmp(root);

    for(int i=0;i<q;i++)
    {
        auto it = query[i];
        int op = it.first;
        string place = it.second.first;
        int uid = it.second.second;
        if(op==1)
        {
            if(!lock(place,uid))
                cout<<"false"<<endl;
            else
                cout<<"true"<<endl;
        }
        if(op==2)
        {
            if(!unlock(place,uid))
                cout<<"false"<<endl;
            else
                cout<<"true"<<endl;
        }
        if(op==3)
        {
            if(!upgrade(place,uid))
                cout<<"false"<<endl;
            else
                cout<<"true"<<endl;
        }
    }

    return 0;

    

    





}