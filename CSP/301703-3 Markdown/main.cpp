#include <bits/stdc++.h>
using namespace std;
//强调
void replace_(string& str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '_')
            ;
        sum++;
    }
    sum /= 2;
    while (sum--)
    {
        if (str.find('_') == string::npos)
            break;
        int pos = str.find('_');
        str.erase(pos, 1);
        str.insert(pos, "<em>");
        pos = str.find('_');
        str.erase(pos, 1);
        str.insert(pos, "</em>");
    }
}
//链接
void replacelink(string& str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '[')
            ;
        sum++;
    }
    while (sum--)
    {
        if (str.find("](") == string::npos)
            break;
        int pos1 = str.find("[");
        int pos2 = str.find("]");
        int pos3 = str.find("(");
        int pos4 = str.find(")");
        string text = str.substr(pos1 + 1, pos2 - pos1 - 1);
        string link = str.substr(pos3 + 1, pos4 - pos3 - 1);
        str.erase(pos1, pos4 - pos1 + 1);
        string ins = "<a href=\"" + link + "\">" + text + "</a>";
        str.insert(pos1, ins);
    }
}
int main()
{
    string line;
    while (getline(cin, line))
    {
        //标题
        if (line.find('#') == 0 && line[line.rfind('#') + 1] == ' ')
        {
            stringstream os;
            int sum = 0;
            string con = line.substr(line.rfind('#') + 2);
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == '#')
                    sum++;
            }
            replace_(con);
            replacelink(con);
            os << "<h" << sum << ">" << con << "</h" << sum << ">";
            cout << os.str() << endl;
        }
        //无序列表
        else if (line.find('*') == 0 && line[line.rfind('*') + 1] == ' ')
        {
            stringstream os;
            string listline;
            os << "<ul>" << endl;
            string con = line.substr(line.rfind('*') + 2);
            replace_(con);
            replacelink(con);
            os << "<li>" << con << "</li>" << endl;
            while (getline(cin, listline))
            {
                if (listline.find('*') != 0 || line[line.rfind('*') + 1] != ' ')
                    break;
                con = listline.substr(listline.rfind('*') + 2);
                replace_(con);
                replacelink(con);
                os << "<li>" << con << "</li>" << endl;
            }
            os << "</ul>" << endl;
            cout << os.str();
        }
        //段落
        else if (line.find('#') != 0 && line.find('*') != 0 && line.length() > 0)
        {
            stringstream os;
            string pline;
            os << "<p>";
            replace_(line);
            replacelink(line);
            os << line;
            while (getline(cin, pline))
            {
                if (pline.length() == 0)
                    break;
                replace_(pline);
                replacelink(pline);
                os << endl << pline;
            }
            os << "</p>" << endl;
            cout << os.str();
        }
        else if (line.length() == 0)
        {
            continue;
        }
    }
    return 0;
}

//stringstream的用法w
