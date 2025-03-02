using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Red_Black_Tree
{
    public class Node
    {
        public bool Color { get; set; }// False -> black, True -> Red
        public Node Right { get; set; }
        public Node Left { get; set; }
        public Node Parent { get; set; }
        public Node() {
            Color = false;// Assume this node is root or a leaf
            Right = null;
            Left = null;
            Parent = null;
        }
        public Node(Node parent, Node right, Node left, bool color) {
            Color = color;
            Right = right;
            Left = left;
            Parent = parent;
        }
    }
}
