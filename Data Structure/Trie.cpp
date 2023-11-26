#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool endMark;
    Node *next[27]; // for lowercase letters only
    Node() {
        endMark = false;

        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};

Node *root;
/*
void _insert(char *s, int len)
{
    Node *cur = root;

    for(int i = 0; i < len; i++)
    {
        int idx = s[i]-'a';
        if(cur->next[idx] == NULL)
            cur->next[idx] = new Node();
        cur = cur->next[idx];
    }

    cur->endMark = true;
}
*/
void _insert(char *str,int len)
{
	Node *curr=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'a';
		if(curr->next[id]==NULL)
			curr->next[id]=new Node();
		curr=curr->next[id];
	}
	curr->endMark=1;
}

bool _search(char *s, int len)
{
    Node *cur = root;

    for(int i = 0; i < len; i++)
    {
        int id = s[i]-'a';
        if(cur->next[id] == NULL) return false;
        cur = cur->next[id];
    }

    return cur->endMark;
}

void del(Node *cur)
{
    for(int i = 0; i < 26; i++)
        if(cur->next[i] != NULL)
            del(cur->next[i]);

    delete(cur);
}

string process(string t)
{
    int i, len=t.size();

    for(i=0; i<len; i++)
    {
        if(t[i] <= 'Z') t[i] = t[i]+32;
    }

    return t;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //string s;
    int n;
    char s[100];

    cin >> n;

    root = new Node();

    while(n--)
    {
        cin >> s;
        _insert(s, strlen(s));
        //cout << process(s) << endl;
    }

    cin >> s;

    if(_search(s, strlen(s))) cout << "True";
    else cout <<"False";


    return 0;
}
