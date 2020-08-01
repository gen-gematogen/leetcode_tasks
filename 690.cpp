/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_set<int> subords;
        
        subords.insert(id);
        int n = employees.size();
        int pos = 0;
        int ans = 0;
        
        while (!subords.empty()){
            if (subords.find(employees[pos]->id) != subords.end()){
                ans += employees[pos]->importance;
                
                subords.erase(employees[pos]->id);
                
                for (int i: employees[pos]->subordinates){
                    subords.insert(i);
                }
            }
            
            pos = (pos + 1) % n;
        }
        
        return ans;
    }
};
