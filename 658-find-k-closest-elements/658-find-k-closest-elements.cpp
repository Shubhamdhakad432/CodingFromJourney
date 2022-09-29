class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        vector<pair<int,int>> v;
        vector<int>an;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({max(x,a[i])-min(x,a[i]),i});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>e,pair<int,int>f){
            if(e.first<f.first)
            {
                return true;
            }
            else if(e.first==f.first)
            {
                return e.second<f.second;
            }
            return false;
        });
        
        for(int i=0;i<k;i++)
        {
            an.push_back(a[v[i].second]);
        }
        sort(an.begin(),an.end());
        return an;
    }
};