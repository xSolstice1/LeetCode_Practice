class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1); //each children must have at least one candy

        for (int i=1; i<ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) { //if left kid has lower rating
                candies[i] = candies[i-1]+1; //assign one more candy to current kid
            }
        }

        for (int i=ratings.size()-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) { //if right kid has lower rating
                candies[i] = max(candies[i],candies[i+1]+1); //avoid giving kid candy twice
            }
        }

        return accumulate(candies.begin(),candies.end(),0);
    }
};
