class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        transform(paragraph.begin(),paragraph.end(),paragraph.begin(),::tolower); //transform to lower case

        //remove punctuations
        for (char &c:paragraph) {
            if (ispunct(c)) {
                c = ' ';
            }
        }

        stringstream ss(paragraph);
        string word = "";
        unordered_map<string,int> mp;
        priority_queue<pair<int,string>> pq;

        while (ss >> word) {
            if (find(banned.begin(),banned.end(),word) == banned.end()) {
                mp[word]++;
            }
        }

        for (auto [w,freq]:mp) {
            pq.push({freq,w});
        }

        return pq.top().second;
    }
};