#ifndef GRAPHKV_H
#define GRAPHKV_H
#pragma once
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template<class T>

class GRAPHKV
{
    vector<T> vertList;
    vector<T> labelList;
    bool* visitedVerts = new bool[vertList.size()];
public:
    int adjMatrix[20][20] = {};
    GRAPHKV();
    ~GRAPHKV();
    void InsertEdge(const T& vertex1, const T& vertex2, int weight);
    void InsertVertex(const T& vertex);
    void DeleteVertex();
    int GetVertPos(const T& vertex);
    bool IsEmpty();
    bool IsFull();
    int GetAmountVerts();
    string Print();
    void answer(int*** mat, int n1, int** help, int* path,int amountVerts);
    void preparation(int***& mat, int& n1, int**& help, int*& result,int amountVerts);
    int tsalesman(int*** mat, int n1, int** help, int* result);

};

template<class T>
void GRAPHKV<T>::InsertVertex(const T& vertex) {
    if (!this->IsFull()) {
        cout<<"\nKOLPPP\n";
        this->vertList.push_back(vertex);
    }
    else {
        cout << "Граф уже заполнен. Невозможно добавить новую вершину " << endl;
        return;
    }
}
template<class T>
void GRAPHKV<T>::DeleteVertex() {

    this->vertList.pop_back();

}

template<class T>
int GRAPHKV<T>::GetAmountVerts() {
    return this->vertList.size();
}
template<class T>
bool GRAPHKV<T>::IsEmpty() {
    if (this->vertList.size() != 0)
        return false;
    else
        return true;
}
template<class T>
bool GRAPHKV<T>::IsFull() {
    return (vertList.size() == 20);
}
template <class T>
int GRAPHKV<T>::GetVertPos(const T& vertex) {
    for (int i = 0; i < this->vertList.size(); i++) {
        if (this->vertList[i] == vertex)
            return i;
    }
    return -1;
}
template<class T>
GRAPHKV<T>::GRAPHKV() {
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            this->adjMatrix[i][j] = 0;
        }
    }
}
template<class T>
GRAPHKV<T>::~GRAPHKV() {

}

template<class T>
void GRAPHKV<T>::InsertEdge(const T& vertex1, const T& vertex2, int weight) {
    if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1)) {
        int vertPos1 = GetVertPos(vertex1);
        int vertPos2 = GetVertPos(vertex2);
        if (this->adjMatrix[vertPos1][vertPos2] != 0
            && this->adjMatrix[vertPos2][vertPos1] != 0) {
            cout << "LOOL" << endl;
            return;
        }
        else {
            this->adjMatrix[vertPos1][vertPos2] = weight;
            this->adjMatrix[vertPos2][vertPos1] = weight;
        }
    }
    else {
        cout << "LOL " << endl;
        return;
    }
}

template<class T>
string GRAPHKV<T>::Print() {
    string prt;
    if (!this->IsEmpty()) {
        cout << "Matrix: " << endl;
        for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i) {
            cout << this->vertList[i] << " ";
            for (int j = 0; j < vertListSize; ++j) {
                cout << " " << this->adjMatrix[i][j] << " ";
                prt = this->adjMatrix[i][j];
            }
            cout << endl;
        }
        return prt;
        cout<<"\n========================\n";
    }
}
#endif // GRAPHKV_H
