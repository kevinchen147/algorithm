template <typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template <typename T_container,
          typename T = typename std::enable_if<
              !std::is_same<T_container, std::string>::value,
              typename T_container::value_type>::type>
std::ostream& operator<<(std::ostream& os, const T_container& v) {
    os << '{';
    std::string sep;
    for (const T& x : v) os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { std::cerr << std::endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    std::cerr << ' ' << H;
    dbg_out(T...);
}

#define dbg(...)                                                           \
    std::cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: ", \
        dbg_out(__VA_ARGS__)

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right)
        : val(x), left(_left), right(_right) {}
};