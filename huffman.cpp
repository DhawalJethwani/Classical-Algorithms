#include <bits/stdc++.h>
using namespace std;

struct MHNode
{
    char data;
    int freq;
    MHNode *left, *right;

    MHNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MHNode* l, MHNode* r)
    {
        return (l->freq > r->freq);
    }
};

void code(struct MHNode* root, string str)
{
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    code(root->left, str + "0");
    code(root->right, str + "1");
}

void Huffman(char data[], int freq[], int size)
{
    struct MHNode *left, *right, *top;

    priority_queue<MHNode*, vector<MHNode*>, compare> minHeap;
    for (int i = 0; i < size; i++)
        minHeap.push(new MHNode(data[i], freq[i]));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MHNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    code(minHeap.top(), "");
}

int main()
{
    int n;
    cin >> n;
    char arr[n];
    int freq[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        cin >> freq[i];
    }
    Huffman(arr, freq, n);
    return 0;
}
