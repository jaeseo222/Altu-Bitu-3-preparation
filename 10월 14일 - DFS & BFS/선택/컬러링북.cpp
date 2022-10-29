.
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ci;

int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};



//(r,c)로부터 같은 영역 마킹

int bfs(vector<vector<int>> & picture,int m,int n,int r,int c,int color){
    
    
    int size_of_area=0;
    
    queue<ci> q;
    
    q.push({r,c});
    
    while(!q.empty()){
        
        
        int cr = q.front().first;
        int cc = q.front().second; 
        
        picture[cr][cc]=0; //방문체크
        q.pop();
            
            
            //범위를 벗어나거나 색깔이 다르면
        if(cr<0 || cr>=n || cc<0 || cr >=n || picture[cr][cc]!=color)
            continue;
        
        
        
        size_of_area++; // 같은 영역 수 
        
        q.push({cr,cc});
    }
    
    return size_of_area;
    
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    
    for(int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if(picture[m][n]!=0){
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
