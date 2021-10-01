#include<iostream>
using namespace std;

#include<bits/stdc++.h>
void swap(int *a,int *b)
    
{
    int c;
     c=*a;
    *a=*b;
    *b=c;
    
}
int partition(int input[],int s,int e){
    int count =0;
    int x=input[s];
    int i;
    for(i=s;i<=e;i++)                                                       
    {
        if(input[i]<x)
        {
            count++;
        }
    }
    i=0;
    int j=e;
    swap(&input[s+count],&input[s]);
    while(i<(s+count)&&j>(s+count)){
        if(input[i]<x){
            i++;
        }
        else if(input[j]>=x){
            j--;
        }
        else{
            swap(&input[i],&input[j]);
        }
    }
    
}
void sort(int input[],int s,int e)
{if(s>=e)
{
    return;
}
   int c = partition(input,s,e);
    sort(input,s,c-1);
    sort(input,c+1,e);
}
void quickSort(int input[], int size) {
 
 sort(input,0,size-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


