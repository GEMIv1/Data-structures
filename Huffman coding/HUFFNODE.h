using namespace std;


struct HUFFNODE{
    int freq;
    char ch;
    HUFFNODE *left;
    HUFFNODE *right;

    HUFFNODE(){
        freq = 0;
        left = nullptr;
        right = nullptr;
    }
    HUFFNODE(char ch, int freq){
        this->ch = ch;
        this->freq = freq;
        right = nullptr;
        left = nullptr;
    }
};

struct Compare {
        bool operator()(const HUFFNODE *a, const HUFFNODE *b) {
            return a->freq > b->freq;
        }
};
