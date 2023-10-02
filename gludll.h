#ifndef _GLUDLL_H_
#define _GLUDLL_H_
#include <string>

typedef struct gdll_node {
    struct gdll_node* left;
    struct gdll_node* right;
} gdll_node;

typedef struct gdll_struct{
    int data;
    std::string name;
    gdll_node glnode;
} gdll_struct;


class gdll{
    private:
        gdll_node *node;
        static int numberOfNodes;

    public:
        gdll(int data, std::string name);

        void pushData(int data, std::string name);

        void printData();

        void pushDataat(int data, std::string name, int pos);

        void deleteData(int pos);

        ~gdll();
};

#endif
