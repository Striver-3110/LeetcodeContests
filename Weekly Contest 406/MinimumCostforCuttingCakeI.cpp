class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int hCuts = 1;
        int vCuts = 1;
        int total_cost = 0;
        int i = m-2;
        int j = n-2;
        while(i >= 0 && j >= 0){
            if(hc[i] > vc[j]){
                total_cost += hc[i] * vCuts;
                hCuts++;
                i--;
            }else{
                total_cost += vc[j] * hCuts;
                vCuts++;
                j--;
            }
        }
        while(i >= 0){
            total_cost += hc[i] * vCuts;
            i--;
        }
        while(j >= 0){
            total_cost += vc[j] * hCuts;
            j--;
        }
        return total_cost;
    }
};