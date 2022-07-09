#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

//深度优先遍历，递归
class Solution {
public:
    int getImportance(vector<Employee> employees, int id) {
        int size = employees.size();
        if(size==0)
            return 0;
        //在id_map中构建员工id和employee一一对应关系
        for(int i=0;i<size;i++)
        {
            Employee employee = employees[i];
            id_map[employee.id] = employee;
        }
        return dfs(id_map, id);
    }
private:
    int result;
    map<int, Employee> id_map;
    int dfs(map<int, Employee> id_map, int id)
    {
        int size = id_map[id].subordinates.size();
        if(size==0)
            return id_map[id].importance;
        for(int i=0;i<size;i++)
            result += dfs(id_map, id_map[id].subordinates[i]);
        return result;
    }
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int size = employees.size();
        if(size==0)
            return 0;
        //在id_map中构建员工id和employee一一对应关系
        for(int i=0;i<size;i++)
        {
            Employee* employee = employees[i];
            id_map[employee->id] = employee;
        }
        return dfs(id_map, id);
    }
private:
    map<int, Employee*> id_map;
    int dfs(map<int, Employee*> id_map, int id)
    {
        int size = id_map[id]->subordinates.size();
        if(size==0)
            return id_map[id]->importance;
        int result = id_map[id]->importance;
        for(int i=0;i<size;i++)
            result += dfs(id_map, id_map[id]->subordinates[i]);
        return result;
    }
};


//广度优先遍历，非递归
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int size = employees.size();
        if(size==0)
            return 0;
        //在id_map中构建员工id和employee一一对应关系
        for(int i=0;i<size;i++)
        {
            Employee* employee = employees[i];
            id_map[employee->id] = employee;
        }
        return bfs(id_map, id);
    }
private:
    map<int, Employee*> id_map;
    int bfs(map<int, Employee*> id_map, int id)
    {
        int size = id_map[id]->subordinates.size();
        if(size==0)
            return id_map[id]->importance;
        int result = 0;
        queue<int> q;
        q.push(id);
        while(!q.empty())
        {
            int id_cur = q.front();
            q.pop();
            result += id_map[id_cur]->importance;
            int sub_size = id_map[id_cur]->subordinates.size();
            for(int i=0;i<sub_size;i++)
            {
                q.push(id_map[id_cur]->subordinates[i]);
            }
        }
        return result;
    }
};


