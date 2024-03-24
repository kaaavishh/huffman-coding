#ifndef HEADER_HPP
#define HEADER_HPP
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

struct Node {
    char ch;
    unsigned frequency;
    string code;
    Node *left, *right;

    Node() {
        left = right = NULL;
    }
};

class huffman {
    private:
        vector <Node*> arr;

        fstream inFile, outFile;

        string inFileName, outFileName;
        
        Node *root;
        
        class Compare {
            public:
                bool operator() (Node* l, Node* r)
                {
                    return l->frequency > r->frequency;
                }
        };

        priority_queue <Node*, vector<Node*>, Compare> minHeap;
        void createArr();
        void traverse(Node*, string);
        int binToDec(string);

        string decToBin(int);

        void buildTree(char, string&);
        void createMinHeap();
        void createTree();
        void createCodes();
        void saveEncodedFile();
        
        void saveDecodedFile();
        
        void getTree();

    public:
        
        huffman(string inFileName, string outFileName)
        {
            this->inFileName = inFileName;
            this->outFileName = outFileName;
            createArr();
        }
        
        void compress();
        
        void decompress();
};
#endif
