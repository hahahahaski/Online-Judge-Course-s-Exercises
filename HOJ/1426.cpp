#include <iostream>
#include <cstring>

// ...����̫����
// ��ɵ�Ƶ�һ��DFS
// ����20�������ڿ϶����Եõ����...
// ����AC��
// ���һ���Special Judge
// �����Ψһ...

int n = 0;
char ans[100];
int cnt = 0;

bool isValid(int len)
{
    int mod = 0;
    for (int i = len - 1; i >= 0; --i)
        mod = ((mod * 10) + ans[i] - '0') % n;
    if (mod == 0)
        return true;
    return false;
}

void DFS(int i)
{
    if (i > 20)
        return;
    if (cnt >= 1)
        return;
    ans[i] = '1';
    if (isValid(i + 1))
    {
        for (int j = i; j >= 0; --j)
            std::cout << ans[j];
        std::cout << std::endl;
        ++cnt;
        return;
    }
    ans[i] = '0';
    DFS(i + 1);
    ans[i] = '1';
    DFS(i + 1);
}

int main()
{
    for ( ; std::cin >> n && n != 0; )
    {
        memset(ans, '0', sizeof(ans));
        cnt = 0;
        DFS(0);
    }
    return 0;
}

