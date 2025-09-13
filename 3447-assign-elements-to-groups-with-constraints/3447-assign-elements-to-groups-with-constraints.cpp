class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        // bruteforce approach, TLE again :(
        vector<int> res(groups.size(),-1); //assign -1 to vector res of groups.size()

        // for (int i=0; i<groups.size(); i++) {
        //     for (int j=0; j<elements.size(); j++) {
        //         if (groups[i]%elements[j]==0) {
        //             res[i] = j;
        //             break;
        //         }
        //     }
        // }

        // return res;

    //approach 2, try to map factors (elements) to it's respective index, so we don't have to pass through vector elements everytime
        unordered_map<int,int> factorMap;

        for (int i=0; i<elements.size(); i++) {
            if (!factorMap.count(elements[i])) factorMap[elements[i]] = i;
        }

        for (int i=0; i<groups.size(); i++) {
            int num = groups[i];
            int minInd = INT_MAX; //keep track of min index j for elements

            for (int divisor=1; divisor*divisor <= num; divisor++) { //check all possible divisors for num
                if (num%divisor==0) {
                    if (factorMap.count(divisor)) minInd = min(minInd,factorMap[divisor]); //update min index

                    int other = num/divisor;
                    if (other!=divisor && factorMap.count(other)) minInd = min(minInd,factorMap[other]); //update min index
                }
            }

            res[i] = (minInd == INT_MAX ? -1:minInd);
        }

        return res;
    }
};