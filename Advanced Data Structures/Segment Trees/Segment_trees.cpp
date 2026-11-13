#include <bits/stdc++.h>
using namespace std;

void build(int ind, int low, int high, int a[], int seg[])
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid, a, seg);
    build(2 * ind + 2, mid + 1, high, a, seg);

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

void updateQuery(int ind, int val, int low, int high, int i, int seg[] ){
    if(low == high){
        seg[ind] = val;
        return;
    }

    int mid = (low + high) / 2;
    if(i <= mid){
        updateQuery(2 * ind + 1, val, low, mid, i, seg);
    }
    else{
        updateQuery(2 * ind + 2, val, mid + 1, high, i, seg);
    }

    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int query(int ind, int low, int high, int l, int r, int seg[])
{
    // completely outside or does not lies in the range
    if (r < low || high < l)
    {
        return INT_MIN;
    }

    // completely inside or lies completely in the range
    if (l <= low && high <= r)
    {
        return seg[ind];
    }

    // partially inside and partially outside or overlaps
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r, seg);
    int right = query(2 * ind + 2, mid + 1, high, l, r, seg);

    return max(left, right);
}

int main()
{

    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int seg[4 * n];
    build(0, 0, n - 1, a, seg);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r, seg) << endl;
    }

    return 0;
}