
// ��ȫ��������

#include <iostream>
#include <vector>
#include <climits>

int main()
{
    int T = 0;
    std::cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        int E = 0, F = 0;
        std::cin >> E >> F;
        int N = 0;
        std::cin >> N;
        // m��ʾӲ��Ǯ����w��ʾӲ������
        std::vector<int> m, w;
        for (int j = 1; j <= N; ++j)
        {
            int tempM = 0, tempW = 0;
            std::cin >> tempM >> tempW;
            m.push_back(tempM);
            w.push_back(tempW);
        }
        if (E == F)
        {
            std::cout << "The minimum amount of money in the piggy-bank is 0." << std::endl;
            continue;
        }
        // dp[i][j]��ʾ��m[0..i]��Ӳ�Ҵճ�j����ʱ����СǮ��
        // dp[i][j] = INT_MAX��ʾ��m[0..i]��Ӳ���޷��ճ�j����
        // ��ʼ������Ҫ
        std::vector<std::vector<int> > dp(N, std::vector<int>(F - E + 1, INT_MAX));
        for (int j = 0; j * w[0] <= F - E; ++j)
            dp[0][j * w[0]] = j * m[0];
        // ����Ҫ��
        // dp[i][0]��ʾ��m[0..i]��Ӳ�Ҵճ�0��������СǮ������0
        for (int j = 1; j < N; ++j)
            dp[j][0] = 0;
        for (int j = 1; j < N; ++j)
        {
            for (int k = 1; k <= F - E; ++k)
            {
                int value = INT_MAX;
                for (int l = 0; l * w[j] <= k; ++l)
                {
                    if (dp[j - 1][k - l * w[j]] != INT_MAX && dp[j - 1][k - l * w[j]] + l * m[j] < value)
                        value = dp[j - 1][k - l * w[j]] + l * m[j];
                }
                dp[j][k] = value;
            }
        }
        if (dp[N - 1][F - E] == INT_MAX)
            std::cout << "This is impossible." << std::endl;
        else
            std::cout << "The minimum amount of money in the piggy-bank is " << dp[N - 1][F - E] << "." << std::endl;
    }
    return 0;
}

