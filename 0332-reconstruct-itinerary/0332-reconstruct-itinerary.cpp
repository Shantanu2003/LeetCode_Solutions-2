class Solution {
public:
void dfs(unordered_map<string, multiset<string>>& graph, string airport, vector<string>& itinerary) {
    while (!graph[airport].empty()) {
        string next_destination = *graph[airport].begin();
        graph[airport].erase(graph[airport].begin());
        dfs(graph, next_destination, itinerary);
    }
    itinerary.push_back(airport);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    // Create a graph represented as an unordered_map with multiset to store destinations in lexical order
    unordered_map<string, multiset<string>> graph;
    
    // Build the graph using given tickets
    for (const vector<string>& ticket : tickets) {
        graph[ticket[0]].insert(ticket[1]);
    }
    
    vector<string> itinerary;
    dfs(graph, "JFK", itinerary);
    
    // Reverse the itinerary to get the correct order
    reverse(itinerary.begin(), itinerary.end());
    
    return itinerary;
}
};