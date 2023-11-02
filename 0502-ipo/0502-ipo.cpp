class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       vector<pair<int, int>> projects(profits.size());
    for (int i = 0; i < profits.size(); i++) {
        projects.push_back(make_pair(capital[i], profits[i]));
    }
    
    sort(projects.begin(), projects.end()); // Sort projects by capital requirements
    
    priority_queue<int> available_projects; // Use a max-heap for available projects
    int i = 0;
    
    for (int count = 0; count < k; count++) {
        while (i < projects.size() && projects[i].first <= w) {
            available_projects.push(projects[i].second);
            i++;
        }
        
        if (!available_projects.empty()) {
            w += available_projects.top();
            available_projects.pop();
        } else {
            break;
        }
    }
    
    return w;

    }
};