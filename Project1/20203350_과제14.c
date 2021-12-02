//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX_VERTICES 50
//typedef struct GraphType {
//	int n;  //정점의 개수
//	int adj_mat[MAX_VERTICES][MAX_VERTICES];
//}GraphType;
////그래프 초기화
//void init(GraphType* g)
//{
//	int r, c;
//	g->n = 0;
//	for (r = 0; r < MAX_VERTICES; r++)
//		for (c = 0; c < MAX_VERTICES; c++)
//			g->adj_mat[r][c] = 0;
//}
////정점 삽입 연산
//void insert_vertex(GraphType* g, int v)
//{
//	if (((g->n) + 1) > MAX_VERTICES) {
//		printf("number of point is %d\n", g->n);
//		fprintf(stderr, "그래프: 정점의 개수 초과");
//		return;
//	}
//	g->n++;
//}
////간선 삽입 연산
//void insert_edge(GraphType* g, int start, int end)
//{
//	if (start >= g->n || end >= g->n) {
//		fprintf(stderr, "그래프: 정점 번호 오류");
//		return;
//	}
//	g->adj_mat[start][end] = 1;
//	g->adj_mat[end][start] = 1;
//}
////인접 행렬 출력 함수 
//void print_adj_mat(GraphType* g)
//{
//	for (int i = 0; i < g->n; i++)
//	{
//		for (int j = 0; j < g->n; j++) {
//			printf("%2d", g->adj_mat[i][j]);
//		}
//		printf("\n");
//	}
//}
///*
//void read_graph_mat00(GraphType* g, char* name)
//{
//	int r, c;
//	errno_t err;
//	err = fopen_s(&name, "graph.txt", "rt");
//	if (NULL != name)
//	{
//		fscanf_s(name, "%d", &(*g).n);
//		for (r = 0; r < MAX_VERTICES; r++)
//			for (c = 0; c < MAX_VERTICES; c++)
//				fscanf_s(name, "%d", &g->adj_mat[r][c]);
//
//	}
//}
//*/
//void read_graph_mat(GraphType* g, char* filename)
//{
//	int i, j, val;
//	FILE* fp;
//	errno_t err;
//	err = fopen_s(&fp,filename, "r");
//	if (fp != NULL) {
//		init(g);
//		fscanf_s(fp, "%d", &g->n);
//		for (i = 0; i < g->n; i++) {
//			for (j = 0; j < g->n; j++) {
//				fscanf_s(fp, "%d", &val);
//				if (val != 0)
//					insert_edge(g, i, j);
//			}
//		}
//		fclose(fp);
//	}
//}
//void write_graph_mat(GraphType* g, char* filename)
//{
//	int i, j;
//	FILE* fp;
//	errno_t err;
//	err = fopen_s(&fp, filename, "w");
//	if (fp != NULL) {
//		fprintf(fp, "%d\n", g->n);
//		for (i = 0; i < g->n; i++) {
//			for (j = 0; j < g->n; j++) {
//				fprintf(fp, "%d ", g->adj_mat[i][j]);
//			}
//			fprintf(fp, "%c", '\n');
//		}
//		fclose(fp);
//	}
//}
//
//void main()
//{
//	GraphType* g;
//	g = (GraphType*)malloc(sizeof(GraphType));
//	init(g);
//	//FILE* fp1 = fopen_s(&fp1, "graph01.txt", "rt");
//	//FILE* fp2 = fopen_s(&fp2, "graph02.txt", "wt");
//	read_graph_mat(g, "graph01.txt");
//
//	print_adj_mat(g);
//	write_graph_mat(g, "graph02.txt");
//
//	//fclose(fp1);
//	//fclose(fp2);
//	free(g);
//}