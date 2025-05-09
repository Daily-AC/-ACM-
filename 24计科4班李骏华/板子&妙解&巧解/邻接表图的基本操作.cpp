#include <iostream>
#include <climits>
#include <queue>
using namespace std;

const int size = 100;  // ������󶥵���Ϊ100

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

// ���ʱ������
bool visited[size];

// 1. �жϱ��Ƿ����
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

// 2. �г��ڽӱ�
void Neighbors(ALGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return;
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        cout << "��<" << G.vertices[x].data << "," 
             << G.vertices[p->adjvex].data << ">, Ȩֵ: " << p->info << endl;
        p = p->next;
    }
}

// 3. ���붥��
bool InsertVertex(ALGraph &G, int x) {
    if (G.vexnum >= size) return false;
    G.vertices[G.vexnum].data = x;
    G.vertices[G.vexnum].first = nullptr;
    G.vexnum++;
    return true;
}

// 4. ɾ������
bool DeleteVertex(ALGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return false;
    
    // ɾ����xΪ���ı�
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        ArcNode *temp = p;
        p = p->next;
        delete temp;
        G.arcnum--;
    }
    G.vertices[x].first = nullptr;
    
    // ɾ������������ָ��x�ı�
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
    
    // ������Ķ���ǰ��
    for (int i = x; i < G.vexnum - 1; i++) {
        G.vertices[i] = G.vertices[i + 1];
    }
    
    // �����ڽӱ��д���x�Ķ�����
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

// 5. ��ӱ�
bool AddEdge(ALGraph &G, int x, int y, int weight = 1) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    
    // �����Ƿ��Ѵ���
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        if (p->adjvex == y) return false;
        p = p->next;
    }
    
    // ���x��y�ı�
    ArcNode *newNode = new ArcNode;
    newNode->adjvex = y;
    newNode->info = weight;
    newNode->next = G.vertices[x].first;
    G.vertices[x].first = newNode;
    
    // ���y��x�ıߣ�����ͼ��
    newNode = new ArcNode;
    newNode->adjvex = x;
    newNode->info = weight;
    newNode->next = G.vertices[y].first;
    G.vertices[y].first = newNode;
    
    G.arcnum++;
    return true;
}

// 6. ��һ���ڽӵ�
int FirstNeighbor(ALGraph &G, int x) {
    if (x < 0 || x >= G.vexnum) return -1;
    if (G.vertices[x].first != nullptr) {
        return G.vertices[x].first->adjvex;
    }
    return -1;
}

// 7. ��һ���ڽӵ�
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

// 8. ��ȡ��Ȩֵ
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

// 9. ���ñ�Ȩֵ
bool Set_edge_value(ALGraph &G, int x, int y, int v) {
    if (x < 0 || x >= G.vexnum || y < 0 || y >= G.vexnum)
        return false;
    
    bool found = false;
    
    // ����x��y�ı�Ȩֵ
    ArcNode *p = G.vertices[x].first;
    while (p != nullptr) {
        if (p->adjvex == y) {
            p->info = v;
            found = true;
            break;
        }
        p = p->next;
    }
    
    // ����y��x�ı�Ȩֵ������ͼ��
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

// �ݹ�DFS��������
void DFS(ALGraph &G, int v) {
    cout << G.vertices[v].data << " ";  // ���ʶ���
    visited[v] = true;
    
    // ���������ڽӵ�
    for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
        if (!visited[w]) {
            DFS(G, w);
        }
    }
}

// DFS����
void DFSTraverse(ALGraph &G) {
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
void BFSTraverse(ALGraph &G) {
    cout << "BFS�������: ";
    // ��ʼ�����ʱ��
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    queue<int> Q;  // ��������
    
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            cout << G.vertices[i].data << " ";  // ���ʶ���
            visited[i] = true;
            Q.push(i);
            
            while (!Q.empty()) {
                int v = Q.front();
                Q.pop();
                
                // ����v�������ڽӵ�
                for (int w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor(G, v, w)) {
                    if (!visited[w]) {
                        cout << G.vertices[w].data << " ";  // ���ʶ���
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
    cout << "\n\n===== �ڽӱ���� =====" << endl;
    ALGraph G;
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
    cout << "����A�ĵ�һ���ڽӵ�: " << G.vertices[FirstNeighbor(G, 0)].data << endl;
    cout << "����D�ĵ�һ���ڽӵ�: " << G.vertices[FirstNeighbor(G, 3)].data << endl;
    
    // 6. ��һ���ڽӵ�
    cout << "\n6. ��һ���ڽӵ�:" << endl;
    cout << "����A��B�����һ���ڽӵ�: " << G.vertices[NextNeighbor(G, 0, 1)].data << endl;
    cout << "����A��C�����һ���ڽӵ�: " << (NextNeighbor(G, 0, 2) == -1 ? "��" : string(1, G.vertices[NextNeighbor(G, 0, 2)].data)) << endl;
    
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
    for (int i = 0; i < G.vexnum; i++) cout << (char)G.vertices[i].data << " ";
    cout << endl;
    cout << "��(A,C)����? " << (Adjacent(G, 0, 1) ? "��" : "��") << endl;  // ����C��������1
    cout << "��(C,D)����? " << (Adjacent(G, 1, 2) ? "��" : "��") << endl;
    
    // 9. ����ͼ����
    cout << "\n9. ����ͼ����:" << endl;
    DFSTraverse(G);
    BFSTraverse(G);
    
    cout << "\n===== �ڽӱ���Խ��� =====" << endl;
}

int main() {
    testALGraph();
    return 0;
}
