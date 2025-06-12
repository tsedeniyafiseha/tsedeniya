//leetcode 127 word ladder

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    // Check if two words differ by exactly one character
    bool differByOneChar(const string& w1, const string& w2) {
        int diffCount = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) {
                if (++diffCount > 1) return false;
            }
        }
        return diffCount == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adjacencyList;
        int size = wordList.size();

        // Build graph: each word is a node; edges connect words differing by one character
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (differByOneChar(wordList[i], wordList[j])) {
                    adjacencyList[wordList[i]].push_back(wordList[j]);
                    adjacencyList[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        // Connect beginWord with words in wordList differing by one character, if not already connected
        if (adjacencyList.find(beginWord) == adjacencyList.end()) {
            for (const string& word : wordList) {
                if (differByOneChar(beginWord, word)) {
                    adjacencyList[beginWord].push_back(word);
                    adjacencyList[word].push_back(beginWord);
                }
            }
        }

        // BFS from beginWord to find shortest path to endWord
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [currentWord, steps] = q.front();
            q.pop();

            if (currentWord == endWord) {
                return steps;
            }

            for (const string& neighbor : adjacencyList[currentWord]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push({neighbor, steps + 1});
                }
            }
        }

        // If no transformation sequence exists
        return 0;
    }
};

int main() {
    Solution solution;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit";
    string endWord = "cog";

    int length = solution.ladderLength(beginWord, endWord, wordList);
    cout << "Length of shortest transformation sequence: " << length << endl;

    return 0;
}
