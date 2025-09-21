class MovieRentingSystem {
    struct Node {
        int price, shop, movie;
        bool operator<(const Node& other) const {
            if (price != other.price) return price < other.price;
            if (shop != other.shop) return shop < other.shop;
            return movie < other.movie;
        }
    };

    unordered_map<int, set<Node>> available;
    set<Node> rented;
    unordered_map<int, unordered_map<int,int>> priceMap;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[shop][movie] = price;
            available[movie].insert({price, shop, movie});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        auto& s = available[movie];
        int cnt = 0;
        for (auto it = s.begin(); it != s.end() && cnt < 5; ++it, ++cnt) {
            res.push_back(it->shop);
        }
        return res;
    }

    void rent(int shop, int movie) {
        int p = priceMap[shop][movie];
        Node node{p, shop, movie};
        available[movie].erase(node);
        rented.insert(node);
    }

    void drop(int shop, int movie) {
        int p = priceMap[shop][movie];
        Node node{p, shop, movie};
        rented.erase(node);
        available[movie].insert(node);
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto it = rented.begin(); it != rented.end() && cnt < 5; ++it, ++cnt) {
            res.push_back({it->shop, it->movie});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */