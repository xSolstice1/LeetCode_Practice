#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source;
    int destination;
    int timestamp;
    //set uniqueness
    bool operator==(const Packet &o) const {
        return source == o.source
            && destination == o.destination
            && timestamp == o.timestamp;
    }
};

//hash for packet
struct PacketHash {
    size_t operator()(const Packet &p) const {
        //combine hashes
        size_t h1 = std::hash<long long>()(
            ((long long)p.source << 32) ^ p.destination );
        size_t h2 = std::hash<int>()(p.timestamp);
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1<<6) + (h1>>2));
    }
};

class Router {
private:
    int memoryLimit;
    //fifo
    deque<Packet> packetQueue;
    //set to keep uniquepackets
    unordered_set<Packet, PacketHash> uniquePackets;
    //store timestamps
    unordered_map<int, vector<int>> destTimestamps;
    //store processed to check for index
    unordered_map<int, int> processedCount;

public:
    Router(int memoryLimit_) : memoryLimit(memoryLimit_) {}

    bool addPacket(int source, int destination, int timestamp) {
        Packet p{source, destination, timestamp};
        //duplicate?
        if (uniquePackets.find(p) != uniquePackets.end()) {
            return false;
        }
        //remove oldest
        if ((int)packetQueue.size() == memoryLimit) {
            forwardPacket();
        }
        //insert
        packetQueue.push_back(p);
        uniquePackets.insert(p);
        destTimestamps[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if (packetQueue.empty()) {
            return {};
        }
        Packet p = packetQueue.front();
        packetQueue.pop_front();
        uniquePackets.erase(p);
        //mark processed
        processedCount[p.destination]++;
        return {p.source, p.destination, p.timestamp};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end()) {
            return 0;
        }
        const vector<int> &times = it->second;
        int startIndex = processedCount[destination];
        auto lower = lower_bound(times.begin() + startIndex, times.end(), startTime);
        auto upper = upper_bound(times.begin() + startIndex, times.end(), endTime);
        return (int)(upper - lower);
    }
};
