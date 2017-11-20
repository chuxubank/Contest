#include<iostream>
#include<string>
using namespace std;

struct Privilege  //定义权限
{
    string name;
    int level;
};
struct Role  //定义角色
{
    string name;
    struct Privilege privilege[11];
    int priviNum;
};
struct User  //定义用户
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
    struct Privilege p;// 如果权限带等级
    if(quanxian.find(":",0)!=string::npos){
        int pos=quanxian.find(":",0);
        p.name = quanxian.substr(0,pos);
        p.level = quanxian.at(quanxian.length()-1)-'0';
    }//如果不带等级
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
    scanf("%d",&p);//输入权限
    for(int i=0;i<p;i++){
        cin>>quanxian;
        pri[i]=getPrivilege(quanxian);
    }
    cin>>r;//输入角色
    for(int i=0;i<r;i++){
        string username;
        cin>>role[i].name;
        cin>>role[i].priviNum;//输入角色的特权
        for(int j=0;j<role[i].priviNum;j++){
            string quanxian;
            cin>>quanxian;
            role[i].privilege[j]=getPrivilege(quanxian);
        }
    }
    cin>>u;//输入用户
    for(int i=0;i<u;i++){
        cin>>user[i].name;
        cin>>user[i].roleNum;
        for(int j=0;j<user[i].roleNum;j++){
            string rolename;
            cin>>rolename;
            user[i].uRole[j]=role[findRole(rolename)];
        }
    }
    cin>>q;//开始查询
    while(q--){
        string name;
        string quanxian;
        cin>>name>>quanxian;
        int priviFlag=0,maxLevel=-1;
        if(findUser(name)!=-1){//找到用户
            User u=user[findUser(name)];
            for(int j=0;j<u.roleNum;j++){//遍历用户的角色
                for(int k=0;k<u.uRole[j].priviNum;k++){//遍历每个角色的特权
                    struct Privilege p;
                    p=getPrivilege(quanxian);
                    if(p.name==u.uRole[j].privilege[k].name){//找到了带权限的用户
                        if(p.level==-1&&u.uRole[j].privilege[k].level==-1)//不分等级权限的不分等级查询
                            priviFlag=1;
                        else if(p.level==-1&&u.uRole[j].privilege[k].level!=-1){//分等级权限的不分等级查询
                             if(maxLevel<u.uRole[j].privilege[k].level){
                                 priviFlag=1;
                                 maxLevel=u.uRole[j].privilege[k].level;
                             }
                        }
                        else if(p.level!=-1&&u.uRole[j].privilege[k].level!=-1){//分等级权限的分等级查询
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
