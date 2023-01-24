#include <iostream>
#include "../include/SetGraph.h"
#include "../include/MatrixGraph.h"
#include "../include/ListGraph.h"
#include "../include/ArcGraph.h"
using namespace std;

int main(){
    cout << "---SetGraph---" << endl;
    SetGraph st(10);
    st.AddEdge(1, 2);
    cout << st.GetNextVertices(1)[0] << endl;
    
    cout << endl << "---MatrixGraph---" << endl;
    MatrixGraph ma(st);
    ma.AddEdge(2, 3);
    cout << ma.GetNextVertices(1)[0] << endl;
    cout << ma.GetNextVertices(2)[0] << endl;
    
    cout << endl << "---ListGraph---" << endl;
    ListGraph li(ma);
    li.AddEdge(3, 4);
    cout << li.GetNextVertices(1)[0] << endl;
    cout << li.GetNextVertices(2)[0] << endl;
    cout << li.GetNextVertices(3)[0] << endl;
    
    cout << endl << "---ArcGraph---" << endl;
    ArcGraph ar(li);
    ar.AddEdge(4, 5);
    cout << ar.GetNextVertices(1)[0] << endl;
    cout << ar.GetNextVertices(2)[0] << endl;
    cout << ar.GetNextVertices(3)[0] << endl;
    cout << ar.GetNextVertices(4)[0] << endl;
}
