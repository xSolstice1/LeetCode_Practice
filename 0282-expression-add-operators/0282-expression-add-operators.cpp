class Solution {
public:
    void backtrack(string num, int target, vector<string>& res, string curr,
    int index, long eval, long prev) {
        if (index == num.size()) {
            if (eval == target) {
                res.push_back(curr);
            }
            return;
        }

        for (int i=index; i<num.size(); i++) {
            if (i != index && num[index] == 0) break; //leading zero

            string curSub = num.substr(index,i-index+1);
            long curEval = stol(curSub);

            if (index == 0) {
                backtrack(num,target,res,curSub,i+1,curEval,curEval);
            } else {
                // add
                backtrack(num,target,res,curr+"+"+curSub,i+1,eval+curEval,curEval);
                // minus
                backtrack(num,target,res,curr+"-"+curSub,i+1,eval-curEval,-curEval);
                // multiply
                backtrack(num,target,res,curr+"*"+curSub,i+1,(eval-prev)+(prev*curEval),prev*curEval);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        if (num.empty()) return {};

        vector<string> res;
        backtrack(num,target,res,"",0,0,0);
        return res;
    }
};