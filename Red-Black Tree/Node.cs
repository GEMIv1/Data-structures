using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Red_Black_Tree
{
    public class Node<T>:IComparable<Node<T>>
    {
        public bool Color { get; set; }// False -> black, True -> Red
        public Node<T> Right { get; set; }
        public Node<T> Left { get; set; }
        public Node<T> Parent { get; set; }
        public T Value { get; set; }
        public Node() {
            Color = false;// Assume this node is root or a leaf
            Right = null;
            Left = null;
            Parent = null;
            Value = default;

        }
        public Node(Node<T> parent, Node<T> right, Node<T> left, bool color, T value) {
            Color = color;
            Right = right;
            Left = left;
            Parent = parent;
            Value = value;
        }
        public int CompareTo(Node<T> obj)
        {
            return Comparer<T>.Default.Compare(this.Value, obj.Value);
        }
        public override string ToString() => $"Parent: {(Parent==null?"Root": Parent.Value)} ,Color: {(Color ? "Red" : "Black")}, Value: {Value}";
    }
}
