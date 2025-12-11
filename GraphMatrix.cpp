#include "GraphMatrix.hpp"

GraphMatrix::GraphMatrix(int numV, GType type) : Graph(numV, 0, type){
    // TODO

    adjMatrix = new bool*[v];
    for(int i = 0; i < v; i++)
    {
        adjMatrix[i] = new bool[v];

        for(int j = 0; j < v; j++)
        {
            adjMatrix[i][j] = false;
        }
    }

}

GraphMatrix::~GraphMatrix() {
    // TODO

    if(adjMatrix != nullptr)
    {
        for(int i = 0; i < v; i++)
        {
            delete[] adjMatrix[i];
        }

        delete[] adjMatrix;

    }


}

bool GraphMatrix::isEdge(int i, int j) const {
    // TODO

    if(i < 0 || i >= v || j < 0 || j >= v)
    {
        return false;
    }

    return adjMatrix[i][j];

}

ostream& GraphMatrix::print(ostream& os) const {
    os << "    ";
    for (int i = 0; i < v; i++) {
        os << i << ' ';
    }
    os << endl;

    os << "---";
    for (int i = 0; i < v; i++) {
        os << "--";
    }
    os << endl;

    for (int i = 0; i < v; i++) {
        os << i << " | ";
        for (int j = 0; j < v; j++) {
            os << adjMatrix[i][j] << ' ';
        }
        os << endl;
    }

    return os;
}

void GraphMatrix::toggleEdge(int i, int j) {
    // TODO

    if(i < 0 || i >= v || j < 0 || j >= v)
    {
        return;
    }

    if(adjMatrix[i][j])
    {
        adjMatrix[i][j] = false;
        e--;


        if(graphType == UNDIRECTED && i != j)
        {
            adjMatrix[j][i] = false;
        }
    }else
    {
        adjMatrix[i][j] = true;
        e++;

        if(graphType == UNDIRECTED && i != j)
        {
            adjMatrix[j][i] = true;
        }
    }

}
