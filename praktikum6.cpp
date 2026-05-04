#include "raylib.h"
#include <vector>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

struct Node {
    int id;
    Vector2 pos;
    Color color;
};

vector<Node> nodes = {
    {0, {400, 100}, GOLD},   
    {1, {200, 250}, LIGHTGRAY}, 
    {2, {600, 400}, LIGHTGRAY}, 
    {3, {400, 250}, LIGHTGRAY}, 
    {4, {600, 250}, LIGHTGRAY}, 
    {5, {400, 400}, LIGHTGRAY}  
};

vector<int> adj[6] = {
    {1, 3, 4}, 
    {4},       
    {5},       
    {4},       
    {5, 2},    
    {}         
};

void ResetNodes() {
    for (int i = 0; i < 6; i++) nodes[i].color = LIGHTGRAY;
    nodes[0].color = GOLD;
}

int main() {
    InitWindow(800, 600, "Praktikum 6 - Visualisasi BFS/DFS Zahra");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_B)) {
            ResetNodes();
            queue<int> q;
            q.push(0);
            while(!q.empty()){
                int n = q.front(); q.pop();
                nodes[n].color = SKYBLUE; // Warna penanda BFS
                for(int neighbor : adj[n]) q.push(neighbor);
            }
        }

        if (IsKeyPressed(KEY_D)) {
            ResetNodes();

            stack<int> s;
            s.push(0);
            while(!s.empty()){
                int n = s.top(); s.pop();
                nodes[n].color = LIME; // Warna penanda DFS
                for(int neighbor : adj[n]) s.push(neighbor);
            }
        }

        if (IsKeyPressed(KEY_R)) ResetNodes();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Tekan: [B] BFS | [D] DFS | [R] Reset", 20, 20, 20, DARKGRAY);

        // 1. Gambar Garis (Sisi/Edges)
        for (int i = 0; i < 6; i++) {
            for (int neighbor : adj[i]) {
                DrawLineEx(nodes[i].pos, nodes[neighbor].pos, 3, GRAY);
            }
        }

        // 2. Gambar Lingkaran (Simpul/Nodes)
        for (int i = 0; i < 6; i++) {
            DrawCircleV(nodes[i].pos, 30, nodes[i].color);
            DrawCircleLines(nodes[i].pos.x, nodes[i].pos.y, 30, BLACK);
            DrawText(TextFormat("%d", nodes[i].id), nodes[i].pos.x - 7, nodes[i].pos.y - 10, 25, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}