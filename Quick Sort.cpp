#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int>& vec, int x, int y) {
    if(x>=y) {
        return;
    }
    int val=vec[x];
    int a=x,b=x,c=y+1;
    while (b+1<c) {
        if(vec[b+1]==val) {
            b++;
        }
        else if (vec[b+1]<val) {
            int s=vec[b+1];
            vec[b+1]=vec[a+1];
            vec[a+1]=s;
            a++;
            b++;
        }
        else {
            int t=vec[b+1];
            vec[b+1]=vec[c-1];
            vec[c-1]=t;
            c--;
        }
    }
    vec[x]=vec[a];
    vec[a]=val;
    quicksort(vec, x, a-1);
    quicksort(vec, c, y);
}

int main() {
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) {
        cin>>vec[i];
    }
    quicksort(vec,0,n-1);
    for(auto i:vec) {
        cout<<i<<" ";
    }
    return 0;
}
