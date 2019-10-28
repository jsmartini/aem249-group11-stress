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
    vector<double> div(vector<double>, int scalar);
}

namespace linalg{
    //matrix operations
    //matrixes are just gonna be grouped vectors in most cases I can think of?

    //will be double most of the time
    template <class T> 
    class matrix {
        private:
            vector<vector<T>> elements;
        public:
            matrix(vector<vector<T>>);
            matrix inv();
            vector<vector<T>> get();
    };
    
}

#endif // !UITL
