class Solution {
public:
    void backtrack(string num, int target, string path, vector<string>& res,
    int index, long curr, long prev) {
        if (index==num.size()) {
            if (curr==target) {
                res.push_back(path);
            }
            return;
        }

        for (int i=index; i<num.size(); i++) {
            if (num[index] == '0' && i != index) break; //leading 0

            string curSub = num.substr(index,i-index+1);
            long curEval = stol(curSub);

            if (index == 0) { //start
                backtrack(num,target,path+curSub,res,i+1,curEval,curEval);
            } else {
                //backtrack 3 diff scenarios, +, -, *
                backtrack(num,target,path+'+'+curSub,res,i+1,curr+curEval,curEval);
                backtrack(num,target,path+'-'+curSub,res,i+1,curr-curEval,-curEval);
                backtrack(num,target,path+'*'+curSub,res,i+1,(curr-prev)+(prev*curEval),curEval*prev);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        if (num.empty()) return {};
        vector<string> res;
        backtrack(num,target,"",res,0,0,0);

        return res;
    }
};