#include <iostream>
#include <cstring>

// ״̬ѹ��DP
// �������
// �����AC����
// 

long long n = 0, m = 0, k = 0;
// dp[i][j][k]�������i�й�����j�����ӣ���i�е�״̬Ϊxʱ�ķ�����
long long dp[82][22][1 << 9];
long long ans;
// mark���ÿһ�е�״̬
long long mark[1 << 9], len;

long long num(long long x)
{
    long long sum = 0;
    while (x)
    {
        if (x & 1)
            ++sum;
        x >>= 1;
    }
    return sum;
}

bool judge(long long x)
{
    if (x & (x << 1))
        return false;
    return true;
}

int main()
{
    while (std::cin >> n >> m >> k)
    {
        ans = 0;
        memset(dp, 0, sizeof(dp));
        memset(mark, 0, sizeof(mark));
        len = 0;
        long long tepp = n > m ? n : m;
        m = n > m ? m : n; // mΪС����
        n = tepp;
        // ��ʼ����һ�еķ��÷�����
        // �޳�ĳһ���еĲ��Ϸ�����״̬
        for (long long i = 0; i < (1 << m); ++i)
        {
            // ��i״̬û�����ڵ����ӷ���һ��
            if (judge(i))
            {
                dp[1][num(i)][len] = 1; // ��һ��״̬Ϊiʱ������num(i)�����ӵķ�����
                mark[len++] = i; // ���״̬
            }
        }
        // ��2�е���n��
        for (long long i = 2; i <= n; ++i)
        {
            // ���ڷ�0..k������
            for (long long j = 0; j <= k; ++j)
            {
                // ö�ٵ�i��0..len - 1��״̬
                for (long long x = 0; x < len; ++x)
                {
                    // ö�ٵ�i - 1��0..len - 1��״̬ 
                    for (long long y = 0; y < len; ++y)
                    {
                        // ��i��״̬x��1�ĸ���
                        long long tmp = num(mark[x]);
                        // ����������û���ڵ�����
                        // �ҵ�ǰ��������Ŀ���ڴ��е�ǰ״̬���õ�������Ŀ
                        if ( ((mark[x] & mark[y]) == 0) && j >= tmp)
                            dp[i][j][x] += dp[i - 1][j - tmp][y]; // ʩ���������
                            // ����ǰ�й�����j�����ӣ���ǰ����tmp�����ӣ�״̬Ϊx��
                            // ����һ�й�����j - tmp�����ӣ�״̬Ϊy
                    }
                }
            }
        }
        // ö��״̬���
        for (long long i = 0; i < len; ++i)
            ans += dp[n][k][i];
        std::cout << ans << std::endl;
    }
    return 0;
}

