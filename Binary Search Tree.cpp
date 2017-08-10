#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;
int conv=1;

struct node
{
    float a;
    struct node *parent=0;
    struct node *lchild=0;
    struct node *rchild=0;
    int flag=0;
};
typedef struct node str;

str *ins_node(str *root)
{
    str *temp=new str[1];
    temp->flag=abs(conv-1);
    if(temp)
    {
        cout << "Enter a number to insert in the tree" << endl;
        cin >> temp->a;
        if(!root)
        {
            root=temp;
        }
        else
        {
            str *temp1=root;
            while(1)
            {
                if(temp->a<=temp1->a)
                {
                    if(temp1->lchild==0)
                    {
                        temp1->lchild=temp;
                        temp->parent=temp1;
                        break;
                    }
                    else
                    {
                        temp1=temp1->lchild;
                    }
                }
                else if(temp->a>temp1->a)
                {
                    if(temp1->rchild==0)
                    {
                        temp1->rchild=temp;
                        temp->parent=temp1;
                        break;
                    }
                    else
                    {
                        temp1=temp1->rchild;
                    }
                }
            }
        }
        cout << "   Successfully inserted!!" << endl << endl;
    }
    else
    {
        cout << "   Overflow!!" << endl << endl;
    }
    return root;
}
str *del_node(str *root)
{
    int d;
    str *temp=root;
    if(temp)
    {
        float key;
        str *node=0;
        cout << "Enter a number to delete from the tree" << endl;
        cin >> key;
        while(1)
        {
            d=0;
            if(temp->a==key)
            {
                d=1;
                node=temp;
                break;
            }
            else if(key<=temp->a && temp->lchild)
            {
                temp=temp->lchild;
            }
            else if(key>temp->a && temp->rchild)
            {
                temp=temp->rchild;
            }
            else
            {
                node=NULL;
                break;
            }
        }
        if(node)
        {
            if(!node->lchild && !node->rchild && !node->parent)
            {
                root=NULL;
            }
            else if(!node->lchild && !node->rchild)
            {
                if(node->parent->lchild==node)
                {
                    node->parent->lchild=NULL;
                    node->parent=NULL;
                }
                else
                {
                    node->parent->rchild=NULL;
                    node->parent=NULL;
                }
            }
            else if(!node->lchild)
            {
                int e=0;
                str *t=node->rchild;
                while(t->lchild)
                {
                    t=t->lchild;
                    e=1;
                }
                if(t->rchild)
                {
                    t->rchild->parent=t->parent;
                    if(e==0)
                    {
                        t->rchild->parent->rchild=t->rchild;
                    }
                    else
                    {
                        t->rchild->parent->lchild=t->rchild;
                    }
                }
                else
                {
                    if(e==0)
                    {
                        t->parent->rchild=NULL;
                    }
                    else
                    {
                        t->parent->lchild=NULL;
                    }
                }
                t->parent=NULL;
                if(node->lchild)
                {
                    t->lchild=node->lchild;
                    node->lchild->parent=t;
                    node->lchild=NULL;
                }
                if(node->rchild)
                {
                    t->rchild=node->rchild;
                    t->rchild->parent=t;
                    node->rchild=NULL;
                }
                if(node->parent)
                {
                    t->parent=node->parent;
                    if(node->parent->rchild==node)
                    {
                        t->parent->rchild=t;
                    }
                    else
                    {
                        t->parent->lchild=t;
                    }
                    node->parent=NULL;
                }
                else
                {
                    root=t;
                }
            }
            else
            {
                int e=0;
                str *t=node->lchild;
                while(t->rchild)
                {
                    t=t->rchild;
                    e=1;
                }
                if(t->lchild)
                {
                    t->lchild->parent=t->parent;
                    if(e==0)
                    {
                        t->lchild->parent->lchild=t->lchild;
                    }
                    else
                    {
                        t->lchild->parent->rchild=t->lchild;
                    }
                }
                else
                {
                    if(e==0)
                    {
                        t->parent->lchild=NULL;
                    }
                    else
                    {
                        t->parent->rchild=NULL;
                    }
                }
                t->parent=NULL;
                if(node->rchild)
                {
                    t->rchild=node->rchild;
                    node->rchild->parent=t;
                    node->rchild=NULL;
                }
                if(node->lchild)
                {
                    t->lchild=node->lchild;
                    t->lchild->parent=t;
                    node->lchild=NULL;
                }
                if(node->parent)
                {
                    t->parent=node->parent;
                    if(node->parent->lchild==node)
                    {
                        t->parent->lchild=t;
                    }
                    else
                    {
                        t->parent->rchild=t;
                    }
                    node->parent=NULL;
                }
                else
                {
                    root=t;
                }
            }
            delete node;
            cout << "   Successfully Deleted!!" << endl << endl;
        }
        else
        {
            cout << "   Number is not found!!" << endl << endl;
        }
    }
    else
    {
        cout << "   Underflow!!\n   Oops!! The tree is empty!!" << endl << endl;
    }
    return root;
}

