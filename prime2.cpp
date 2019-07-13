#include<iostream>
using namespace std;

int main(){
    
    char repeat;
    
    while(repeat!='n'&&repeat!='N')
    {
        int a,b,i,type=1,count=1;
        
        cout<<" 輸入數字查質數\n\n "; 
        cin>>a;
        if(a<2)
        {
            cin.sync();     //避免輸入的型別不同造成影響 
            cout<<"\n 最小的質數為2，請輸入大於2的值\n\n\n\n\n\n\n"<<endl;
            continue;
        }
        
        cout<<"\n 2"<<endl;
        
        for(b=3;b<=a;b++)
        {
            for(i=2;i<b;i++)
            {
                if(b%i==0)
                    type=0; //不為質數時type設為0 
            }
            if(type==1)
            { 
                cout<<" "<<b<<endl;
                count++;
            } 
            type=1;
        }
        cout<<"\n\n 小於等於 "<<a<<" 的質數總共有 "<<count<<" 個\n\n\n"<<endl; 
        
        do{
        cin.sync();         //避免之前輸入的數字或符號影響 
        cout<<" 再次查詢? y/n ";
        cin>>repeat;
        }while(repeat!='y'&&repeat!='Y'&&repeat!='n'&&repeat!='N');
        
        if(repeat=='y'|repeat=='Y')
            cout<<"\n\n\n\n\n"<<endl;   
    }
    return 0;
}
