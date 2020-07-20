# PAT
Solutions for PAT

### 熟练掌握知识点
- 字符串
    - 模拟 熟练string相关方法的使用
    - KMP
    - 回文串Manacher
    - 字典树 
- 数学
    - [ ] 大整数模拟（推荐用Java解决）
        - [ ] 大整数加法
        - [ ] 大整数减法
        - [ ] 大整数乘法
        - [ ] 大整数除法
    - [ ] 素数
        - [x] 素数筛
        - 区间筛
    - [ ] 最大公约数 gcd
    - [ ] 最小公倍数
    - [ ] 合数分解
    - [ ] 逆元
    - [ ] 快速幂, 矩阵快速幂
    - [ ] 蔡勒公式 随便给一个日期，就能用这个公式推算出是星期几
    - 找规律
- 数据结构
    - [ ] 线性表
        - [ ] 链表模拟
            - [x] 逆转 A1074
            - [X] 合并 A1133
            - [x] 排序 A1052
            - [ ] 增删改查 A1133 A1097 A1032
            - tips:根据pat考察的惯用格式，并不需要完全模拟实现链表，只需要在功能上模拟其作用即可，可以利用vector储存链表结点，然后直接对vector进行操作，最后按照链表格式输出处理后的vector即可
            - [ ] * 使用指针模拟
    - [ ] 栈
        - [x] 中缀转后缀表达式
        - [ ] 后缀表达式运算
        - [ ] 模拟栈，实现较高级应用 A1057
        - [ ] 单调栈
    - [ ] 队列
        - [ ] 模拟排队
    - [ ] 堆
        - [ ] 最大堆
        - [ ] 最小堆
    - [ ] 哈希散列
        - [x] 平方探测法 A1078
        - [x] 平均搜索时间 A1145
- [ ] 图论
    - [ ] 最短路问题
        - [x] Dijkstra 单源最短路
        - [ ] Dijkstra+ 堆优化
        - [ ] 单源最短路 bellman ford 算法 可以处理负边权图
        - [ ] SPFA
        - [ ] 多源最短路 Floyd Warshall 算法
    - [ ] 拓扑排序
    - [ ] 关键路径
    - [ ] 树
        - [ ] 遍历
            - [ ] 先序遍历 递归、非递归实现
            - [ ] 后序遍历 递归、非递归实现
            - [ ] 中序遍历 递归、非递归实现
            - [x] 给出先序中序求后序 A1138
            - [ ] 给出后序中序求先序、层序 A1020
            - [ ] 给出先序后序求可能的中序
            - [ ] 层序遍历
            - [ ] 多叉树遍历
        - [ ] LCA
            - A1151, A1143
            - 根据最近公共祖先的概念判断的题，不考虑复杂LCA算法
        - [x] 表达式树 2019年秋季考试 7-3 Postfix Expression (25分)
        - [ ] 哈夫曼树
    - [ ] 欧拉路的判断应用
    - [ ] 平衡树
        - [ ] 判断平衡性
        - [ ] 建立平衡树
    - [x] 并查集
        - [x] 基础模板 A1118, A1114
        - 路径优化
- [ ] 排序
    - [x] 插入排序 A1089, A1098
    - [ ] 归并排序
    - [x] 快速排序
    - [x] 堆排序 A1098
    - [ ] 拓扑排序 A1146
- [ ] 暴力
    - 搜索
        - DFS + 剪枝优化
        - BFS
        - 多源BFS
        - Dijkstra+DFS
    - 经典问题
        - [ ] 八皇后
        - [ ] 汉诺塔
        - [ ] 装载问题
- 贪心
- 分治
    - [ ] 二分查找系列
        - 等于
        - 大于、大于等于
        - 小于、小于等于
        - 相关stl
            - binary_search
            - lower_bound(num, num+size, x)-num:大于等于x的第一个数的下标
            - upper_bound(num, num+size, x)-num:大于x的第一个数的下标
- [ ] dp
    - [ ] 背包问题
        - 01背包+构造最优解
        - 完全背包
        - 多重背包
    - [ ] LIS 最长递增子序列
    - [ ] LCS 最长公共子序列LCS
    - [ ] 整数拆分
- STL
    - string
    - vector
    - List
    - set
    - map
    - stack
    - queue
    - priority_queue
    - algorithm
        - max, max_element
        - min, min_element
        - lower_bound
        - upper_bound
        - binary_search
        - sort, stable_sort
        - fill
        - swap
        - reverse
- C++11
    - Lambda
    - auto
    - std::to_string
    - stoi，stod，stof，stol，stold，stoll，stoul，stoull
- 优化
    - IO优化