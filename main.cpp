#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    bool isLeaf(TreeNode* r) {
        return r && !r->left && !r->right;
    }

    int findTiltR(TreeNode* r, int& tilt) {
        if (isLeaf(r)) return r->val;
        int leftsum = r->left ? findTiltR(r->left, tilt) : 0;
        int rightsum = r->right ? findTiltR(r->right, tilt) : 0;
        tilt += abs(rightsum - leftsum);
        return r->val + leftsum + rightsum;
    }

    int findTilt(TreeNode* root) {
        if (!root) return 0;
        int tilt = 0;
        findTiltR(root, tilt);
        return tilt;
    }
};
void test1() {
    vector<int> v1{1, 2, 3};
    auto *t1 = new TreeNode(v1);
    cout << "1 ? " << Solution().findTilt(t1) << endl;

    vector<int> v2{1, 2, 3, 4};
    auto *t2 = new TreeNode(v2);
    cout << "7 ? " << Solution().findTilt(t2) << endl;
}

void test2() {

}

void test3() {

}