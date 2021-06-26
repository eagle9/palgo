//shaun's own idea and code
//accepted after several bug fixes
//runtime 12ms, faster than 99%, mem less than 52%
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> count_of_domain; //domain to its visit count
        
        for (string cd: cpdomains) {
            //"count domain.xx.yy"
            int ispace = cd.find(' ');
            if (ispace != string::npos) {
                int count = stoi(cd.substr(0, ispace));
                string domain = cd.substr(ispace+1);
                
                count_of_domain[domain] += count;
                
                //process subdomains
                //while (int idot = domain.find('.') != string::npos) { //bug not working wrong answer, this while loop not correct with assignment and testing
                //for(int idot = domain.find('.'); idot != string::npos;) { //not work either
                //while (domain.find('.') != string::npos) { //this works, but call find twice
                while (true) {
                    int idot = domain.find('.');
                    if (idot == string::npos) break;
                    //string subdomain = domain.substr(0, idot); //bug futu brain
                    string subdomain = domain.substr(idot+1);
                    count_of_domain[subdomain] += count;
                    domain = subdomain;
                }
            }
        }
        vector<string> res;
        for (auto& kvpair: count_of_domain) {
            //kvpair.first = domain,  kvpair.second is count
            res.push_back(to_string(kvpair.second) + " " + kvpair.first);
        }
        return res;
        
    }
};
