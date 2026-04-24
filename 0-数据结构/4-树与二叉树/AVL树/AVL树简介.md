# AVL 树简介

## 1. 什么是 AVL 树？

AVL 树是一种自平衡二叉搜索树（BST），由俄国数学家 Adelson-Velsky 和 Landis 提出。

- 它是一棵二叉搜索树：左子树节点值小于根节点，右子树节点值大于根节点。
- 它也是一棵高度平衡的树：每个节点的左右子树高度差（平衡因子）最多为 1。

因此，AVL 树在插入、删除后会自动保持“近似对称”的形态，避免退化成链表。

## 2. 数形结合：AVL 树的直观理解

AVL 树的核心思想是把“数”和“形”结合起来：

- “数”是节点的高度和节点的平衡因子。
- “形”是树的左右倾斜程度和节点位置关系。

从数的角度，看高度、平衡因子；从形的角度，看树是否左高、右高、偏斜。

如果某个节点的左右子树高度差超过 1，则说明该节点对应的树形已经失衡，需要通过旋转把形状调整回平衡。

## 3. 平衡因子（Balance Factor）

对于节点 `x`：

- `bf(x) = height(left(x)) - height(right(x))`

AVL 树要求：

- `bf(x) ∈ {-1, 0, 1}`

这意味着：

- `bf(x) = 0`：左右子树高度相等，形态最对称。
- `bf(x) = 1`：左子树比右子树高 1，属于轻度左偏。
- `bf(x) = -1`：右子树比左子树高 1，属于轻度右偏。

若 `|bf(x)| > 1`，则该节点失衡，需要旋转修复。

## 4. AVL 树的几何性质

- AVL 树保证树高 `h` 是对数级别的。
- 最坏情况下，AVL 树的高度满足：`h < 1.44 * log₂(n + 2)`。
- 因此查找、插入、删除均可维持 `O(log n)`。

从形上看，AVL 树总是保持“近似完全二叉树”的形状，而不是出现长而瘦的链状结构。

## 5. 旋转修复：通过形变恢复平衡

AVL 树最重要的修复手段是旋转操作。旋转本质上是对树结构的局部形状重塑。

### 5.1 LL（左左）型

```
    z                y
   /                / \
  y      ->        x   z
 /
x
```

- 形态：左子树的左边高度过高。
- 修复：对 `z` 进行右旋。

### 5.2 RR（右右）型

```
z                 y
 \               / \
  y     ->      z   x
   \
    x
```

- 形态：右子树的右边高度过高。
- 修复：对 `z` 进行左旋。

### 5.3 LR（左右）型

```
    z              z              x
   /              /              / \
  y      ->     x      ->      y   z
   \          /
    x        y
```

- 形态：左子树的右边高度过高。
- 修复：先对 `y` 左旋，再对 `z` 右旋。

### 5.4 RL（右左）型

```
z                 z                 x
 \                 \               / \
  y      ->        x      ->      z   y
 /                 \
x                   y
```

- 形态：右子树的左边高度过高。
- 修复：先对 `y` 右旋，再对 `z` 左旋。

## 6. 基本操作及功能

### 6.1 查找

AVL 树的查找与普通二叉搜索树相同：沿着根节点向左或向右走。

由于高度受限，时间复杂度为 `O(log n)`。

### 6.2 插入

插入步骤：

1. 按 BST 规则插入新节点。
2. 从插入点向上回溯，更新每个祖先节点高度。
3. 计算每个节点的平衡因子。
4. 若 `|bf| > 1`，执行 LL / RR / LR / RL 旋转之一。
5. 修复后继续回溯直到根节点。

从形象角度看，插入可能使某条路径变得“偏高”，旋转就是把偏高的子树“抬正”。

### 6.3 删除

删除步骤：

1. 按 BST 规则删除节点。
2. 从删除点向上回溯，更新高度和平衡因子。
3. 若发现失衡，执行相应旋转。
4. 继续回溯，直到根节点恢复平衡。

删除后，树的某个分支可能变矮，AVL 树通过旋转把邻近结构重新分配，使形态恢复平衡。

## 7. 代码示例（C++）

```cpp
struct Node {
    int val;
    Node* left;
    Node* right;
    int height;
    Node(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* node) {
    return node ? node->height : 0;
}

int balanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

void updateHeight(Node* node) {
    node->height = 1 + max(height(node->left), height(node->right));
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->val) node->left = insert(node->left, key);
    else if (key > node->val) node->right = insert(node->right, key);
    else return node;

    updateHeight(node);
    int bf = balanceFactor(node);

    if (bf > 1 && key < node->left->val) return rightRotate(node);      // LL
    if (bf < -1 && key > node->right->val) return leftRotate(node);    // RR
    if (bf > 1 && key > node->left->val) {                             // LR
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && key < node->right->val) {                            // RL
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
```

## 8. AVL 树的优点与适用场景

- 优点：
  - 查找、插入、删除时间复杂度都为 `O(log n)`。
  - 形态始终保持平衡，较少出现极端退化情况。
  - 适合读写频繁、对查询稳定性要求高的场景。

- 适用场景：
  - 内存中的平衡索引结构。
  - 需要严格时间上界的数据结构。
  - 频繁执行插入和删除操作的集合。

## 9. 与红黑树对比

| 特性 | AVL 树 | 红黑树 |
|------|--------|--------|
| 平衡性 | 更严格 | 更宽松 |
| 查询效率 | 更高 | 稍低 |
| 插入/删除旋转次数 | 可能更多 | 可能更少 |
| 实现复杂度 | 中等 | 略高 |

从形态上看：

- AVL 树更像“高度受控的对称树”。
- 红黑树更像“允许颜色约束的松散平衡树”。

## 10. 结语

AVL 树是“数与形结合”的典型例子：

- 通过数值（高度、平衡因子）判断形态是否失衡；
- 通过形变（旋转）将不平衡的树形恢复成对称。

它的价值在于：既保留二叉搜索树的快速查找，又通过旋转让树保持稳定高效。