using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

namespace Red_Black_Tree
{
    class RedBlackTree<T>
    {
        private Node<T> root;
        public Node<T> Root { get => root; set { root = value; } }
        private void LeftRotation(Node<T> x)
        {
            Node<T> y = x.Right;
            x.Right = y.Left;
            if(y.Left != null)// If y.left is not leaf(Null object) therefore this is a subtree so we can update the parent of y.Left.Parent to x without any throwing exception
            {
                y.Left.Parent = x;
            }
            y.Parent = x.Parent;// Update the parent of y to be the Parent of x

            // After updating the parent of y to be the parent of x we have to update the pointers of parent of x to know where the y will be (on the left or on the right)

            if (x.Parent == null) // x is the root
            {
                Root = y;
            }
            else if (x.Parent.Left == x)// x was the left child so y has to be the left child
            {
                x.Parent.Left = y;
            }
            else { x.Parent.Right = y; }// x was the right child so y has to be the right child

            y.Left = x;
            x.Parent = y;
        }
        private void RightRotation(Node<T> x)
        {
            Node<T> y = x.Left;
            x.Left = y.Right;
            if (y.Right != null)
            {
                y.Right.Parent = x;
            }
            y.Parent = x.Parent;

            if (x.Parent == null)
            {
                Root = y;
            }
            else if (x.Parent.Left == x)
            {
                x.Parent.Left = y;
            }
            else { x.Parent.Right = y; }

            y.Right = x;
            x.Parent = y;
        }
        private void InsetionFixUP(Node<T> z)
        {
            /*
                Fix up roles:
                    1 - Parent Red and Uncle Red -> flip the colors (Parent and Uncle) -> Black, (Grand parent) -> Red.
                    2 - Parent Red and Uncle Black -> Make rotation(on the grand parent) with the opposite direction of the Inserted Node(z) and then recolor. 
             */
            
            if (root == z)// z is the root and its color red
            {
                root.Color = false;// make it black
            }
            else
            {
                while (z.Parent.Color)
                {
                    if(z.Parent == z.Parent.Parent.Left)
                    {
                        Node<T> uncle = z.Parent.Parent.Right;
                        if (uncle != null && uncle.Color)// Uncle color is also red like the parent
                        {
                            // Push the blackness of the grand parent
                            z.Parent.Color = false;
                            uncle.Color = false;
                            if (z.Parent.Parent != root)
                            {
                                z.Parent.Parent.Color = true;
                            }
                            z = z.Parent.Parent;
                        }
                        else if (uncle == null || !uncle.Color) // Uncle is not Red
                        {
                            if (z == z.Parent.Right) // If z is the right child
                            {
                                z = z.Parent;
                                LeftRotation(z);// after making the rotation the z becomes the parent of the z.parent
                            }
                            z.Parent.Color = false;
                            z.Parent.Parent.Color = true;
                            RightRotation(z.Parent.Parent);
                        }
                    }
                    else // z.parent is the right child
                    {
                        Node<T> uncle = z.Parent.Parent.Left;
                        if (uncle != null && uncle.Color)
                        {
                            z.Parent.Color = false;
                            uncle.Color = false;

                            if(z.Parent.Parent != root)
                            {
                                z.Parent.Parent.Color = true;
                            }
                            z = z.Parent.Parent;
                        }
                        else if(uncle == null || !uncle.Color)
                        {
                            if(z == z.Parent.Left)
                            {
                                z = z.Parent;
                                RightRotation(z);
                            }
                            z.Parent.Color = false;
                            z.Parent.Parent.Color = true;
                            LeftRotation(z.Parent.Parent);
                        }
                    }
                }
            }
        }
        public void Insert(T value)
        {

            Node<T> z = new Node<T> { Value = value , Left = null, Right = null, Color = true};

            Node<T> currNode = root;
            Node<T> parent = null;
            while (currNode != null) {
                parent = currNode;
                if (z.CompareTo(currNode)>0)
                {
                    currNode = currNode.Right;
                }
                else
                {
                    currNode = currNode.Left;
                }
            }
            z.Parent = parent;
            if (parent == null)//root
            {
                z.Color = false;
                root = z;
            }
            else if (parent.CompareTo(z) > 0)
            {
                parent.Left = z;
            }
            else if (parent.CompareTo(z) < 0)
            {
                parent.Right = z;
            }
            InsetionFixUP(z);
            /*
                The violation will be that there is two consecutive red nodes, So we have to fix it and not violate the blackHeight(x) 
             */
        }

        public void PrintByBFS()
        {
            
            Queue<Node<T>> queue = new Queue<Node<T>>();
            queue.Enqueue(root);

            while (queue.Count > 0)
            {
                Node<T> curr = queue.Dequeue();

                Console.WriteLine(curr);

                if (curr.Left == null)
                {
                    Console.WriteLine("Color: Black, Value: null");
                }

                else { 
                    queue.Enqueue(curr.Left);
                }

                if (curr.Right == null) { 
                    Console.WriteLine("Color: Black, Value: null");
                }
                else
                {
                    queue.Enqueue(curr.Right);
                }
            }
        }

    }
}
