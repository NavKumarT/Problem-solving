// Last updated: 8/29/2025, 9:48:54 PM
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i = 0, j = 0, count = 0, sold = 0;
        while(count < students.size() && j < sandwiches.size()){
            if(students[i] == sandwiches[j]){
                students[i] = -1;
                i++;
                j++;
                count = 0;
                sold++;
            } else
                i++;
            count++;
            i = i % students.size();
        }
        return sandwiches.size() - sold;
    }
};