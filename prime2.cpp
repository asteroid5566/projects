#include<iostream>
using namespace std;

int main(){
    
    char repeat;
    
    while(repeat!='n'&&repeat!='N')
    {
        int a,b,i,type=1,count=1;
        
        cout<<" ��J�Ʀr�d���\n\n "; 
        cin>>a;
        if(a<2)
        {
            cin.sync();     //�קK��J�����O���P�y���v�T 
            cout<<"\n �̤p����Ƭ�2�A�п�J�j��2����\n\n\n\n\n\n\n"<<endl;
            continue;
        }
        
        cout<<"\n 2"<<endl;
        
        for(b=3;b<=a;b++)
        {
            for(i=2;i<b;i++)
            {
                if(b%i==0)
                    type=0; //������Ʈ�type�]��0 
            }
            if(type==1)
            { 
                cout<<" "<<b<<endl;
                count++;
            } 
            type=1;
        }
        cout<<"\n\n �p�󵥩� "<<a<<" ������`�@�� "<<count<<" ��\n\n\n"<<endl; 
        
        do{
        cin.sync();         //�קK���e��J���Ʀr�βŸ��v�T 
        cout<<" �A���d��? y/n ";
        cin>>repeat;
        }while(repeat!='y'&&repeat!='Y'&&repeat!='n'&&repeat!='N');
        
        if(repeat=='y'|repeat=='Y')
            cout<<"\n\n\n\n\n"<<endl;   
    }
    return 0;
}
