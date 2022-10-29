#include <vector>
#include <queue>


using namespace std;

typedef pair<int,int> ci;

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};



//(r,c)로부터 상하좌우로 뻗어나가며 같은 색상을 지닌곳을 방문체크
int bfs(vector<vector<int>> & picture,int m,int n,int r,int c,int color){
    
    
    int size_of_area=0;
    
    queue<ci> q;
    
    q.push({r,c});
    picture[r][c]=0; //  방문체크
    
    while(!q.empty()){
        
        size_of_area++; // 영역의 넓이 +1
        int cr = q.front().first;
        int cc = q.front().second; 
       
        q.pop();

        // 상하좌우 탐색
        for(int i=0;i<4;i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            //범위를 벗어나거나 색깔이 다르면
            if(nr<0 || nr>=m || nc< 0 || nc>= n ||  picture[nr][nc]!=color)
                continue;
            
            picture[nr][nc]=0; // 방문체크 
            q.push({nr,nc});
           
        }  
    }
    
    return size_of_area; 
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if(picture[i][j]!=0){
                
                int size = bfs(picture,m,n,i,j,picture[i][j]);
                max_size_of_one_area=max(max_size_of_one_area,size); //최댓값 갱신
                number_of_area++; //영역 수 증가 
                
            }
                
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
