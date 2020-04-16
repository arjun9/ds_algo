#include <iostream>
#include <math.h>

using namespace std;

class SortEstimate {
    public:
    double howMany(int c, int time) {
        double hi = 100000000, lo = 0.0, num = 0.0, est_time = 0.0;

        while((hi - lo) > 0.000000001) {
           num = (hi + lo)/2;
           est_time = c * num * (log2l(num));
           if(est_time == time)
                return num;
           else if(est_time > time)
                hi = num;
           else
                lo = num;
        }

        return num;
    }
};

int main() {
    SortEstimate estimate;
    cout << estimate.howMany(1, 2000000000);
    return 0;
}

