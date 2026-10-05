class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        int res = n;

        queue<int> q;

        for(int student : students){
            q.push(student);
        }

        for(int sandwich : sandwiches){

            int count = 0;
            while( count < n && q.front() != sandwich){
                q.push(q.front());
                q.pop();
                count++;
            }

            if(q.front() == sandwich){
                q.pop();
                res--;
            }
            else break;
        }

        return res;
    }
};