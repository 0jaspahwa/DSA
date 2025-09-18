class FoodRatings {
public:
    struct foodinfo{
        int rating;
        string name;
        bool operator<(const foodinfo& other) const{
            if(rating != other.rating){
                return rating < other.rating;
            }
            return name > other.name;
        }
    };
    typedef pair<int,int> P;
    unordered_map<string,priority_queue<foodinfo>> cuisineheaps;
    unordered_map<string, int> foodR;
    unordered_map<string,string> foodC;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodR[food] = rating;
            foodC[food] = cuisine;
            cuisineheaps[cuisine].push({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        foodR[food] = newRating;
        string cuisine = foodC[food];
        cuisineheaps[cuisine].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
        while(!cuisineheaps[cuisine].empty() &&cuisineheaps[cuisine].top().rating != foodR[cuisineheaps[cuisine].top().name]){
            cuisineheaps[cuisine].pop();

            
        }
        return cuisineheaps[cuisine].top().name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */