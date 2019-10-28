#ifndef UTIL_H
#define UTIL_H

#include <vector>

using namespace std;

namespace vec_ops{
    //vector operations
    vector<double> cross(vector<double>, vector<double>);
    vector<double> dot(vector<double>, vector<double>);
    vector<double> add(vector<double>, vector<double>);
    vector<double> sub(vector<double>, vector<double>);
    vector<double> div(vector<double>, double scalar);
}

namespace linalg{
    //matrix operations
    //matrixes are just gonna be grouped vectors in most cases I can think of?

    //will be double most of the time
    template <typename T> 
    class Matrix {
        vector<vector<T>> elements;
        public:
            Matrix(vector<vector<T>> x){
                elements = x;
            }
            
            matrix inv();

            vector<vector<T>> get(){
                return elements;
            }
    };

}

vector<double> vec_ops::cross(vector<double> x, vector<double> y){

}

vector<double> vec_ops::dot(vector<double> x, vector<double> y){

}

vector<double> vec_ops::add(vector<double> x, vector<double> y){

}

vector<double> vec_ops::sub(vector<double> x, vector<double> y){

}

vector<double> vec_ops::div(vector<double> x, double scalar){

}

#endif // !UITL
