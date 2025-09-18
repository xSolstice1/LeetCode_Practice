class TaskManager {
public:
    // Each taskId maps to {userId, priority}
    unordered_map<int, pair<int,int>> taskMap; 

    // Max-heap: {priority, taskId}
    priority_queue<pair<int,int>> pq; 

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskMap[taskId] = {userId, priority}; //store task info
            pq.push({priority, taskId}); //push into heap
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority}; //add new task
        pq.push({priority, taskId}); //push into heap
    }
    
    void edit(int taskId, int newPriority) {
        int userId = taskMap[taskId].first; //get userId
        taskMap[taskId] = {userId, newPriority}; //update mapping
        pq.push({newPriority, taskId}); //push new version into heap
    }
    
    void rmv(int taskId) {
        taskMap.erase(taskId); //just erase from map, lazy removal in heap
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top(); 
            if (taskMap.count(taskId) && taskMap[taskId].second == priority) {
                //found valid task
                int userId = taskMap[taskId].first; 
                taskMap.erase(taskId); //remove from system
                pq.pop(); 
                return userId; 
            }
            pq.pop(); //discard outdated entry
        }
        return -1; //no tasks available
    }
};


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */