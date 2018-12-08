using namespace std;

typedef enum { Black, White } Color;
struct Coordinate {
  int x, y;
  bool operator == (const Coordinate& that) const {
    return x == that.x && y == that.y;
  }
};

bool findPathDFS(const vector<vector<Color>>& maze, )

vector<Coordinate> searchMaze(vector<vector<Color>> maze, const Coordinate& start, const Coordinate& end) {
  vector<Coordinate> path;
  return 
}