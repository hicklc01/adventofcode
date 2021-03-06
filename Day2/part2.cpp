#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    int total = accumulate(
        istream_iterator<string>(cin),
        istream_iterator<string>(),
        0,
        [&](int x, string y) {  
            stringstream ss(y);
            vector<int> sides;
            while(ss.good())
            {
                string raw;
                getline( ss, raw,'x');
                sides.push_back(stoi(raw));
            }
            sort(sides.begin(),sides.end());
            return x + 2*(sides[0]+sides[1]) + sides[0]*sides[1]*sides[2]; 
        }
    );
    cout<<total<<endl;
    return 0;
}
