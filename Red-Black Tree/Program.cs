namespace Red_Black_Tree
{
    internal class Program
    {
        static void Main(string[] args)
        {
            RedBlackTree<int> RBtree = new RedBlackTree<int>();

            RBtree.Insert(3);
            RBtree.Insert(1);
            RBtree.Insert(2);

            RBtree.PrintByBFS();
        }
    }
}
