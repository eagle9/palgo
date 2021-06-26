/*
cutting: bfs of state graph, a state is a node of the graph
state is (m,c,turn), from the problem, we know the state win status(color), then we bfs the graph with the game rule, and try to color the state graph nodes
finally see if we can get the color of state (1,2,1)

runtime 556ms, faster than 14%, mem less than 100%

understand and fully commented

*/
class Solution {
    //from problem statement, number of nodes in the graph <=50
    // [mouse position, cat position, turn]  
    //position is node label: 0 to 49
    //turn 1 for mouse to move, turn 2 for cat to move
    //color = 1, mouse wins
    //color = 2, cat wins
    //color = 0, draw
private:
    int color[50][50][3]; 
    
public:
    int catMouseGame(vector<vector<int>>& graph) 
    {
        int N = graph.size();
                
        queue<vector<int>>q;
        //init some of the know states, and push them into the queue
        for (int i=0; i<N; i++) {
            for (int turn=1; turn<=2; turn++){
                color[0][i][turn] = 1;  // mouse win conditions -- mouse at hole 0
                q.push({0,i,turn});
                
                if (i!=0){ //
                    color[i][i][turn] = 2;  // cat win conditions: mouse and cat at the same node(not hole)
                    q.push({i,i,turn});
                }
            }
        }
        
        //color the state graph from states whose color are known
        while (!q.empty()){            
            int m = q.front()[0]; 
            int c = q.front()[1];
            int t = q.front()[2];            
            int status = color[m][c][t];
            q.pop();
                        
            //findAllParents -- return m2,c2,t2 that can reach m,c,t by 1 move either by cat or mouse
            for (auto nextNode: findAllParents(graph,m,c,t)){
                int m2 = nextNode[0];
                int c2 = nextNode[1];
                int t2 = nextNode[2];
                
                if (color[m2][c2][t2]!=0) continue; // has been determined
                /*
                color[m][c][t] = status == 1, mouse win
                m2,c2,1  t2=1, mouse turn to move, mouse wants to win, so next state will be m, c2,t.   color[m2][c2][t2] = 1
                
                color[m][c][t] = status == 2, cat win
                m2,c2,2, cat turn to move, cat wants to win, so next state will be m2, c, t. color[m2][c2][t2] = 2
                combine as follows
                */
                if (t2==status) {  // immediate win, (m2,c2,t2)->(m,c,t)
                    color[m2][c2][t2] = status;
                    q.push({m2,c2,t2});                    
                }
                //can not immeidately win from m2,c2,t2
                //all lose from m2,c2,t2,
                else if (allChildrenWin(graph, m2,c2,t2)) {   // eventually lose
                    color[m2][c2][t2] = (t2==1)? 2:1;
                    q.push({m2,c2,t2});                
                }            
            }
        }
        //see if the node (mouse at 1, cat at 2, mouse turn to move) is colored or not
        return color[1][2][1];
    }
    
    //find all (m2,c2,t2) that reach m,c,t in one move by mouse/cat
    vector<vector<int>> findAllParents(vector<vector<int>>& graph, int m, int c, int t)
    {
        vector<vector<int>>neighbours;
        if (t==1){ //current turn is for mouse, prev move by cat, t2 = 2
            for (int c_next: graph[c]){
                //not allowed for the cat to move to hole node 0
                if (c_next!=0) neighbours.push_back({m,c_next,2});
            }
        }
        else //t == 2, prev move by mouse, t2=1
        {
            for (int m_next: graph[m])
                neighbours.push_back({m_next,c,1});
        }
        return neighbours;
    }
    
    //from (m,c,t), check if all lose
    bool allChildrenWin(vector<vector<int>>& graph, int m, int c, int t){
        if (t==1){ //mouse turn to move, all cat win?
            for (int m_next: graph[m]) {
                if (color[m_next][c][2]!=2) return false;
                
            }
        }
        else if (t==2){ //cat turn to move, all mouse win? 
            for (int c_next: graph[c]){
                if (c_next!=0) {
                    if (color[m][c_next][1]!=1) return false;
                } 
                
            }
        }
        //pass all win test, return true now
        return true;
    }
};

