#include <bits/stdc++.h>
using namespace std;

const int size = 100;  // 假设最大顶点数为100

struct MGraph {
    char vex[size];
    int edge[size][size];
    int vexnum, arcnum;
};

// 访问标记数组
bool visited[size];

// 1. 判断边是否存在
bool Adjacent(MGraph &G, int x, int y) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    return G.edge[x][y] != 0;
}

// 2. 列出邻接边
void Neighbors(MGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return;
    for (int y = 0; y < G.vexnum; y++) {
        if (G.edge[x][y] != 0) {
            cout << "边<" << G.vex[x] << "," << G.vex[y] << ">, 权值: " << G.edge[x][y] << endl;
        }
    }
}

// 3. 插入顶点
bool InsertVertex(MGraph &G, char x) {
    if (G.vexnum >= size) return false;
    G.vex[G.vexnum] = x;
    // 初始化新顶点的边
    for (int i = 0; i <= G.vexnum; i++) {
        G.edge[G.vexnum][i] = 0;
        G.edge[i][G.vexnum] = 0;
    }
    G.vexnum++;
    return true;
}

// 4. 删除顶点
bool DeleteVertex(MGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return false;
    
    // 删除顶点x相关的边，并统计删除的边数
    int deletedEdges = 0;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.edge[x][i] != 0) deletedEdges++;
        if (G.edge[i][x] != 0) deletedEdges++;
    }
    // 无向图每条边被统计了两次，需要调整
    if (deletedEdges > 0) G.arcnum -= deletedEdges / 2;
    
    // 将后面的顶点前移
    for (int i = x; i < G.vexnum - 1; i++) {
        G.vex[i] = G.vex[i + 1];
    }
    
    // 移动边矩阵
    for (int i = x; i < G.vexnum - 1; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.edge[i][j] = G.edge[i + 1][j];
        }
    }
    for (int j = x; j < G.vexnum - 1; j++) {
        for (int i = 0; i < G.vexnum; i++) {
            G.edge[i][j] = G.edge[i][j + 1];
        }
    }
    
    G.vexnum--;
    return true;
}

// 5. 添加边
bool AddEdge(MGraph &G, int x, int y, int weight = 1) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    if (G.edge[x][y] == 0) {
        G.edge[x][y] = weight;
        G.edge[y][x] = weight;  // 无向图
        G.arcnum++;
        return true;
    }
    return false;
}

// 6. 第一个邻接点
int FirstNeighbor(MGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return -1;
    for (int y = 0; y < G.vexnum; y++) {
        if (G.edge[x][y] != 0) {
            return y;
        }
    }
    return -1;
}

// 7. 下一个邻接点
int NextNeighbor(MGraph &G, int x, int y) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return -1;
    for (int z = y + 1; z < G.vexnum; z++) {
        if (G.edge[x][z] != 0) {
            return z;
        }
    }
    return -1;
}

// 8. 获取边权值
int Get_edge_value(MGraph &G, int x, int y) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return INT_MIN;
    return G.edge[x][y];
}

// 9. 设置边权值
bool Set_edge_value(MGraph &G, int x, int y, int v) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    G.edge[x][y] = v;
    G.edge[y][x] = v;  // 无向图
    return true;
}

// 递归DFS辅助函数
void DFS(MGraph &G, int v) {
    cout << G.vex[v] << " ";  // 访问顶点
    visited[v] = true;
    
    // 遍历所有邻接点
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

// DFS遍历
void DFSTraverse(MGraph &G) {
    cout << "DFS遍历结果: ";
    // 初始化访问标记
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    // 对每个未访问顶点调用DFS
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
    cout << endl;
}

// BFS遍历
void BFSTraverse(MGraph &G) {
    cout << "BFS遍历结果: ";
    // 初始化访问标记
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    queue<int> Q;  // 辅助队列
    
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            cout << G.vex[i] << " ";  // 访问顶点
            visited[i] = true;
            Q.push(i);
            
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                
                // 遍历v的所有邻接点
                for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
                    if (!visited[w]) {
                        cout << G.vex[w] << " ";  // 访问顶点
                        visited[w] = true;
                        Q.push(w);
                    }
                }
            }
        }
    }
    cout << endl;
}

