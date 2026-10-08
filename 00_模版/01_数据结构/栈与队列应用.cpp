/*
 * 栈与队列应用
 *
 * 【用途】三个经典模型合订：① 后缀（逆波兰）表达式求值；② queue + bool 数组模拟定容缓存（FIFO 页面置换缺页计数）；
 *         ③ 括号匹配计数（单类型只用计数器），以及多类型括号必须用栈的合法性判定。
 * 【输入】eval_rpn：后缀表达式字符串（token 之间用空格分隔，结尾可带 . / @ / # 之一，也可不写）；
 *         fifo_page_fault_count：请求页号序列 req 与缓存容量 cap；
 *         count_matched_pairs / is_bracket_sequence_valid：括号串 s。
 * 【输出】eval_rpn 返回表达式的值（ll，空串返回 0）；
 *         fifo_page_fault_count 返回缺页次数（ll）；count_matched_pairs 返回配对成功的括号对数
 *         （ll，循环结束后残留的 depth 就是未匹配的左括号数）；is_bracket_sequence_valid 返回整个序列是否合法（bool）。
 * 【复杂度】eval_rpn 时间 O(串长)、空间 O(栈里同时存放的操作数)；
 *           页面置换时间 O(请求数)、空间 O(最大页号)；括号匹配时间 O(串长)，计数器版空间 O(1)、栈版空间 O(串长)。
 * 【易错提醒】1. 后缀表达式里先弹出的是右操作数：b 先弹、a 后弹，减法与除法必须算 a - b、a / b，写反结果就错；
 *             2. 读到 . / @ / # 这类结束符要立刻 break，不要丢给 stoll 去转换（会抛 invalid_argument 异常）；
 *             3. 栈空时 st.top() 是未定义行为：每个运算符要求栈里至少两个操作数，输入不保证合法时先判 st.size() >= 2；
 *             4. 整数除法向零截断（-7 / 2 == -3、7 / -2 == -3），题目要向下取整得单独处理负数，除数为 0 也必须自己判；
 *             5. 定容缓存要「判满 -> 弹队首并置回 false -> 入队并置 true」，bool 数组漏置一次就会把驻留页当成缺页；
 *             6. 只有一种括号时计数器就够；括号类型多于一种、且要求交叉嵌套合法（如 ([)] 非法）时必须用栈，计数器会误判。
 *
 * 多组数据：栈、队列、bool 数组都在函数内新建，无全局状态，反复调用即可。
 */

/* ==================== 一、后缀（逆波兰）表达式求值：空格分隔、. / @ / # 结束 ==================== */

ll eval_rpn(const string &s)
{
    stack<ll> st;
    istringstream iss(s);
    string token;

    while (iss >> token)
    {
        if (token == "." || token == "@" || token == "#")
        {
            break;
        }

        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            ll b = st.top();
            st.pop();
            ll a = st.top();
            st.pop();

            if (token == "+")
            {
                st.push(a + b);
            }
            else if (token == "-")
            {
                st.push(a - b);
            }
            else if (token == "*")
            {
                st.push(a * b);
            }
            else
            {
                st.push(a / b);
            }
        }
        else
        {
            st.push(stoll(token));
        }
    }

    if (st.empty())
    {
        return 0;
    }
    return st.top();
}

/* 备注：若题目给的是「无空格、每个操作数只有一位数字、以 @ 结束」的紧凑串（如 34+5*@），
 *       把 istringstream 逐 token 的写法换成逐字符扫描：isdigit(c) 就压入 c - '0'，读到 @ 立刻 break，
 *       读到运算符时同样「先弹 b、再弹 a」，循环结束后 st.top() 就是答案。
 */

/* ==================== 二、queue + bool 数组模拟定容缓存：FIFO 页面置换缺页计数 ==================== */

ll fifo_page_fault_count(const vector<int> &req, int cap)
{
    if (cap <= 0)
    {
        return (ll)req.size();
    }

    int max_page = 0;
    for (int x : req)
    {
        if (x > max_page)
        {
            max_page = x;
        }
    }

    vector<bool> in_cache(max_page + 1, false);
    queue<int> q;
    ll faults = 0;

    for (int x : req)
    {
        if (in_cache[x])
        {
            continue;
        }

        faults++;

        if ((int)q.size() == cap)
        {
            int old = q.front();
            q.pop();
            in_cache[old] = false;
        }

        q.push(x);
        in_cache[x] = true;
    }

    return faults;
}

/* 备注：页号要求是 0 .. max_page 的非负整数（直接拿来当下标）；出现负数页号时先整体加一个偏移量再调用。
 *       要改成 LRU，把 queue<int> 换成 list<int>：命中时把该页 splice 到表头、淘汰时取表尾即可。
 */

/* ==================== 三、括号匹配：单类型用计数器，多类型嵌套必须用栈 ==================== */

ll count_matched_pairs(const string &s)
{
    ll depth = 0;
    ll matched = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            depth++;
        }
        else if (c == ')' && depth > 0)
        {
            depth--;
            matched++;
        }
    }

    return matched;
}

bool is_bracket_sequence_valid(const string &s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (st.empty())
            {
                return false;
            }

            char left = st.top();
            st.pop();

            if ((c == ')' && left != '(') || (c == ']' && left != '[') || (c == '}' && left != '{'))
            {
                return false;
            }
        }
    }

    return st.empty();
}

/* ==================== 调用示例（贴进自己的 main） ====================
    string expr;
    getline(cin, expr);                          // 例：3 4 + 5 * .  -> 35
    cout << eval_rpn(expr) << "\n";

    int n, cap;
    cin >> n >> cap;
    vector<int> req(n);
    for (int i = 0; i < n; i++)
        cin >> req[i];
    cout << fifo_page_fault_count(req, cap) << "\n";

    string s;
    cin >> s;                                    // 例：(()())  -> 配对数 3
    cout << count_matched_pairs(s) << "\n";
    cout << (is_bracket_sequence_valid(s) ? "YES" : "NO") << "\n";
    ==================================================================== */
