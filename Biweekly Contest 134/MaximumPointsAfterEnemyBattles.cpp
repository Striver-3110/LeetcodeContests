class Solution {
public:
    // long long maximumPoints(vector<int>& ee, int ce) {
    //     sort(ee.begin(),ee.end());

    //     int n = ee.size();
    //     long long p = 0;
    //     int i, j = n-1;
    //     for(i = 0; i <= j;){
    //         // if current energy is sufficient then remove defeat the enemy with the smallest energy enemy
    //         // in order to maximize the points
    //         if(ce >= ee[i]){
    //             // if it is so, then calculate how many such enemies can be deafeted with current energy
    //             p += (ce / ee[i]);
    //             // what will be the remaining energy
    //             ce = ce % ee[i];
    //         }else if(p > 0){
    //             // if current energy is not sufficient then add the greater energy in order to maximize 
    //             // battle points
    //             ce += ee[j];
    //             // mark that enemy
    //             j--;
    //         }else break;
    //     }
    //     return p;
    // }
    long long maximumPoints(vector<int>& ee, int ce) {
        long long min = *min_element(ee.begin(), ee.end());
        if( ce < min) return 0;
        long long baseEnergy = ce - min;
        long long totalEnergy = accumulate(ee.begin(), ee.end(), baseEnergy);
        return totalEnergy / min;
    }
};