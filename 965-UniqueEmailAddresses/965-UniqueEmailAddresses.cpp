// Last updated: 8/29/2025, 9:49:49 PM
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(string email : emails){
            int n = email.length();
            string localName = "";
            bool localNameFlag = true;
            int i = 0;
            for( i = 0; i < n; i++){
                char ch = email[i];
                if(ch == '+' || ch == '@')
                    break;
                if(localNameFlag){
                    if(ch == '.')
                        continue;
                    localName += ch;
                }
            }
            while(i < n && email[i] != '@')
                i++;
            string domainName = "";
            bool domainFlag = false;
            for(; i < n; i++){
                char ch = email[i];
                if(ch == '@'){
                    domainFlag = true;
                    continue;
                }
                if(domainFlag){
                    domainName += ch;
                }
            }
            s.insert(localName + "@" + domainName);
        }
        
        return s.size();
    }
};