class Solution {
public:
    // int numberOfSubmatrices(vector<vector<char>>& grid) {
    //     vector<vector<pair<int,int>>> freq(grid.size(),vector<pair<int,int>>(grid[0].size(),{0,0})); // (fx,fy)
        
    //     // traverse on the first row in order to initialize the freq matrix
    //     for(int i = 0; i < grid[0].size(); i++){
    //         if(grid[0][i] == 'X'){
    //             freq[0][i] = {1,0};
    //         }else if(grid[0][i] == 'Y'){
    //             freq[0][i] = {0,1};
    //         }
    //     }
    //     int n = grid.size();// number of rows
    //     int m = grid[0].size(); // number of columns

    //     for(int i = 0; i < m; i++){ // columns
    //         for(int j = 1; j < n; j++){ // rows
    //             if(grid[j][i] == 'X'){
    //                 freq[j][i].first = freq[j-1][i].first + 1;
    //                 freq[j][i].second = freq[j-1][i].second;
    //             }
    //             else if(grid[j][i] == 'Y'){
    //                 freq[j][i].second = freq[j-1][i].second + 1;
    //                 freq[j][i].first = freq[j-1][i].first;
    //             }else{
    //                 freq[j][i] = freq[j-1][i];
    //             }
    //         }
    //     }
    //     int cnt = 0;
    //     for(int i = 0; i < n; i++){
    //         for(int j = 1; j < m; j++){
    //             freq[i][j].first += freq[i][j-1].first;
    //             freq[i][j].second += freq[i][j-1].second;
    //         }
    //     }

        
    //     for(int i = 0; i < n; i++){
    //         for(int j = 0; j < m; j++){
    //             // cout<<freq[i][j].first<<","<<freq[i][j].second <<" ";
    //             if(freq[i][j].second != 0 && freq[i][j].second == freq[i][j].first){
    //                 cnt++;
    //             }
    //         }
    //         cout<<endl;
    //     }
    //     return cnt;

    // }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> colFreq(m,{0,0});
        
        // cumulative frequency of x = a, y = b matrix at [i,j]
        int a,b;
        a = b = 0;
        int subMetCnt = 0;

        // initialization and submatrix count in first row
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 'X'){
                colFreq[j].first++;
            }else if(grid[0][j] == 'Y'){
                colFreq[j].second++;
            }
            a += colFreq[j].first; // cumulative freq of x
            b += colFreq[j].second; // cumulative freq of y
            
            if(a > 0 && a == b)subMetCnt++;
        }

        for(int i = 1; i < n; i++){
            a = 0;
            b = 0;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X'){
                    colFreq[j].first++;
                }else if(grid[i][j] == 'Y'){
                    colFreq[j].second++;
                }
                a += colFreq[j].first; // cumulative freq of x
                b += colFreq[j].second; // cumulative freq of y
                
                if(a > 0 && a == b)subMetCnt++;
            }
        }
        return subMetCnt;
    }
};