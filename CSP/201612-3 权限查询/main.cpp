#include<iostream>
#include<string>
using namespace std;

struct Privilege  //����Ȩ��
{
    string name;
    int level;
};
struct Role  //�����ɫ
{
    string name;
    struct Privilege privilege[11];
    int priviNum;
};
struct User  //�����û�
{
    string name;
    struct Role uRole[11];
    int roleNum;
};
struct Privilege pri[101];
struct Role role[101];
struct User user[101];

int findPrivilege(string name)
{
    for(int i=0;i<100;i++){
        if(pri[i].name==name)
            return i;
    }
    return -1;
}
int findRole(string name)
{
    for(int i=0;i<100;i++){
        if(role[i].name==name)
            return i;
    }
    return -1;
}
int findUser(string name)
{
    for(int i=0;i<100;i++){
        if(name==user[i].name)
            return i;
    }
    return -1;
}
struct Privilege getPrivilege(string quanxian)
{
    struct Privilege p;// ���Ȩ�޴��ȼ�
    if(quanxian.find(":",0)!=string::npos){
        int pos=quanxian.find(":",0);
        p.name = quanxian.substr(0,pos);
        p.level = quanxian.at(quanxian.length()-1)-'0';
    }//��������ȼ�
    else{
        p.name=quanxian;
        p.level=-1;
    }
    return p;
}

int main()
{
    int p,u,r,q;
    string quanxian;
    scanf("%d",&p);//����Ȩ��
    for(int i=0;i<p;i++){
        cin>>quanxian;
        pri[i]=getPrivilege(quanxian);
    }
    cin>>r;//�����ɫ
    for(int i=0;i<r;i++){
        string username;
        cin>>role[i].name;
        cin>>role[i].priviNum;//�����ɫ����Ȩ
        for(int j=0;j<role[i].priviNum;j++){
            string quanxian;
            cin>>quanxian;
            role[i].privilege[j]=getPrivilege(quanxian);
        }
    }
    cin>>u;//�����û�
    for(int i=0;i<u;i++){
        cin>>user[i].name;
        cin>>user[i].roleNum;
        for(int j=0;j<user[i].roleNum;j++){
            string rolename;
            cin>>rolename;
            user[i].uRole[j]=role[findRole(rolename)];
        }
    }
    cin>>q;//��ʼ��ѯ
    while(q--){
        string name;
        string quanxian;
        cin>>name>>quanxian;
        int priviFlag=0,maxLevel=-1;
        if(findUser(name)!=-1){//�ҵ��û�
            User u=user[findUser(name)];
            for(int j=0;j<u.roleNum;j++){//�����û��Ľ�ɫ
                for(int k=0;k<u.uRole[j].priviNum;k++){//����ÿ����ɫ����Ȩ
                    struct Privilege p;
                    p=getPrivilege(quanxian);
                    if(p.name==u.uRole[j].privilege[k].name){//�ҵ��˴�Ȩ�޵��û�
                        if(p.level==-1&&u.uRole[j].privilege[k].level==-1)//���ֵȼ�Ȩ�޵Ĳ��ֵȼ���ѯ
                            priviFlag=1;
                        else if(p.level==-1&&u.uRole[j].privilege[k].level!=-1){//�ֵȼ�Ȩ�޵Ĳ��ֵȼ���ѯ
                             if(maxLevel<u.uRole[j].privilege[k].level){
                                 priviFlag=1;
                                 maxLevel=u.uRole[j].privilege[k].level;
                             }
                        }
                        else if(p.level!=-1&&u.uRole[j].privilege[k].level!=-1){//�ֵȼ�Ȩ�޵ķֵȼ���ѯ
                             if(p.level<=u.uRole[j].privilege[k].level)
                                 priviFlag=1;
                        }
                    }
                }
            }
        }
        if(priviFlag==1&&maxLevel!=-1)
            cout<<maxLevel<<endl;
        else if(priviFlag==1&&maxLevel==-1)
            cout<<"true"<<endl;
        else if(priviFlag==0)
            cout<<"false"<<endl;
    }
    return 0;
}
