#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include <algorithm>


using namespace std;

/*random number generation*/
int RandomNumber () { return (std::rand()%100); }

/*print vector*/
void PrintVector(const vector<int> & v){
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){

    srand((unsigned)time(NULL));
    int size_a, size_b;

    /*Enter vectors dimensions*/
    cout << "Enter size vector A" << endl;
    cin >> size_a;
    cout << "Enter size vector B" << endl;
    cin >> size_b;

    vector<int> A(size_a);
    vector<int> B(size_b);

    /*Fill vectors*/
    generate(A.begin(),A.end(),RandomNumber);
    generate(B.begin(),B.end(),RandomNumber);

    /*Sort vectors*/
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    /*Print vectors*/
    cout << "Vector 1 elements" << endl;
    PrintVector(A);
    cout << "Vector 2 elements" << endl;
    PrintVector(B);
    
    /*Check first element in common*/
    vector<int> result(A.size() + B.size());
    vector<int>::iterator it,end_comparison;
    end_comparison = set_intersection(
        A.begin(), A.end(),
        B.begin(), B.end(),
        result.begin());

    result.resize(end_comparison-result.begin());

    /*print result*/
    if(count(A.begin(),A.end(),*(result.begin()))){
        cout << "First Element that the two vectors have in common is: " << *(result.begin()) << endl;

    }else{
        cout << "No match between elements" << endl;
    }
    
    return 0;
}