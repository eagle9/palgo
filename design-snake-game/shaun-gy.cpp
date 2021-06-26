//gy idea, shaun read and understand, won't be easy on the fly
//runtime 160ms, faster than 99%, mem less than 100%
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food.resize(food.size());
        for (int i = 0; i < food.size(); ++i) {
            this->food[i] = {food[i][0], food[i][1]};
        }
        score = 0;
        snake.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = snake.front(), tail = snake.back();
        snake.pop_back();
        //change snake head xy according to the move
        if (direction == "U") --head.first;
        else if (direction == "L") --head.second;
        else if (direction == "R") ++head.second;
        else if (direction == "D") ++head.first;
        
        //new head reaches snake body itself, or outbound, return -1, exit game
        if (count(snake.begin(), snake.end(), head) || head.first < 0 || head.first >= height || head.second < 0 || head.second >= width) {
            return -1;
        }
        //add the new head to begin, tail already removed
        snake.insert(snake.begin(), head);
        
        if (!food.empty() && head == food.front()) {
            food.erase(food.begin()); //consume food at the new head
            snake.push_back(tail);  //grow its tail
            ++score;
        }
        return score;
    }

private:
    int width, height, score;
    //food: list of food positions
    //snake: the xy coordinates occupied by the snake
    vector<pair<int, int>> food, snake;
}; 

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
