// https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool checkCyclicDep(vector<vector<int>>& depList, vector<bool>& visited, vector<bool>& recStack, int i = 0) {
        if (recStack[i]) {
            return true; 
        }
        if (!visited[i]) {
            visited[i] = true;
            recStack[i] = true;
            for (int &j : depList[i]) {
                if (checkCyclicDep(depList, visited, recStack, j)) {
                    return true;
                }
            }
            recStack[i] = false;
        }
        return false;
    }

    bool canFinishDFS(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> depList(numCourses);
        for (auto &pair : prerequisites) {
            auto [course, prerequisite] = tie(pair[0], pair[1]);
            depList[course].push_back(prerequisite);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && checkCyclicDep(depList, visited, recStack, i)) {
                return false;
            }
        }
        return true;
    }

    bool canFinishBFS(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> depList(numCourses);
        vector<int> inDegree(numCourses);
        for (auto &pair : prerequisites) {
            auto [course, prerequisite] = tie(pair[0], pair[1]);
            depList[prerequisite].push_back(course);
            ++inDegree[course];
        }
        queue<int> q;
        // vector<int> topoSort;
        int topoSortSize = 0;
        for (int course = 0; course < numCourses; course++) {
            if (inDegree[course] == 0) {
                q.push(course);
            }
        }
        while (!q.empty()) {
            int course = q.front();
            // topoSort.push_back(course);
            ++topoSortSize;
            q.pop();
            for (int &dc : depList[course]) {
                --inDegree[dc];
                if (inDegree[dc] == 0) {
                    q.push(dc);
                }
            }
        }
        // return topoSort.size() == numCourses;
        return topoSortSize == numCourses;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return canFinishBFS(numCourses, prerequisites);
    }
};