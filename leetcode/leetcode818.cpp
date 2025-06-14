#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    struct State {
        int pos;
        int speed;
        int moves;

        State(int p, int s, int m) : pos(p), speed(s), moves(m) {}
    };

    int racecar(int target) {
        queue<State> q;
        unordered_set<string> visited;

        q.push(State(0, 1, 0));

        while (!q.empty()) {
            State current = q.front(); q.pop();

            int pos = current.pos;
            int speed = current.speed;
            int moves = current.moves;

            if (pos == target) return moves;

            string key = to_string(pos) + "," + to_string(speed);
            if (visited.count(key)) continue;
            visited.insert(key);

            // Option 1: Accelerate
            q.push(State(pos + speed, speed * 2, moves + 1));

            // Option 2: Reverse (only when it's likely helpful)
            if ((pos + speed > target && speed > 0) || (pos + speed < target && speed < 0)) {
                int newSpeed = speed > 0 ? -1 : 1;
                q.push(State(pos, newSpeed, moves + 1));
            }
        }

        return -1; // Should not reach here
    }
};
