#include <raylib.h>

#include <stdio.h>
#include <math.h>

#include "array_list.h"
#include "linked_list.h"

typedef struct {
    ArrayListOf(LinkedListOf(int)) adj;
    ArrayListOf(Vector2) ps;
} Graph;

Graph init_graph(int n) {
    Graph graph;
    graph.ps  = al_init(n, Vector2);
    graph.adj = al_init(n, LinkedListOf(int));
    for (int i = 0; i < n; i++)
        *al_at(graph.adj, i) = ll_init(int);

    return graph;
}

void clear_graph() {
    // TODO
}

void circle_graph(const Graph g, float radius) {
    if (al_size(g.adj) == 0) return;
    ArrayListOf(Vector2) ps = g.ps;
    float slices = PI*2/al_size(g.adj);
    float degree = PI/2;

    for (int i = 0; i < al_size(ps); i++) {
        Vector2 *p = al_at(ps, i);
        p->x = cosf(degree)*(float)radius;
        p->y = sinf(degree)*(float)radius;
        degree+=slices;
    }
}

void DrawGraph(const Graph g) {
    if (al_size(g.adj) == 0) return;
    ArrayListOf(Vector2) ps = g.ps;

    for (int i = 0; i < al_size(g.adj); i++) {
        LinkedListOf(int) v = *al_at(g.adj, i);
        LinkedListIt(int) it = ll_head(v);
        for (; it != ll_end(v); it = ll_next(it)) {
            Vector2 *p1 = al_at(ps, i);
            Vector2 *p2 = al_at(ps, *ll_at(it));
            DrawLine(p1->x, p1->y, p2->x, p2->y, GREEN);
        }
    }

    int f_sz = 6;
    for (int i = 0; i < al_size(g.adj); i++) {
        Vector2 *p = al_at(ps, i);
        DrawCircle((int)p->x, (int)p->y, 10, RED);
        DrawCircleLines((int)p->x, (int)p->y, 10, BLACK);

        char buf[64];
        sprintf(buf, "%d", i);

        float f_wt = MeasureText(buf, f_sz);
        DrawText(buf, p->x-(f_wt/2), p->y-((f_sz/2)+1.f), f_sz, BLACK);
    }

}

int main(void) {
    const int WIDTH = 800, HEIGHT = 500;
    InitWindow(WIDTH, HEIGHT, "hello");

    SetTargetFPS(60);
    int n, m; scanf("%d %d", &n, &m);

    Graph graph = init_graph(n);

    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        ll_push_back(*al_at(graph.adj, a), b);
        ll_push_back(*al_at(graph.adj, b), a);
    }

    circle_graph(graph, n*n);

    // Drawing
    Camera2D cam = {0};
    cam.offset = (Vector2){GetRenderWidth()/2.0f, GetRenderHeight()/2.0f}; 
    cam.target.x = 0, cam.target.y = 0;
    cam.zoom = 1;
    while (!WindowShouldClose()) {
        cam.zoom = expf(logf(cam.zoom) + ((float)GetMouseWheelMove()*0.1f));
        BeginDrawing();
        BeginMode2D(cam);
        
        ClearBackground(RED);
        DrawGraph(graph);

        EndMode2D();
        EndDrawing();
    }
    return 0;
}
