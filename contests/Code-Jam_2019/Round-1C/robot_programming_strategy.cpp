// https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134c90

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class tree {
    public:
    tree* rock=NULL;
    tree* scissor=NULL;
    tree* paper=NULL;
};
string mycode(tree* root) {
    string code;
    if(root==NULL) return "";
    if(root->scissor && root->paper==NULL) {
        code=mycode(root->rock);
        if(code=="IMPOSSIBLE") return code;
        else return 'R'+code;
    }
    else if(root->rock && root->scissor==NULL) {
        code=mycode(root->paper);
        if(code=="IMPOSSIBLE") return code;
        else return 'P'+code;
    }
    else if(root->paper && root->rock==NULL) {
        code=mycode(root->scissor);
        if(code=="IMPOSSIBLE") return code;
        else return 'S'+code;
    }
    else {
        return "IMPOSSIBLE";
    }
}
void prnt(tree* root) {
    if(root==NULL) return;
    if(root->rock) cout<<'R'<<" ";
    if(root->paper) cout<<'P'<<" ";
    if(root->scissor) cout<<'S'<<" ";
    cout<<endl;
    prnt(root->rock);
    prnt(root->paper);
    prnt(root->scissor);
}
int main() {
    int t,n; cin>>t;
    for(int x=1;x<=t;x++) {
        string code; cin>>n;
        tree* root=new tree;
        while(n--) {
            tree* temp=root;
            cin>>code;
            while(code.length()<=255) code+=code;
            for(int i=0;i<code.length();i++) {
                if(code[i]=='R') {
                    if(temp->rock==NULL)
                        temp->rock=new tree;
                    temp=temp->rock;
                }
                if(code[i]=='P') {
                    if(temp->paper==NULL)
                        temp->paper=new tree;
                    temp=temp->paper;
                }
                if(code[i]=='S') {
                    if(temp->scissor==NULL)
                        temp->scissor=new tree;
                    temp=temp->scissor;
                }
            }
        }
        // cout<<"start"<<endl;
        // prnt(root);
        // cout<<"end"<<endl;
        code=mycode(root);
        cout<<"Case #"<<x<<": "<<code<<endl;
    }
}