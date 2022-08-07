// declaration : segmenttree obj(size, array);
struct segmenttree {
	int n;
	vector<int> st;

	segmenttree(int n, vector<int>& a) {
		this->n = n;
		st.resize(4 * n, 0);
		build(a);
	}

	// helper functions
	void build(int start, int end, int node, vector<int>& v) {
		if (start == end) {
			st[node] = v[start];
			return;
		}

		int mid = (start + end) / 2;
		build(start, mid, 2 * node + 1, v);
		build(mid + 1, end, 2 * node + 2, v);

		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	int query(int l, int r, int start, int end, int node) {
		// no overlap
		if (start > r or end < l) {
			return 0;
		}

		// complete overlap
		if (start >= l and end <= r) {
			return st[node];
		}

		// partial overlap
		int mid = (start + end) / 2;
		int q1 = query(l, r, start, mid, 2 * node + 1);
		int q2 = query(l, r, mid + 1, end, 2 * node + 2);

		return (q1 + q2);
	}

	void update(int start, int end, int index, int value, int node) {
		if (start == end) {
			st[node] = value;
			return;
		}

		int mid = (start + end) / 2;
		if (index <= mid) {
			update(start, mid, index, value, 2 * node + 1);
		} else {
			update(mid + 1, end, index, value, 2 * node + 2);
		}
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	// called functions
	void build(vector<int>& v) {
		build(0, n - 1, 0, v);
	}

	int query(int l, int r) {
		return query(l, r, 0, n - 1, 0);
	}

	void update(int x, int y) {
		update(0, n - 1, x, y, 0);
	}
};

class NumArray {
    segmenttree *st;
    int N;
    
public:
    NumArray(vector<int>& nums) {
        N = size(nums);
        st = new segmenttree(N, nums);
    }
    
    void update(int index, int val) {
        st->update(0, N - 1, index, val, 0);
    }
    
    int sumRange(int left, int right) {
        return st->query(left, right, 0, N - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */