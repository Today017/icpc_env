#pragma once
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <vector>
#include <cassert>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <utility>
using namespace std;
using ll = long long;

#define rep(i, n) for(ll i=0; i<n; i++)
#define REP(i, n) for(ll i=0; i<n; i++)
#define per(i, n) for(ll i=(n)-1; i>=0; i--)

#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin(), (x).end()

bool chmax(auto& a, auto b) { return a<b ? a=b, 1: 0; }
bool chmin(auto& a, auto b) { return a>b ? a=b, 1: 0; }
bool CHMAX(auto& a, auto b) { return a<b ? a=b, 1: 0; }
bool CHMIN(auto& a, auto b) { return a>b ? a=b, 1: 0; }

const int INF = 1e9+10;
const ll INFL = 4e18;

#ifdef DEBUG
#include "./debug.hpp"
#else
#define debug(...)
#define print_line
#endif
