#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int bfs(int N,int M,vector<string>vec)
{
    typedef pair<int, int> P;
    int INF = 100000000;
    queue<P> que;
    vector<vector<int>> d(N, vector<int>(M, INF));  //到各个位置的最短距离的数组
    int sx, sy;  //起点坐标
    int gx, gy;  //终点坐标
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        if (vec[i][j] == 'S') {
            sx = i;
            sy = j;
        } else if (vec[i][j] == 'G') {
            gx = i;
            gy = j;
        }
    }
}
    
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while(que.size())
    {
        P p = que.front();
        que.pop();
        if(p.first == gx &&p.second==gy)
            break;
        int nx, ny;
        for (int i = 0; i < 4;i++)
        {
            nx = p.first + dx[i];
            ny = p.second + dy[i];
        }
        if (0 <= nx && nx<N && 0<=ny && ny<M && vec[nx][ny]!='#' && d[nx][ny]==INF)
        {
            que.push(P(nx, ny));
            d[nx][ny] = d[p.first][p.second] + 1;
        }
    }
    return d[gx][gy];
}
int main()
{

    int N, M;
    cin >> N >> M;
    string str;
    vector<string> vec;
    cin.ignore();
    for (int i = 0; i < N;i++)
    {
        getline(cin, str);
        vec.push_back(str);
    }
    cout<<bfs(N, M, vec);

    cout << endl;
    system("pause");
    return 0;
}