void search_key(str *temp)
{
    int d;
    if(temp)
    {
        float key;
        cout << "Enter a number to search in the tree" << endl;
        cin >> key;
        while(1)
        {
            d=0;
            if(temp->a==key)
            {
                d=1;
                break;
            }
            else if(key<=temp->a && temp->lchild)
            {
                temp=temp->lchild;
            }
            else if(key>temp->a && temp->rchild)
            {
                temp=temp->rchild;
            }
            else
            {
                break;
            }
        }
        if(d==0)
        {
            cout << "   Key not found!!\n\n";
            return;
        }
        else if(d==1)
        {
            cout << "   Key found!!\n\n";
            return;
        }
    }
    else
    {
        cout << "   Oops!! The tree is empty!!\n\n";
        return;
    }
}

void print_preorder(str *temp)
{
    while(temp)
    {
        if(temp->flag!=conv && temp->flag!=2)
        {
            cout << temp->a << " ";
        }
        temp->flag=2;
        if(temp->lchild==0)
        {
            if(temp->rchild && temp->rchild->flag!=conv)
            {
                temp=temp->rchild;
            }
            else
            {
                temp->flag=conv;
                temp=temp->parent;
            }
        }
        else if(temp->lchild && temp->lchild->flag!=conv)
        {
            temp=temp->lchild;
        }
        else if(temp->lchild && temp->lchild->flag==conv && temp->rchild && temp->rchild->flag!=conv)
        {
            temp=temp->rchild;
        }
        else
        {
            temp->flag=conv;
            temp=temp->parent;
        }
    }
    conv=abs(conv-1);
}

void print_inorder(str *temp)
{
    while(temp)
    {
        if(temp->lchild==0)
        {
            if((temp->rchild && temp->rchild->flag!=conv) || temp->rchild==0)
            {
                cout << temp->a << " ";
            }
            if(temp->rchild && temp->rchild->flag!=conv)
            {
                temp=temp->rchild;
            }
            else
            {
                temp->flag=conv;
                temp=temp->parent;
            }
        }
        else if(temp->lchild && temp->lchild->flag!=conv)
        {
            temp=temp->lchild;
        }
        else if(temp->lchild && temp->lchild->flag==conv && temp->rchild==0)
        {
            cout << temp->a << " ";
            temp->flag=conv;
            temp=temp->parent;
        }
        else if(temp->lchild && temp->lchild->flag==conv && temp->rchild && temp->rchild->flag!=conv)
        {
            cout << temp->a << " ";
            temp=temp->rchild;
        }
        else
        {
            temp->flag=conv;
            temp=temp->parent;
        }
    }
    conv=abs(conv-1);
}