void testMGraph() {
    cout << "===== 邻接矩阵测试 =====" << endl;
    MGraph G;
    G.vexnum = 0;
    G.arcnum = 0;
    
    // 1. 插入顶点
    cout << "\n1. 插入顶点A,B,C,D:" << endl;
    InsertVertex(G, 'A');  // 0
    InsertVertex(G, 'B');  // 1
    InsertVertex(G, 'C');  // 2
    InsertVertex(G, 'D');  // 3
    cout << "顶点数: " << G.vexnum << endl;
    
    // 2. 添加边
    cout << "\n2. 添加边(A,B),(A,C),(B,C),(C,D):" << endl;
    AddEdge(G, 0, 1, 10);  // A-B 权值10
    AddEdge(G, 0, 2, 20);  // A-C 权值20
    AddEdge(G, 1, 2, 30);  // B-C 权值30
    AddEdge(G, 2, 3, 40);  // C-D 权值40
    cout << "边数: " << G.arcnum << endl;
    
    // 3. 判断边是否存在
    cout << "\n3. 判断边是否存在:" << endl;
    cout << "边(A,B)存在? " << (Adjacent(G, 0, 1) ? "是" : "否") << endl;
    cout << "边(A,D)存在? " << (Adjacent(G, 0, 3) ? "是" : "否") << endl;
    
    // 4. 列出邻接边
    cout << "\n4. 列出顶点A的邻接边:" << endl;
    Neighbors(G, 0);
    
    // 5. 第一个邻接点
    cout << "\n5. 第一个邻接点:" << endl;
    cout << "顶点A的第一个邻接点: " << G.vex[FirstNeighbor(G, 0)] << endl;
    cout << "顶点D的第一个邻接点: " << G.vex[FirstNeighbor(G, 3)] << endl;
    
    // 6. 下一个邻接点
    cout << "\n6. 下一个邻接点:" << endl;
    cout << "顶点A在B后的下一个邻接点: " << G.vex[NextNeighbor(G, 0, 1)] << endl;
    cout << "顶点A在C后的下一个邻接点: " << (NextNeighbor(G, 0, 2) == -1 ? "无" : to_string(NextNeighbor(G, 0, 2))) << endl;
    
    // 7. 获取和设置边权值
    cout << "\n7. 边权值操作:" << endl;
    cout << "边(A,B)的权值: " << Get_edge_value(G, 0, 1) << endl;
    cout << "设置边(A,B)权值为50..." << endl;
    Set_edge_value(G, 0, 1, 50);
    cout << "边(A,B)的新权值: " << Get_edge_value(G, 0, 1) << endl;
    
    // 8. 删除顶点
    cout << "\n8. 删除顶点B:" << endl;
    DeleteVertex(G, 1);
    cout << "顶点数: " << G.vexnum << ", 边数: " << G.arcnum << endl;
    cout << "当前顶点: ";
    for (int i = 0; i < G.vexnum; i++) cout << G.vex[i] << " ";
    cout << endl;
    cout << "边(A,C)存在? " << (Adjacent(G, 0, 1) ? "是" : "否") << endl;  // 现在C的索引是1
    cout << "边(C,D)存在? " << (Adjacent(G, 1, 2) ? "是" : "否") << endl;
    
    // 9. 测试图遍历
    cout << "\n9. 测试图遍历:" << endl;
    DFSTraverse(G);
    BFSTraverse(G);
    
    cout << "\n===== 邻接矩阵测试结束 =====" << endl;
}

int main() {
    testMGraph();
    return 0;
}
