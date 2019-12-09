#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>

#include <memory.h>
using namespace std;
struct Node
{
    Node(int l, string w, Node *n) : level(l)
    {
        if (n)
        {
            parents.push_back(n);
        }
        word = w;
    }
    int level = 0;
    string word = "";
    vector<Node *> parents;
};

class Solution
{
public:
    int minPath = INT_MAX;
    unordered_set<string> word_set;

    vector<vector<string>> result;
    vector<string> tmpResult;

    queue<Node *> deleteQueue;
    map<string, Node *> word2Node;
    bool search(queue<Node *> &q)
    {
        bool flag = false;
        for (int k = q.size(); k > 0; --k)
        {
            Node *node = q.front();
            string word = node->word;

            int level = node->level;
            q.pop();

            for (int i = 0; i < word.size(); i++)
            {
                string tmpWord = word;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    tmpWord[i] = ch;
                    if (word_set.count(tmpWord) && tmpWord != word)
                    {
                        if (!word2Node[tmpWord])
                        {
                            //创建节点，关联父节点
                            Node *tmpNode = new Node(level + (level > 0 ? 1 : -1), tmpWord, node);
                            word2Node[tmpWord] = tmpNode;
                            q.push(tmpNode);
                        }
                        else
                        {
                            //判定是否同一个方向
                            if (level * word2Node[tmpWord]->level > 0)
                            {

                                //判定已保存的节点的级别，是否小于当前节点一个等级
                                if (level + (level > 0 ? 1 : -1) == word2Node[tmpWord]->level)
                                {
                                    word2Node[tmpWord]->parents.push_back(node);
                                }
                            }
                            else
                            {
                                //相交

                                flag = true;
                                minPath = abs(level) + abs(word2Node[tmpWord]->level);
                                tmpResult = vector<string>(minPath);
                                //区分正向BFS节点，和反向BFS节点
                                if (node->level > 0)
                                {
                                    updateResult(node, word2Node[tmpWord]);
                                }
                                else
                                {
                                    updateResult(word2Node[tmpWord], node);
                                }
                            }
                        }
                    }
                }
            }
            deleteQueue.push(node);
        }

        return flag;
    }
    //双向bfs
    void bfs(string beginWord, string endWord, vector<string> &wordList)
    {

        queue<Node *> q;
        Node *start = new Node(1, beginWord, NULL);
        q.push(start);
        word2Node[beginWord] = start;

        queue<Node *> rq;
        Node *end = new Node(-1, endWord, NULL);
        rq.push(end);
        word2Node[endWord] = end;

        while (!q.empty() || !rq.empty())
        {
            if (search(q) || search(rq))
            {
                break;
            }
        }

        while (!deleteQueue.empty())
        {
            Node *n = deleteQueue.front();
            deleteQueue.pop();
            delete n;
            n = NULL;
        }
    }

    //查找端点
    void updateResult(Node *node, Node *rnode)
    {
        tmpResult[node->level - 1] = node->word;
        tmpResult[rnode->level + minPath] = rnode->word;
        if (node->parents.size() == 0 && rnode->parents.size() == 0)
        {
            result.push_back(tmpResult);
        }
        else
        {
            if (node->parents.size() == 0)
            {
                for (Node *p : rnode->parents)
                {

                    updateResult(node, p);
                }
            }
            else
            {
                for (Node *p : node->parents)
                {

                    updateResult(p, rnode);
                }
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        word_set.insert(wordList.begin(), wordList.end());
        if (!word_set.count(endWord))
            return result;

        bfs(beginWord, endWord, wordList);

        return result;
    }
};

int main(int argc, char *args[])
{
    vector<string> wordList({"hot", "dot", "dog", "lot", "log", "cog"});
    Solution s;
    s.findLadders("hit", "cog", wordList);

    getchar();
    return 0;
}
