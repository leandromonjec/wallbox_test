#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include <algorithm>
#include <exception>
using namespace std;

/*random number generation*/
int RandomNumber (int i) { return std::rand()%i;}

/*print vector*/
void PrintVector(const vector<int> & v){
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
}


int main(){

    srand((unsigned)time(NULL));
    int size_a;

    /*Enter vectors dimensions*/
    cout << "Enter size vector A" << endl;
    cin >> size_a;
    vector<int> coin_tosses_list(size_a);
    vector<int> sorted_list;
    vector<int> zero_index_list;
    vector<int> one_index_list;

    /*Fill vectors. If the list length is odd, we need to have one extra zero, so the list
    start in 0  and ends in 0*/
    
    if (size_a % 2 == 0){
        fill(coin_tosses_list.begin(),coin_tosses_list.begin()+coin_tosses_list.size()/2,0);
        fill(coin_tosses_list.begin()+coin_tosses_list.size()/2,coin_tosses_list.end(),1);
    }
    else{      
        fill(coin_tosses_list.begin(),coin_tosses_list.begin()+coin_tosses_list.size()/2+1,0);
        fill(coin_tosses_list.begin()+coin_tosses_list.size()/2+1,coin_tosses_list.end(),1);

    }

    /* Creates a sorted list to compare with the original coin tosses list*/
    for(int i = 0 ; i<size_a ; i++){
        sorted_list.push_back(i % 2 == 0? 0 : 1);
    }

    /* shuffle coin tosses list*/
    random_shuffle ( coin_tosses_list.begin(), coin_tosses_list.end(), RandomNumber);

    // Print vector
    PrintVector(coin_tosses_list);

  /* Compares the coin tosses list with the expected result, so we can find the indexes of the values that we need to change. 
  If the value that we need to change is a 0, we store the index in zero_index_list and if it's one, we save it in one_index_list
  */
    for (int i = 0; i< size_a;i++){

        if (sorted_list[i] != coin_tosses_list[i]){
            if(coin_tosses_list[i] == 0){
                zero_index_list.push_back(i);         
            }else{
                one_index_list.push_back(i); 
                }                      
        }else{
            continue;
        }
    }

    /*Count permutations*/
    int val;
    int permutations_count = zero_index_list.size()>one_index_list.size() ? one_index_list.size() : zero_index_list.size(); 
    for (int i = 0; i< one_index_list.size();i++){
        val = coin_tosses_list[zero_index_list[i]]; 
        coin_tosses_list[zero_index_list[i]] = coin_tosses_list[one_index_list[i]];
        coin_tosses_list[one_index_list[i]]=val;
    }

    cout << endl;

    /* Print sorted coin tosses list*/
    PrintVector(coin_tosses_list);


    cout << "Total permutations to sort vector : " << permutations_count << endl;
    return 0;
}