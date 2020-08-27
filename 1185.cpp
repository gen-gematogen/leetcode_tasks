class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        
        int pos = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5) +
        (365 * (year + 4800 - ((14 - month) / 12))) +
        ((year + 4800 - ((14 - month) / 12)) / 4) - 
        ((year + 4800 - ((14 - month) / 12)) / 100) + 
        ((year + 4800 - ((14 - month) / 12)) / 400)  - 32045) % 7;
        
        return days[pos];
    }
};
