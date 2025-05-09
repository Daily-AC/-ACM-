#include <iostream>
#include <climits>
#include <queue>
using namespace std;

const int size = 100;  // 假设最大顶点数为100

struct ArcNode {
    int adjvex;
    struct ArcNode *next;
    int info;
};

struct VNode {
    int data;
    ArcNode *first;
};

struct ALGraph {
    VNode vertices[size];
    int vexnum, arcnum;
};

// 访问标记数组
bool visited[size];

// 1. 判断边是否存在
bool Adjacent(ALGraph &G, int x, int y) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        if (p->adjvex == y) return true;
        p = p->next;
    }
    return false;
}

// 2. 列出邻接边
void Neighbors(ALGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return;
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        cout << "边<" << G.vertices[x].data << "," 
             << G.vertices[p->adjvex].data << ">, 权值: " << p->info << endl;
        p = p->next;
    }
}

// 3. 插入顶点
bool InsertVertex(ALGraph &G, int x) {
    if (G.vexnum >= size) return false;
    G.vertices[G.vexnum].data = x;
    G.vertices[G.vexnum].first = nullptr;
    G.vexnum++;
    return true;
}

// 4. 删除顶点
bool DeleteVertex(ALGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return false;
    
    // 删除以x为起点的边
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        ArcNode *temp = p;
        p = p->next;
        delete temp;
        G.arcnum--;
    }
    G.vertices[x].first = nullptr;
    
    // 删除其他顶点中指向x的边
    for (int i = 0; i < G.vexnum; i++) {
        if (i == x) continue;
        
        ArcNode *pre = nullptr;
        ArcNode *curr = G.vertices[i].first;
        while (curr != nullptr) {
            if (curr->adjvex == x) {
                if (pre == nullptr) {
                    G.vertices[i].first = curr->next;
                } else {
                    pre->next = curr->next;
                }
                ArcNode *temp = curr;
                curr = curr->next;
                delete temp;
                G.arcnum--;
            } else {
                pre = curr;
                curr = curr->next;
            }
        }
    }
    
    // 将后面的顶点前移
    for (int i = x; i < G.vexnum - 1; i++) {
        G.vertices[i] = G.vertices[i + 1];
    }
    
    // 调整邻接表中大于x的顶点编号
    for (int i = 0; i < G.vexnum - 1; i++) {
        ArcNode *p = G.vertices[i].first;
        while (p != nullptr) {
            if (p->adjvex > x) {
                p->adjvex--;
            }
            p = p->next;
        }
    }
    
    G.vexnum--;
    return true;
}

// 5. 添加边
bool AddEdge(ALGraph &G, int x, int y, int weight = 1) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    
    // 检查边是否已存在
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        if (p->adjvex == y) return false;
        p = p->next;
    }
    
    // 添加x到y的边
    ArcNode *newNode = new ArcNode;
    newNode->adjvex = y;
    newNode->info = weight;
    newNode->next = G.vertices[x].first;
    G.vertices[x].first = newNode;
    
    // 添加y到x的边（无向图）
    newNode = new ArcNode;
    newNode->adjvex = x;
    newNode->info = weight;
    newNode->next = G.vertices[y].first;
    G.vertices[y].first = newNode;
    
    G.arcnum++;
    return true;
}

// 6. 第一个邻接点
int FirstNeighbor(ALGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return -1;
    if (G.vertices[x].first != nullptr) {
        return G.vertices[x].first->adjvex;
    }
    return -1;
}

// 7. 下一个邻接点
int NextNeighbor(ALGraph &G, int x, int y) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return -1;
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        if (p->adjvex == y) {
            if (p->next != nullptr) {
                return p->next->adjvex;
            }
            break;
        }
        p = p->next;
    }
    return -1;
}

// 8. 获取边权值
int Get_edge_value(ALGraph &G, int x, int y) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return INT_MIN;
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        if (p->adjvex == y) {
            return p->info;
        }
        p = p->next;
    }
    return INT_MIN;
}

// 9. 设置边权值
bool Set_edge_value(ALGraph &G, int x, int y, int v) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    
    bool found = false;
    
    // 设置x到y的边权值
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        if (p->adjvex == y) {
            p->info = v;
            found = true;
            break;
        }
        p = p->next;
    }
    
    // 设置y到x的边权值（无向图）
    p = G.vertices[y].first;
    while (p != nullptr) {
        if (p->adjvex == x) {
            p->info = v;
            return found;
        }
        p = p->next;
    }
    
    return found;
}

// 递归DFS辅助函数
void DFS(ALGraph &G, int v) {
    cout << G.vertices[v].data << " ";  // 访问顶点
    visited[v] = true;
    
    // 遍历所有邻接点
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

// DFS遍历
void DFSTraverse(ALGraph &G) {
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
void BFSTraverse(ALGraph &G) {
    cout << "BFS遍历结果: ";
    // 初始化访问标记
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    queue<int> Q;  // 辅助队列
    
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            cout << G.vertices[i].data << " ";  // 访问顶点
            visited[i] = true;
            Q.push(i);
            
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                
                // 遍历v的所有邻接点
                for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
                    if (!visited[w]) {
                        cout << G.vertices[w].data << " ";  // 访问顶点
                        visited[w] = true;
                        Q.push(w);
                    }
                }
            }
        }
    }
    cout << endl;
}

void testALGraph() {
    cout << "\n\n===== 邻接表测试 =====" << endl;
    ALGraph G;
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
    cout << "顶点A的第一个邻接点: " << G.vertices[FirstNeighbor(G, 0)].data << endl;
    cout << "顶点D的第一个邻接点: " << G.vertices[FirstNeighbor(G, 3)].data << endl;
    
    // 6. 下一个邻接点
    cout << "\n6. 下一个邻接点:" << endl;
    cout << "顶点A在B后的下一个邻接点: " << G.vertices[NextNeighbor(G, 0, 1)].data << endl;
    cout << "顶点A在C后的下一个邻接点: " << (NextNeighbor(G, 0, 2) == -1 ? "无" : string(1, G.vertices[NextNeighbor(G, 0, 2)].data)) << endl;
    
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
    for (int i = 0; i < G.vexnum; i++) cout << (char)G.vertices[i].data << " ";
    cout << endl;
    cout << "边(A,C)存在? " << (Adjacent(G, 0, 1) ? "是" : "否") << endl;  // 现在C的索引是1
    cout << "边(C,D)存在? " << (Adjacent(G, 1, 2) ? "是" : "否") << endl;
    
    // 9. 测试图遍历
    cout << "\n9. 测试图遍历:" << endl;
    DFSTraverse(G);
    BFSTraverse(G);
    
    cout << "\n===== 邻接表测试结束 =====" << endl;
}

int main() {
    testALGraph();
    return 0;
}
