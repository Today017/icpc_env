#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <set>
#include <vector>

class PartitionRefinement {
   public:
    PartitionRefinement() = default;
    explicit PartitionRefinement(int n) : sets(1), cls(n, 0) {
        for (int i = 0; i < n; ++i) sets[0].insert(i);
    }

    int find(int x) const { return cls[x]; }

    bool same(int x, int y) const {
        int cx = find(x), cy = find(y);
        return cx != -1 && cy != -1 && cx == cy;
    }

    bool contains(int x) const { return cls[x] != -1; }

    void erase(int x) {
        if (contains(x)) {
            sets[cls[x]].erase(x);
            cls[x] = -1;
        }
    }

    int size(int i) const { return sets[i].size(); }

    int member(int i) const {
        assert(0 <= i && i < (int)sets.size());
        return *sets[i].begin();
    }

    std::vector<int> members(int i) const {
        assert(0 <= i && i < (int)sets.size());
        return std::vector<int>(sets[i].begin(), sets[i].end());
    }

    std::vector<std::pair<int, int>> refine(const std::vector<int>& pivot) {
        std::map<int, std::vector<int>> split;
        for (auto x : pivot) {
            if (!contains(x)) continue;
            int i = cls[x];
            split[i].push_back(x);
            sets[i].erase(x);
        }
        std::vector<std::pair<int, int>> updated;
        for (auto& [i, s] : split) {
            int ni = sets.size();
            sets.emplace_back(s.begin(), s.end());
            if (sets[i].size() < sets[ni].size()) {
                std::swap(sets[i], sets[ni]);
            }
            if (sets[ni].empty()) {
                sets.pop_back();
                continue;
            }
            for (auto x : sets[ni]) {
                cls[x] = ni;
            }
            updated.push_back({i, ni});
        }
        return updated;
    }

   private:
    std::vector<std::set<int>> sets;
    std::vector<int> cls;
};