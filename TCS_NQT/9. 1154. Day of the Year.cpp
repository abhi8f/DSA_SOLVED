class Solution {
public:
    int dayOfYear(string date) {
        stringstream ss(date);
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));

        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int totalDays = day;
        for(int i = 1; i < month; i++) {
            totalDays += daysInMonth[i];
        }

        if (month > 2) {
            if ((year%400==0) || ((year%100!=0)&&(year%4==0))){
                totalDays++;
            }
        }

        return totalDays;
    }
};
