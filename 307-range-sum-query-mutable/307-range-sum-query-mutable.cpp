class NumArray
{
private:
	int arr_size;
	int tree_size;
	vector<int> tree;
	int merge(int l, int r) { return (l + r); }

	void buildTree(vector<int> &arr, int treeIndex, int lo, int hi)
	{
		if (lo == hi)
		{
			tree[treeIndex] = arr[lo];
			return;
		}
		int mid = lo + (hi - lo) / 2;
		int leftIndex = 2 * treeIndex + 1;
		int rightIndex = 2 * treeIndex + 2;
		buildTree(arr, leftIndex, lo, mid);
		buildTree(arr, rightIndex, mid + 1, hi);
		tree[treeIndex] = merge(tree[leftIndex], tree[rightIndex]);
	}

	void updateTree(int treeIndex, int lo, int hi, int arrIndex, int val)
	{
		if (lo == hi)
		{
			tree[treeIndex] = val;
			return;
		}
		int mid = lo + (hi - lo) / 2;
		int leftIndex = 2 * treeIndex + 1;
		int rightIndex = 2 * treeIndex + 2;
		if (arrIndex > mid)
			updateTree(rightIndex, mid + 1, hi, arrIndex, val);
		else
			updateTree(leftIndex, lo, mid, arrIndex, val);
		tree[treeIndex] = merge(tree[leftIndex], tree[rightIndex]);
	}

	int queryTree(int treeIndex, int lo, int hi, int i, int j)
	{
		if (lo > j || hi < i)
			return 0;
		if (i <= lo && j >= hi)
			return tree[treeIndex];
		int mid = lo + (hi - lo) / 2;
		int leftIndex = 2 * treeIndex + 1;
		int rightIndex = 2 * treeIndex + 2;
		if (i > mid)
			return queryTree(rightIndex, mid + 1, hi, i, j);
		else if (j <= mid)
			return queryTree(leftIndex, lo, mid, i, j);
		int leftQuery = queryTree(leftIndex, lo, mid, i, mid);
		int rightQuery = queryTree(rightIndex, mid + 1, hi, mid + 1, j);
		return merge(leftQuery, rightQuery);
	}

public:
	NumArray(vector<int> &nums)
	{
		arr_size = nums.size();
		if (arr_size == 0)
			return;
		int height = (int)(ceil(log2(arr_size)));
		tree_size = 2 * (int)pow(2, height) - 1;
		tree.resize(tree_size, 0);

		buildTree(nums, 0, 0, arr_size - 1);
	}

	void update(int i, int val)
	{
		updateTree(0, 0, arr_size - 1, i, val);
	}

	int sumRange(int i, int j)
	{
		int sum = queryTree(0, 0, arr_size - 1, i, j);
		return sum;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */