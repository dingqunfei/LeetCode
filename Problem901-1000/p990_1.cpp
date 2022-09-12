class UnionFind {
private:
    int size;
    vector<int> parent;
public:
    UnionFind(int n)
    {
        size = n;
        parent.resize(n);
        for(int i = 0; i < size; ++i)
        {
            parent[i] = i;
        }
    }

    int Find(int x)
    {
        if(x != parent[x])
        {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y)
    {
        int rootX = Find(x);
        int rootY = Find(y);
        if(rootX != rootY)
        {
            parent[rootX] = rootY;
            --size;
        }
    }

    bool Connected(int x, int y)
    {
        return Find(x) == Find(y);
    }

    int count()
    {
        return size;
    }

};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf(26);
        for(auto eq: equations)
        {
            if (eq[1] == '=') {
                char x = eq[0];
                char y = eq[3];
                uf.Union(x - 'a', y - 'a');
            }
        }
        for (auto eq : equations) {
            if (eq[1] == '!') {
                char x = eq[0];
                char y = eq[3];
                if (uf.Connected(x - 'a', y - 'a'))
                {
                    return false;
                }
            }
        }
        return true;
    }
};