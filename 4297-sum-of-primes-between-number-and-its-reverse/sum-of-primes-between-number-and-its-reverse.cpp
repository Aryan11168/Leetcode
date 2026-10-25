constexpr int N=1001;
bitset<N> sieve=0;
int prefix[N]={0};
void Sieve_PrefixSum(){
    if (sieve[0]==1) return; // Proceed once
    sieve[0]=sieve[1]=1;
    const int Nsqrt=sqrt(N-1);
    for(int p=2; p<=Nsqrt; p+=1+(p>2)){
        if (sieve[p]==0)
            for(int j=p*p; j<N; j+=p) sieve[j]=1;
    }
    for(int i=2; i<N; i++){
        prefix[i]=prefix[i-1];
        prefix[i]+=(sieve[i]?0:i);
    }
}
class Solution {
public:
    static int rev(int x){
        int ans=0;
        for(; x; x/=10)
            ans=10*ans+(x%10);
        return ans;
    }
    static int sumOfPrimesInRange(int n) {
        Sieve_PrefixSum();
        auto [xMin, xMax]=minmax(n, rev(n));
        return prefix[xMax]-prefix[xMin-1];
    }
};