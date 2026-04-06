#include <string>

#include <unordered_map>
#include <string_view>
#include <map>
#include <cstdint>
#include <iostream>

using namespace std;

class TimeMap {
    // map <key, ordered<timestamp, value>>
    std::unordered_map<std::string, std::map<int, std::string>> m_map; 

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m_map[key][timestamp] = value;

    }
    
    string get(string key, int timestamp) {

    auto it_key = m_map.find(key);
    if (it_key == m_map.end()){ return "";}

    auto it_timestamp = it_key->second.upper_bound(timestamp);
    if (it_timestamp == it_key->second.begin()){
        return ""; // iterator at beginning, if beginning (smallest) elem larger than we want
    }

    it_timestamp--;
    return it_timestamp->second;
    
        
    }
};



        // if(m_map.find(key) != m_map.end()){
        //     if(m_map[key].find(timestamp) != m_map[key].end()){
        //         return m_map[key][timestamp];
        //     } else {
        //         if (m_map[key].upper_bound(timestamp) == m_map[key].begin()){
        //             // no valid target, all timestamps greater
        //             return "";
        //         } else {
        //             auto it_res = (m_map[key].upper_bound(timestamp))--;
        //             return it_res.second;

        //         }
        //         // if (m_map[key].begin()->first <= timestamp){
        //         // }
        //     }

        // }
        // return "";