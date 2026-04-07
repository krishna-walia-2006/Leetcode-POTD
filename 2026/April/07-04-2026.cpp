// Key observation ==>  Robot will move only on perimeter

class Robot {
    int index = 0;
    bool moved = false;
    vector<vector<int>> position;
public:
    Robot(int width, int height) {
        
        //Directions 
            // 1 -> East
            // 2 -> North
            // 3 -> West
            // 4 -> South

        // left to right
        for(int x = 0;x < width;x++) {
            position.push_back({x,0,1});
        }

        //bottom to top
        for(int y = 1;y < height;y++) {
            position.push_back({width-1,y,2});
        }

        //right to left
        for(int x = width-2;x >= 0;x--) {
            position.push_back({x,height-1,3});
        }

        //top to bottom
        for(int y = height-2;y >= 1;y--) {
            position.push_back({0,y,4});
        }

        position[0][2] = 4;
    }
    
    void step(int num) {
        moved = true;
        index = (index + num)%position.size();
    }
    
    vector<int> getPos() {
        return {position[index][0],position[index][1]};
    }
    
    string getDir() {
        if(moved==false) return "East";
        if(position[index][2]==1) return "East";
        else if(position[index][2]==2) return "North";
        else if(position[index][2]==3) return "West";
        else return "South"; 
    }
};