void print_postorder(str *temp)
{
    while(temp)
    {
        if(temp->lchild==0)
        {
            if((temp->rchild && temp->rchild->flag==conv) || temp->rchild==0)
            {
                cout << temp->a << " ";
            }
            if(temp->rchild && temp->rchild->flag!=conv)
            {
                temp=temp->rchild;
            }
            else
            {
                temp->flag=conv;
                temp=temp->parent;
            }
        }
        else if(temp->lchild && temp->lchild->flag!=conv)
        {
            temp=temp->lchild;
        }
        else if(temp->lchild && temp->lchild->flag==conv && temp->rchild==0)
        {
            cout << temp->a << " ";
            temp->flag=conv;
            temp=temp->parent;
        }
        else if(temp->lchild && temp->lchild->flag==conv && temp->rchild && temp->rchild->flag!=conv)
        {
            temp=temp->rchild;
        }
        else
        {
            cout << temp->a << " ";
            temp->flag=conv;
            temp=temp->parent;
        }
    }
    conv=abs(conv-1);
}

void min_val(str *temp)
{
    while(temp->lchild)
    {
        temp=temp->lchild;
    }
    cout << "   Minimum value in the tree : " << temp->a << endl << endl;
}

void max_val(str *temp)
{
    while(temp->rchild)
    {
        temp=temp->rchild;
    }
    cout << "   Maximum value in the tree : " << temp->a << endl << endl;
}

int main()
{
    str *root=0;
    int op=1,d=0;
    cout << "............Keys corresponding to the function to implement............" << endl;
    cout << " 1 - Insert\n 2 - Delete\n 3 - Search\n 4 - Traversal(Preorder)\n 5 - Traversal(Inorder)\n 6 - Traversal(Postorder)\n 7 - Find minimum entry\n 8 - Find maximum entry\n 9 - Exit\n";
    cout << "Press one of the above keys to continue...... ";
    while(1)
    {
        if(op>0 && op<10)
        {
            if(d)
            {
                cout << "Which function are you about to execute next?\n";
                cout << "Look up from the above table and enter the corresponding key : ";
            }
            cin >> op;
            if(op>0 && op<10)
            {
                cout << "   Instruction Accepted!!\n\n";
            }
            if(op==1)
            {
                root=ins_node(root);
                d=1;
            }
            else if(op==2)
            {
                root=del_node(root);
                d=1;
            }
            else if(op==3)
            {
                search_key(root);
                d=1;
            }
            else if(op==4)
            {
                if(root)
                {
                    cout << "   The tree when traversed in Preorder :\n   ";
                    print_preorder(root);
                    cout << "\n\n";
                }
                else
                {
                    cout << "   Oops!!The tree is empty!!\n\n";
                }
                d=1;
            }
            else if(op==5)
            {
                if(root)
                {
                    cout << "   The tree when traversed in Inorder :\n   ";
                    print_inorder(root);
                    cout << "\n\n";
                }
                else
                {
                    cout << "   Oops!!The tree is empty!!\n\n";
                }
                d=1;
            }
            else if(op==6)
            {
                if(root)
                {
                    cout << "   The tree when traversed in Postorder :\n   ";
                    print_postorder(root);
                    cout << "\n\n";
                }
                else
                {
                    cout << "   Oops!!The tree is empty!!\n\n";
                }
                d=1;
            }
            else if(op==7)
            {
                if(root)
                {
                    min_val(root);
                }
                else
                {
                    cout << "   Oops!!The tree is empty!!\n\n";
                }
                d=1;
            }
            else if(op==8)
            {
                if(root)
                {
                    max_val(root);
                }
                else
                {
                    cout << "   Oops!!The tree is empty!!\n\n";
                }
                d=1;
            }
            else if(op==9)
            {
                break;
            }
        }
        else
        {
            cout << "   Invalid Input!! Try Again.\n\n";
            op=1;
            d=1;
        }
    }
    return 0;
}
