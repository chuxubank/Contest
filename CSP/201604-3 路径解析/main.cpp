#include <iostream>
#include <string>
using namespace std;
int main(){
    int num;
    string curDir;
    cin >> num >> curDir;
    getchar();
    for (int i = 0; i<num; i++){
        string in;
        getline(cin, in);
        long pos;
        // 添加当前目录
        if (in[0] != '/'){
            in = curDir + "/" + in;
        }
        if (in.size() == 0){
            in = curDir;
        }
        // 除去多个///
        while ((pos = in.find("//")) != -1){
            int count = 2;
            while (in[pos + count] == '/'){
                count++;
            }
            in.erase(pos, count - 1);
        }
        // 除去../
        while ((pos = in.find("/../")) != -1){
            if (pos == 0){
                in.erase(pos + 1, 3);
            }
            else{
                long spos;
                spos = in.rfind("/", pos - 1);
                in.erase(spos, pos - spos + 3);
            }
        }
        // 除去./
        while ((pos = in.find("/./")) != -1){
            in.erase(pos + 1, 2);
        }
        // 除去最后一个/
        if (in.size()>1 && in[in.size() - 1] == '/')
            in.erase(in.size() - 1);
        
        cout << in << endl;
    }
    return 0;
}
//第一个问题是没有考虑字符串末尾是/..或者/.的情况；另外，像.././../这种情况下，只往上退了一个目录。

//#include <iostream>
//#include <string>
//using namespace std;
//int main(){
//    string a="1234567890";
//    a.erase(2,6);
//    cout<<a<<endl;
//    return 0;
//}
//


