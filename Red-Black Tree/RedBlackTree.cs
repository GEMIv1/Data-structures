using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Red_Black_Tree
{
    class RedBlackTree
    {
        public Node Root { get; set; }
        private void LeftRotation(Node x)
        {
            Node y = x.Right;
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
        private void RightRotation(Node x)
        {
            Node y = x.Left;
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

        //public void Insert();
        //public void Delete();
        //public void RemoveAt(int index);
        //public void Search();
    }
}
