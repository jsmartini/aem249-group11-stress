#ifndef UTIL_H
#define UTIL_H

#include <vector>

using namespace std;

namespace vec_ops{
    //vector operations
    vector<double> cross(vector<double>, vector<double>);
    double dot(vector<double>, vector<double>);
    vector<double> add(vector<double>, vector<double>);
    vector<double> sub(vector<double>, vector<double>);
    vector<double> div(vector<double>, double scalar);
    vector<double> resize(vector<double>, int);
    bool agree(vector<double>, vector<double>);
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
            
            Matrix inv();

            vector<vector<T>> get(){
                return elements;
            }
    };

}

bool vec_ops::agree(vector<double> x, vector<double> y){
    //makes sure vectors are of same dimension
    return x.size() == y.size();
}

vector<double> vec_ops::cross(vector<double> x, vector<double> y){
    
}

double vec_ops::dot(vector<double> x, vector<double> y){
    if(!agree(x,y)){
        throw -1;
    }else{
        double sum = 0;
        for(unsigned i = 0; i < x.size(); i++){
            sum+= x.at(i) * y.at(i);
        }
        return sum;
    }
}

vector<double> vec_ops::add(vector<double> x, vector<double> y){
    if(!agree(x,y)){
        throw -1;
    }else{
        vector<double> resultant (x.size());
        resultant.assign(resultant.size(), 0);
        for(unsigned i = 0; i < x.size(); i++){
            resultant.at(i) = x.at(i) + y.at(i);
        }
        return resultant;
    }
}

vector<double> vec_ops::sub(vector<double> x, vector<double> y){
    if(!agree(x,y)){
        throw -1;
    }else{
        vector<double> resultant (x.size());
        resultant.assign(resultant.size(), 0);
        for(unsigned i = 0; i < x.size(); i++){
            resultant.at(i) = x.at(i) - y.at(i);
        }
        return resultant;
    }
}

vector<double> vec_ops::div(vector<double> x, double scalar){
    for(unsigned i = 0; i<x.size(); i++){
        x.at(i) = x.at(i)/scalar;
    }
    return x;
}

#endif // !UITL
