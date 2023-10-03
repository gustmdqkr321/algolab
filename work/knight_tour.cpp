#include <iostream>
#include <math.h>
using namespace std;

typedef struct Point{
    int x, y;
}point;

point direction[8] = {
    {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}
};
bool board[9][9];
int path[9][9];
int knight_tour(int row, int col, point p, int count)
{
    point next;
    if(count == row*col) // count는 옮긴 횟수고 모든 칸을 방문하면 성공이자 끝 모든 칸의 갯수 = row x col
    {
        return 1;
    }
    for(int i=0; i<8; i++) // 각 칸을 움직일때 마다 8개의 방향으로 재귀호출 해야함
    {
        next.x = p.x + direction[i].x; // i번쨰 움직임을 갱신
        next.y = p.y + direction[i].y; // 총 8번
        if(next.x >0 && next.x <= col && next.y >0 && next.y <= row && board[next.y][next.x] != false)
        { // 다음 위치가 체스판 안에 들어가게 하기 위해 0보단 크고 row col보단 작게 최대 크기를 9로해서 0은 뺴야함
            board[next.y][next.x] = false; // 옮긴위치 마킹
            path[next.y][next.x] = count + 1; // 카운트 +1해서 루트에 저장 카운트는 몇번쨰 방문하는지 나타내는 변수임
            if(knight_tour(row,col,next,count+1))
            { // 재귀로 계속 8개씩 호출해서 성공하면 반환
                return 1;
            }
            board[next.y][next.x] = true; // 실패한 루트는 이동했던 루트 초기화
            // path는 초기화 안해도 성공한 루트에서 덮어씌우기 때문에 괜찮다
            // ** 중요한 관점은 한번 호출될떄 무조건 8개의 방향이 다 호출되는것이 아니라 하나의 방향으로 쭉 가보고 
            // 실패하면 반복문 돌려서 다른 방향으로 가보는거임 ** 
        }
    }
    return 0;
}


void print_path(int x,int y) // path 출력
{
    for(int i=1; i<x+1; i++) // 1부터 보드크기만큼 출력
    { 
        for(int j=1; j<y+1; j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력 
    int x,y,start_x,start_y;
    for (int i=0; i<t; i++)
    {
        cin >> y >> x >> start_y >> start_x;
        point start;
        start.x = start_x;
        start.y = start_y;
        // int count = 1;
        for(int j=1; j<9; j++) // 0좌표는 안쓰기 떄문에 1부터 시작해도 문제가 없다
        { // 보드,루트 초기화
            for(int k=1; k<9; k++)
            {
                board[j][k] = true; // 갈수 있으면 true
                path[j][k] = 0; // 시작이 1이니 0으로 초기화
            }
        }
        board[start.y][start.x] = false; // 시작위치는 직접 초기 설정해줘야함
        path[start.y][start.x] = 1;
        if(knight_tour(y,x,start,1)) // 루트가 있으면
        {
            cout << 1 << endl;
            print_path(y,x); // 출력하고
        }
        else // 실패하면 0만 출력
        {
            cout << 0 << endl;
        }

    }


	return 0;
}