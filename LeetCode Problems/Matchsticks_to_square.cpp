class Solution {
public:
    static bool compare(int a,int b)
    {
        return a>b;
    }
    bool sumToTarget(vector<int>& matchsticks,int sides[],int i)
    {
        if(i==matchsticks.size())
        {
            if(sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0)
            {
                return true;
            }
            return false;
        }
        for(int j=0;j<4;j++)
        {
            if(matchsticks[i]>sides[j])
            {
                continue;
            }
            sides[j]-=matchsticks[i];
            if(sumToTarget(matchsticks,sides,i+1))
                return true;
            sides[j]+=matchsticks[i];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        
        int n=matchsticks.size();
        sort(matchsticks.begin(),matchsticks.end(),compare);
        int sum=0;
        if(n<4)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            sum+=matchsticks[i];
        }
        if((sum%4)!=0)
        {
            return false;
        }
        int sides[4];
        for(int i=0;i<4;i++)
        {
            sides[i]=sum/4;
        }
        return sumToTarget(matchsticks,sides,0);
    }
};