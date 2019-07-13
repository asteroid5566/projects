#include<iostream>
using namespace std;

int main(){
    
    char repeat;
    
    while(repeat!='n'&&repeat!='N')
    {
        int a,b,i,type=1,count=1;
        
        cout<<" 块计琩借计\n\n "; 
        cin>>a;
        if(a<2)
        {
            cout<<"\n 程借计2叫块2\n\n\n\n\n"<<endl;
            continue;
        }
        cout<<"\n 2"<<endl;
        
        for(b=3;b<=a;b++)
        {
            for(i=2;i<b;i++)
            {
                if(b%i==0)
                    type=0; //ぃ借计type砞0 
            }
            if(type==1)
            { 
                cout<<" "<<b<<endl;
                count++;
            } 
            type=1;
        }
        cout<<"\n\n 单 "<<a<<" 借计羆Τ "<<count<<" \n\n\n"<<endl; 
        
        do{
        cout<<" Ω琩高? y/n ";
        cin>>repeat;
        }while(repeat!='y'&&repeat!='Y'&&repeat!='n'&&repeat!='N');
        
        if(repeat=='y'|repeat=='Y')
            cout<<"\n\n\n\n\n"<<endl;   
    }
    return 0;
}
