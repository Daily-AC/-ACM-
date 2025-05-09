#include <bits/stdc++.h>
using namespace std;

const int size = 100;  // ������󶥵���Ϊ100

struct MGraph {
    char vex[size];
    int edge[size][size];
    int vexnum, arcnum;
};

// ���ʱ������
bool visited[size];

// 1. �жϱ��Ƿ����
bool Adjacent(MGraph &G, int x, int y) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    return G.edge[x][y] != 0;
}

// 2. �г��ڽӱ�
void Neighbors(MGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return;
    for (int y = 0; y < G.vexnum; y++) {
        if (G.edge[x][y] != 0) {
            cout << "��<" << G.vex[x] << "," << G.vex[y] << ">, Ȩֵ: " << G.edge[x][y] << endl;
        }
    }
}

// 3. ���붥��
bool InsertVertex(MGraph &G, char x) {
    if (G.vexnum >= size) return false;
    G.vex[G.vexnum] = x;
    // ��ʼ���¶���ı�
    for (int i = 0; i <= G.vexnum; i++) {
        G.edge[G.vexnum][i] = 0;
        G.edge[i][G.vexnum] = 0;
    }
    G.vexnum++;
    return true;
}

// 4. ɾ������
bool DeleteVertex(MGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return false;
    
    // ɾ������x��صıߣ���ͳ��ɾ���ı���
    int deletedEdges = 0;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.edge[x][i] != 0) deletedEdges++;
        if (G.edge[i][x] != 0) deletedEdges++;
    }
    // ����ͼÿ���߱�ͳ�������Σ���Ҫ����
    if (deletedEdges > 0) G.arcnum -= deletedEdges / 2;
    
    // ������Ķ���ǰ��
    for (int i = x; i < G.vexnum - 1; i++) {
        G.vex[i] = G.vex[i + 1];
    }
    
    // �ƶ��߾���
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

// 5. ��ӱ�
bool AddEdge(MGraph &G, int x, int y, int weight = 1) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    if (G.edge[x][y] == 0) {
        G.edge[x][y] = weight;
        G.edge[y][x] = weight;  // ����ͼ
        G.arcnum++;
        return true;
    }
    return false;
}

// 6. ��һ���ڽӵ�
int FirstNeighbor(MGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return -1;
    for (int y = 0; y < G.vexnum; y++) {
        if (G.edge[x][y] != 0) {
            return y;
        }
    }
    return -1;
}

// 7. ��һ���ڽӵ�
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

// 8. ��ȡ��Ȩֵ
int Get_edge_value(MGraph &G, int x, int y) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return INT_MIN;
    return G.edge[x][y];
}

// 9. ���ñ�Ȩֵ
bool Set_edge_value(MGraph &G, int x, int y, int v) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    G.edge[x][y] = v;
    G.edge[y][x] = v;  // ����ͼ
    return true;
}

// �ݹ�DFS��������
void DFS(MGraph &G, int v) {
    cout << G.vex[v] << " ";  // ���ʶ���
    visited[v] = true;
    
    // ���������ڽӵ�
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

// DFS����
void DFSTraverse(MGraph &G) {
    cout << "DFS�������: ";
    // ��ʼ�����ʱ��
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    // ��ÿ��δ���ʶ������DFS
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i);
        }
    }
    cout << endl;
}

// BFS����
void BFSTraverse(MGraph &G) {
    cout << "BFS�������: ";
    // ��ʼ�����ʱ��
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    queue<int> Q;  // ��������
    
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            cout << G.vex[i] << " ";  // ���ʶ���
            visited[i] = true;
            Q.push(i);
            
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                
                // ����v�������ڽӵ�
                for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
                    if (!visited[w]) {
                        cout << G.vex[w] << " ";  // ���ʶ���
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
    cout << "===== �ڽӾ������ =====" << endl;
    MGraph G;
    G.vexnum = 0;
    G.arcnum = 0;
    
    // 1. ���붥��
    cout << "\n1. ���붥��A,B,C,D:" << endl;
    InsertVertex(G, 'A');  // 0
    InsertVertex(G, 'B');  // 1
    InsertVertex(G, 'C');  // 2
    InsertVertex(G, 'D');  // 3
    cout << "������: " << G.vexnum << endl;
    
    // 2. ��ӱ�
    cout << "\n2. ��ӱ�(A,B),(A,C),(B,C),(C,D):" << endl;
    AddEdge(G, 0, 1, 10);  // A-B Ȩֵ10
    AddEdge(G, 0, 2, 20);  // A-C Ȩֵ20
    AddEdge(G, 1, 2, 30);  // B-C Ȩֵ30
    AddEdge(G, 2, 3, 40);  // C-D Ȩֵ40
    cout << "����: " << G.arcnum << endl;
    
    // 3. �жϱ��Ƿ����
    cout << "\n3. �жϱ��Ƿ����:" << endl;
    cout << "��(A,B)����? " << (Adjacent(G, 0, 1) ? "��" : "��") << endl;
    cout << "��(A,D)����? " << (Adjacent(G, 0, 3) ? "��" : "��") << endl;
    
    // 4. �г��ڽӱ�
    cout << "\n4. �г�����A���ڽӱ�:" << endl;
    Neighbors(G, 0);
    
    // 5. ��һ���ڽӵ�
    cout << "\n5. ��һ���ڽӵ�:" << endl;
    cout << "����A�ĵ�һ���ڽӵ�: " << G.vex[FirstNeighbor(G, 0)] << endl;
    cout << "����D�ĵ�һ���ڽӵ�: " << G.vex[FirstNeighbor(G, 3)] << endl;
    
    // 6. ��һ���ڽӵ�
    cout << "\n6. ��һ���ڽӵ�:" << endl;
    cout << "����A��B�����һ���ڽӵ�: " << G.vex[NextNeighbor(G, 0, 1)] << endl;
    cout << "����A��C�����һ���ڽӵ�: " << (NextNeighbor(G, 0, 2) == -1 ? "��" : to_string(NextNeighbor(G, 0, 2))) << endl;
    
    // 7. ��ȡ�����ñ�Ȩֵ
    cout << "\n7. ��Ȩֵ����:" << endl;
    cout << "��(A,B)��Ȩֵ: " << Get_edge_value(G, 0, 1) << endl;
    cout << "���ñ�(A,B)ȨֵΪ50..." << endl;
    Set_edge_value(G, 0, 1, 50);
    cout << "��(A,B)����Ȩֵ: " << Get_edge_value(G, 0, 1) << endl;
    
    // 8. ɾ������
    cout << "\n8. ɾ������B:" << endl;
    DeleteVertex(G, 1);
    cout << "������: " << G.vexnum << ", ����: " << G.arcnum << endl;
    cout << "��ǰ����: ";
    for (int i = 0; i < G.vexnum; i++) cout << G.vex[i] << " ";
    cout << endl;
    cout << "��(A,C)����? " << (Adjacent(G, 0, 1) ? "��" : "��") << endl;  // ����C��������1
    cout << "��(C,D)����? " << (Adjacent(G, 1, 2) ? "��" : "��") << endl;
    
    // 9. ����ͼ����
    cout << "\n9. ����ͼ����:" << endl;
    DFSTraverse(G);
    BFSTraverse(G);
    
    cout << "\n===== �ڽӾ�����Խ��� =====" << endl;
}

int main() {
    testMGraph();
    return 0;
}
